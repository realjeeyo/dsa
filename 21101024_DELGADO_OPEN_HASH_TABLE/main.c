#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "myHash.h"

void main(){
    Dictionary d;
    initDictionary(&d);
    
    Student a = {21101024, "Jio", 1, "BSIT", 2};
    Student b = {20000001, "Josh", 1, "BSIT", 2};
    Student c = {20000011, "Jansen", 1, "BSIT", 2};
    Student f = {20101000, "Jose", 1, "BSIT", 2};
    Student g = {20101010, "Dusky", 1, "BSIT", 2};
    
    addStudent(&d, a);
    addStudent(&d, b);
    addStudent(&d, c);
    addStudent(&d, f);
    
    removeStudent(&d, b);
    addStudent(&d, g);
    visualize(d);
}