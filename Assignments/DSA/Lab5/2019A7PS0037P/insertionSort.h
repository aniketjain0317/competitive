#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "recordsArray.h"

char* stack_top;
char* stack_bottom;

void insertInOrder(struct recordsArray* cards, struct record x);
void insertionSort(struct recordsArray* unsorted, struct recordsArray* sorted);
