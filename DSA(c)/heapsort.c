#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int left(int i) {return 2*i;}
int right(int i) {return 2*i+1;}
int parent(int i) {return i/2;}

void maxHeapify(int arr[], int n, int i)
{
  int l = left(i);
  int r = right(i);
  int mx =  i;
  if(l < n && arr[l]>arr[i]) mx=l;
  if(r < n && arr[r]>arr[mx]) mx=r;

  if(mx!=i)
  {
    int temp = arr[mx];
    arr[mx] = arr[i];
    arr[i] = temp;
    maxHeapify(arr,n,mx);
  }
}

void buildMaxHeap(int arr[], int n)
{
  for(int i = n/2; i>=0; i--) maxHeapify(arr,n,i);
}

void heapSort(int arr[], int n)
{
  buildMaxHeap(arr,n);
  for(int i = n-1; i > 0; i--)
  {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    maxHeapify(arr,i,0);
  }
}

int main()
{
  int arr[5] = {6,3,4,2,1};
  heapSort(arr,5);
  for(int i =0; i <5 ; i++) printf("%d ", arr[i]); printf("\n");
}
