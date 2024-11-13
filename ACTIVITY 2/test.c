#include <stdio.h>
#include <string.h>


char compareString(){
    char string1[100];
    printf("Enter your first word (Maximum 100 characters): ");
    scanf("%[^\n]", string1);

    char string2[100];
    printf("\nEnter the word that you want to compare (max 100 characters): ");
    scanf("%[^\n]", string2);

    int sizeString1 = sizeof(string1), sizeString2 = sizof(string2);

    if (sizeString1 > sizestring2 || sizeString1 < sizeString2){
        printf("False.\n");
    } else {
        
    }       
}


int main(){
    return 0;
}