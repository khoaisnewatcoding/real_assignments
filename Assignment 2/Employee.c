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
float calculateAverageSalary(Employee* filteredGroup[], int numFilteredEmp){
    if (numFilteredEmp == 0){
        return 0; //Imagine the company has no other gender, gotta avoid devising by 0 :)
    }

    int totalSalary = 0;
    for (int i = 0; i < numFilteredEmp; i++){
        totalsalary =+ filteredGroup[i]->salary;
    }
    return (totalsalary / numFilteredEmp);
}



// Faizan:
//compare data by iterating through employee's database and then filter by criteria
void compareEmployeebyGender(Employee* employees[], int numEmployees, Employee* filteredEmployeesMale[], Employee* filteredEmployeesFemale[], Employee* filteredEmployeesNonBinary[], int* numFilteredMaleEmployees, int* numFilteredFemaleEmployees, int* numFilteredNonBinaryEmployees){
    //step 1: Iterating through the employees array
    //step 2: compare "gender" and filter it out
    // step 3: display employees average salary by category Male, Female, non-binary
    // We will intialize the number of filtered employees to 0:

    // step1 and 2: Iterating through the employees database to filter for each gender group
    *numFilteredMaleEmployees = 0;
    *numFilteredFemaleEmployees = 0;
    *numFilteredNonBinaryEmployees = 0;


    for(int i = 0; i < numEmployees; i++){ // Iterate through all employees in the database and filter for each gender group:
        if (strcmp(employees[i]->gender, "male") == 0 ){
            // transfer the data of filtered employees into a new database for "Male" group
            filteredEmployeesMale[*numFilteredMaleEmployees] = employees[i];
            (*numFilteredMaleEmployees)++; // Make sure the new filtered emp go to the next space in the group
            //If the employee's gender is "female", add them to the filteredFemaleEmployees array
        } elif (strcmp(employees[i]->gender, "female") == 0 ){ 
            filteredEmployeesFemale[*numFilteredFemaleEmployees] = employees[i]; 
            (*numFilteredFemaleEmployees)++;
            //If the employee's gender is "non-binary", add them to the filteredNonBinaryEmployees array
        else if (strcmp(employees[i]->gender, "non-binary") == 0 ){
        } elif (strcmp(employees[i]->gender, "non-binary") == 0 ){
            filteredEmployeesNonBinary[*numFilteredNonBinaryEmployees] = employees[i];
            (*numFilteredNonBinaryEmployees)++;
        }
    }

    // Step 3:Calculate and display the average salary for each gender group

    float avgMaleEmps = calculateAverageSalary(filteredEmployeesMale, *numFilteredMaleEmployees);
    float avgFemaleEmps = calculateAverageSalary(filteredEmployeesFemale, *numFilteredFemaleEmployees);
    float avgNonbinaryEmps = calculateAverageSalary(filteredEmployeesNonBinary, *numFilteredNonBinaryEmployees);
    // Display the results:
    printf("Average Male Salary: %.2f\n", avgMaleEmps);
    printf("Average Female Salary: %.2f\n", avgFemaleEmps);
    printf("Average Non-Binary Salary: %.2f\n", avgNonbinaryEmps);

}

void compareEmployeebyEthnicity(Employee* employees[], int numEmployees, Employee* filteredBIPOCemp[], Employee* filterednonBIPOCemp[], int* numBIPOCemp, int* numnonBIPOCemp){
    // Follow the same step as the previous function

    *numBIPOCemp = 0;
    *numnonBIPOCemp = 0;

    for(int i = 0; i < numEmployees; i++){
        if(strcmp(employees[i]->ethnicity, "BIPOC") == 0){
            filteredBIPOCemp[*numBIPOCemp] = employees[i];
            (*numBIPOCemp)++;
        } elif (strcmp(employees[i]->ethnicity, "non-BIPOC") == 0){
            filterednonBIPOCemp[*numnonBIPOCemp] = employees[i];
            (*numnonBIPOCemp)++;
        }
    }

    float avgBIPOCemps = calculateAverageSalary(filteredBIPOCemp, *numBIPOCemp);
    float avgnonBIPOCemps = calculateAverageSalary(filterednonBIPOCemp, *numnonBIPOCemp);

    printf("Average BIPOC Salary: %.2f\n", avgBIPOCemps);
    printf("Average non-BIPOC Salary: %.2f\n", avgnonBIPOCemps);

}


   