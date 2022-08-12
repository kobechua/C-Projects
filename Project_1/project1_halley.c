/*
Hanz Chua
U26738740
This program calculates the next occurence of Comet Halley
*/

#include <stdio.h>

int main(void){
    int year = 0, check = 0, answer = 0;

    printf("Enter year: ");
    scanf("%d",&year);
    check  = (year-1986)/76;
    if (year <= 1986){
        printf("Please enter a valid year.");
    }
    else {
        answer = year + (76 -(year-1986)+(76*check));
        printf("Next Appearance: %d",answer);
    }

}