#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "myData.h"
#include "myQueue.h"

void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

Queue createQueue(){
    Queue newQ;
    newQ.head = NULL;
    newQ.tail = NULL;
    return newQ;
}

Queue copyQueue(Queue q){
    Queue newQueue = createQueue();
    for (NodePtr trav = q.head; trav != NULL; trav=trav->link){
        enqueue(&newQueue, trav->data);
    }
    return newQueue;
}

bool isEmpty(Queue q){
    return q.head == NULL && q.tail == NULL;
}

void displayQ(Queue q){
    Queue tempQ = copyQueue(q);
    
    printf("\nPrinting Queue: \n");
    while (!isEmpty(tempQ)){
        printf("\nStudent ID: %d\n", front(tempQ).studID);
        printf("Student Name: %s, %s\n", front(tempQ).studName.lName, front(tempQ).studName.fName);
        printf("Program: %s\n", front(tempQ).program);
        printf("Sex: %c\n", front(tempQ).sex);
        dequeue(&tempQ);
    }
}

void makeNull(Queue *q){
    while(!isEmpty(*q)){
        dequeue(q);
    }
}

bool enqueue(Queue *q, Student stud){
    NodePtr newStud = malloc(sizeof(NodeType));
    
    if (newStud != NULL){
        newStud->data = stud;
        newStud->link = NULL;
        
        if(isEmpty(*q)){
            q->head = newStud;
            q->tail = newStud;
        } else {
            q->tail->link = newStud;
            q->tail = newStud;
        }
        
        return true;
    }
    return false;
}

bool dequeue(Queue *q){
    if(!isEmpty(*q)){
        NodePtr temp = q->head;
        q->head = temp->link;
        
        if(q->head == NULL){
            q->tail = NULL;
        }
        
        free(temp);
        return true;
    }
    return false;
}

Student front(Queue q){
    return q.head->data;
}

Student back(Queue q){
    return q.tail->data;
}

int countElem(Queue q){
    int ctr=0;
    Queue tempQueue = copyQueue(q);
    while(!isEmpty(tempQueue)){
        ++ctr;
        dequeue(&tempQueue);
    }
    return ctr;
}

Name *getStudent(Queue q, char *program, char sex){
    Name *nameList = malloc(sizeof(Name) * countElem(q));
    Queue newQ = copyQueue(q);
    int ctr=0;
    
    while(!isEmpty(newQ)){
        Student temp = front(newQ);
        if(!strcmp(program, "") && sex == ' '){
            nameList[ctr++] = temp.studName;
        } else if (!strcmp(program, "")){
            if (front(newQ).sex == sex){
                nameList[ctr++] = temp.studName;
            }
        } else if (sex == ' '){
            if (!strcmp(temp.program, program)){
                nameList[ctr++] = temp.studName;
            }
        } else if (!strcmp(temp.program, program) && temp.sex == sex){
            nameList[ctr++] = temp.studName;
        }
        dequeue(&newQ);
    }
    
    Name emptyName = {"", ' '};
    nameList[ctr] = emptyName;
    nameList = realloc(nameList, sizeof(Name) * ctr);
    return nameList;
}

bool insertSorted(Queue *q, Student stud){
    Queue tempQ = createQueue();
    NodePtr newStud = malloc(sizeof(NodeType));
    
    if (newStud!=NULL){
        newStud->data = stud;
        newStud->link = NULL;
        
        if(isEmpty(*q)){
            q->head = newStud;
            q->tail = newStud;
            return true;
        } else {
            while(q->head != NULL && strcmp(q->head->data.studName.lName, stud.studName.lName) >= 0){
                NodePtr temp = q->head;
                q->head = temp->link;
                if(tempQ.head == NULL){
                    tempQ.head = temp;
                } else {
                    tempQ.tail->link = temp;
                }
                tempQ.tail = temp;
            }
            if(tempQ.head == NULL){
                tempQ.head = newStud;
            } else {
                tempQ.tail->link = newStud;
            }
            
            tempQ.tail = newStud;
            if (q->head != NULL){
                tempQ.tail->link = q->head;
            }
            
            q->head = tempQ.head;
            q->tail = tempQ.tail;
            return true;  
        }
    }
    return false;
}