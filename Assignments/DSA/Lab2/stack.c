#include "stack.h"

void push(struct linkedList* head, int ele)
{
  insertFirst(head,ele);
}

struct node *pop(struct linkedList *head)
{
  return deleteFirst(head);
}

void printStack(struct linkedList * head)
{
  printList(head);
}
