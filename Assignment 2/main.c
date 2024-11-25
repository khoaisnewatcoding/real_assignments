#include "Employee.h"

#define MAX_EMPLOYEES 100


int main(){
    Employee* employee[MAX_EMPLOYEES]; //assuming the max employee is 100
    int choice;
    int numEmployees = 0;

    Employee* filteredEmployeesMale[MAX_EMPLOYEES];
    Employee* filteredEmployeesFemale[MAX_EMPLOYEES];
    Employee* filteredEmployeesNonBinary[MAX_EMPLOYEES];
    int numFilteredMaleEmployees, numFilteredFemaleEmployees, numFilteredNonBinaryEmployees;

    Employee* filteredBIPOCemp[MAX_EMPLOYEES];
    Employee* filterednonBIPOCemp[MAX_EMPLOYEES];
    int numBIPOCemp, numnonBIPOCemp;

    // Interface
    printf("Pay Scale Comparison for Equity and Inclusion\n\n");
    do{
       printf("Choose an option");
       printf("1. Enter Employees Data.\n");
       printf("2. Display Employees Average Salary by Gender\n");
       printf("3. Display Employees Average Salary by Ethnicity\n");
       printf("0. Exit.")
       printf("Enter your choice: "); 
       scanf("%d", &choice);
       
        switch(choice){ 
            case 1:
                if (numEmployees >= 100){
                    printf("Employee Database is full!\n");
                }
                else {
                    employees[numEmployees] = (Employee*)malloc(sizeof(Employee));
                    inputEmployeeData(employee[numEmployees]);
                    numEmployees++;
                    printf("Employee Added Successfully!\n");
                }
                break;
            case 2: 
                // Call function to display average salary by gender:
                if (numEmployees == 0){
                    printf("No employees were added yet!\n");
                } else{
                    compareEmployeebyGender(employees, numEmployees, filteredEmployeesMale, filteredEmployeesFemale, filteredEmployeesNonBinary, &numFilteredMaleEmployees, &numFilteredFemaleEmployees, &numFilteredNonBinaryEmployees);
                }
                break;
            
            case 3:
                // Call function to display average salary by ethnicity 
                if (num Employees == 0){
                    printf("No employees were added yet!\n");
                } else{
                    compareEmployeebyEthnicity(employees, numEmployees, filteredBIPOCemp, filterednonBIPOCemp, &numBIPOCemp, &numnonBIPOCemp);
                }
                break;     

            // Giving the user the option to exit the program:
            case 0:
                printf("Exiting program...\n");
                break;
     
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0); // Loop until user chooses to exit the program:

    //free allocated memory
    for (int i = 0; i < numEmployees; i++){
        free(employees[i])
    }

    return 0;
}