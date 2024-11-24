#ifndef STUDENTS_H
#define STUDENTS_H

// I wanna have a database for students' grades
// I wanna 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_LINE_LENGTH 100
// #define MAX_GRADES 4

struct Student{
    int id; //Student ID
    float grades[4]; // An array for student's grade
    int grade_count;
};

// Function declaration


// calculate the average in grades
float calculateGPA(struct Student* students);

//  Outputting
void printStudentInfo(struct Student* students);


int parseStudent(char* line, struct Student* students);

#endif