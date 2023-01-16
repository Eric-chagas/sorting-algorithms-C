#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int v[1000000], aux=1, i = 0, lim;

    while(aux != 0){
        scanf("%d", &aux);
        if(aux == 0) break;
        v[i] = aux;
        i++;
    }
    
    scanf("%d", &lim);

    int size = i, v2[1000], j = 0;
    aux = 0;

    for(i = 0; i <= size; i++){
        aux += v[i]; 
        if(aux > lim){
            aux = 0;
            v2[j] = i;
            j++;
        }
    }

    for(j = j-1; j >=0; j--){
        printf("%d\n", v[v2[j]]);
    }
    
    return 0;
}

