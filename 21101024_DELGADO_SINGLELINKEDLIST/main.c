#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sLinkedList.h"

void main(){
    NodePtr head = NULL;
    
    insertRear(&head, 1);
    insertRear(&head, 2);
    insertRear(&head, 3);
    insertFront(&head, 1);
    insertFront(&head, 2);
    insertFront(&head, 3);
    insertAt(&head, 5, 3);
    deleteAt(&head, 3);
    
    deleteFirstOcc(&head, 2);
    deleteAllOcc(&head, 3);
    displayAll(head);
}