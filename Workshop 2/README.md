STUDENT NAME: HOANG DANG KHOA NGUYEN
STUDENT ID: 178143236
in workshop 2 i've wrote
-------------------------------------------------------------
#include <stdio.h>

int main(){
    // Part1
    float tempC1, tempF1;
    printf("Please enter your temperature in Celcius: ");
    scanf("%f", &tempC1);
    tempF1 = (tempC1 * (9.0 / 5.0)) + 32.0;
    printf("Here is your temperature in Fahrenheit: %.2f\n", tempF1);
    // Part2
    float tempF2, tempC2;
    printf("Please enter your temperature in Fahrenheit: ");
    scanf("%f", &tempF2);
    tempC2 = (tempF2 - 32) * (5.0/ 9.0);
    printf("Here is your temperature in Celcius: %.2f\n", tempC2);
    return 0;
}
-------------------------------------------------------------
-This is a temperature converting program. It converts C to F and vice versa.
-In this work, i've learnt how to declare multiple variables in a single line, which is convenient and much cleaner and takes up less memory in my opinion.
-I've also noticed how to adjust the rounding for %f by adding .(whatever decimal point you want to round) which produce a much cleaner output.
-Also, through this work, I've grasped a much clearer understanding of how scanf and printf works overall and it will help me utilize these two much more efficiently in the future.

