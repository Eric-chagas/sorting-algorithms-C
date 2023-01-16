#include <stdio.h>
#include <stdlib.h>

//Define item type for the elements which will be sorted
typedef int item;

//Macro to return our desired item
#define key(A) (A)

//Macro that returns if item A is less than item B | if true returns 1, else returns 0
#define less(A, B) (key(A) < key(B))

//Macro to exchange two items
#define exch(A, B) {item T = A; A = B; B = T;}

//Macro to compare AND exchange items
#define cmpexch(A, B) {if(less(A, B)) exch(A, B)}

//Insertion Sort prototype
void insertionSort(item *, int, int);

int main(void) {

    int n, i, aux, v[1000000], sum = 0;

    scanf("%d", &n);

    /*for(i = 0; i < n; i++){
        scanf("%d", &aux);
        v[i] = aux;
    }*/
    
    for(i = 0; i < 1000000; i++){
        v[i] = rand();
    }

    insertionSort(v, 0, 1000000-1);

    sum++;
    aux = v[0];

    for(i = 0; i < 1000000; i++){
        if(v[i] != aux){
            sum++;
            aux = v[i];
        }
    }
    printf("%d\n", sum);
        
    return 0;
}

//Insertion Sort definition
void insertionSort(item *v, int l, int r){
    for(int i = r; i > l; i--){
        cmpexch(v[i], v[i-1]);
    }

    for(int i = l+2; i<=r; i++) {
        int j = i;
        int temp = v[j];
        while(less(temp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }
}



