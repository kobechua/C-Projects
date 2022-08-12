/*
Hanz Chua
U26738740
This program determines whether or not X is a multiple of 11
*/

#include <stdio.h>
#define LENGTH 10000

int main(){
    char x[LENGTH];
    char sum1;
    char sum2;
    char answer;
    int i = 0;

    printf("Enter the value of X: ");                           //taking input of x
    scanf("%s", x);

    while (x[i] != '\0'){                                       //loop goes through x and adds alternating numbers
        if ((i % 2) == 1){

            sum1 = sum1 + x[i]-'0';
            
        }
        if((i % 2) == 0){

            sum2 = sum2 + x[i]-'0';

        }

        i++;

    }

    answer = (sum1 - sum2)%11;
        
    if (answer == 11 || answer == 0){               //checks if x meets the conditions
        printf("%s is a multiple of 11\n", x);
    }
    else{
        printf("%s is not a multiple of 11\n", x);
    }

    
    return 0;

}
