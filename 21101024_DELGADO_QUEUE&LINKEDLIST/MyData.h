#ifndef MYDATA_H
#define MYDATA_H

typedef struct{
    char fname[20];
    char lname[20];
} Name;

typedef struct{
    int studID;
    Name studName;
    char program[8];
    char sex; // F - female, M - male;
} Student;

#endif