#include <stdio.h>

int main(){
    printf("Please enter three different integers \n");
    int x, y, z;

    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);

    int sum = x + y + z;
    float average = sum/3.0;
    int product = x*y*z;

    int min, max;
    max = x>y? x:y;
    max = max>z? max:z;
    min = x<y? x:y;
    min = z<min? z:min;


    printf("The sum is ");
    printf("%d", sum);
    printf("\n");
    printf("The average is ");
    printf("%f", average);
    printf("\n");
    printf("The product is ");
    printf("%d", product);
    printf("\n");
    printf("The min is ");
    printf("%d", min);
    printf("\n");
    printf("The max is ");
    printf("%d", max);
    printf("\n");

    return 0;
}