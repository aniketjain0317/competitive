/* stack.h */
#include <stdio.h>
#include "linkedlist.h"

void push(struct linkedList* head, int ele);
struct node *pop(struct linkedList *head);
void printStack(struct linkedList * head);
