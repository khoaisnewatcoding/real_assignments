// Name: Hoang Dang Khoa Nguyen COURSE CODE: BTP100NCC
// Student Number: 178143236
// Please don't ender a string or a char inside the terminal because idk what try catch statement in C is :(
#include <stdio.h>

int main(){
    float item1_price, item1_quantity;
    float item2_price, item2_quantity;
    float item3_price, item3_quantity;
    float tax_percent = 0.085;

    // For item1_price and item1_quantity
    printf("Please enter the price for item 1: ");
    scanf("%f", &item1_price);
    if (item1_price > 0)
        printf("The price for item 1 is %f\n", item1_price);
    else
        printf("Not a valid price.\n");

    printf("Please enter the quantity for item 1: ");
    scanf("%f", &item1_quantity);
    if (item1_quantity > 0)
        printf("The quantity for item 1 is %f\n", item1_quantity);
    else 
        printf("Not a valid quantity.\n");
    

    // For item2_price and item2_quantity
    printf("Please enter the price for item 2: ");
    scanf("%f", &item2_price);
    if (item2_price > 0)
        printf("The price of item 2 is %f\n", item2_price);
    else
        printf("Not a valid price.\n");

    printf("Please enter the quantity for item 2: ");
    scanf("%f", &item2_quantity);
    if (item2_quantity > 0)
        printf("The quantity of item 2 is %f\n", item2_quantity);
    else
        printf("Not a valid quantity.\n");


    // For item3_price and item3_quantity
    printf("Please enter the price for item 3: ");
    scanf("%f", &item3_price);
    if (item3_price > 0)
        printf("The price of item 3 is %f\n", item3_price);
    else
        printf("Not a valid price.\n");

    printf("Please enter the quantity for item 3: ");
    scanf("%f", &item3_quantity);
    if (item3_quantity > 0)
        printf("The quantity of item 3 is %.2f\n", item3_quantity);
    else
        printf("Not a valid quantity.\n");


    // Calculation part
    float item1_subtotal = item1_price * item1_quantity;
    float item2_subtotal = item2_price * item2_quantity;
    float item3_subtotal = item3_price * item3_quantity;
    float Subtotal = item1_subtotal + item2_subtotal + item3_subtotal;
    float Total_Cost = Subtotal * (1 + tax_percent);
    float Tax_Cost = Subtotal * tax_percent;


    // Bill Format
    printf("Shopping Bill Calculator: \n");
    printf("\n");
    printf("------------------------------------");
    printf("\n");
    printf("Item 1 subtotal: %.2f\n", item1_subtotal);
    printf("Item 2 subtotal: %.2f\n", item2_subtotal);
    printf("Item 3 subtotal: %.2f\n", item3_subtotal);
    printf("\n");
    printf("\n");
    printf("Subtotal: %.2f\n", Subtotal);
    printf("Tax: %.2f\n", Tax_Cost);
    printf("Total Cost: %.2f\n", Total_Cost);
    printf("\n");
    printf("\n");
    printf("------------------------------------");

    return 0;
}
