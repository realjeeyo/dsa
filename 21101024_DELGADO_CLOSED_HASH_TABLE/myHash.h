#ifndef MYHASH_H
#define MYHASH_H

#include <stdbool.h>

typedef struct{
    int studID;
    char studName[16];
    char program[8];
    bool sex; // True - Male; False - Female
    int level;
} Student;

typedef struct{
    Student *data;
    int count;
    int max;
} StudDictionary;

int getHash(Student s);
void initDictionary(StudDictionary *d);
bool insertStud(StudDictionary *d, Student s);
bool removeStud(StudDictionary *d, Student s);
Student getStud(StudDictionary d, Student s);
void visualize(StudDictionary d);

#endif