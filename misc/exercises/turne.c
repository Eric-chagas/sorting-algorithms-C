#include <stdio.h>
#include <string.h>

void printaMatrix(char[10000][27], int);

int main(){

    char cidades[10000][27], aux[27];
    int iterator = 0, strLen, pos, end;
    
    scanf("%s", cidades[iterator]);
    strLen = strlen(cidades[iterator-1]);
    iterator++;
    end = iterator;
    
    while(scanf("%s", aux) == 1){ 
        if((aux[0]+32) == cidades[iterator-1][strLen]){          
            strcpy(cidades[end], aux);
            iterator++;
        }
        else {
            end++;
            strcpy(cidades[end], cidades[end-1]);
            strLen = strlen(aux);
            strcpy(cidades[end-1], aux);
            iterator++;
        }
    } 
    
    printaMatrix(cidades, iterator); 


    return 0;
}


void printaMatrix(char matrix[10000][27], int size){
    
    for(int i = 0; i < size; i++){
        printf("%s\n", matrix[i]);
    }
    
}
