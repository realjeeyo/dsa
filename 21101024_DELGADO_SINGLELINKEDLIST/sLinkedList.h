#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
} NodeType, *NodePtr;

bool insertFront(NodePtr* list, int item);
bool insertRear(NodePtr* list, int item);
bool insertAt(NodePtr* list, int item, int index);

bool deleteFront(NodePtr* list);
bool deleteRear(NodePtr* list);
bool deleteAt(NodePtr* list, int index);
bool deleteFirstOcc(NodePtr* list, int item);
bool deleteAllOcc(NodePtr* list, int item);

void displayAll(NodePtr list);

#endif