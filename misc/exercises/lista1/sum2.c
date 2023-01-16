#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, sum = 0, aux;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        sum += aux;
    } 

    printf("%d\n", sum);
    return 0;
}

