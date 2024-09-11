#ifndef QUEUE_H
#define QUEUE_H

#include "MyData.h"
#include <stdbool.h>

typedef Student Data;

typedef struct node{
    Data elem;
    struct node *link;
} NodeType, *NodePtr;

typedef struct{
    NodePtr head, tail;
} Queue;

void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
void display(Queue q); // Cannot use traversal nor enqueue or dequeue
void visualize(Queue q); // Can use traversal here

bool enqueue(Queue *q, Data d);
bool dequeue(Queue *q);
Data front(Queue q);

int countQ(Queue q); // for counting Queue elements
Queue copyQ(Queue q); // copying Queue

Name *getStudent(Queue q, char *program, char sex); // Gets the name of the student that matches with the program and sex. If program is an empty string then use all programs.
                                                    //  If sex is an empty character then get both sex, use the concept of adding an empty string values for the name to use as a terminator
                                                    // For the name array.
bool insertSorted(Queue q, Data d); // Insert the Data d based on lastname only.

#endif