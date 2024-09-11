#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"

void main(){
    Queue qA = createQueue();
    
    displayQ(qA);
    for (int i=0;i<6;++i){
        enqueue(&qA, i+10);
        displayQ(qA);
    }
    // printf("\n\n");
    // for (int i=0;i<7;++i){
    //     dequeue(&qA);
    //     displayQ(qA);
    // }
    
    printf("\n\n");
    Queue even = getEven(&qA);
    displayQ(qA);
    displayQ(even);
    
}