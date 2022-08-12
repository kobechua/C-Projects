/*
Hanz Chua
U26738740
This program concatenates according to the following rules:
1) the suffix for each file starts as an empty string; 
2) one by one, you must read a word from the file and concatenate it to the suffix if the length of the resulting 
string is below the limit of M characters; 
3) every time a word cannot be concatenated to the suffix due to the lack of space, you must "reset" the suffix 
(set it to an empty string again) to open space for the new word. 
*/

#include<stdio.h>   
#include<string.h>
#define LEN 10000

int main(int argc, char *argv[]){

    int i;
    int length;
    char suffix[length+1];

    printf("Enter the value of M: ");   //Gets value of max characters in a suffix
    scanf("%d", &length);

    for(i = 1;i < argc;i++){    //Repeats loop for each file in a.out
        FILE *pFile;
        pFile  = fopen(argv[i], "r");   //opens file and assigns it to pFile
        char str[LEN];
        char temp[LEN];

        if (pFile == NULL){     //checks if file is there
            printf("Error opening file\n");
            return 1;
        }

        while (!feof(pFile)&&!ferror(pFile)){   //reads file and performs the concatenation
            fscanf(pFile, "%[^\n]\n", str);

            strcpy(temp, str);
            
            strcat(suffix, temp);
            int suffixlength = strlen(suffix);

            if (suffixlength <= length){
                continue;
            }
            else{
                strcpy(suffix,str);
            }
        
        }
        
        printf("%s: %s\n", argv[i], suffix);    //prints the outputs

        strcpy(suffix, "");     //sets suffix to null at the end of the loop

    }
    return 0;
}