#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    char sex;
} Person;

typedef struct node{
    Person data;
    struct node *link;
} NodeType, *NodePtr, *Stack;

Stack copyStack(Stack s); // DONE

void initStack(Stack *s); // DONE
bool isEmpty(Stack s); // DONE
void displayStack(Stack s); // DONE

bool push(Stack *s, Person p); // insertFront - DONE
bool pop(Stack *s); // deleteFront - DONE
Person peek(Stack s); // return s->data - DONE

/*Insert sorted base on lastname. Rember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p); // DONE

/*Insert sorted base on lastname. Rember to use the property 
  of the stack but without using push, pop, and peek functions.*/
bool insertSorted2(Stack *s, Person p); // DONE

/*Sort the values based on name. Use flag for ascending 
  or descending. */
void sortStack(Stack *s, bool flag);

void main(){
    Stack s;
    initStack(&s);
    
    Person a = {"Aaron", 20, 'M'};
    Person b = {"Jericho", 20, 'M'};
    Person c = {"JL", 20, 'M'};
    Person d = {"Dusky", 21, 'M'};
    Person e = {"Josh", 20, 'M'};
    Person f = {"Jansen", 19, 'M'};
    Person g = {"Maya", 20, 'F'};
    Person h = {"Summi", 20, 'F'};
    Person i = {"Jio", 20, 'M'};
    push(&s, a);
    push(&s, b);
    push(&s, c);
    push(&s, d);
    push(&s, e);
    push(&s, f);
    push(&s, g);
    push(&s, h);
    push(&s, i);
    // insertSorted2(&s, a);
    // insertSorted2(&s, b);
    // insertSorted2(&s, c);
    // insertSorted2(&s, d);
    // insertSorted2(&s, e);
    // insertSorted2(&s, f);
    // insertSorted2(&s, g);
    // insertSorted2(&s, h);
    // insertSorted2(&s, i);
    
    sortStack(&s, 1);
    displayStack(s);
}

Stack copyStack(Stack s){
    Stack newStack;
    initStack(&newStack);
    
    while(s != NULL){
        push(&newStack, peek(s));
        s = s->link;
    }
    
    return newStack;
}

void initStack(Stack *s){
    *s = NULL;
}

bool isEmpty(Stack s){
    return s == NULL;
}

void displayStack(Stack s){
    Stack tempStack = copyStack(s);
    
    while (!isEmpty(tempStack)){
        Person p = peek(tempStack);
        printf("Name: %s", p.name);
        printf("\nAge: %d", p.age);
        printf("\nSex: %c\n\n", p.sex);
    
        pop(&tempStack);
    }
}

bool push(Stack *s, Person p){
    Stack newStack = malloc(sizeof(NodeType));
    
    if (newStack != NULL){
        newStack->data = p;
        newStack->link = *s;
        *s = newStack;
        return true;
    }
    return false;
}

bool pop(Stack *s){
    if(*s != NULL){
        Stack temp = *s;
        *s = temp->link;
        free(temp);
        return true;
    }
    return false;
}

Person peek(Stack s){
    return s->data;
}

bool insertSorted1(Stack *s, Person p){
    if(isEmpty(*s)){
        push(s, p);
        return true;
    }
    Stack tempStack;
    initStack(&tempStack);
    while(!isEmpty(*s) && strcmp(peek(*s).name, p.name) <= 0){
        push(&tempStack, peek(*s));
        pop(s);
    }
    push(s, p);
    
    while (!isEmpty(tempStack)){
        push(s, peek(tempStack));
        pop(&tempStack);
    }
        
    return true;
}

bool insertSorted2(Stack *s, Person p){
    Stack newStack = malloc(sizeof(NodeType));
    
    if(newStack != NULL){
        newStack->data = p;
        
        if(isEmpty(*s)){
            newStack->link = *s;
            *s = newStack;
            return true;
        } else {
            Stack prev = *s, trav = (*s)->link;
            for (;trav != NULL && strcmp(trav->data.name, p.name) <= 0;prev = trav, trav = trav->link){}
            newStack->link = trav;
            prev->link = newStack;
            return true;
        }
    }
    return false;
}

void sortStack(Stack *s, bool flag){
    Stack tempStack;
    initStack (&tempStack);
    
    while (!isEmpty(*s)){
        Person tempPerson = peek(*s);
        pop(s);
        
        if (flag){
            while (!isEmpty(tempStack) && strcmp(peek(tempStack).name, tempPerson.name) > 0){
                push(s, peek(tempStack));
                pop(&tempStack);
            } // 1 == ASC
        } else {
            while (!isEmpty(tempStack) && strcmp(peek(tempStack).name, tempPerson.name) < 0){
                push(s, peek(tempStack));
                pop(&tempStack);
            } // 0 == DESC
        }
        
        push(&tempStack, tempPerson);
    }
    
    while (!isEmpty(tempStack)){
        push(s, peek(tempStack));
        pop(&tempStack);
    }
}