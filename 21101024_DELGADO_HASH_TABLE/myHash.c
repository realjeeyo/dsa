#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "myHash.h"

int getHash(Student s){
    int hash=0;
    
    // Number of 1s in the studID
    for (int i=0;i<31;++i, hash +=(s.studID >> i)&1){}
    
    // First 3 Letters of the studName
    for (int i=0;i<3;++i){
        hash+=s.studName[i];
    }
    
    // The entire program name
    for (int i=0;s.program[i] != '\0';++i){
        hash+=s.program[i];
    }
    
    // For DEBUGGING HASH
    // printf("\n{HASH: %d}\n", hash % MAX);
    
    return hash % MAX;
} // number of 1s in studId + 1st 3 letters of studName + program

void initDictionary(Dictionary *d){
    for (int i=0;i<MAX;++i){
        d->elems[i] = NULL;
    }
    d->count = 0;
}

bool addStudent(Dictionary *d, Student s) {
    NodePtr newStud = malloc(sizeof(NodeType));
    NodePtr trav;
    int key = getHash(s);

    if (newStud != NULL) {
        newStud->stud = s;
        newStud->link = NULL;
        
        if (d->elems[key] == NULL || d->elems[key]->stud.studID > s.studID) {
            newStud->link = d->elems[key];
            d->elems[key] = newStud;
            return true;
        }
        
        for (trav = d->elems[key]; trav->link != NULL; trav = trav->link) {
            if (trav->link->stud.studID == s.studID) {
                printf("Student already exists!");
                return false;
            }
        }
        
        newStud->link = trav->link;
        trav->link = newStud;

        return true;
    }
    return false;
} // Done


bool removeStudent(Dictionary *d, Student s){
    NodePtr trav;
    int key = getHash(s);
    for (trav = d->elems[key];trav!=NULL;trav=trav->link){
        if (trav->stud.studID == s.studID){
            NodePtr temp = trav;
            trav = temp->link;
            free(temp);
            
            if (trav == NULL){
                d->elems[key] = NULL;
            }
            return true;
        }
    }
    return false;
} // Done

Student getStudent(Dictionary d, Student s){
    int key = getHash(s);
    for (NodePtr trav = d.elems[key];trav!=NULL;trav=trav->link){
        if (trav->stud.studID == s.studID){
            return trav->stud;
        }
    }
} // Done

void visualize(Dictionary d){
    int key;
    for (int i=0;i<MAX;++i){
        printf("\n[%d] - ", i);
        if (d.elems[i] != NULL){
            for (NodePtr trav = d.elems[i];trav!=NULL;trav=trav->link){
                printf("{%d, %s}", trav->stud.studID, trav->stud.studName);
                if (trav->link != NULL){
                    printf(" -> ");
                }
            }
        } else {
            printf("Empty");
        }
    }
}