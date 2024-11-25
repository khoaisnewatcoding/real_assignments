// STUDENT NAME: HOANG DANG KHOA NGUYEN                STUDENT ID: 178143236
//COURSE CODE: BTO125NCC.09700.2247

#include "Students.h"

int main() {
   // read input into a string buffer
   char line[1000]; // The line array
   struct Student students[100]; // Struct array (Maximum 100 students)
   int student_count = 0;

   printf("Enter student id and grades\n");
 
   
   while (1) { //always true so the loop keeps going until one of the condition inside forces the loop to break
      // read input
      if (fgets(line, sizeof(line), stdin) == NULL){
         break; 
      }

      // remove newline "/n" and replace ith with "\o" so the strtok can work
      int len = strlen(line);
      if (len > 0 && line[len-1] == '\n') {
         line[len-1] = '\0'; // Replace the last character as a new line character into a string terminator
      }

      // Inputs end once the new line is empty
      if(strlen(line) == 0){
         break;
      }
      // parsing process
      if (parseStudentRecord(line, &students[student_count])){
         student_count++;
         if (student_count >= 100){ //prevent from overflowing
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