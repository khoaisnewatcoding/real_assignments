#include "Employee.c"
// NO PAIN NO GAIN!!!
// NO CAP ONLY FAX
void inputEmployeeData(Employee* employee){ // Khoa's
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
        printf("Gender (male/female/non-binary): ");
        scanf("%s", employee->gender);
    } while (strcmp(employee->gender, "male") != 0 && strcmp(employee->gender, "female") != 0 && strcmp(employee->gender, "non-binary") != 0);
    
    //Get ethnicity
    char userinput[10];
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
        scanf("%d", employee->salary);
    } while (employee->salary <= 0);
}

// Emir description:
/*
*/
//Emir's
void calculateAverageSalary(struct Employee* employees[], int numEmployees, struct AverageValues* companyAverages, int *numGroups ){
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
            companyAverages[*numGroups].totalGroupSalary = employees[i].salary;
            companyAverages[*numGroups].numEmps = 1;
            (*numGroups)++;
        }
    
    }

    for (int i = 0; i < *numGroups; i++){
        companyAverages[i].averageSalary = companyAverages[i].totalGroupSalary / companyAverages[i].numEmps;
    }
}

// Faiz:
// Faiz youre doing comparison
//compare data by iterating through employee's database and then filter by criteria
// i think you can use for loop for this
void filterEmployeesbyender(Employee* employees[], int numEmployees, const char *genderFilter, Employee* filteredEmployees[], int *numFilteredEmployees) {
    // We will intialize the number of filtered employees to 0:
    *numFilteredEmployees = 0; 
    for (int i = 0; i < numEmployees; i++) { // iterate through all employees and filter by criteria
        if (strcmp(employees[i]->gender, genderFilter) == 0) { // if gender matches the gender filter
            filteredEmployees[*numFilteredEmployees] = employees[i]; // copy the employee to the filtered employees array
            (*numFilteredEmployees)++; // increment the number of filtered employees:
        }
    }

    // Prints the filtered employees information along with its filtered genders:
    printf("Filtered Employees by Gender: %s\n", genderFilter); 
    for (int i = 0; i < *numFilteredEmployees; i++) { //
        printf("ID: %d\nName: %s\nGender: %s\nEthnicity: %s\nSalary: %d\n\n", //
               filteredEmployees[i]->id, filteredEmployees[i]->name, //
               filteredEmployees[i]->gender, filteredEmployees[i]->ethnicity, 
               filteredEmployees[i]->salary);
    } // prints the total number of filtered employees and their information about their genders:
    printf("Total number of filtered employees: %d\n", *numFilteredEmployees);
}