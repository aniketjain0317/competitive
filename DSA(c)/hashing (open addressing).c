#include <stdio.h>
#include <stdlib.h>

int N = 41, N2=37;
int EMPTY = -1, DELETED = -2;

int hash(int k) {return k%N;}
int hash2(int k) {return N2 - k%N2;}
int dhash(int k, int i) {return (hash(k) + i*hash2(k))%N;}

int *map;
int *mapv;

void init()
{
  map = (int*) malloc(N*sizeof(int));
  mapv = (int*) malloc(N*sizeof(int));
  for(int i=0; i<N; i++)
  {
    map[i]=EMPTY;
    mapv[i]=EMPTY;
  }
}

int insertMap(int k, int v)
{
  for(int i =0; i<N; i++)
  {
    int j = dhash(k,i);
    if(map[j]==EMPTY || map[j]==DELETED)
    {
      map[j]=k;
      mapv[j]=v;
      return j;
    }
  }
  return -1;
}

int findMap(int k)
{
  for(int i =0; i<N; i++)
  {
    int j = dhash(k,i);
    if(map[j]==EMPTY) return -1;
    if(map[j]==k) return mapv[j];
  }
  return -1;
}

int deleteMap(int k)
{
  for(int i =0; i<N; i++)
  {
    int j = dhash(k,i);
    if(map[j]==EMPTY) return -1;
    if(map[j]==k)
    {
      map[j]=DELETED;
      mapv[j]=DELETED;
    }
  }
  return -2;
}

int main()
{
  init();
  insertMap(42,40);
  insertMap(69,420);
  printf("%d\n",findMap(69));
  return 0;
}
