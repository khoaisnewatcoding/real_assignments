#include "Employee.c"


void inputEmployeeData(Employee* employee){ // Khoa's
    //Prompting the user to input employee data
    printf("Enter Employee information here\n");
    // Get ID
    printf("ID: ");
    scanf("%d", &employee->id);
    // Get name
    printf("Employee's Name: ");
    scanf("%s", employee->name);
    //Get gender
    printf("Gender (Male/Female/Non-binary): ");
    scanf("$s", employee->gender);
    //Get ethnicity
    printf("Employee's ethnicity")



    
}   

float calculateAverageSalary(Employee* employee[], int numEmployees, AverageValues* values, int *numGroups ){
    *numGroups = 0 //base amount of groups set to 0

    for (i = 0; i < numEmployees; i++){
        
    }

}