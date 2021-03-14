#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "memory.h"

void insertFirst(struct linkedList* head, int ele)
{
    struct node *link = (struct node*) myalloc(sizeof(struct node));
    link->element=ele;
    link->next = head->first;
    head -> first = link;
    head -> count ++;
}

struct node* deleteFirst(struct linkedList * head)
{
    struct node* temp;
    temp = head->first;
    head->first = temp->next;
    head -> count --;
    return temp;
}

void printList (struct linkedList * head){
    struct node *ptr = head->first;
    printf("\n[ ");
    while(ptr != NULL)
    {
        printf("%d,",ptr->element);
        ptr = ptr->next;
    }
    printf(" ]\n");
}
