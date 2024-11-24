#include "Students.h"


// Calculating the average
float calculateGPA(struct Student* students){
    float sum = 0;
    for(int i = 0; i < 4; i++) {
        sum += students->grades[i];
    }
    return (sum / 4);
}

// Getting the output:
void printStudentInfo(struct Student* students){
    float average = calculateGPA(students);
    printf("Student ID: %d, Average Grade: %.2f\n", students->id, average);
}

// hardest part

// read a string and parse it to multiple students
int parseStudent(char *line, struct Student* students) {
    char *token;
    int grade_index = 0;

    // parsing part
    // Get the ID
    // Parse the num to grades


    // getting the ID
    token = strtok(line, " ");
    if ( token == NULL ){
        return 0; // Terminates if the string is empty
    }
    students->id = atoi(token); // Convert the string into an integer value

    // Getting the grades
    while ( token != NULL){
        token = strtok(NULL, " ");
        students->grades[grade_index++] = atof(token);
        
        if  (grade_index >= 4){
            break;
        }
    }

    students->grade_count = grade_index;
    return grade_index > 0;

}