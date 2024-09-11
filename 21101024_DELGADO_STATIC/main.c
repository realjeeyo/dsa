#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "static.h"
// #include "dynamic.h"

void main(){
    
    List mainList;
    mainList.count = 0;
    
    // List mainList = initArray(3); // dynamic.h
    
    insertRear(&mainList, 1);
    insertRear(&mainList, 2);
    insertRear(&mainList, 3);
    insertRear(&mainList, 4);
    insertRear(&mainList, 5);
    
    insertInto(&mainList, 69, 3);
    insertRear(&mainList, 69);
    insertFront(&mainList, 69);
    
    deleteFirstOcc(&mainList, 69);
    
    printf("size of mainList: %d\n\n", mainList.count);
    displayAll(mainList);
    
    deleteAllOcc(&mainList, 69);
    
    printf("size of mainList: %d\n\n", mainList.count);
    displayAll(mainList);
}