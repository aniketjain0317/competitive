#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "records.h"

void readInput(char* fname, record* arr)
{
  int n = atoi(fname);
  FILE* fp = freopen(fname, "r", stdin);
  char str[256];
  int i=0;
  while(gets(str))
  {
    char name[256];
    int empID;
    sscanf(str,"%s %d",name,&empID);
    strcpy(arr[i].name,name);
    arr[i].empID = empID;
    i++;
  }
  fclose(fp);
}

void printRecords(record* arr, int n)
{
  printf("RECORDS: \n");
  for(int i=0; i<n; i++)
  {
    printf("%d: %d, %s\n",i+1,arr[i].empID, arr[i].name);
  }
}
