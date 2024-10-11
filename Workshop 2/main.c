//Name: HOANG DANG KHOA NGUYEN
//STUDENT ID: 178143236
// In this file, temp means temperature :)
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

