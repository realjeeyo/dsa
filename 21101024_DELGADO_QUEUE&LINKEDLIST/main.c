#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "MyData.h"
#include "Queue.h"

void main(){
    Queue q = createQueue();
    Data stud1 = {1, {"Jio", "Delgado"}, "BSIT", 'M'};
    Data stud2 = {2, {"Dusky", "Saballa"}, "BSCS", 'M'};
    Data stud3 = {3, {"Jessica", "Codilla"}, "BSIT", 'F'};
    enqueue(&q,stud1);
    enqueue(&q,stud2);
    enqueue(&q,stud3);
    visualize(q);
    
    Name *newList = getStudent(q, "BSCS", ' ');
    for (int i=0;strcmp(newList[i].fname, "") != 0 && strcmp(newList[i].lname, "") != 0;++i){
        printf("%s, %s\n", newList[i].lname, newList[i].fname);
    }
}