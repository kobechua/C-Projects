/*
Hanz Chua
U26738740
This program determines if the characters in the input are in order.
*/

#include <stdio.h>
#include <ctype.h>


int main(){
    int letter1;
    int letter2;
    int status;


    printf("Input: ");
    letter1 = getchar();
    if (letter1 < 122 && letter1 > 65){
    do{

        if (letter2<=letter1){
            status = 1;
        }
        else {
            status = 0;
            break;
        }
        letter2 = letter1;
    }

    while ((letter1 = getchar()) != '\n');

    if (status == 1){
        printf("Output: In order.");
    }
    else{
        printf("Output: Not in order");
    }
    return 0;
    }
    else{
        printf("Output: Not in order");
        return -1;
    }
}