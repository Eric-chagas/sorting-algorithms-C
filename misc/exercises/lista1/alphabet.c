#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    char s1[21], s2[21];
    
    scanf("%s %s", s1, s2);

    if(strcmp(s1, s2) < 0){
        printf("%s is the loser.\n", s2);
    } else if(strcmp(s1, s2) > 0){ 
        printf("%s is the loser.\n", s1);
    }

    return 0;
}

