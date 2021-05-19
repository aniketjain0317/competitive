#include <stdio.h>
#include <stdlib.h>

int A = 101, N=10000;
int hash(int k)
{
  int x = 0;
  while(k>0)
  {
    x = x*A + k%10;
    k/=10;
  }
  return x%N;
}
int findMap(int k)
{
  linkedlist* ls = map[hash(k)];
  if(ls==NULL) return NULL;
  return findList(ls, k);
}
void insertMap(int k, int v)
{
  linkedlist* ls = map[hash(k)];
  if(ls==NULL)
  {
    linkedlist* lsNew = (linkedlist*) malloc(sizeof(linkedlist));
    map[hash(k)]=lsNew;
    ls = lsNew;
  }
  insertList(ls, k, v);
}
void deleteMap(int k)
{
  linkedlist* ls = map[hash(k)];
  if(ls==NULL) return;
  deleteList(ls, k);
}

int main()
{
  printf("%d\n",hash(42069));
}
