#include <stdio.h>

int main(){

    int x, n;

    printf("Enter the exponent... \n");
    scanf("%d", &x);
    printf("Enter the number of iterations..\n");
    scanf("%d", &n);

    double result = 1.0;
    double factorial = 1.0;
    double power = 1.0;
    for (int i=1; i<n; i++){
        power = power*x;
        factorial = factorial*i;
        result +=  (power/factorial);
    }
    printf("%lf", result);

    return 0;
}