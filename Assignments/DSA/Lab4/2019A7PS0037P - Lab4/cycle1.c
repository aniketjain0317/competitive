#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "linkedlist.h"


bool checkCycle(struct linkedList* Ls)
{
    struct node *hare, *tort;
    hare = tort = Ls->first;

    while(hare && hare->next && tort)
    {
        hare = hare->next->next;
        tort = tort->next;
        if(hare==tort)
            return true;
    }
    return false;
}
