#include <stdio.h>

/* So i'm going to divide each calculation into different functions to make it cleaner 
    Emir ur going to do the rest of 4 5 6 similar to what im doing rn
    Make sure u sent me the rest of the code when ur doing so i can review!


*/
// Part 1 
float calc_emission_transport() {
    char transportation[100];
    float emission_factor;
    float emissions;

    printf("What method of transportation do you use?(E.g Gasoline, Electric, Hybrid) ");
    scanf(" %[^\n]", transportation);

    if ((transportation[0] == 'G' || transportation[0] == 'g') && transportation[1] == 'a' && transportation[2] == 's') {
        emission_factor = 0.404;
    } else if ((transportation[0] == 'E' || transportation[0] == 'e') && transportation[1] == 'l' && transportation[2] == 'e') {
        emission_factor = 0.10425;
    } else if ((transportation[0] == 'H' || transportation[0] == 'h') && transportation[1] == 'y' && transportation[2] == 'b') {
        emission_factor = 0.404;
    } else {
        emission_factor = 0.0;
    }

    float miles_per_day;

    do {
        printf("How many miles do you drive per day? ");
        scanf("%f", &miles_per_day);
    } while (miles_per_day < 0);

    emissions = miles_per_day * emission_factor;

    return emissions;
}

// Part 2

float calc_emission_housing(){
    float kwh_per_month;
    float energy_emissions;
    do {
        printf("Enter your average monthly electricity consumption (kwh per month): ");
        scanf("%f", &kwh_per_month);
    } while (kwh_per_month < 0);

    energy_emissions = (kwh_per_month / 7) * 0.24;

    return energy_emissions;
}

// Part 3

float calc_emission_waste(){
    float waste_per_week, waste_emissions;
    do {
        printf("Enter your amount of waste generated per week: ");
        scanf("%f", &waste_per_week);
    } while (waste_per_week < 0);

    waste_emissions = (waste_per_week / 7) * 0.24;

    return waste_emissions;
}

float get_canada_daily_average(){

    return 0;
}

int main(){

    // step 1
    float from_transportation = calc_emission_transport();
    // step 2
    float from_housing = calc_emission_housing();
    // step 3
    float from_waste = calc_emission_waste();
    // step 4
    float total_emission = from_transportation + from_housing + from_waste;
    // step 5: average
    float daily_average = get_canada_daily_average();

    // step 6:
    printf("Your total carbon footprint in CO2 per day is %f\n", total_emission);

    if (total_emission > daily_average) {
        printf("Your emission is above Canadian average, which is %f\n", daily_average);
    } else {
        printf("Your emission is below Canadian average, which is %f\n", daily_average);
    }
}

