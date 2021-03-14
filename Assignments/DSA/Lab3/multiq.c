#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#include "que.h"
#include "multiq.h"

struct MultiQ* createMQ(int num)
{
    struct MultiQ* mq = (struct MultiQ*) malloc(sizeof(struct MultiQ));

    for(int i = 0; i < num; i++)
    {
        mq->queues[i] = newQ();
    }

    mq->num = num;

    return mq;
}

struct MultiQ* addMQ(struct MultiQ* mq, struct Task* t)
{
    struct Queue* q = mq->queues[t->p];

    addQ(q, t->id);

    return mq;
}

struct Task* nextMQ(struct MultiQ* mq)
{
    int i = 0;
    struct Queue* q;
    for(i = mq->num-1; i >= 0; i--)
    {
        q = mq->queues[i];
        if(!isEmpty(q))
        {
            break;
        }
    }
    

    int id = front(q)->element;

    struct Task* t = (struct Task*) malloc(sizeof(struct Task));
    t->p = i;
    t->id = id;

    return t;
}

struct Task* delNextMQ(struct MultiQ* mq){
    int i = 0;
    struct Queue* q;
    for(int i = mq->num-1; i >= 0; i--){
        q = mq->queues[i];
        if(!isEmpty(q))
            break;
    }

    int id = front(q)->element;

    delQ(q);

    struct Task* t = (struct Task*) malloc(sizeof(struct Task));
    t->p = i;
    t->id = id;

    return t;
}

int sizeMQ(struct MultiQ* mq){
    int sum = 0;

    for(int i = 0; i < mq->num; i++){
        sum = sum + lengthQ(mq->queues[i]);
    }

    return sum;
}

int sizeMQbyPriority(struct MultiQ* mq, int p)
{
    int sum = 0;    
    sum = lengthQ(mq->queues[p]);

    return sum;
}

struct Queue* getQueueFromMQ(struct MultiQ* mq, int p){
    return mq->queues[p];
}