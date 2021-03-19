#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "sorting.h"

record* copyArray(record* src, int n);
int testRun(record* arr, int n);
int estimateCutOff(record* arr, int l, int r);
