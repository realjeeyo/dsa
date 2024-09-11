#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyStack.h"
#include <string.h>

void initStack(Stack *s){
    s->count = 0;
}

Stack createStack(){
    Stack newStack;
    newStack.count=0;
    
    return newStack;
}

bool isEmpty(Stack s){
    return s.count == 0;
}

bool isFull(Stack s){
    return s.count >= MAX;
}

void visualize(Stack s){
    for (int i=0;i<s.count;++i){
        printf("Student ID: %d\n", s.elems[i].studID);
        printf("Student Full Name: %s, %s %s\n", s.elems[i].studName.lname, s.elems[i].studName.fname, s.elems[i].studName.mname);
        printf("Enrolled Program: %s - %d\n\n", s.elems[i].program, s.elems[i].year);
    }
}

bool push(Stack *s, Student stud){
    if (!isFull(*s)){
        s->elems[(s->count)++] = stud;
        return true;
    }
    return false;
}

bool pop(Stack *s){
    if (!isEmpty(*s)){
        (s->count)--;
        return true;
    }
    return false;
}

//call only if not empty
Student peek(Stack s){
    return s.elems[s.count-1];
}

bool isFound(Stack s, String lname){
    while (!isEmpty(s)){
        Student tempStud = peek(s);
        if(!strcmp(tempStud.studName.lname,lname)){
            return true;
        }
        pop(&s);
    }
    return false;
}

Name* getStudentInProgram(Stack s, String program, int *count){
    // Stack even = createStack();
    // Stack temp = createStack();
    
    // while (!isEmpty(*s)){
    //     (peek(*s) % 2 == 0) ? push(&even, peek(*s)) : push(&temp, peek(*s));
    //     pop(s);
    // }
    
    // while (!isEmpty(temp)){
    //     push(s, peek(temp));
    //     pop(&temp);
    // }
    
    // return even;
    
    Name *nameList = malloc(sizeof(Name)*s.count);
    
    while (!isEmpty(s)){
        Student tempStud = peek(s);
        if(!strcmp(tempStud.program, program)){
            nameList[(*count)++] = tempStud.studName;
        }
        pop(&s);
    }
    
    nameList = realloc(nameList, sizeof(Name)*(*count));
    return nameList;
}

void makeNull(Stack *s){
    while(!isEmpty(*s)){
        pop(s);
    }
}