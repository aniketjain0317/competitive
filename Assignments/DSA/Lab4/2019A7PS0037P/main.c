#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "memory.h"
#include "random.h"
#include "linkedlist.h"
#include "createLists.h"

int N = 15;

int main()
{
  srand(time(0));
  struct linkedList* Ls = createList(N);
  struct node* curr = Ls->first;
  printf("N: %d, %d\nList: ", N,Ls->count);
  while(curr!=NULL)
  {
    printf("%d ", curr->element);
    curr=curr->next;
  }
  // Ls = createCycle(Ls);
}
