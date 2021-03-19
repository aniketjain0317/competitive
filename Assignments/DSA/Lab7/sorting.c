#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

void swap(record* a, record* b)
{
  record temp = *a;
  *a = *b;
  *b = temp;
}

// Taking last element as pivot
int partition(record* arr, int l, int r)
{
  int i = l-1;
  for(int j=l; j<r; j++)
    if(arr[j].empID <= arr[r].empID)
      swap(&arr[++i], &arr[j]);

  swap(&arr[++i], &arr[r]);
  return i;
}

void quicksort(record* arr, int n, int s)
{
  int stack[n];
  int top = -1;

  stack[++top]=0;
  stack[++top]=n-1;

  while(top>=0)
  {
    int r = stack[top--];
    int l = stack[top--];
    int sz = r-l+1;
    if(sz<=s) continue;

    int p = partition(arr,l,r);
    if(p>l)
    {
      stack[++top] = l;
      stack[++top] = p-1;
    }
    if(p<r)
    {
      stack[++top] = p+1;
      stack[++top] = r;
    }
  }
}

void insertionsort(record* arr, int n)
{
  int i, j;
  record key;
  for (i = 1; i < n; i++)
  {
      key = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j].empID > key.empID) {
          arr[j + 1] = arr[j];
          j = j - 1;
      }
      arr[j + 1] = key;
  }
}

void customsort(record* arr, int n, int s)
{
  quicksort(arr,n,s);
  insertionsort(arr,n);
}
