#include <stdio.h>

// Define constants and variables
#define MAX_STUDENTS 5
#define MAX_GRADES_PER_STUDENT 5

int main(){
    int num_students, num_grades_per_student; //declaring datatype for these two variables
    int grades[MAX_STUDENTS][MAX_GRADES_PER_STUDENT]; // declaring the datatype for grades array and the size of it by using max students as row and max grades as the columms
    float average[MAX_STUDENTS]; // declaring the datatype for average array which contains the average grade for each students.
    char letter_grade[MAX_STUDENTS]; //declaring the datatype for letter grade array which stores the letter grade for each students


    // Input phase
    do { 
        printf("Please enter the number of students (Max %d): ", MAX_STUDENTS);
        scanf("%d", &num_students);
    } while (num_students < 1 || num_students > MAX_STUDENTS); // If user enters the number within this range, it will loop the code asking the same thing

    do {
        printf("Please enter the number of grades per student (Max %d): ", MAX_GRADES_PER_STUDENT);
        scanf("%d", &num_grades_per_student); // Corrected: takes input for num_grades_per_student
    } while (num_grades_per_student < 1 || num_grades_per_student > MAX_GRADES_PER_STUDENT); // Similar to above, except it's grades


    //Grade entry
    printf("Enter grade for all students: \n");
    for (int i = 0; i < num_students; i++){
        int sum = 0; // Sum is declared here. Whenever the loop starts, sum's first value will always be 0
        printf("Please enter grade for student %d:\n", i + 1);
        for (int o = 0; o < num_grades_per_student; o++){ // Corrected: fixed syntax error in the loop
            do{
                printf("Enter grade %d: ", o + 1);
                scanf("%d", &grades[i][o]); // Corrected: input for grades array
            } while (grades[i][o] < 0 || grades[i][o] > 100); // make sure that the grade input is within valid range, otherwise it will prompt the user to input again
            sum += grades[i][o]; // adds all the grades the user inputs for each student
        }
        average[i] = (float)sum / num_grades_per_student; // this average array is in the first for loop, indicating it stores the average grade for each student.


        //Grade conversion to letter
        if (average[i] >= 90)
            letter_grade[i] = 'A';
        else if (average[i] >= 80)
            letter_grade[i] = 'B';
        else if (average[i] >= 70)
            letter_grade[i] = 'C';
        else if (average[i] >= 60)
            letter_grade[i] = 'D';
        else
            letter_grade[i] = 'F';

        //This whole logical statement is also in for loop because for each student it needs to convert the grade. Therefore, this block of code cannot be outside.

        // Output phase
        printf("Average: %.2f\n", average[i]); // Display average with 2 decimal places
        printf("Letter Grade: %c\n", letter_grade[i]);
    }

    return 0;
}
