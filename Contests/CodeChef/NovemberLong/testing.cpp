#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
typedef struct
{
    int num;
} array;
void sum_of_rows(array *, int, int); // DO NOT MODIFY
int sum(array *, int, int);  // DO NOT MODIFY

int main(int argc, char *argv[])
{
    array *ptr, *start;
    int r, c, i, j, count = 0;
// obtain the values of r and c here...
        char* p;
        r = strtol(argv[1],&p,10);
        printf("%d",r);
}
