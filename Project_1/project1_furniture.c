/*
Hanz Chua
U26738740
This program calculates rental costs of several types of furniture monthly
*/

#include <stdio.h>
 
 int main(void){
     int selection = 0,months = 0,cost = 0;
     printf("Please select from the following menu:\n1. Sofa\n2. Loveseat\n3. Post Bed\n4. Dresser\n5. Kitchen Table\n");
     printf("\nEnter furniture selection:");
     scanf("%d",&selection);

     if (selection < 1 || selection >= 6){
         printf("Please enter a number from 1 to 5.");
        return 0;
        }

     printf("Enter months rented:");
     scanf("%d",&months);

    if (months < 0){
        printf("Please enter a number above zero.");
        return 0;
            }
    if (selection > 0){
        if (selection == 1){
            cost = 60 + 45 * (months-1);
            if (cost >= 450){
                cost = 450;
                }
            } 
        if (selection == 2){
            cost = 45 + 30 * (months-1);
            if (cost >= 280){
                cost = 280;
                }
            }    
        if (selection == 3){
            cost = 55+ 38 *(months-1);
            if (cost >= 350){
                cost = 350;
                }
            }
        if (selection == 4){
            cost = 28 + 25 * (months-1);
            if (cost >= 200){
                cost = 200;
                }
            }
        if (selection == 5){
            cost = 35 + 20 *(months-1);
            if (cost >= 220){
                cost = 220;
                }
            }
        }
     printf("Amount due: $%d", cost);
     return 0;
    } 