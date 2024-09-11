#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MySet.h"
#define MAX 100

Set createSet(){
    Set newSet;
    newSet.count = 0;
    for (int i=0;i<MAX;++i){
        newSet.elems[i]=false;
    }
    return newSet;
}

bool addElement(Set *s, int item){
    if (item<MAX && item >=0){
        s->elems[item]=true;
        ++s->count;
        return true;
    }
    return false;
}

bool removeElement(Set *s, int item){
    if (item>=0 && item<MAX && (s->elems[item])){
        s->elems[item] = false;
        return true;
    }
    return false;
}

void displaySet(Set s){
    int count=0;
    printf("\n{");
    for (int i=0;i<MAX;++i){
        if (s.elems[i]){
            printf("%d", i);
            if (count<s.count-1){
                printf(", ");
                count++;
            }
        }
    }
    printf("}\n");
}

Set unionSet(Set a, Set b){
    Set newSet = createSet();
    
    for (int i=0;i<MAX;++i){
        if (a.elems[i] || b.elems[i]){
            addElement(&newSet, i);
        }
    }
    
    return newSet;
}

Set intersectionSet(Set a, Set b){
    Set newSet = createSet();
    
    for (int i=0;i<MAX;++i){
        if (a.elems[i] && b.elems[i]){
            addElement(&newSet, i);
        }
    }
    
    return newSet;
}


Set differenceSet(Set a, Set b){
    Set newSet = createSet();
    
    for (int i=0;i<MAX;++i){
        if (a.elems[i] == true && b.elems[i] == false){
            addElement(&newSet, i);
        }
    }
    
    return newSet;
}

Set symmetricDifferenceSet(Set a, Set b){
    Set newSet = createSet();
    
    for (int i=0;i<MAX;++i){
        if (a.elems[i] != b.elems[i]){
            addElement(&newSet, i);
        }
    }
    
    return newSet;
}

int cardinality(Set s){
    return s.count;
}

bool isElement(Set s, int item){
    return s.elems[item];
}