#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "myHash.h"

#define MAX 10

int getHash(Student s){
    int hash = 0;
    for (int i=0;i<31;++i){
        if ((s.studID >> i) & 1 == 1){
            hash+=i+1;
        }
    }
    return hash % MAX;
}

void initDictionary(StudDictionary *d){
    d->max = MAX;
    d->data = calloc(d->max, sizeof(Student));
    d->count = 0;
}

void resizeDictionary(StudDictionary *d){
    StudDictionary temp;
    temp.max=d->max*2;
    temp.data = calloc(temp.max, sizeof(Student));
    temp.count = 0;
    
    for (int i=0;i<d->max;){
        if (d->data[i].studID > 0){
            insertStud(&temp, d->data[i]);
        }
        ++i;
    }
    *d = temp;
    free(temp.data);
}

bool insertStud(StudDictionary *d, Student s){
    if (d->count < d->max * 0.8){
        int i=getHash(s);
        if (d->data[i].studID == s.studID){
            printf("\nDuplicate Data: {%d, %s, %s, %d, %d}", d->data[i].studID, d->data[i].studName, d->data[i].program, d->data[i].sex, d->data[i].level);
            // printf("\nStudent Already Exists.");
            return false;
        }
        for(; d->data[i].studID > 0; i = (i+1) % d->max){}
        d->data[i]=s;
        ++(d->count);
        return true;
    } else {
        printf("\n\nList is Full! Resizing, rehashing, and retrying...");
        resizeDictionary(d);
        insertStud(d, s);
        return false;
    }
}

bool removeStud(StudDictionary *d, Student s){
    int i = getHash(s);
    if (d->data[i].studID > 0){
        for (;d->data[i].studID != s.studID; i = (i+1) % d->max){
            if (d->data[i].studID == 0){
                return false;
            }
        }
        d->data[i].studID = -1;
        --(d->count);
        
        return true;
    }
    return false;
}

Student getStud(StudDictionary d, Student s){
    int i = getHash(s);
    for (;d.data[i].studID > 0;i = (i+1) % d.max){
        if (d.data[i].studID == s.studID){
            return d.data[i];
        }
    }
    printf("\nCould not find student.");
}

void visualize(StudDictionary d){
    printf("\n\n========Printing Dictionary========");
    for (int i=0;i<d.max;++i){
        printf("\n[%d] - ",i+1);
        if (d.data[i].studID == 0){
            printf("Empty");
        } else if (d.data[i].studID == -1){
            printf("Deleted");  
        } else {
            printf("{%d, %s, %s, %d, %d}", d.data[i].studID, d.data[i].studName, d.data[i].program, d.data[i].sex, d.data[i].level);
        }
    }
    printf("\n===================================");
    
}