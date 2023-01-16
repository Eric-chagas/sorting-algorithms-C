#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    char string[10000];
   
    printf("Insert your line:\n"); 
    scanf("%[^\n]%*c", string);

    printf("\n%s\n", string);
    
    printf("Insert your line:\n"); 
    scanf("%[^\n]%*c", string);

    printf("\n%s\n", string);

    return 0;
}

