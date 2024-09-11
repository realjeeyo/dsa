#ifndef DYNAMIC_H
#define DYNAMIC_H
#include <stdbool.h>

typedef struct{
    int *items;
    int count;
    int max;
} List;

List initArray(int max);

bool insertFront(List* list, int val);
bool insertRear(List* list, int val);
bool insertInto(List* list, int val, int index);

bool deleteFront(List* list);
bool deleteRear(List* list);
bool deleteAt(List* list, int index);
bool deleteFirstOcc(List* list, int val);
bool deleteAllOcc(List* list, int val);

bool displayAll(List list);

#endif