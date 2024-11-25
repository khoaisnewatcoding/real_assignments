

#include "Employee.h"

#define MAX_EMPLOYEES 100

int main(){
    struct Employee* employee[MAX_EMPLOYEES]; //assuming the max employee is 100
    int choice;
    int numEmployees = 0;

    struct Employee* filteredEmployeesMale[MAX_EMPLOYEES];
    struct Employee* filteredEmployeesFemale[MAX_EMPLOYEES];
    struct Employee* filteredEmployeesNonBinary[MAX_EMPLOYEES];
    int numFilteredMaleEmployees = 0, numFilteredFemaleEmployees = 0, numFilteredNonBinaryEmployees = 0;

    struct Employee* filteredBIPOCemp[MAX_EMPLOYEES];
    struct Employee* filterednonBIPOCemp[MAX_EMPLOYEES];
    int numBIPOCemp = 0, numnonBIPOCemp = 0;

    // Interface
    printf("Pay Scale Comparison for Equity and Inclusion\n\n");
    do{
        printf("Choose an option\n");
        printf("1. Enter Employees Data.\n");
        printf("2. Display Employees Average Salary by Gender\n");
        printf("3. Display Employees Average Salary by Ethnicity\n");
        printf("0. Exit.\n");
        printf("Enter your choice: "); 
        scanf("%d", &choice);
       
        switch(choice){ 
            case 1:
                if (numEmployees >= MAX_EMPLOYEES){
                    printf("Employee Database is full!\n");
                }
                else {
                    employee[numEmployees] = malloc(sizeof(struct Employee));  // Allocate memory for a new employee
                    inputEmployeeData(employee[numEmployees]);  // Populate data for this employee
                    numEmployees++;  // Increment employee count
                    printf("Employee Added Successfully!\n");
                }
                break;
            case 2: 
                // Call function to display average salary by gender:
                if (numEmployees == 0) {
                    printf("No employees were added yet!\n");
                } else {
                    compareEmployeebyGender(employee, numEmployees, filteredEmployeesMale, filteredEmployeesFemale, filteredEmployeesNonBinary, 
                                            &numFilteredMaleEmployees, &numFilteredFemaleEmployees, &numFilteredNonBinaryEmployees);
                }
                break;
            case 3:
                // Call function to display average salary by ethnicity 
                if (numEmployees == 0){
                    printf("No employees were added yet!\n");
                } else {
                    compareEmployeebyEthnicity(employee, numEmployees, filteredBIPOCemp, filterednonBIPOCemp, &numBIPOCemp, &numnonBIPOCemp);
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
        free(employee[i]);
    }

    return 0;
}
