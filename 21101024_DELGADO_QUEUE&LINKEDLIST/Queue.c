#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Queue.h"
#include "MyData.h"

void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
} // Done

Queue createQueue(){
    Queue newQ;
    newQ.head = NULL;
    newQ.tail = NULL;
    
    return newQ;
} // Done

bool isEmpty(Queue q){
    return q.head==NULL;
} // Done

void display(Queue q){
    
} // Cannot use traversal nor enqueue or dequeue. INCOMPLETE
void visualize(Queue q){
    NodePtr trav=q.head;
    
    while(trav != NULL){
        printf("Student ID: %d\n", trav->elem.studID);
        printf("Student Name: %s, %s\n", trav->elem.studName.lname, trav->elem.studName.fname);
        printf("Program: %s\n", trav->elem.program);
        printf("Sex: %c\n\n", trav->elem.sex);
        
        trav=trav->link;
    }
} // Can use traversal here

bool enqueue(Queue *q, Data d){
    NodePtr newData = malloc(sizeof(NodeType));
    
    if (newData != NULL){
        newData->elem = d;
        newData->link = NULL;
        
        if (q->tail == NULL){
            q->head = newData;
            q->tail = newData;
        } else {
            q->tail->link = newData;
            q->tail = newData;
        }
        return true;
    }
    return false;
} // Done

bool dequeue(Queue *q){
    if(!isEmpty(*q)){
        NodePtr temp = q->head;
        
        if (q->head->link == NULL){
            q->head = NULL;
            q->tail = NULL;
        } else {
            q->head = temp->link;
        }
        
        free(temp);
        return true;
    }
    return false;
} // Done

Data front(Queue q){
    if (!isEmpty(q)){
        return q.head->elem;
    } else {
        Data emptyData = {0, {"", ""}, "", ' '};
        return emptyData;
    }
} // Done

int countQ(Queue q){
    int i=0;
    Queue newQ = copyQ(q);
    for (;!isEmpty(newQ);++i, dequeue(&newQ)){}
    return i;
} // Done

Queue copyQ(Queue q){
    NodePtr trav = q.head;
    Queue newQ = createQueue();
    while(trav != NULL){
        enqueue(&newQ, trav->elem);
        trav = trav->link;
    }
    
    return newQ;
} // Done

Name *getStudent(Queue q, char *program, char sex){
    int i=0, count = countQ(q);
    Queue newQ = copyQ(q);
    Name *nameList = malloc(sizeof(Name)*count);
    
    while (!isEmpty(newQ)){
        if (!strcmp(program, "") && sex == ' '){
            nameList[i++]=newQ.head->elem.studName;
        } else if (!strcmp(program, "")){
            if (newQ.head->elem.sex == sex){
                nameList[i++]=newQ.head->elem.studName;
            }
        } else if (sex == ' '){
            if (!strcmp(newQ.head->elem.program, program)){
                nameList[i++]=newQ.head->elem.studName;
            }
        } else {
            if (!strcmp(newQ.head->elem.program, program) && newQ.head->elem.sex == sex){
                nameList[i++]=newQ.head->elem.studName;
            }
        }
        
        dequeue(&newQ);
    }
    
    Name emptyName = {"", ""};
    nameList[i]=emptyName;
    return nameList;
} // Gets the name of the student that matches with the program and sex. If program is an empty string then use all programs.
//  If sex is an empty character then get both sex, use the concept of adding an empty string values for the name to use as a terminator
// For the name array.


bool insertSorted(Queue q, Data d); // Insert the Data d based on lastname only. INCOMPLETE