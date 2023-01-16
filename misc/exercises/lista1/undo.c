#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int i = 0, j = 0;
    char command[9], aux, words[10000][101];
    while(scanf("%s", command) == 1){
        aux = '1';
        if(command[0] == 'i'){
            while(aux != '\n'){
                scanf("%c", &aux);
                words[i][j] = aux;
                j++;
                if(aux == '\n'){
                    j = 0;
                    i++;
                }
            }
        }
        else {
            if(i > 0) {
                words[i][j] = '\n';
                j = 1;
                i--;
                while(words[i][j] != '\n'){
                    printf("%c", words[i][j]);
                    words[i][j] = '\n';
                    j++;
                }
                printf("\n");
                j = 0;
            } else {
                printf("NULL\n");
            }
        }
    }
    
    return 0;
}

