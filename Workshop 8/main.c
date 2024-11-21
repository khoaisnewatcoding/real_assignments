// NAME: HOANG DANG KHOA NGUYEN  STUDENT ID: 178143236
// COURSE CODE: BTP100NCC.04893.2247


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
    printf("Workshop 8\n");
    printf("-----------------------\n\n");


    // Task 1: String initialization and manipulation
    char input_string[50] = "Hello, World!\0";
    
    // Task 2: String output
    printf("Task 1 and 2: String initialization and output\n");
    printf("%s\n\n", input_string);

    // Task 3: String length
    printf("Task 3: String Length\n");
    int strlength = strlen(input_string);
    printf("The length of the input_string is: %d\n\n", strlength);

    // Task 4: String copy
    printf("Task 4: String copy\n"); 
    char copied_string[50];
    strcpy(copied_string, input_string);
    printf("copied_string: %s\n\n", copied_string);

    // Task 5: String concatenation
    printf("Task 5: String concatenation\n");
    char concatenated_string[100];
    strcpy(concatenated_string, input_string);
    strcat(concatenated_string, copied_string);
    printf("concatenated_string: %s\n\n", concatenated_string);

    // Task 6: Absolute value
    printf("Task 6: Absolute value\n"); 
    double absolute_value = fabs(-12.345);
    printf("absolute_value of -12.345: %.2f\n\n", absolute_value);

    // Task 7: Random number generation
    printf("Task 7: Random number generation\n");
    srand(time(NULL));
    int random_num = (rand() % 100 - 1 + 1) + 1; // Formula to random a num in [min, max]: [rand() % (max - min + 1)] + min
    printf("Random number from 1 to 100: %d\n", random_num);

    return 0;
}
