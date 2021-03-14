/* driver.c */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{
  FILE * fileptr = fopen(argv[1], "r");
  struct linkedList * head = (struct linkedList *) malloc(sizeof(struct linkedList));
  head->first=NULL;
  head->count=0;
  while (!feof(fileptr))
  {
    int temp;
    fscanf(fileptr, "%d ", &temp);
    push(head,temp);
  }
  fclose(fileptr);
  printStack(head);
  while(head->count>0)
  {
    pop(head);
    printStack(head);
  }
}
