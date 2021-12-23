#include <stdio.h>

int main (){
    unsigned int x;
    int n;
    char o;
    printf("Please Enter the desired number!");
    printf("\n");
    scanf("%u", &x);
    printf("Please Enter the number of rotations!");
    printf("\n");
    scanf("%d", &n);
    printf("Please Enter the roation direction ('l' for left rotation and 'r' for right rotation)");
    printf("\n");
    scanf(" %c", &o);

    if(o == 'l') {
        while(n--){
            int MSB = (x>>7)&1;
            x = (x<<1) | MSB;
            if(x>=256){
                x=x-256;
            }
        }
        printf("%u",x);
    }
    else if(o=='r'){
         while(n--){
            int LSB = x&1;
            x = (x>>1) | LSB<<7;
        }
        printf("%u",x);

    }
    else{
        printf("Please enter a valid operand");

    }
    

    return 0;

}