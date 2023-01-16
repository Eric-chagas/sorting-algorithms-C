#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int aux = 0, n = 1, tri=0;
    char answ[4];
    while(scanf("%s", answ) == 1){ 
        if(answ[0] == 's'){
            aux++;
        }
        n++;
        
        if(n > 10){
            if(aux >= 2){
                tri++;
            }
            n = 1;
            aux = 0;
        } 
    }
    printf("%d\n", tri);
    
    return 0;
}

