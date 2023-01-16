#include <stdio.h>
#include <string.h>

void printaMatrix(char[1000000][30], int);

int main(){

    char cidades[1000000][30], end[1000000][30], aux[30];
    int iterator = 0, strLen, endIndex = 0, ignore = 0, True = 1, False = 0;
    
    scanf("%s", aux);
    strLen = strlen(aux);
    strcpy(cidades[iterator], aux);
    iterator++;
    
    while(scanf("%s", aux) == 1){ 
        if(ignore == True){
            strLen = strlen(aux);
            strcpy(cidades[iterator], aux);
            iterator++;
            ignore = False;
        }
        else {
            //printf("%c == %c\n", aux[0]+32, cidades[iterator-1][strLen-1]);
            if((aux[0]+32) == cidades[iterator-1][strLen-1]){          
                strcpy(end[endIndex], aux);
                endIndex++;
                ignore = True;
                //printf("%s!!!!! igual\n", aux);
            }
            else {
                strLen = strlen(aux);
                strcpy(cidades[iterator], aux);
                iterator++;
                ignore = False;
            }
        }
    } 
    printaMatrix(cidades, iterator); 
    printaMatrix(end, endIndex);

    return 0;
}


void printaMatrix(char matrix[1000000][30], int size){
    
    for(int i = 0; i < size; i++){
        printf("%s\n", matrix[i]);
    }
    
}
