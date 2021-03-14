/* linkedlist.c */
#include "linkedlist.h"
#include "memory.h"

void insertFirst(struct linkedList * head, int ele)
{
  struct node *link = (struct node*)myalloc(sizeof(struct node));
  link->element = ele;
  link->next = head->first;
  //point first to new first node
  head -> first = link;
  head->count++;
}

//delete first item
struct node* deleteFirst(struct linkedList * head)
{
    struct node * temp = head->first;
    head->first = temp->next;

    head->count--;
    
    return temp;
}

void printList(struct linkedList * head)
{
  struct node *ptr = head->first;
  printf("\n[ ");
  while(ptr != NULL)
  {
    printf("%d, ", ptr->element);
    ptr = ptr->next;
  }
  printf(" ]");
}
