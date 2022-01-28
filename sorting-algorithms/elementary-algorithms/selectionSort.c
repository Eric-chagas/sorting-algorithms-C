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

//Selection Sort prototype
void selectionSort(item *, int, int);

int main(void) {

    item v[10000];
    for(int i = 0; i < 10000; i++){
        v[i] = rand();
    }
    
    for(int i = 0; i < 10000; i++){
        printf("%d\n", v[i]);
    }
    printf("\n");

    selectionSort(v, 0, 9999);

    for(int i = 0; i < 10000; i++){
        printf("%d\n", v[i]);
    }
    printf("\n");
    
    return 0;
}

//Selection Sort definition
void selectionSort(item *v, int l, int r){
    if(l == r) return;
    int min = l;
    for(int j = l+1; j <= r; j++){
        if (less(v[j], v[min])){
            min = j;
        }
    }
    exch(v[min], v[l]);
    selectionSort(v, l+1, r);
}
