/*
Hanz Chua
U26738740
This program calculates and displays the factorial of each element in an integer array.
*/

#include <stdio.h>


int fact (int n){
    if (n <= 1){
        return 1;
    }
    else{
        return n * fact(n-1);
    }

}

void calculate_fact(int a[], int n, int b[]){
    int i;
    for (i = 0; i < n; i++)
    {
        b[i] = fact(a[i]);
    }
    return;
}

int main(){
    int length, i, num;

    printf("Enter length of array: ");
    scanf("%d",&length);

    int element[length];
    int array[length]; 

    printf("Enter elements of the array: ");
    for (i = 0;i < length;i++){
        scanf("%d",&num);
        element[i] = num;
    }

    calculate_fact(element, length, array);
    printf("Output array: ");
    for(i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    
    
    

    
}   
