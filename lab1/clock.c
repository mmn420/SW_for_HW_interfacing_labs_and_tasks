#include <stdio.h>

int main (){

    printf("Enter the time in seconds \n");
    int sec;
    scanf("%d", &sec);
    int hours, minutes;
    minutes = sec/60;
    sec = sec - minutes*60;
    hours = minutes/60;
    minutes = minutes - hours*60;

    printf("%d", hours);
    printf(":");
    printf("%d", minutes);
    printf(":");
    printf("%d", sec);
    printf(":");


    return 0;
}