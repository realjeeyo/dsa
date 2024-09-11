#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdbool.h>
#define MAX 5

typedef struct{
    int elems[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
bool isFull(Queue q);
void displayQ(Queue q);

bool enqueue(Queue *q, int item);
bool dequeue(Queue *q);
int front(Queue q);

int countElem(Queue q);
Queue getEven(Queue *q);

#endif