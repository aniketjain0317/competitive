#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "memory.h"



struct linkedList* createList(int N)
{
    struct linkedList * Ls = (struct linkedList *) myalloc (sizeof(struct linkedList));
    for(int i = 0; i < N; i++)
        insertFirst(Ls, rand());
    return Ls;
}

struct linkedList* createCycle(struct linkedList* Ls)
{
    if(rand() % 2 == 0)
    {
        printf("No cycle formed\n");
        return Ls;
    }
    struct node *last, *rand_node;
    long long random = rand() % Ls->count;
    last = rand_node = Ls->first;
    int i=0;
    while(last->next != NULL){
        if(i==random) rand_node=last;
        last = last->next; i++;
    }

    last->next = rand_node;

    printf("Cycle formed at random element %d\n",random);
    return Ls;
}
