#include <stdio.h>

int main (){
    
    int n;
    printf("Please enter the number of terms! \n");
    scanf("%d", &n);
    int arr[n];
    if (n >= 2){
        arr[0]=0;
        arr[1]=1;
        printf("%d \n", arr[0]);
        printf("%d \n", arr[1]);
        
        for(int i=2; i<n; i++){
        arr[i]=arr[i-1]+arr[i-2];
        printf("%d \n", arr[i]);
    }
    }
    
    else {
        for(int i=0; i<n; i++){
        arr[i]=i;
        printf("%d \n", arr[i]);
    }
    }




    return 0;
}