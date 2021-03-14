#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "linkedlist.h"


bool checkCycle(struct linkedList* Ls)
{
    struct node *curr, *prev, *next;
    curr = Ls->first;

    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        if(curr == Ls->first)
            return true;
    }
    return false;
}
