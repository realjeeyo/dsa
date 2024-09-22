#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdbool.h>
#include "myData.h"

typedef struct node{
    Student data;
    struct node *link;
} NodeType, *NodePtr;

typedef struct{
    NodePtr head, tail;
} Queue;

void initQueue(Queue *q); // Done
Queue createQueue(); // Done

Queue copyQueue(Queue q); // Done

bool isEmpty(Queue q); // Done
void displayQ(Queue q); // Done

void makeNull(Queue *q); // Done
bool enqueue(Queue *q, Student stud); // Done
bool dequeue(Queue *q); // Done
Student front(Queue q); // Done
Student back(Queue q); // Done

int countElem(Queue q); 
Name *getStudent(Queue q, char *program, char sex); 
bool insertSorted(Queue *q, Student stud); 

#endif