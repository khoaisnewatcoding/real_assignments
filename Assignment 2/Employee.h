#ifndef employee
#define employee

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
1. Struct Definition:
a. Define a ‘Employee’ structure that includes the following fields:
i. Employee ID (integer)
ii. Name (string)
iii. Gender (string)
iv. Ethnicity (string)
v. Salary (float) 
*/

//COMPANY = AMAZON


#define MAX_NAME 100

//this struct holds the employee values
struct Employee {
    int id //employee id
    char name[MAX_NAME]; //employee name
    char gender[5]; //employee gender
    char ethnicity[20]; //employee ethnicity
    float salary; //employee salary
};

//this struct holds the average company values
struct AverageValues{
    char group[20]; //an array with a combination of the employee gender and ethnicity seperated by a comma
    int numEmps;
    float totalGroupSalary;
    float averageSalary;
};


// Make functions prototype here

void inputEmployeeData(Employee* employee); // Khoa is going to work on this

float calculateAverageSalary(Employee* employee[], int numEmployees, AverageValues* values, int *numGroups ); //emir

void compareAndFilterEmployeesByGender( Employee* employee[], int numEmployees,int *genderFilter, int *numFilteredEmployees); //Faiz


#endif