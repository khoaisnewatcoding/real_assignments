// STUDENT NAME: HOANG DANG KHOA NGUYEN                                     COURSE CODE: BTP100NCC.04893.2247
// STUDENT ID: 178143236

#include <stdio.h>

// Define constants and variables:
#define MAX_STUDENTS 5
#define MAX_GRADES_PER_STUDENT 5

int main() {
    int num_students, num_grades_per_student, grade;
    float average;
    char letter_grade;

    // INPUT PHASE:
    do {
        printf("Enter the number of students (Max %d): ", MAX_STUDENTS);
        scanf("%d", &num_students);
    } while (num_students < 1 || num_students > MAX_STUDENTS);

    do {
        printf("Enter the number of grades per student (Max %d): ", MAX_GRADES_PER_STUDENT);
        scanf("%d", &num_grades_per_student);
    } while (num_grades_per_student < 1 || num_grades_per_student > MAX_GRADES_PER_STUDENT);

    // Grade entry
    printf("Enter grades for all students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        int sum = 0;

        for (int k = 0; k < num_grades_per_student; k++) {
            do{
                printf("Enter Grade %d: ", k + 1);
                scanf("%d", &grade);
                sum += grade;
            } while (grade < 0 || grade > 100);
                
        }

        // Calculation phase    
        average = (float)sum / num_grades_per_student; 

        // Letter grade determination
        if (average >= 90) {
            letter_grade = 'A';
        } else if (average >= 80) {
            letter_grade = 'B';
        } else if (average >= 70) {
            letter_grade = 'C';
        } else if (average >= 60) {
            letter_grade = 'D';
        } else {
            letter_grade = 'F';
        }

        // Output phase
        printf("Average Grade: %.2f\n", average);
        printf("Letter Grade: %c\n", letter_grade);
    }

    return 0;
}
