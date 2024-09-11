#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "static.h"

bool insertFront(List* list, int val){
    if (list->count < MAX){
        for (int i=list->count;i>0;--i){
            list->items[i]=list->items[i-1];
        }
        list->items[0]=val;
        ++list->count;
        return true;
    }
    return false;
}

bool insertRear(List* list, int val){
    if (list->count < MAX){
        list->items[list->count++]=val;
        return true;
    }
    return false;
}

bool insertInto(List* list, int val, int index){
    if (list->count < MAX){
        int i;
        for (i=list->count;i>index;--i){
            list->items[i]=list->items[i-1];
        }
        list->items[index]=val;
        ++list->count;
        return true;
    }
    return false;
}

bool deleteFront(List* list){
    if (list->count > 0){
        for (int i=0;i<list->count;++i){
            list->items[i]=list->items[i+1];
        }
        --list->count;
        return true;
    }
    return false;
}

bool deleteRear(List* list){
    if (list->count > 0){
        --list->count;
        return true;
    }
    return false;
}

bool deleteAt(List* list, int index){
    if (list->count>0){
        for (int i=index;i<list->count;++i){
            list->items[i]=list->items[i+1];
        }
        --list->count;
        return true;
    }
    return false;
}

bool deleteFirstOcc(List* list, int val){
    if (list->count>0){
        for (int i=0;i<list->count;++i){
            if (list->items[i] == val){
                deleteAt(list, i);
                return true;
            }
        }
    }
    return false;
}

bool deleteAllOcc(List* list, int val){
    if (list->count>0){
        for (int i=0;i<list->count;++i){
            if (list->items[i] == val){
                deleteAt(list, i);
                --i;
            }
        }
        return true;
    }
    return false;
}

void displayAll(List list){
    printf("Displaying ALL Values:\n");
    for (int i=0;i<list.count;++i){
        printf("%d\n", list.items[i]);
    }
}