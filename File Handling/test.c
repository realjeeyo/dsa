#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main(){
    Person list [5];

    list[0] = newPerson("Choi", 12);
    list[1] = newPerson("Delgado", 20);
    list[2] = newPerson("Saballa", 21);
    list[3] = newPerson("Codilla", 20);
    list[4] = newPerson("Maratas", 20);

    for (int i=0;i<5;++i){
        displayPerson(list[i]);
    }

    return 0;
}