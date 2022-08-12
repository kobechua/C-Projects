#include <stdio.h>

void find_parity(int *a, int n, int *all_even, int *all_odd){


    if (*a%2 == 0){
        *all_even = 1;

    }
    if (*a%2 > 0) {
        *all_odd = 1;

    }
    // printf("all_even:%d all_even: %d\n",*all_even,*all_odd);
    return;
}

int main(){
    int length, i, input, list[length], odd = 0, even = 0;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < length; i++){
        scanf("%d",&input);
        list[i] = input;
    }

    for (i = 0; i < length; i++){
        find_parity(&list[i],length,&even,&odd);
        // printf("even:%d odd: %d\n", even, odd);
    }

    if (even == 1 && odd == 0){
        printf("Output: good, all elements are even\n");
    }
    else if (odd == 1 && even == 0){
        printf("Output: good, all elements are odd\n");
    }
    else{
        printf("Output: not good\n");
    }

    return 0;
}

