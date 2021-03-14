#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "insertionSort.h"

void insertInOrder(struct recordsArray* cards, struct record x)
{
  int pos = length(cards);
  for(int i=0; i<pos; i++)
  {
    if(get(cards, i).card_no >= x.card_no)
    {
      pos=i;
      break;
    }
  }
  insert(cards, pos, x);
}

void insertionSort(struct recordsArray* unsorted, struct recordsArray* sorted)
{
  // STACK SPACE CHECKER
  char b2;
  stack_top = &b2;
  // printf("%d\n", (int)(stack_bottom - stack_top));
  int pos = length(sorted);
  if(pos == length(unsorted))
    return;
  struct record x = get(unsorted, pos);
  insertInOrder(sorted, x);
  insertionSort(unsorted, sorted);
}
