#include <stdio.h>

int main(){

    // declaring float variables for the exam scores, and average score
    float exam1, exam2, exam3;

    printf("Enter a score out of 100 for each exam.\n");

    // exam 1 score 
    printf("Enter exam 1 score: ");
    scanf("%f", &exam1);
    if (exam1 > 0)
        printf("Exam 1 score: %.2f \n", exam1);
    else if (exam1 == 100)
        printf("Amazing! Exam 1 score: %.2f \n", exam2);
    else 
        printf("Please enter a valid score!\n");

    // exam 2 score 
    printf("Enter exam 2 score: ");
    scanf("%f", &exam2);
    if (exam2 > 0)
        printf("Exam 2 score: %.2f \n", exam2);
    else if (exam2 == 100)
        printf("Amazing! Exam 2 score: %.2f \n", exam2);
    else 
        printf("Please enter a valid score!\n");

    // exam 3 score 
    printf("Enter exam 3 score: ");
    scanf("%f", &exam3);
    if (exam3 > 0)
        printf("Exam 3 score: %.2f \n", exam3);
    else if (exam3 == 100)
        printf("Amazing! Exam 3 score: %.2f \n", exam3);
    else 
        printf("Please enter a valid score!\n");

    // average score
    float average = (exam1 + exam2 + exam3)/3;

    // output for the grade
    if (average == 100){
        printf("Amazing! \n");
    }
    else if (90 <= average && average <= 100){
        printf("Great! You get an A! \n");
    }
    else if (80 <= average && average <= 90){
        printf("Good! You get a B. \n");
    }
    else if (70 <= average && average <= 80){
        printf("Okay! You get a C. \n"); 
    }
    else if (60 <= average && average <= 70){
        printf("Keep trying! You get a D. \n"); 
    }
    else if (average <= 60){
        printf("See me after class! You get a F. \n");
    }
    else{
        printf("The average is invalid. \n");
    }
    printf("The average score is: %.2f", &average);

    return 0;
}