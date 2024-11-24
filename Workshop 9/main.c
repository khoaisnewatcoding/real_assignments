/* BTP 100—Introduction to Programming using C
 Workshop #9
 You are required to develop a program in C that processes student records from standard input 
(keyboard). Each student record consists of a student ID (integer) followed by a variable number 
of grades (floating-point numbers). The program should compute the average grade for each 
student and display the results.
 Learning Objectives:
 1. Implement functions to read student records, compute average grades and display results.
 2. Utilize appropriate standard input functions (‘fgets()’, ‘sscanf()’) for reading and parsing 
input data.
 3. Utilize string manipulation functions (‘strtok()’, ‘strcpy()’, etc.) from the string library to 
process input data efficiently.
 4. Appropriately utilize and implement header files.
 Tasks:
 1. Input Format:
 a. Input will consist of multiple lines, each containing a student ID followed by one 
or more grades separated by spaces.
 b. Example input:
    101 78.5 84.2 92.3 76.8
    102 65.3 70.2 60.5 55.5
    103 88.0 91.5 87.2 89.8
 2. Output Format:
 a. For each student, output should display their student ID and calculated average 
grade formatted to two decimal places.
 b. Example output:
    Student ID: 101, Average Grade: 82.45
    Student ID: 102, Average Grade: 62.88
    Student ID: 103, Average Grade: 89.13
 1
3. Functions to Implement:
 a. calculateAverage(): Computes the average grade given an array of grades.
 b. printStudentInfo(): Prints the student ID and average grade in the specified 
format.
 c. parseStudentRecord(): Parses a line of input to extract student ID and grades 
using string manipulation functions.
 4. Program break down:
 a. Your main should contain just your main function and the inclusion of 
“Student.h”.
 b. Your “Student.c” should contain the implementation of the functions declared in 
“Student.h”.
 c. Your “Student.h” file should contain forward declarations of your functions, as 
well as any structs, library inclusions and macro definitions.
 Hints:
   Use ‘fgets()’ to read entire lines of input and ‘sscanf()’ or ‘strtok()’ for parsing.
   Ensure accurate input reading and error handling.
   Utilize string library functions (‘strcpy()’, ‘strtok()’, ‘strlen()’, etc.) for efficient string 
processing.
 Deliverables:
 Note: every one of your files should have your name, the date and the course code at the top in a 
comment block. Furthermore, compressed files will not be graded.
 • Your Student.h, Student.c and main.c files.
 • Your README.md which contains your short reflection on the topics covered in this lab.
 2

*/
#include "Students.h"

int main() {
   // read input into a string buffer
   char line[1000]; // The line array
   struct Student students[100]; // Struct array (Maximum 100 students)
   int student_count = 0;

   printf("Enter student id and grades\n");
 
    // Read lines until EOF (Ctrl+D on Unix, Ctrl+Z on Windows)
   while (fgets(line, sizeof(line), stdin) != NULL) {
      // Process each line here
      // Remove newline if needed
      int len = strlen(line);
      if (len > 0 && line[len-1] == '\n') {
         line[len-1] = '\0'; // Replace the last character as a new line character into a string terminator
      }
      if (parseStudent(line, &students[student_count])){
         student_count++;
         if (student_count >= 100){ //prevent
            printf("Maximum student count reached!!!!!!\n");
            break;
         }
      } else{
         printf("Invalid input, skipping line.\n");
      }
   }     
   


   //Printing student's records
   for (int j = 0; j  < student_count; j++){
      printStudentInfo(&students[j]);
   }

   
   return 0;
}