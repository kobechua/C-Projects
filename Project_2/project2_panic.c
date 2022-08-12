/*
Hanz Chua
U26738740
This program calculates the cost of groceries after applying store's panic buying policy.
*/

#include <stdio.h>

int main(){
    int price = 0, units = 0, wallet = 0, total = 0, i = 0;


    printf("Enter item price: ");
    scanf("%d",&price);
    printf("Enter number of units: ");
    scanf("%d",&units);
    printf("Enter money amount: ");
    scanf("%d",&wallet);

    if (price <= 0 || units <= 0 || wallet < 0){
        printf("Invalid entry.");
    }

    else {
        while (units > 0){
            total = total + (units*price);
            units--;
        }
    
        if (wallet < total){
            int required_amount = total - wallet;
            printf("Needs %d dollar(s) to complete the purchase!",required_amount);
        }
        else {
            printf("Has enough money!");
        }   

    }


    return 0;
}