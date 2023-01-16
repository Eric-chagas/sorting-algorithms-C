#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    int n, grades[100], auxNum, min, instance = 0;
    char names[100][21], auxString[21], loser[21];

    while(scanf("%d", &n) == 1){
    
        min = 11;
        instance++;
        for(int i = 0; i < n; i++){
            scanf("%s", auxString);
            strcpy(names[i], auxString);
            scanf("%d", &auxNum);
            grades[i] = auxNum;
            if(auxNum < min){
                min = auxNum;
                strcpy(loser, auxString);
            }
        }
    
        for(int i = 0; i < n; i++){
            if(grades[i] == min){
                if(strcmp(names[i], loser) > 0){
                    strcpy(loser, names[i]);
                }
            }
        }

        printf("Instancia %d\n", instance);
        printf("%s\n", loser);

        //printf("%s %d\n", names[0], grades[0]);
        //printf("%d\n", min);
    }
    return 0;
}

