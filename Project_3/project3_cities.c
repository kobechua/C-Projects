/*
Hanz Chua
U26738740
This program finds which cities are reachable by the given drones


#include <stdio.h>

int main(void){
    int cities, drones, location, distance, i, j, x,k;
    int cities_reached[100];

    printf("Enter number of cities (N): ");
    scanf("%d", &cities);

    if (cities > 0 && cities < 101){
        printf("Enter number of drones (M): ");
        scanf("%d", &drones);
        if (drones > 0 && drones < 101){
            printf("Enter drone list:\n");
            for (i = 0; i < drones; i++){
                scanf("%d %d", &location, &distance);

                if (location > 0 && location < (cities + 1) && distance > 0 && distance < (cities + 1)){
                    for (j=0; j < (cities/distance); j++){
                        x = (location) + (j*distance);
                        cities_reached[x] = 1;
                        }
                    for (j=-(cities/distance); j < 0; j++){                
                        x = (location) + (j*distance);
                        if (x > 0){
                            cities_reached[x] = 1;
                            }
                        }
                    }
                else {
                    printf("Invalid list of drones\nDrone location and travel distance must be in the range [1,%d]\n",cities);
                    return;
                }
            }

               

                printf("Cities reached by a drone: ");
                for (j=0; j < cities+1; j++){
                    if (cities_reached[j] < 2 && cities_reached[j] > 0){
                    printf("%d ", j);
                    }
                }
                printf("\n");
            }
        else{
            printf("Invalid number of drones %d\nMust be in range [0,100]\n", drones);
            
        }
    }
    else{
        printf("Invalid number of cities %d\nMust be in range [0,100]\n", cities);
        }
    
return 0;
}
*/ 

/*
Hanz Chua
U26738740
This program finds which cities are reachable by the given drones
*/

#include <stdio.h>

int main(void){
    int cities, drones, location, distance, i, j, x,k;
    int cities_reached[100];

    printf("Enter number of cities (N): ");
    scanf("%d", &cities);

    if (cities > 0 && cities < 101){
        printf("Enter number of drones (M): ");
        scanf("%d", &drones);
        if (drones > 0 && drones < 101){
            printf("Enter drone list:\n");
            for (i = 0; i < drones; i++){
                scanf("%d %d", &location, &distance);

                if (location > 0 && location < (cities + 1) && distance > 0 && distance < (cities + 1)){
                    for (j=0; j < (cities/distance); j++){
                        x = (location) + (j*distance);
                        cities_reached[x] = 1;
                        }
                    for (j=-(cities/distance); j < 0; j++){                
                        x = (location) + (j*distance);
                        if (x > 0){
                            cities_reached[x] = 1;
                            }
                        }
                    }
                else {
                    printf("Invalid list of drones\nDrone location and travel distance must be in the range [1,%d]\n",cities);
                    return;
                }
            }

               

                printf("Cities reached by a drone: ");
                for (j=0; j < cities+1; j++){
                    if (cities_reached[j] < 2 && cities_reached[j] > 0){
                    printf("%d ", j);
                    }
                }
                printf("\n");
            }
        else{
            printf("Invalid number of drones %d\nMust be in range [0,100]\n", drones);
            
        }
    }
    else{
        printf("Invalid number of cities %d\nMust be in range [0,100]\n", cities);
        }
    
return 0;
}
    



