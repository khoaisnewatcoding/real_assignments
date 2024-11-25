//STUDENT NAME: HOANG DANG KHOA NGUYEN                STUDENT ID: 178143236
//COURSE CODE: BTO125NCC.09700.2247

#include "Students.h"


// Calculating the average
float calculateAverage(struct Student* students){
    float sum = 0;
    for(int i = 0; i < students->grade_count; i++) {
        sum += students->grades[i];
    }
    if(students->grade_count == 0){
        return 0; // if there is no student the gpa is 0 (avoid dividing by 0)
    }
    return (sum / students->grade_count);
}

// Getting the output:
void printStudentInfo(struct Student* students){
    float average = calculateAverage(students);
    printf("Student ID: %d, Average Grade: %.2f\n", students->id, average);
}

// hardest part

// read a string and parse it to multiple students


int parseStudentRecord(char *line, struct Student *students) {
    char *token;
    int grade_index = 0;

    // Get the ID
    token = strtok(line, " ");
    if (token == NULL) {
        return 0; // Terminate if the string is empty
    }
    students->id = atoi(token); // Convert the string to an integer

    // Get the grades
    while ((token = strtok(NULL, " ")) != NULL) { // parse the remaining part of the string and convert it floats
        if (grade_index >= 4) {
            break; // Ignore extra grades
        }
        students->grades[grade_index++] = atof(token); // Convert to float
    }

    students->grade_count = grade_index;

    // Return success if at least one grade was parsed
    return grade_index > 0;
}
