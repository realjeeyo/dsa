#ifndef MYDATA_H
#define MYDATA_H

typedef struct {
    char fName[20];
    char lName[20];
} Name;

typedef struct {
    int studID;
    Name studName;
    char program[8];
    char sex; 
} Student;

#endif