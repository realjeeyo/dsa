#ifndef MYHASH_H
#define MYHASH_H

#define MAX 10
#include <stdbool.h>

typedef struct{
  int studID;
  char studName[20];
  bool sex; //true - male, false - female
  char program[8];
  int level;
} Student;

typedef struct node{
    Student stud;
    struct node *link;
} NodeType, *NodePtr;

typedef struct {
    NodePtr elems[MAX];
    int count;
} Dictionary;

int getHash(Student s); // number of 1s in studId + 1st 3 letters of studName + program (RETURN VALUE SHOULD BE FROM 0-9)
void initDictionary(Dictionary *d);
bool addStudent(Dictionary *d, Student s);
bool removeStudent(Dictionary *d, Student s);
Student getStudent(Dictionary d, Student s);
void visualize(Dictionary d);

#endif