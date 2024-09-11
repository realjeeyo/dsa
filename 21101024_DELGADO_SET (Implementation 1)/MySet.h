#ifndef MYSET_H
#define MYSET_H

#include <stdbool.h>
#define MAX 100

typedef struct {
    bool elems[MAX];
    int count;
} Set; // Array (Implementation 2)

Set createSet();
bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);

Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDifferenceSet(Set a, Set b);
int cardinality(Set s);
bool isElement(Set s, int item);

#endif