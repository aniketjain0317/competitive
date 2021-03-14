#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <stdbool.h>

#include "linkedlist.h"
#include "memory.h"
#include "createlist.h"
#include "cycle.h"

long long space = 0ll;

int main(int argc, char *argv[])
{
    struct timeval t1, t2;
    double elapsedTime;
    gettimeofday(&t1, NULL);
    srand ( time(NULL) );
    struct linkedList* Ls = createList(atoi(argv[1]));
    createCycle(Ls);
    bool ans = checkCycle(Ls);
    printf("Check if cycle: %s\n", ans ? "true" : "false");
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("Time used: %f ms.\n", elapsedTime);
    printf("Space used: %lld .\n", space);
}
