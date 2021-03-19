#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "cutoff.h"

record* copyArray(record* src, int n)
{
  record* dst = (record*) malloc(n*sizeof(record));
  for(int i=0; i<n; i++)
    dst[i]=src[i];
  return dst;
}

int testRun(record* arr, int n)
{
  record* arrQS = copyArray(arr,n);
  record* arrIS = copyArray(arr,n);

  struct timespec start, end;
  double timeQS, timeIS;

  clock_gettime(CLOCK_MONOTONIC, &start);
  quicksort(arrQS,n,0);
  clock_gettime(CLOCK_MONOTONIC, &end);
  timeQS = (end.tv_sec - start.tv_sec) * 1e9;
  timeQS = (timeQS + (end.tv_nsec - start.tv_nsec)) * 1e-9;

  clock_gettime(CLOCK_MONOTONIC, &start);
  insertionsort(arrIS,n);
  clock_gettime(CLOCK_MONOTONIC, &end);
  timeIS = (end.tv_sec - start.tv_sec) * 1e9;
  timeIS = (timeIS + (end.tv_nsec - start.tv_nsec)) * 1e-9;

  if(!timeIS || !timeQS) return -1;
  double ch = ((timeIS-timeQS)/timeQS);
  // printf("Ratio: %d, %.9f, %.9f: %.9f\n", n,timeIS, timeQS, ch);
  if(ch<0) return -1;
  else if(ch<1e-7) return 0;
  else return 1;
}

int estimateCutOff(record* arr, int l, int r)
{
  int m = (l+r)/2;
  if(r-l<3) return m;
  int x3 = testRun(arr,m);
  if(x3==0) return m;
  if(x3==1) return estimateCutOff(arr,l,m-1);
  if(x3==-1) return estimateCutOff(arr,m+1,r);
}
