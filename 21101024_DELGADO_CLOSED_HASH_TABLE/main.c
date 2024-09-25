#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "myHash.h"

void main(){
    StudDictionary d;
    initDictionary(&d); // Initial MAX is 10
    
    Student a = {1, "Jio", "BSIT", 1, 2};
    Student b = {2, "Dusky", "BSIT", 1, 2};
    Student c = {3, "Summi", "BSIT", 0, 2};
    Student e = {4, "JL", "BSIT", 1, 2};
    Student f = {5, "Josh", "BSIT", 1, 2};
    Student g = {6, "Jansen", "BSIT", 1, 2};
    Student h = {7, "Kentward", "BSIT", 1, 2};
    Student i = {8, "Rameses", "BSCS", 1, 2};
    Student j = {9, "Myles", "BSCS", 1, 2};
    
    insertStud(&d, a);
    insertStud(&d, b);
    insertStud(&d, c);
    insertStud(&d, e);
    insertStud(&d, f);
    insertStud(&d, g);
    insertStud(&d, h);
    insertStud(&d, i);
    visualize(d);
    insertStud(&d, j);
    visualize(d);
}