#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sLinkedList.h"

bool insertFront(NodePtr* list, int item){
    NodePtr temp = malloc(sizeof(NodeType));
    
    if (temp!=NULL){
        temp->data = item;
        temp->next = *list;
        *list = temp;
        return true;
    }
    return false;
}

bool insertRear(NodePtr* list, int item){
    NodePtr temp = malloc(sizeof(NodeType));
    
    if (temp!=NULL){
        temp->data = item;
        temp->next = NULL;
        NodePtr *trav = list;
        for (;*trav!=NULL;trav=&(*trav)->next){}
        *trav = temp;
        return true;
    }
    return false;
}

bool insertAt(NodePtr* list, int item, int index){
    NodePtr temp = malloc(sizeof(NodeType));

    if (temp!=NULL){
        temp->data = item;
        
        NodePtr *trav = list;
        for (int i=0;i<index && *trav!=NULL;trav=&(*trav)->next, ++i){}
        temp->next = *trav;
        *trav=temp;
        
        return true;
    }
    return false;
}

bool deleteFront(NodePtr* list){
    if (*list != NULL){
        NodePtr temp = *list;
        *list = temp->next;
        free(temp);
        return true;
    }
    return false;
}

bool deleteRear(NodePtr* list){
    if (*list != NULL){
        NodePtr *trav = list;
        for (;(*trav)->next!=NULL;trav=&(*trav)->next){}
        NodePtr temp = *trav;
        *trav = NULL;
        
        free(temp);
        return true;
    }
    return false;
}

bool deleteAt(NodePtr* list, int index){
    if (*list != NULL){
        NodePtr *trav = list;
        for (int i=0;i<index && *trav!=NULL;trav=&(*trav)->next, ++i){}
        NodePtr temp = *trav;
        *trav = temp->next;
        free(temp);
        
        return true;
    }
    return false;
}
bool deleteFirstOcc(NodePtr* list, int item){
    if (*list != NULL){
        NodePtr *trav = list;
        int i=0;
        for (;(*trav)->data != item && *trav != NULL;trav=&(*trav)->next, ++i){}
        deleteAt(list, i);
        return true;
    }
    return false;
}
bool deleteAllOcc(NodePtr* list, int item){
    if (*list != NULL){
        NodePtr *trav = list;
        int i=0;
        for (;*trav != NULL;){
            if ((*trav)->data == item){
                NodePtr temp = *trav;
                *trav = temp->next;
                free(temp);
            } else {
                trav=&(*trav)->next;
            }
        }
        return true;
    }
    return false;
}

void displayAll(NodePtr list){
    for (NodePtr trav = list;trav != NULL;trav=trav->next){
        printf("%d\n", trav->data);
    }
}