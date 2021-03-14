#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>


#include "insertionSort.h"

void solve(char* filename)
{
  struct recordsArray cards, sorted_cards;
  init(&cards); init(&sorted_cards);
  FILE* fp = freopen(filename, "r", stdin);
  char str[256];
  while(gets(str))
  {
    struct record r = parseRecordString(str);
    append(&cards, r);
  }
  fclose(fp);


  // IMPLEMENT TIME & MEMORY CHECKERS HERE
  char b1;
  stack_bottom = &b1;
  struct timeval t1, t2;
  double elapsedTime;
  gettimeofday(&t1, NULL);

  insertionSort(&cards, &sorted_cards);

  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  int stack_space_used = (int)(stack_bottom - stack_top);

  FILE* fp2 = freopen("results.txt","a",stdout);
  printf("\nRESULTS: %s\n", filename);
  printf("Time Taken: %f ms\n", elapsedTime);
  printf("Stack space used: %d\n", stack_space_used);
  fclose(fp2);
  // printAllRecords(&cards);
  // printAllRecords(&sorted_cards);

  // printCardNumbers(&cards);
  // printCardNumbers(&sorted_cards);
}

int main()
{
  char* arr[9] = {"8","10","64", "100", "512", "1000", "4096", "10000", "32768"};
  for(int i=0; i<9; i++) solve(arr[i]);
}
