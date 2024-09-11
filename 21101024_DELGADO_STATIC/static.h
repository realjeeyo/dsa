#ifndef STATIC_H
#define STATIC_H
#define MAX 10
#include <stdbool.h>

typedef struct{
    int items[MAX];
    int count;
} List;

bool insertFront(List* list, int val);
bool insertRear(List* list, int val);
bool insertInto(List* list, int val, int index);

bool deleteFront(List* list);
bool deleteRear(List* list);
bool deleteAt(List* list, int index);
bool deleteFirstOcc(List* list, int val);
bool deleteAllOcc(List* list, int val);

void displayAll(List list);

#endif