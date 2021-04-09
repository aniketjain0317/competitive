#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int booksize=0;


typedef struct record
{
 int index;
 int count;
 struct record *next;
} record;

typedef struct
{
 record **table;
 int elementcount;
 int insertioncost;
 int querycost;
} Hashtable;

int hashfunc(char a[],int baseNo,int tablesize)
{
    int sum=0;
    for(int i=0;i<strlen(a);i++)
        sum+=(int)a[i];
    sum=(sum%baseNo)%tablesize;
    return sum;
}

int hardHashFunc(char a[])
{
    int sum=0;
    for(int i=0;i<strlen(a);i++)
        sum+=(int)a[i];
    sum=(sum%5003)%5000;
    return sum;
}

int collisionCnt(char *a[],int baseNo,int tablesize)
{
    int arr[tablesize];
    for(int i=0;i<tablesize;i++)
        arr[i]=0;
    for(int i=0;i<booksize;i++)
        arr[hashfunc(a[i],baseNo,tablesize)]++;
    int collision=0;
    for(int i=0;i<tablesize;i++)
        if(arr[i]>1)
            collision+=arr[i]-1;
    return collision;
}

char ** parser(char filename[])
{
    FILE * fptr = fopen(filename,"r");
    char** book;
    int s = 1000, i = 0;
    book = (char**)malloc(sizeof(char*)*s);
    char c[10000];
    while(fscanf(fptr, "%s", c)!=EOF){
        book[i] = (char*)malloc(sizeof(char)*(strlen(c)+1));
        strcpy(book[i++],c);
        if(i>= s)
        {
            s+=10000;
            book = (char**)realloc(book,sizeof(char*)*s);
        }
    }
    booksize = i;
    return book;
}

void profiling(int baseNo[],int tablesize[],char *a[])
{
    int mincollision=collisionCnt(a,baseNo[0],tablesize[0]);
    int mintableindex=0;
    int minbaseindex=0;
    int k=0;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<6;j++)
        {
            printf("collisionCnt:%d\n",collisionCnt(a,baseNo[(6*i+j)],tablesize[i]));
            if(mincollision>collisionCnt(a,baseNo[(6*i+j)],tablesize[i]))
            {
                mincollision=collisionCnt(a,baseNo[(6*i+j)],tablesize[i]);
                mintableindex=i;
                minbaseindex=(6*i+j);
            }
        }
    }
}

Hashtable createHashTable(int tablesize)
{
    Hashtable ht;
    record *entries[tablesize];
    for (int i = 0; i < tablesize; i++)
        entries[i]=NULL;
    ht.table=entries;
    ht.elementcount=0;
    ht.insertioncost=0;
    ht.querycost=0;
    return ht;
}

void recordInsert(Hashtable *ht, char **a, int j){
    int hash = hardHashFunc(a[j]);
    int insCost = 0;
    int newelem = 0;
    record *node = ht->table[hash];
    while(node!= NULL){
        if(strcmp(a[node->index], a[j])==0){
            node->count++;
            newelem =1;
            break;
        }
        else
        {
            insCost++;
            node = node->next;
        }
    }
    if(newelem == 0)
    {
        ht->table[hash] = malloc(sizeof(record));
        ht->table[hash]->index = j;
        ht->table[hash]->count = 1;
        ht->table[hash]->next = NULL;
        ht->elementcount++;
    }
    ht->insertioncost += insCost;
}

int insertAll(Hashtable *ht, char **a)
{
    for(int i=0; i < booksize; i++)
        recordInsert(ht, a, i);
    return ht->insertioncost;
}

record* recordLookup(Hashtable *ht, char *a,char **book)
{
    int hash = hardHashFunc(a);
    record *temp = NULL;
    temp = ht->table[hash];
    if(temp==NULL)
        return NULL;
    else
    {
        while (temp!=NULL)
        {
            if(strcmp(book[temp->index],a)==0)
            {
                ht->querycost++;
                return temp;
            }
            else
            {
                ht->querycost++;
                temp=temp->next;
            }
        }
        return NULL;
    }
}

int lookupAll(Hashtable *ht, char **a,char **book,float m)
{

    ht->querycost = 0;
    int k=(int)(booksize*m);
    while(k>0)
    {
      record *temp=recordLookup(ht,a[--k],book);
    }
    return ht->querycost;
}

int main()
{
    int baseNo[]={5003, 5009, 5011, 5000011, 5000077, 5000081, 50021, 50023, 50033, 50000017, 50000021, 50000047, 500009, 500029, 500041, 500000003, 500000009, 500000041};
    int tablesize[]={5000,50000,500000};
    char **book = parser("aliceinwonderland.txt");
    profiling(baseNo,tablesize,book);
    Hashtable ht = createHashTable(5000);
    printf("Insertion cost: %d\n", insertAll(&ht,book));
    printf("Lookup cost: %d\n", lookupAll(&ht, book, book,1));
}
