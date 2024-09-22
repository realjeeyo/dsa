#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "myData.h"
#include "myQueue.h"

void main(){
    Queue q = createQueue();
    
    Student a = {1, {"Jio", "Delgado"}, "BSIT", 'M'};
    Student b = {2, {"Josh", "Lui"}, "BSIT", 'M'};
    Student c = {3, {"Jansen", "Choi"}, "BSIT", 'M'};
    Student d = {4, {"Rameses", "Barria"}, "BSCS", 'M'};
    Student e = {5, {"Samantha", "Antiporta"}, "BSCS", 'F'};
    Student f = {6, {"A", "A"}, "BSCS", 'F'};
    
    // displayQ(q);
    insertSorted(&q, a);
    insertSorted(&q, b);
    insertSorted(&q, c);
    insertSorted(&q, d);
    // insertSorted(&q, e);
    displayQ(q);

    // insertSorted(&q, f);
    // displayQ(q);
}