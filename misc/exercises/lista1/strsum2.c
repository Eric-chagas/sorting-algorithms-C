#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int n, sum = 0, j;
    char s[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", s);
        j = 0, sum = 0;
        while(s[j] != '\0'){
            if(s[j] >= 48 && s[j] <= 57){
                sum += s[j] - 48;
            }
            j++;
        }
        printf("%d\n", sum);
    }

    return 0;
}

