#include "Employee.h"

void inputEmployeeData(struct Employee* employee){ // Khoa's
    // What if the user input is literally BS and doesnt even relate?
    // Then we have to loop until its valid!

    //Prompting the user to input employee data
    printf("Enter Employee information here\n");
    // Get ID
    printf("ID: ");
    scanf("%d", &employee->id);
    
    // Get name
    printf("Employee's Name: ");
    scanf("%s", employee->name);
    //Get gender
    do{
        printf("Gender (male/female/nonbinary): ");
        scanf("%s", employee->gender);  // Ensure this only captures gender correctly
    } while (strcmp(employee->gender, "male") != 0 && strcmp(employee->gender, "female") != 0 && strcmp(employee->gender, "nonbinary") != 0);
    
    //Get ethnicity
    char userinput[20];
    do {
        printf("Employee's ethnicity (BIPOC, non-BIPOC) / Enter ? for more information: ");
        scanf("%s", userinput);

        // Check if the user wants more information
        if (strcmp(userinput, "?") == 0) {
            char user_request;
            do {
                printf("\nBIPOC: BLACK, INDIGENOUS, PEOPLE OF COLOR\n");
                printf("non-BIPOC: NON BLACK, NON INDIGENOUS, NOT PEOPLE OF COLOR\n\n");
                printf("Enter y to go back to entering ethnicity: ");
                
                getchar(); // Clear any leftover newline character from previous input
                scanf("%c", &user_request);

                if (user_request == 'y' || user_request == 'Y') {
                    break; // Exit the inner loop and return to the main input
                } else {
                    printf("Invalid input. Please enter 'y' to go back.\n");
                }
            } while (1); // Keep looping until the user enters 'y' or 'Y'
        } 
        // Check for valid ethnicity inputs
        else if (strcmp(userinput, "BIPOC") == 0 || strcmp(userinput, "non-BIPOC") == 0) {
            strcpy(employee->ethnicity, userinput); // Save valid input
            break; // Exit the main loop
        } 
        // Invalid input for ethnicity
        else {
            printf("Invalid input. Please try again.\n");
        }

    } while (1); // Keep looping until a valid ethnicity is provided
    //Get salary
    // Must be greater than 0
    do{
        printf("Employee's Salary:");
        scanf("%d", &employee->salary);
    } while (employee->salary <= 0);
}



// Emir description:
/* This function will basically loop through the employees struct and check if the group (which is consisted of both a gender and an ethnicity) exists.
if it does, the function will add the other persons salary and also increment the employee count by 1. After that it will take calculate the average salary and
save it under the companyAverage struct averageSalary.
*/
//Emir's
// Just calculate the salary average by criteria
/*void calculateAverageSalary(struct Employee* genderFiltered[], int filterednumEmployees, struct AverageValues* filteredcompanyAverages, int *numGroups ){
    *numGroups = 0; //base amount of groups set to 0
    int i, j;

    for (int i = 0; i < numEmployees; i++){
        char currentGroup[30]; //this is an array that holds the employees gender and ethnicity

        strcpy(currentGroup, employees[i]->gender); //copies the gender of the employee to the variable currentGroup
        strcat(currentGroup, ","); //appends a comma after the gender which will seperate it from the ethnicity
        strcat(currentGroup, employees[i]->ethnicity); //appends the ethnicity of the employee after the comma. (currentGroup output will now look like "Male, White")
        
        //check to see if the user inputted group already exists:
        int exists = 0; //this will be used to check if the group exists or not
        for (int j = 0; j < *numGroups; j++){
            if (strcmp(companyAverages[j].group, currentGroup) == 0) {
                exists = 1;
                break; //groups match - exit loop
            }
        }
        
        //if the user inputted group doesnt exist:
        if (!exists){
            strcpy(companyAverages[*numGroups].group, currentGroup); 
            companyAverages[*numGroups].totalGroupSalary = employees[i].salary; //copies the salary of the x`
            companyAverages[*numGroups].numEmps = 1; //start off the number of groups at 1
            (*numGroups)++; //iterate the amount of groups by 1 each time
        }
    
    }

    for (int i = 0; i < *numGroups; i++){
        companyAverages[i].averageSalary = companyAverages[i].totalGroupSalary / companyAverages[i].numEmps;
    }
}
*/

