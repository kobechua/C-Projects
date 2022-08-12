#include <stdio.h>



int main(){
    int n, k, i, j, input, list[n], sorted[k];

    int find_minimum();

    printf("Enter number of parts (N): ");
    scanf("%d",&n);

    if (n < 1 || n > 1000000){
        printf("Invalid number of parts.\n");
        return 0;
    }


    printf("Enter number of part types (K): ");
    scanf("%d",&k);

    if (k < 1 || k > 10000){
        printf("Invalid number of part types.\n");
        return 0;
    }


    printf("Enter part list: ");


    for (i = 0; i < n; i++){
        printf("k:%d\n", k);
        scanf("%d", &input);
        list[i] = input;
    }

    for (i = 0; i < n; i++){

        if (list[i] > k || list[i] < 1){
            printf("Invalid part types.");
            return 0;
        }
    }



    for (i = 1; i < k+1; i++){
        for (j = 0; j < n; j++){
            if (list[j] == i){
                sorted[i] += 1;
            }
        }
    }

    // for (j = 1; j < k+1; j++){
    //     printf("\n%d\n",sorted[j]);
    // }

    printf("The factory can build %d computer(s).",find_minimum(&sorted[0],k));
    // for (i = 1; i < k+1; i++){
    //     find_minimum(&sorted[i], i);
    // }


    
    return 0;
}

int find_minimum(int *a, int n){
    // printf("\n%d, %d\n", *a, n);

    int temp;
    int result;

    while(n > 0){
        // printf("a: %d, n:%d\n",*(a+n),n);
        temp = *(a+n);
        n--;
        if (*(a+n) > temp){
            result = temp;
        }
        
    }

    return result;
    
}
