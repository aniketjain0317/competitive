/*
GROUP - 14
Created By:   
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/


#include "parser.h"
#include "symbol.h"
#include <stdlib.h>
#include <string.h>

long int allocatedMemory;
long int parseNodes;
bool hasErrors = false;

void initializeVariablesParser() {
    allocatedMemory = 0;
    parseNodes = 0;
}

long int getMemory() {
    return allocatedMemory;
}

long int getParseNodes() {
    return parseNodes;
}

List newList() {
    List l = (List) malloc(sizeof(list));
    if (l == NULL) {
        return NULL;
    }
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
    return l;
}

List insertAtEnd(List l, int i) {
    element e = (element) malloc(sizeof(Node));
    if (e == NULL) {
        return NULL;
    }
    e->data = i;
    e->next = NULL;
    if (l->head == NULL) {
        l->head = e;
    } else {
        l->tail->next = e;
    }
    l->tail = e;
    l->size += 1;
    return l;
}

List insertAtFront(List l, int val) {
    element e = (element) malloc(sizeof(Node));
    if (e == NULL) {
        return NULL;
    }
    e->data = val;
    if (l->head == NULL) {
        l->head = e;
        e->next = NULL;
        l->tail = e;
    } else {
        e->next = l->head;
        l->head = e;
    }
    l->size += 1;
    return l;
}

int contains(List list, int token) {
    element temp = list->head;
    while (temp != NULL) {
        if (token == temp->data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}


hashtable_t *createHashtable(int size) {
    hashtable_t *hashtable = (hashtable_t *) malloc(sizeof(hashtable_t));
    int i;
    if (hashtable == NULL) {
        return NULL;
    }
    hashtable->table = (entry_t **) malloc(sizeof(entry_t *) * size);
    if (hashtable->table == NULL) {
        return NULL;
    }
    for (i = 0; i < size; i++) {
        hashtable->table[i] = (entry_t *) malloc(sizeof(entry_t) * size);
    }
    hashtable->size = size;
    return hashtable;
}

long int hash(hashtable_t *hashtable, char *key) {

    long int hashval = 0;
    int i = 0;
    int len = strlen(key);
    while (i < len) {
        hashval = hashval << 8;
        hashval = (hashval + key[i]) % hashtable->size;
        i++;
    }

    return hashval;
}

entry_t *getPair(char *key, List value) {
    entry_t *newpair = (entry_t *) malloc(sizeof(entry_t));
    if (newpair == NULL) {
        return NULL;
    }
    newpair->key = strdup(key);
    newpair->value = value;
    newpair->next = NULL;
    return newpair;
}

void hash_put(hashtable_t *hashtable, char *key, List value) {
    entry_t *newpair = getPair(key, value);
    int hashval = hash(hashtable, key);
    entry_t *temp = hashtable->table[hashval];
    entry_t *prev = NULL;
    while (temp != NULL && temp->key != NULL && strcmp(key, temp->key) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL && temp->key != NULL && strcmp(key, temp->key) == 0) {
        temp->value = value;
    } else {
        if (temp == hashtable->table[hashval]) {
            newpair->next = temp;
            hashtable->table[hashval] = newpair;
        } else if (temp == NULL) {
            prev->next = newpair;
        } else {
            newpair->next = temp;
            prev->next = newpair;
        }
    }
}

List hash_get(hashtable_t *hashtable, char *key) {
    int hashval = hash(hashtable, key);
    entry_t *temp = hashtable->table[hashval];
    while (temp != NULL && temp->key != NULL && strcmp(key, temp->key) != 0) {
        temp = temp->next;
    }
    if (temp == NULL || temp->key == NULL || strcmp(key, temp->key) != 0) {
        return newList();
    }
    return temp->value;
}

hashtableInt *createHashtableInt(int size) {
    hashtableInt *hashtable = (hashtableInt *) malloc(sizeof(hashtableInt));
    int i;
    if (hashtable == NULL) {
        return NULL;
    }
    hashtable->table = (entryInt **) malloc(sizeof(entryInt *) * size);
    if (hashtable->table == NULL) {
        return NULL;
    }
    for (i = 0; i < size; i++) {
        hashtable->table[i] = (entryInt *) malloc(sizeof(entryInt) * size);
    }
    hashtable->size = size;
    return hashtable;
}

long int hashInt(hashtableInt *hashtable, char *key) {
    long int hashval = 0;
    int i = 0;
    int len = strlen(key);
    while (i < len) {
        hashval = hashval << 8;
        hashval = (hashval + key[i]) % hashtable->size;
        i++;
    }

    return hashval;
}

entryInt *getPairInt(char *key, int value) {
    entryInt *newpair = (entryInt *) malloc(sizeof(entryInt));
    if (newpair == NULL) {
        return NULL;
    }
    newpair->key = strdup(key);
    newpair->value = value;
    newpair->next = NULL;
    return newpair;
}

void hash_putInt(hashtableInt *hashtable, char *key, int value) {
    entryInt *newpair = getPairInt(key, value);
    int hashval = hashInt(hashtable, key);
    entryInt *temp = hashtable->table[hashval];
    entryInt *prev = NULL;
    while (temp != NULL && temp->key != NULL && strcmp(key, temp->key) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL && temp->key != NULL && strcmp(key, temp->key) == 0) {
        temp->value = value;
    } else {
        if (temp == hashtable->table[hashval]) {
            newpair->next = temp;
            hashtable->table[hashval] = newpair;
        } else if (temp == NULL) {
            prev->next = newpair;
        } else {
            newpair->next = temp;
            prev->next = newpair;
        }
    }
}

int hash_getInt(hashtableInt *hashtable, char *key) {
    int hashval = hashInt(hashtable, key);
    entryInt *temp = hashtable->table[hashval];
    while (temp != NULL && temp->key != NULL && strcmp(key, temp->key) != 0) {
        temp = temp->next;
    }
    if (temp == NULL || temp->key == NULL || strcmp(key, temp->key) != 0) {
        return -1;
    }
    return temp->value;
}

void populateWithSymbols(hashtableInt *h) {
    int i;
    for (i = 0; i < NO_OF_TERMINALS; i++) {
        hash_putInt(h, TermSymbol[i], i);
    }
    for (i = 0; i < NO_OF_NON_TERMINALS; i++) {
        hash_putInt(h, NonTermSymbol[i], 100 + i);
    }
}

void getRules(FILE *fp, hashtableInt *hashtable) {
    char buf[100];
    int i = 0;
    for (i = 1; i <= NO_OF_RULES; i++) {
        fscanf(fp, "%[^\n]\n", buf);
        char *token = strtok(buf, " ");
        rules[i] = newList();
        insertAtEnd(rules[i], hash_getInt(hashtable, token));
        while (1) {
            token = strtok(NULL, " ");
            if (token == NULL)
                break;
            insertAtEnd(rules[i], hash_getInt(hashtable, token));
        }
    }
}


void populateHashTables(hashtable_t *table1, hashtable_t *table2) {
    int i;
    for (i = 1; i <= NO_OF_RULES; i++) {
        rule *temp = rules[i]->head;
        List l1 = hash_get(table1, NonTermSymbol[temp->data - 100]);
        l1 = insertAtEnd(l1, i);
        hash_put(table1, NonTermSymbol[temp->data - 100], l1);
        rule *traverse = temp->next;
        while (traverse != NULL) {
            if (traverse->data < 100) {
                traverse = traverse->next;
                continue;
            }
            List l2 = hash_get(table2,
                               traverse->data < 100 ? TermSymbol[traverse->data] : NonTermSymbol[traverse->data - 100]);
            rule *value = traverse->next;
            while (value != NULL) {
                l2 = insertAtEnd(l2, value->data);
                value = value->next;
            }
            l2 = insertAtEnd(l2, 53);   //53 is index of "eps" in TermSymbol array
            l2 = insertAtEnd(l2,
                             54);   //let 54 be index of a special terminal "@" which separates symbols to right from lhs
            l2 = insertAtEnd(l2, temp->data);
            hash_put(table2, traverse->data < 100 ? TermSymbol[traverse->data] : NonTermSymbol[traverse->data - 100],
                     l2);
            traverse = traverse->next;
        }
    }
}

int checkIfTerminal(int id) {
    return id < 98;
}

void first(hashtable_t *table1, hashtable_t *table2, int i) {
    rule *rhs = rules[i]->head->next;
    rule *lhs = rules[i]->head;
    int flag = 1;
    while (rhs != NULL && flag == 1) {
        if (checkIfTerminal(rhs->data)) {
            List non_ter = hash_get(table2, NonTermSymbol[lhs->data - 100]);
            if (!contains(non_ter, rhs->data)) {
                if (rhs->data == 53) {
                    non_ter = insertAtFront(non_ter, rhs->data);
                } else {
                    non_ter = insertAtEnd(non_ter, rhs->data);
                }
                hash_put(table2, NonTermSymbol[lhs->data - 100], non_ter);
            }
            break;
        } else {
            List l = hash_get(table1, NonTermSymbol[rhs->data - 100]);
            element temp = l->head;
            while (temp != NULL) {
                first(table1, table2, temp->data);
                temp = temp->next;
            }
            List temp1 = hash_get(table2, NonTermSymbol[rhs->data - 100]);
            element firsts;
            if (temp1->head->data == 53) {
                firsts = temp1->head->next;
            } else {
                flag = 0;
                firsts = temp1->head;
            }
            List temp2 = hash_get(table2, NonTermSymbol[lhs->data - 100]);
            while (firsts != NULL) {
                if (!contains(temp2, firsts->data)) {
                    temp2 = insertAtEnd(temp2, firsts->data);
                }
                firsts = firsts->next;
            }
            hash_put(table2, NonTermSymbol[lhs->data - 100], temp2);
            rhs = rhs->next;
        }

    }
    if (rhs == NULL && flag == 1) {
        List temp3 = hash_get(table2, NonTermSymbol[lhs->data - 100]);
        temp3 = insertAtEnd(temp3, 53);
        hash_put(table2, NonTermSymbol[lhs->data - 100], temp3);
    }
}

hashtable_t *computeFirst(hashtable_t *table1) {
    hashtable_t *table2 = createHashtable(1009);
    int i;
    for (i = 0; i < NO_OF_TERMINALS; i++) {
        List l = newList();
        l = insertAtEnd(l, i);
        hash_put(table2, TermSymbol[i], l);
    }
    for (i = 1; i <= NO_OF_RULES; i++) {
        first(table1, table2, i);
    }
    return table2;
}

List firstOfAlpha(hashtable_t *first, element head) {
    List firstList = newList();
    element temp = head;
    int flag = 1;
    while (temp != NULL) {
        List l = hash_get(first, temp->data < 100 ? TermSymbol[temp->data] : NonTermSymbol[temp->data - 100]);
        if (l->head->data != 53) {
            flag = 0;
        }
        element ele = l->head;
        while (ele != NULL) {
            if (!contains(firstList, ele->data)) {
                if (ele->data != 53) {
                    firstList = insertAtEnd(firstList, ele->data);
                }
            }
            ele = ele->next;
        }
        temp = temp->next;
        if (flag == 0) {
            return firstList;
        }
    }
    if (flag == 1) {
        firstList = insertAtFront(firstList, 53);
    }
    return firstList;
}

void computeFollowHelp(hashtable_t *table, hashtable_t *first, hashtable_t *follow, char *nonTerminal,
                       hashtableInt *hash_t) {
    if (hash_get(follow, nonTerminal)->size > 0) {
        return;
    }
    List l = hash_get(table, nonTerminal);   //list of all lines on which nonTerminal appears on the RHS
    element temp = l->head;
    while (temp != NULL) {
        element f = temp;
        List list = newList();
        while (f->data != 54) {     // 54 here is for "@"
            list = insertAtEnd(list, f->data);
            f = f->next;
        }
        element s = f->next;
        temp = f->next->next;
        List firstList = firstOfAlpha(first, list->head);
        element e = firstList->head;
        if (e->data == 53) {
            e = e->next;
            if (hash_getInt(hash_t, nonTerminal) != s->data) {
                computeFollowHelp(table, first, follow,
                                  s->data < 100 ? TermSymbol[s->data] : NonTermSymbol[s->data - 100], hash_t);
                List followList = hash_get(follow, s->data < 100 ? TermSymbol[s->data] : NonTermSymbol[s->data - 100]);
                element ele = followList->head;
                while (ele != NULL) {
                    List lis1 = hash_get(follow, nonTerminal);
                    if (!contains(lis1, ele->data)) {
                        insertAtEnd(lis1, ele->data);
                        hash_put(follow, nonTerminal, lis1);
                    }
                    ele = ele->next;
                }
            }
        }
        while (e != NULL) {
            List lis1 = hash_get(follow, nonTerminal);
            if (!contains(lis1, e->data)) {
                insertAtEnd(lis1, e->data);
                hash_put(follow, nonTerminal, lis1);
            }
            e = e->next;
        }
    }
}

void computeFollow(hashtable_t *table, hashtable_t *first, hashtable_t *follow, hashtableInt *hash_t) {
    int i;
    List li = newList();
    hash_put(follow, NonTermSymbol[rules[1]->head->data - 100], insertAtEnd(li, EOS_ID));
    for (i = 2; i <= NO_OF_RULES; i++) {
        char *value =
                rules[i]->head->data < 100 ? TermSymbol[rules[i]->head->data] : NonTermSymbol[rules[i]->head->data -
                                                                                              100];
        computeFollowHelp(table, first, follow, value, hash_t);
    }
}

void fillParseTableWithSynchs(hashtable_t *follow) {
    for (int i = 0; i < NO_OF_NON_TERMINALS; i++) {
        for (int j = 0; j < NO_OF_TERMINALS - 1; j++) {
            List l = hash_get(follow, NonTermSymbol[i]);
            if (contains(l, j) && parse_table[i][j] == 0) {
                parse_table[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < NO_OF_NON_TERMINALS; i++) {
        List l = hash_get(follow, NonTermSymbol[i]);
        if (contains(l, EOS_ID) && parse_table[i][53] == 0) {
            parse_table[i][53] = -1;
        }
    }
}

void generateParseTable(hashtable_t *first, hashtable_t *follow) {
    int i;
    for (i = 1; i <= NO_OF_RULES; i++) {
        rule *alpha = rules[i]->head->next;
        List li = firstOfAlpha(first, alpha);
        element ele = li->head;
        if (ele->data == 53) {
            List f = hash_get(follow, NonTermSymbol[rules[i]->head->data - 100]);
            element e = f->head;
            while (e != NULL) {
                if (e->data == EOS_ID) {
                    parse_table[rules[i]->head->data - 100][53] = i;
                } else {
                    parse_table[rules[i]->head->data - 100][e->data] = i;
                }
                e = e->next;
            }
            ele = ele->next;
        }
        while (ele != NULL) {
            parse_table[rules[i]->head->data - 100][ele->data] = i;
            ele = ele->next;
        }
    }
    fillParseTableWithSynchs(follow);
}

Stack createStack() {
    Stack s = (Stack) malloc(sizeof(struct stack_entry));
    if (s == NULL) {
        return NULL;
    }
    s->size = 0;
    s->list = NULL;
    return s;
}

void push(Stack s, ParseTree node) {

    tree_pointer temp = (tree_pointer) malloc(sizeof(struct tree_pointer));
    if (temp == NULL) {
        return;
    }
    temp->tnode = node;
    if (s->list == NULL) {
        s->list = temp;
        temp->next = NULL;
    }
    temp->next = s->list;
    s->list = temp;
    s->size += 1;
}

ParseTree top(Stack s) {
    if (s->size == 0) {
        return NULL;
    }
    return s->list->tnode;
}

tree_pointer pop(Stack s) {
    if (s->size == 0) {
        return NULL;
    }
    tree_pointer temp = s->list;
    s->list = s->list->next;
    s->size -= 1;
    return temp;
}

// Utility function which calls pop()
void pophelper(Stack s, char *str, int line, char *token) {
    tree_pointer popped = pop(s);
    popped->tnode->lexeme = strdup(str);
    popped->tnode->tokenName = strdup(token);
    popped->tnode->lineno = line;
}

int count = 0;

ParseTree createParseTreeNode(char *str, ParseTree par, int id) {
    ParseTree temp = (ParseTree) malloc(sizeof(struct tree_node));
    temp->id = id;
    temp->parent = par;
    temp->firstChild = NULL;
    temp->noOfChildren = 0;
    temp->sibling = NULL;
    temp->nodeSymbol = strdup(str);
    temp->ruleno = -1;
    count++;
    return temp;
}

void addNodeToStackAndTree(Stack s, rule *temp, ParseTree prev, ParseTree par, int flag) {
    if (temp == NULL) {
        return;
    }
    ParseTree child = createParseTreeNode((temp->data < 98) ? "----" : NonTermSymbol[temp->data - 100], par,
                                          temp->data);
    if (flag == 1) {
        par->firstChild = child;
    } else {
        prev->sibling = child;
    }
    prev = child;
    par->noOfChildren += 1;
    addNodeToStackAndTree(s, temp->next, prev, par, 0);
    push(s, child);
}

ParseTree generateParseTree(symbolTable tab, FILE *fp, hashtableInt *table, hashtable_t *first, bool printReqd) {
    TokenData *tok = getNextToken(tab, fp, printReqd);
    Stack s = createStack();
    push(s, createParseTreeNode("$", NULL, DOLLAR_ID));
    ParseTree top_node = createParseTreeNode("program", NULL, hash_getInt(table, "program"));
    ParseTree root = top_node;
    push(s, top_node);
    int pt_entry;
    while (top_node->id != DOLLAR_ID && tok != NULL) {
        if (top_node->id == 53) {
            pophelper(s, "----", -1, "eps");
        } else if (top_node->id == tok->token) {
            pophelper(s, tok->lexeme, tok->lineNumber, TermSymbol[tok->token]);
            tok = getNextToken(tab, fp, printReqd);
        } else if (tok->token == TK_ERROR) {
            hasErrors = true;
            ParseTree pt = top(s);
            if (pt->id >= 100) {
                while (pt->id >= 100) {
                    pophelper(s, "Error Node", -1, "TK_ERROR");
                    pt = top(s);
                }
            } else {
                while (pt->id < 98) {
                    pophelper(s, "Error Node", -1, "TK_ERROR");
                    pt = top(s);
                }
            }
            tok = getNextToken(tab, fp, printReqd);
        } else if (checkIfTerminal(top_node->id)) {
            hasErrors = true;
            pophelper(s, "Error Node", -1, TermSymbol[top_node->id]);
            if (printReqd) {
                printf("Line %d: The token %s for lexeme %s does not match with the expected token %s\n",
                       tok->lineNumber, TermSymbol[tok->token], tok->lexeme, TermSymbol[top_node->id]);
            }
        } else if (parse_table[top_node->id - 100][tok->token] == 0) {
            hasErrors = true;
            List l = hash_get(first, NonTermSymbol[top_node->id - 100]);
            if (l->head->data == 53) {
                pophelper(s, "Error Node", -1, "----");
            } else {
                if (printReqd)
                    printf("Line %d: The token %s for lexeme %s does not match with the expected token %s\n",
                           tok->lineNumber, TermSymbol[tok->token], tok->lexeme, TermSymbol[l->head->data]);
                tok = getNextToken(tab, fp, printReqd);
            }
        } else if (parse_table[top_node->id - 100][tok->token] == -1) {
            hasErrors = true;
            List l = hash_get(first, NonTermSymbol[top_node->id - 100]);
            pophelper(s, "Error Node", -1, "----");
            if (printReqd)
                printf("Line %d: The token %s for lexeme %s does not match with the expected token %s\n",
                       tok->lineNumber, TermSymbol[tok->token], tok->lexeme, TermSymbol[l->head->data]);
        } else if ((pt_entry = parse_table[top_node->id - 100][tok->token]) > 0) {
            pophelper(s, "----", -1, "----");
            addNodeToStackAndTree(s, rules[pt_entry]->head->next, NULL, top_node, 1);
            top_node->ruleno = pt_entry;
        }
        top_node = top(s);
    }
    return root;
}


void printParseTreeHelp(ParseTree curr, bool memoryCalc) {
    if (curr == NULL) {
        return;
    }
    parseNodes++;
    allocatedMemory += sizeof(struct tree_node);
    allocatedMemory += sizeof(char) * strlen(curr->lexeme) + sizeof(char) * strlen(curr->tokenName);
    allocatedMemory += sizeof(char) * strlen(curr->nodeSymbol);
    printParseTreeHelp(curr->firstChild, memoryCalc);
    bool isNumber =
            strcmp(curr->tokenName, TermSymbol[TK_NUM]) == 0 || strcmp(curr->tokenName, TermSymbol[TK_RNUM]) == 0;
    bool isLeafNode = curr->firstChild == NULL;
    if (!memoryCalc) {
        printf("%22s |%12d |%15s |%20s |%25s |%12s |%22s\n", curr->lexeme, curr->lineno, curr->tokenName,
               isNumber ? curr->lexeme : "----", curr->parent == NULL ? "ROOT" : curr->parent->nodeSymbol,
               isLeafNode ? "yes" : "no",
               curr->nodeSymbol);
    }
    if (!isLeafNode) {
        ParseTree child = curr->firstChild->sibling;
        while (child != NULL) {
            printParseTreeHelp(child, memoryCalc);
            child = child->sibling;
        }
    }
}

void printParseTree(ParseTree root, bool flag, bool memoryCalc) {
    if (root == NULL || !flag) {
        return;
    }
    if (!memoryCalc) {
        printf("%22s |%12s |%15s |%20s |%25s |%12s |%22s\n", "Lexeme", "Line", "TokenName", "ValueIfNumber",
               "ParentNodeSymbol", "IsLeafNode", "NodeSymbol");
        printf("%22s |%12s |%15s |%20s |%25s |%12s |%22s\n", "", "", "", "", "", "", "");
    }
    printParseTreeHelp(root, memoryCalc);
}


ParseTree
printParserLexer(symbolTable table, const char *grammar, const char *testcase, bool printReqd, bool memoryCalc) {
    FILE *fp1 = fopen(grammar, "r");


    hashtableInt *hashtable = createHashtableInt(1009);
    populateWithSymbols(hashtable);
    getRules(fp1, hashtable);

    hashtable_t *table3 = createHashtable(1009);
    hashtable_t *table4 = createHashtable(1009);
    populateHashTables(table3, table4);

    hashtable_t *first = computeFirst(table3);

    hashtable_t *follow = createHashtable(1009);
    computeFollow(table4, first, follow, hashtable);

    generateParseTable(first, follow);
    FILE *fp2 = fopen(testcase, "r");
    ParseTree root = generateParseTree(table, fp2, hashtable, first, printReqd);
    if (!memoryCalc) {
        if (!hasErrors) {
            printf("Input source code is syntactically correct...........\n");
        } else {
            printf("\nInput source code could not be compiled.............\n");
        }
    }
    printParseTree(root, !hasErrors, memoryCalc);
    fclose(fp1);
    fclose(fp2);
    return root;
}

