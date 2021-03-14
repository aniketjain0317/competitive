#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#include "que.h"

struct Queue* newQ(){
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

bool isEmpty(struct Queue* q){
    if(q->count == 0)
    {
        return true;
    }
    return false;
}

struct Queue* delQ(struct Queue* q){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp = q->head;
    q->head = q->head->next;
    q->count--;

    if(q->head == NULL){
        q->tail = NULL;
    }

    free(temp);

    return q;
}

struct node* front(struct Queue* q)
{
    if(q->head == NULL)
    {
        return NULL;
    }
    return q->head;
}

struct Queue* addQ(struct Queue* q, int e){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->element = e;

    q->count++;

    if(q->head == NULL){
        q->head=q->tail=temp;
        return q;
    }

    q->tail->next = temp;
    q->tail = temp;

    return q;
}

int lengthQ(struct Queue* q){
    return q->count;
}