#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "cutoff.h"

int main()
{
  char* files[1] = {"100000"};
  int n = atoi(files[0]);
  record* arr = (record*) malloc(n*sizeof(record));
  readInput(files[0], arr);

  // testRun(arr,n);
  int x = estimateCutOff(arr,1,5000);

  struct timespec start, end;
  double timeCS;
  clock_gettime(CLOCK_MONOTONIC, &start);

  customsort(arr,n,x);

  clock_gettime(CLOCK_MONOTONIC, &end);
  timeCS = (end.tv_sec - start.tv_sec) * 1e9;
  timeCS = (timeCS + (end.tv_nsec - start.tv_nsec)) * 1e-9;

  FILE* fp1 = freopen(".txt", "a", stdout);
  printf("N = %d, x = %d, time taken = %.9f\n",n,x,timeCS);
  fclose(fp1);

  FILE* fp2 = freopen("sorted.txt", "w", stdout);
  printRecords(arr,n);
  fclose(fp2);
  return 0;
}
