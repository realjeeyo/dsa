#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MySet.h"

void main(){
    Set a = createSet();
    Set b = createSet();
    
    addElement(&a, 1);
    addElement(&a, 2);
    addElement(&a, 6);
    addElement(&a, 7);
    addElement(&a, 9);
    
    addElement(&b, 2);
    addElement(&b, 3);
    addElement(&b, 4);
    addElement(&b, 5);
    addElement(&b, 6);
    displaySet(a);
    displaySet(b);
    
    displaySet(differenceSet(a,b));
    displaySet(differenceSet(b,a));
    displaySet(symmetricDifferenceSet(a,b));
    
    // displaySet(unionSet(a,b));
    // displaySet(intersectionSet(a,b));
    
    
}