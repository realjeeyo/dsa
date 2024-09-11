#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdbool.h>
#include "MyHeader.h"
#define MAX 5

typedef struct{
    Student elems[MAX];
    int count;
} Stack;

void initStack(Stack *s);
Stack createStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
void visualize(Stack s);

bool push(Stack *s, Student stud);
bool pop(Stack *s);
Student peek(Stack s);

bool isFound(Stack s, String lname);
Name* getStudentInProgram(Stack s, String program, int *count);
void makeNull(Stack *s);

#endif