#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>

typedef char String[20];
typedef struct {
    String fname, mname, lname;
} Name;

typedef struct {
    int studID;
    Name studName;
    String program;
    int year;
} Student;

Name createName(String fname, String mname, String lname);
Student createStudent(int studID, Name studName, String program, int year);

#endif