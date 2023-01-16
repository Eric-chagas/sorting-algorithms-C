#include <stdio.h>

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        //printf("%d: ", i);
        if(i%3 == 0 && i%5==0){
            printf("fizzbuzz!\n");
        }
        else if(i%3 == 0){
            printf("fizz!\n");
        }
        else if(i%5==0){
            printf("buzz!\n");
        } 
        else{
            printf("%d\n", i);
        }
    }

    printf("\nFinished!\n\n");

    return 0;
}
