#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyQueue.h"

void initQueue(Queue *q){
    q->front = 1;
    q->rear = 0;
}

Queue createQueue(){
    Queue newQ;
    newQ.front = 1;
    newQ.rear = 0;
    return newQ;
}

bool isEmpty(Queue q){
    return q.front == (q.rear + 1) % MAX;
}

bool isFull(Queue q){
    return q.front == (q.rear + 2) % MAX;
}

void displayQ(Queue q){
    printf("{");
    while(!isEmpty(q)){
        printf("%d ", front(q));
        dequeue(&q);
    }
    printf("}\n");
}

bool enqueue(Queue *q, int item){
    if (!isFull(*q)){
        q->rear = (q->rear + 1) % MAX;
        q->elems[q->rear]=item;
        return true;
    }
    return false;
}

bool dequeue(Queue *q){
    if (!isEmpty(*q)){
        q->front = (q->front + 1) % MAX;
        return true;
    }
    return false;
    
}

int front(Queue q){
    return q.elems[q.front];
}


// Queue getEven(Queue *q){ // Using 3 queues
//     Queue tempQ = createQueue();
//     Queue evenQ = createQueue();
    
//     while (!isEmpty(*q)){
//         if (front(*q) % 2 == 0){
//             enqueue(&evenQ, front(*q));
//         } else {
//             enqueue(&tempQ, front(*q));
//         }
//         dequeue(q);
//     }
    
//     for(;!isFull(*q) && !isEmpty(tempQ); enqueue(q, front(tempQ)), dequeue(&tempQ)){}
    
//     return evenQ;
// }

int countElem(Queue q){
    int i=0;
    for (;!isEmpty(q);++i, dequeue(&q)){}
    return i;
}

Queue getEven(Queue *q){ // Using 2 queues
    Queue evenQ = createQueue();
    int count = countElem(*q);
    
    for (int i=0;i<count;++i){
        if (front(*q) % 2 == 0){
            enqueue(&evenQ, front(*q));
        } else {
            enqueue(q, front(*q));
        }
        dequeue(q);
    }
    
    return evenQ;
}