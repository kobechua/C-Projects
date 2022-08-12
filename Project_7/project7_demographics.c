/*
Hanz Chua
U26738740
This program sorts the states by percentage of popilation whose ages are equal or greater than 65 years old.
*/

#include<stdio.h>
#include<string.h>

#define LEN 100

struct state{                                 //initializing the struct
    char name[LEN];
    int population2014, population2010;
    double age5, age18, age65;
};


void sort_states(struct state list[], int n){   //sorting algorithm
    int i, j;
    struct state temp;

    for (i = 0;i<n;i++){
        for (j = 0; j<n-1;j++){
            if(list[j].age65 < list[i].age65){
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
            
        }     
    }
}

int main(){                     //main program
    char input[LEN]; 
    char output[LEN];

    printf("Enter the file name: "); //asks for input
    scanf("%s", input);
    printf("\n");

    char prefix[LEN] = "sorted_";   //concatenates "sorted_" to input name
    strcat(prefix,input);
    strcpy(output, prefix);

    printf("Output file name: %s\n", output);
    

    FILE *pFile;                            //opens file
    pFile = fopen(input, "r");      

    if (pFile == NULL){                     //checks for missing file
        printf("Error opening file\n");
        return 1;
    }
    
    int num_states = 0;                     
    struct state state[150];

    while (!feof(pFile)&&!ferror(pFile)){           //reads file and assigns them to an struct at index "num_states"

        char name[LEN];
        int temp2014, temp2010;
        double temp5, temp18, temp65;

        fscanf(pFile, "%[^,], %d, %d, %lf, %lf, %lf\n", name, &temp2014, &temp2010, &temp5, &temp18, &temp65);
    

        strcpy(state[num_states].name,name);
        state[num_states].population2014 = temp2014;
        state[num_states].population2010 = temp2010;
        state[num_states].age5 = temp5;
        state[num_states].age18 = temp18;
        state[num_states].age65 = temp65;
        num_states++;
    }

    int i;

    sort_states(state, num_states+1);       //calls sorting algorithm 

    FILE* qFile;
    qFile = fopen(output, "w");         //opens output file and writes the states in sorted order

    for(i = 0; i < num_states;i++){
        fprintf(qFile,"%s,%d,%d,%2.1lf,%2.1lf,%2.1lf\n", state[i].name, state[i].population2014, state[i].population2010, state[i].age5, state[i].age18, state[i].age65);
    }
    return 0;
}