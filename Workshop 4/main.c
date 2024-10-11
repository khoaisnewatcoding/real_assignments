//STUDENT NAME: HOANG DANG KHOA NGUYEN      COURSE CODE: BTP100NCC.04893.2247
// SSTUDENT ID: 178143236

#include <stdio.h>

int main() {
    // Part 1
    float exam1_score, exam2_score, exam3_score, Average_score;
    char letter_grade;

    // Promting user input while using if else to make sure that the input's value is within allowed parameter.
    printf("Please enter your first exam score (out of 100): ");
    scanf("%f", &exam1_score);
    if (exam1_score < 0 || exam1_score > 100) {
        printf("INVALID!\n");
        return 0; // Terminates the process if an invalid number is entered.
    }
    printf("Your first exam score is: %.1f\n", exam1_score);

    //------------------------------------------------------------

    printf("Please enter your second exam score (out of 100): ");
    scanf("%f", &exam2_score);
    if (exam2_score < 0 || exam2_score > 100) {
        printf("INVALID!\n");
        return 0; // The same goes for this.
    }
    printf("Your second exam score is: %.1f\n", exam2_score);

    //-------------------------------------------------------------

    printf("Please enter your third exam score (out of 100): ");
    scanf("%f", &exam3_score);
    if (exam3_score < 0 || exam3_score > 100) {
        printf("INVALID!\n");
        return 0; // Same goes for this.
    }
    printf("Your third exam score is: %.1f\n", exam3_score);
    // Average score!
    Average_score = (exam1_score + exam2_score + exam3_score) / 3;

    // Determine the letter grade based on average score
    if (Average_score >= 90 && Average_score <= 100)
        letter_grade = 'A';
    else if (Average_score >= 80 && Average_score < 90)
        letter_grade = 'B';
    else if (Average_score >= 70 && Average_score < 80)
        letter_grade = 'C';
    else if (Average_score >= 60 && Average_score < 70)
        letter_grade = 'D';
    else
        letter_grade = 'F';

    // Printing the output
    printf("Grade Calculator\n");
    printf("\n-------------------------------------\n");
    printf("\nAverage Score: %.1f\n", Average_score);
    printf("Letter Grade: %c\n", letter_grade);
    printf("\n-------------------------------------\n");

    //----------------------------------------------------------------------------------------------------------------

    //Part2
    float weight, height, BMI;
    char* weight_range;
    
    // Getting user's weight and height
    printf("Please enter your weight (kg) : ");
    scanf("%f", &weight);
    printf("Please enter your height (meters) : ");
    scanf("%f", &height);
    // Making sure weight and height is realistic.
    if ( weight <= 0 && height <= 0){
        printf("INVALID! That weight/height does not exist!\n");
        return 0;
    }
    printf("Your weight is %.1f kg and your height is %.2f m\n ", weight, height);

    // Calculating part
    BMI = weight / (height*height);

    // Determine weight range using BMI
    if (BMI < 18.5)
            weight_range = "underweight";
    else if (18.5 <= BMI && BMI < 25)
        weight_range = "normal weight";
    else if (25 <= BMI && BMI < 30)
        weight_range = "overweight";
    else if (BMI >= 30)
        weight_range = "obese";

    // Printing the output
    printf("BMI Calculator\n");
    printf("-------------------------------\n");
    printf("Your BMI is: %.f\n", BMI);
    printf("You are in the %s range\n", weight_range);
    printf("\n-----------------------------\n");

    return 0;
}
