/*
Hanz Chua
U26738740
This program determines if the characters in the input are in order using command line arguments.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char *argv[]){       //parameters of the main function
    int letter1;
    int letter2;
    int status;

    int i;


    if (argc > 2){                                                                  // checks if the arguments are valid
        printf("Incorrect number of arguments. Usage: ./a.out word\n");
        return 0;
    }

    if (argc == 1){
        printf("Incorrect number of arguments. Usage: ./a.out word\n");
        return 0;
    }

    int length = strlen(argv[1]);
    

    for (i = 0;i < length;i++){                                                     // loops through each letter of the argument and checks if they are in order
        // printf("%c\n", argv[1][i]);
        letter1 = argv[1][i];

        if (letter2 <= letter1){
            status = 1;
        }
        else {
            status = 0;
            break;
        }
        letter2 = letter1;
    }

    if (status == 1){                                           //Output
        printf("Output: In order.\n");
    }
    else{
        printf("Output: Not in order.\n");
    }
    return 0;
}