// Emir's 
float calculateAverageSalary(struct Employee* filteredGroup[], int numFilteredEmp){
    if (numFilteredEmp == 0){
        return 0; //Imagine the company has no other gender, gotta avoid devising by 0 :)
    }

    int totalSalary = 0;
    for (int i = 0; i < numFilteredEmp; i++){
        totalSalary += filteredGroup[i]->salary;
    }
    return ((float)totalSalary / numFilteredEmp);
}



// Faiz:
// Faiz youre doing comparison
//compare data by iterating through employee's database and then filter by criteria
// i think you can use for loop for this

// Filter the employee database and filter by gender and then calculate average using the function and displays the result
void compareEmployeebyGender(struct Employee* employees[], int numEmployees, struct Employee* filteredEmployeesMale[], struct Employee* filteredEmployeesFemale[], struct Employee* filteredEmployeesNonBinary[], int* numFilteredMaleEmployees, int* numFilteredFemaleEmployees, int* numFilteredNonBinaryEmployees) {
    //step 1: Iterating through the employees array
    //step 2: compare "gender" and filter it out
    // step 3: display employees average salary by category Male, Female, non-binary
    // We will initialize the number of filtered employees to 0:

    // step1 and 2: Iterating through the employees database to filter for each gender group
    *numFilteredMaleEmployees = 0;
    *numFilteredFemaleEmployees = 0;
    *numFilteredNonBinaryEmployees = 0;

    for(int i = 0; i < numEmployees; i++){
        if (strcmp(employees[i]->gender, "male") == 0){
            filteredEmployeesMale[*numFilteredMaleEmployees] = employees[i];
            (*numFilteredMaleEmployees)++;
        } else if (strcmp(employees[i]->gender, "female") == 0){
            filteredEmployeesFemale[*numFilteredFemaleEmployees] = employees[i];
            (*numFilteredFemaleEmployees)++;
        } else if (strcmp(employees[i]->gender, "nonbinary") == 0){
            filteredEmployeesNonBinary[*numFilteredNonBinaryEmployees] = employees[i];
            (*numFilteredNonBinaryEmployees)++;
        }
    }

    // Step 3: Calculate average salary for each gender group
    float avgMaleEmps = calculateAverageSalary(filteredEmployeesMale, *numFilteredMaleEmployees);
    float avgFemaleEmps = calculateAverageSalary(filteredEmployeesFemale, *numFilteredFemaleEmployees);
    float avgNonbinaryEmps = calculateAverageSalary(filteredEmployeesNonBinary, *numFilteredNonBinaryEmployees);

    printf("Average Male Salary: %.2f\n", avgMaleEmps);
    printf("Average Female Salary: %.2f\n", avgFemaleEmps);
    printf("Average Non-Binary Salary: %.2f\n", avgNonbinaryEmps);
}

// Khoa and faiz both worked on this
// this function filters the employee by ethnicity and implement the calculate average function to do the job and finally display the result
void compareEmployeebyEthnicity(struct Employee* employees[], int numEmployees, struct Employee* filteredBIPOCemp[], struct Employee* filterednonBIPOCemp[], int* numBIPOCemp, int* numnonBIPOCemp){
    // Follow the same step as the previous function

    *numBIPOCemp = 0;
    *numnonBIPOCemp = 0;

    for(int i = 0; i < numEmployees; i++){
        if(strcmp(employees[i]->ethnicity, "BIPOC") == 0){
            filteredBIPOCemp[*numBIPOCemp] = employees[i];
            (*numBIPOCemp)++;
        } else if (strcmp(employees[i]->ethnicity, "non-BIPOC") == 0){
            filterednonBIPOCemp[*numnonBIPOCemp] = employees[i];
            (*numnonBIPOCemp)++;
        }
    }

    // Calculate average salary for BIPOC and non-BIPOC groups
    float avgBIPOCemps = calculateAverageSalary(filteredBIPOCemp, *numBIPOCemp);
    float avgnonBIPOCemps = calculateAverageSalary(filterednonBIPOCemp, *numnonBIPOCemp);

    printf("Average BIPOC Salary: %.2f\n", avgBIPOCemps);
    printf("Average non-BIPOC Salary: %.2f\n", avgnonBIPOCemps);
}

