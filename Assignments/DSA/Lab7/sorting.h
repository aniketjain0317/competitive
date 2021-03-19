#include <stdio.h>
#include <stdlib.h>

#include "records.h"

void swap(record* a, record* b);
int partition(record* arr, int l, int r);
void quicksort(record* arr, int n, int s);

void insertionsort(record* arr, int n);


void customsort(record* arr, int n, int s);
