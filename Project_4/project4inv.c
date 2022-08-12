#include <stdio.h>

int find_minimum(int *a, int n){
    int *last=(a+n);
    int minimum = *a;
    while(a!=last){
        if(*a < minimum)
        minimum= *a;

        a++;
    }
    return minimum;
}

int main(){
    int N, i;
    printf("Enter number of parts (N): ");
    scanf("%d", &N);

    int K;
    printf("Enter number of part types (K):");
    scanf("%d", &K);

    int a[K];

    printf("Enter Part list: \n");

    for (i = 0;i<N;i++){
        int part;
        scanf("%d",&part);
        a[part-1]+=1;
    }
    printf("The factory can build %d computer(s)", find_minimum(a,K));
    return 0;
}