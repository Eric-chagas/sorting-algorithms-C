#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n, aux, sum = 0;
    long long int students[1000000];

    scanf("%d", &n);

    for(int i = 0; i < 1000000; i++){
        students[i] = 0;
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        students[aux] = 1;
    }

    for(int i = 0; i < 1000000; i++){
        if(students[i] == 1){
            sum++;
        }
    }

    printf("%d\n", sum);
    return 0;
}
