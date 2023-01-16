#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    int n, sum = 0, aux;
    char reg[100000], c;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        c = '0';
        if(strchr(reg, c+aux)==NULL){
            printf("%c nao apareceu ainda.\n", c+aux);
            sum++;
        }
        reg[i] = c+aux;
    }

    printf("%d\n", sum);
    return 0;
}

