#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 8

typedef struct {
    char fname[30];
    char lname[30];
} Name;

typedef struct {
    Name elems[MAX];
    int front;
    int rear;
} NQueue;

void initNQueue(NQueue *nq); // DONE
bool isEmpty(NQueue nq); // DONE
bool isFull(NQueue nq); // DONE
void displayQueue(NQueue nq); // DONE

void displayNames(Name *n); // DONE -- helper function

bool enqueue(NQueue *nq, Name n); // DONE
bool dequeue(NQueue *nq); // DONE
Name front(NQueue nq); // DONE

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString); // DONE

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n); // 

void main(){
    NQueue nq;
    initNQueue(&nq);
    
    Name a = {"Jio", "Delgado"};
    Name b = {"Dusky", "Saballa"};
    Name c = {"JL", "Codilla"};
    insertSorted(&nq, c);
    insertSorted(&nq, b);
    insertSorted(&nq, a);
    
    printf("\n\n1: ");
    displayQueue(nq);
}

void initNQueue(NQueue *nq){
    nq->front = 1;
    nq->rear = 0;
}

bool isEmpty(NQueue nq){
    return nq.front == (nq.rear + 1) % MAX;
}

bool isFull(NQueue nq){
    return nq.front == (nq.rear + 2) % MAX;
}

void displayQueue(NQueue nq){
    while (!isEmpty(nq)){
        printf("\n\nFirst Name: %s", front(nq).fname);
        printf("\nLast Name: %s", front(nq).lname);
        dequeue(&nq);
    }
}

void displayNames(Name *n){
    for (int i=0;strcmp(n[i].lname, "") != 0;++i){
        printf("\n\nFirst Name: %s", n[i].fname);
        printf("\nLast Name: %s", n[i].lname);
    }
}

bool enqueue(NQueue *nq, Name n){
    if(!isFull(*nq)){
        nq->rear = (nq->rear + 1) % MAX;
        nq->elems[nq->rear] = n;
        return true;
    }
    return false;
}

bool dequeue(NQueue *nq){
    if(!isEmpty(*nq)){
        nq->front = (nq->front + 1) % MAX;
        return true;
    }
    return false;
}

Name front(NQueue nq){
    return nq.elems[nq.front];
}

Name *filterNames(NQueue *nq, char *filterString){
    Name *newNames = malloc(sizeof(Name)* MAX);
    int ctr=0;
    NQueue tempQueue;
    initNQueue(&tempQueue);
    
    while(!isEmpty(*nq)){
        if(!strcmp(front(*nq).lname, filterString)){
            newNames[ctr++] = front(*nq);
        } else {
            enqueue(&tempQueue, front(*nq));
        }
        dequeue(nq);
    }
    
    while(!isEmpty(tempQueue)){
        enqueue(nq, front(tempQueue));
        dequeue(&tempQueue);
    }
    
    strcpy(newNames[ctr].fname, "");
    strcpy(newNames[ctr++].lname, "");
    newNames = realloc(newNames, sizeof(Name)*ctr);
    return newNames;
}

bool insertSorted(NQueue *nq, Name n){
    if(!isFull(*nq)){
        int i = nq->rear;
        int pos;
        
        if (isEmpty(*nq)){
            nq->rear = (nq->rear + 1) % MAX;
            nq->elems[nq->rear] = n;
            return true;
        }
        
        for (pos = nq->rear; pos != (nq->front - 1 + MAX) % MAX; pos = (pos - 1 + MAX) % MAX){
            if (strcmp(nq->elems[pos].lname, n.lname) <= 0){
                break;
            }
            nq->elems[(pos + 1) % MAX] = nq->elems[pos];
        }
        
        nq->elems[(pos + 1 ) % MAX] = n;
        nq->rear = (nq->rear + 1) % MAX;
        return true;
    }
    return false;
}