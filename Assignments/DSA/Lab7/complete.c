#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct record
{
  char name[256];
  int empID;
} record;

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
    if(p-1>l)
    {
      stack[++top] = l;
      stack[++top] = p-1;
    }
    if(p+1<r)
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

int main()
{
  char* files[1] = {"200000"};
  int n = atoi(files[0]);
  record* arr = (record*) malloc(n*sizeof(record));
  readInput(files[0], arr);

  // testRun(arr,n);
  int x = estimateCutOff(arr,1,1000);

  struct timespec start, end;
  double timeCS;
  clock_gettime(CLOCK_MONOTONIC, &start);

  customsort(arr,n,x);

  clock_gettime(CLOCK_MONOTONIC, &end);
  timeCS = (end.tv_sec - start.tv_sec) * 1e9;
  timeCS = (timeCS + (end.tv_nsec - start.tv_nsec)) * 1e-9;

  FILE* fp1 = freopen("TIMES", "a", stdout);
  printf("N = %d, x = %d, time taken = %.9f\n",n,x,timeCS);
  fclose(fp1);

  FILE* fp2 = freopen("sorted.txt", "w", stdout);
  printRecords(arr,n);
  fclose(fp2);
  return 0;
}
