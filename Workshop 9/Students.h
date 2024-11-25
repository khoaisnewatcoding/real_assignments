#ifndef STUDENTS_H
#define STUDENTS_H

// I wanna have a database for students' grade

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRADES 4

struct Student{
    int id; //Student ID
    float grades[MAX_GRADES]; // An array for student's grade
    int grade_count;
};

// Function declaration


// calculate the average in grades
float calculateAverage(struct Student* students);

//  Outputting
void printStudentInfo(struct Student* students);

// parsing
int parseStudentRecord(char* line, struct Student* students);

#endif