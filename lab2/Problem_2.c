#include <stdio.h>
#include<stdlib.h>

int main(){
    for (int i=0; i<5; i++){
        for(int spaces=0; spaces<abs(4-i); spaces++){
            printf(" ");
        }
        for (int stars=0; stars<2*i+1; stars++){
            printf("*");
        }
        printf("\n");

    }
        for (int i=3; i>=0; i--){
        for(int spaces=0; spaces<abs(4-i); spaces++){
            printf(" ");
        }
        for (int stars=0; stars<2*i+1; stars++){
            printf("*");
        }
        printf("\n");

    }
    return 0;

}