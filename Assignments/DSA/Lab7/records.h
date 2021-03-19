#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record
{
  char name[256];
  int empID;
} record;


void readInput(char* fname, record* arr);
void printRecords(record* arr, int n);
