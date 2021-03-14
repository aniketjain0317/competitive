#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct node {
    int element;
    struct node* next;
};

struct Queue {
    struct node* head;
    struct node* tail;
    int count;
};

extern struct Queue* newQ();
extern bool isEmpty(struct Queue* q);
extern struct Queue* delQ(struct Queue* q);
extern struct node* front(struct Queue* q);
extern struct Queue* addQ(struct Queue* q, int e);
extern int lengthQ(struct Queue* q);