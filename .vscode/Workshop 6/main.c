// STUDENT NAME: HOANG DANG KHOA NGUYEN STUDENT ID:178143236 
//BTP100NCC.04893.2247


#include <stdio.h>
#define MAX_STUDENTS 10

// This structure represents a student with a name, ID, grades, and GPA
typedef struct {
    char name[50];     // Name of the student
    int ID;            // Unique ID of the student
    float grades[5];   // Array to store 5 grades
    float GPA;         // GPA calculated from the grades
} Student;

// Function declarations
void addStudent(Student* students, int* num_students);  // Adds a new student to the array
void displayStudents(Student* students, int num_students);  // Shows info about all students
float calculateGPA(float grades[]);  // Calculates the GPA based on grades
void searchStudentByID(Student* students, int num_students, int id);  // Looks for a student by ID

int main() {
    Student students[MAX_STUDENTS];  // Array to store up to 10 students
    int num_students = 0;            // Current number of students in the array
    int users_choice, id;

    do {
        // Show the menu options to the user
        printf("\nStudent Database Management System\n");
        printf("Menu:\n");
        printf("1. Add a new student\n");
        printf("2. Display all students\n");
        printf("3. Search student by ID\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &users_choice);

        // Perform different actions based on what the user chose
        switch (users_choice) {
            case 1:
                addStudent(students, &num_students);  // Add a new student
                break;
            case 2:
                displayStudents(students, num_students);  // Display all students
                break;
            case 3:
                // Ask for an ID to search for and then call the search function
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                searchStudentByID(students, num_students, id);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (users_choice != 0);  // Keep looping until the user chooses to exit

    return 0;
}

// This function calculates the GPA by averaging an array of grades
float calculateGPA(float grades[]) {
    float sum = 0;
    // Add up all the grades
    for (int i = 0; i < 5; i++) {
        sum += grades[i];
    }
    return sum / 5;  // Return the average (GPA)
}

// This function adds a new student to the array
void addStudent(Student* students, int* num_students) {
    // Check if there's still room for more students
    if (*num_students >= MAX_STUDENTS) {
        printf("Students database is full!\n");
        return;  // Stop here if no space left
    }

    // Get a reference to the new student position in the array
    Student* s = &students[*num_students];
    
    // Get input for the student's details
    printf("Enter student name: ");
    scanf(" %[^\n]", s->name);  // Read the name
    printf("Enter student ID: ");
    scanf("%d", &s->ID);        // Read the ID

    // Get the grades for this student
    printf("Enter grades for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Grade %d: ", i + 1);
        scanf("%f", &s->grades[i]);
    }

    // Calculate and store the GPA based on the grades
    s->GPA = calculateGPA(s->grades);
    (*num_students)++;  // Increment the student count
}

// This function displays info for all students in the array
void displayStudents(Student* students, int num_students) {
    // If there are no students, let the user know and stop here
    if (num_students == 0) {
        printf("There are no students in the database.\n");
        return;
    }

    // Loop through each student and print their details
    for (int i = 0; i < num_students; i++) {
        Student* s = &students[i];
        printf("\nStudent Details:\n");
        printf("Name: %s\n", s->name);
        printf("ID: %d\n", s->ID);
        printf("Grades: ");
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", s->grades[j]);  // Print each grade
        }
        printf("\nGPA: %.2f\n", s->GPA);  // Print the GPA
    }
}

// This function searches for a student by their ID
void searchStudentByID(Student* students, int num_students, int id) {
    // Loop through all students to find a match
    for (int i = 0; i < num_students; i++) {
        if (students[i].ID == id) {  // If the ID matches
            // Print this student's details
            printf("\nStudent Details:\n");
            printf("Name: %s\n", students[i].name);
            printf("ID: %d\n", students[i].ID);
            printf("Grades: ");
            for (int j = 0; j < 5; j++) {
                printf("%.2f ", students[i].grades[j]);
            }
            printf("\nGPA: %.2f\n", students[i].GPA);
            return;  // Exit after finding the student
        }
    }
    // If no student was found with the given ID, inform the user
    printf("Cannot find student with ID: %d.\n", id);
}
