#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    int n, sum = 0, exists = 0, aux, reg[1000000];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        if(i == 0){
            reg[i] = aux;
            sum++;
            continue;
        }
        for(int j = 0; j < i; j++){
            if(reg[j] == aux){
                //printf("%d ja apareceu.\n", aux);
                exists = 1;
                break;
            }
        }
        if(exists == 0){
            sum++;
        }
        reg[i] = aux;
        exists = 0;
    }

    printf("%d\n", sum);
    return 0;
}

