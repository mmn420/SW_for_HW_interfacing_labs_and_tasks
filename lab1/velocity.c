#include <stdio.h>
int main (){
    float u, a, t;

    printf("insert 'u' \n");
    scanf("%f",&u);
    printf("insert 'a' \n");
    scanf("%f",&a);
    printf("insert 't' \n");
    scanf("%f",&t);

    double v = u + a*t;
    double s = u*t + 0.5*a*t*t;
    printf("v = ");
    printf("%lf", v);
    printf("\n");
    printf("s = ");
    printf("%lf", s);
    return 0;


}