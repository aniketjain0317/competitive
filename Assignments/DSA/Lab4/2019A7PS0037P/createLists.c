#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "memory.h"
#include "random.h"
struct linkedList *createList(int N)
{
  struct linkedList* Ls = (struct linkedList*) malloc(sizeof(struct linkedList));
  for(int i=0; i<N; i++) {insertFirst(Ls, rand());
    printf("%d ", Ls->count);}
  return Ls;
}

struct linkedList *createCycle(struct linkedList* Ls)
{
  int cointoss = random(0,1);
  if(!cointoss)
  {
    printf("No cycle formed\n");
    return Ls;
  }

  int cycle_ind = random(1,Ls->count);
  struct node* curr = Ls->first;
  struct node* cycle_node = Ls->first;

  for(int i=1; i<=Ls->count; i++)
  {
    if(i==cycle_ind) cycle_node = curr;
    if(curr->next!=NULL) curr=curr->next;
  }
  curr->next=cycle_node;

  printf("Cycle formed: %d\n", cycle_ind);
  return Ls;
}
