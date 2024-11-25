#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME 100

//this struct holds the employee datas
struct Employee {
    int id; //employee id
    char name[MAX_NAME]; //employee name
    char gender[20]; //employee gender
    char ethnicity[20]; //employee ethnicity
    int salary; //employee salary
};




// Make functions prototype here

void inputEmployeeData(struct Employee* employee); // Khoa is going to work on this

float calculateAverageSalary(struct Employee* filteredGroup[], int numFilteredEmp); //emir
// khoa and faize work on both functions
void compareEmployeebyGender(struct Employee* employees[], int numEmployees, struct Employee* filteredEmployeesMale[], struct Employee* filteredEmployeesFemale[], struct Employee* filteredEmployeesNonBinary[], int* numFilteredMaleEmployees, int* numFilteredFemaleEmployees, int* numFilteredNonBinaryEmployees); //Faiz and khoa

void compareEmployeebyEthnicity(struct Employee* employees[], int numEmployees, struct Employee* filteredBIPOCemp[], struct Employee* filterednonBIPOCemp[], int* numBIPOCemp, int* nonBIPOCemp); // Faiz and khoa

#endif