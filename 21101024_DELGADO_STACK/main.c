#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "MyStack.h"
#include "MyHeader.h"

int main() {
    // Stack stackA;
    
    // initStack(&stackA);
    
    // visualize(stackA);
    // push(&stackA, 10);
    // visualize(stackA);
    // push(&stackA, 5);
    // visualize(stackA);
    // push(&stackA, 2);
    // visualize(stackA);
    // push(&stackA, 12);
    // visualize(stackA);
    // push(&stackA, 88);
    // visualize(stackA);
    // push(&stackA, 69);
    // visualize(stackA);
    
    // int x=5;
    // printf("Does %d exist? %d.\n", x, isFound(stackA, x));
    
    // Stack evenStack = removeEven(&stackA);
    // visualize(stackA);
    // visualize(evenStack);
    
    // Empty the stack.
    // makeNull(&evenStack);
    // visualize(evenStack);
    
    Stack stackA;
    initStack(&stackA);
    Student stud = {1, {"Jio", "Luzano", "Delgado"}, "BSIT", 2};
    Student stud2 = {2, {"Dusky", "Samson", "Saballa"}, "BSIT", 2};
    push(&stackA, stud);
    push(&stackA, stud2);
    
    visualize(stackA);
    
    int count=0;
    Name *names = getStudentInProgram(stackA, "BSIT", &count);
    for (int i=0;i<count;++i){
        printf("%s, %s %s\n", names[i].lname, names[i].fname, names[i].mname);
    }
    return 0;
}