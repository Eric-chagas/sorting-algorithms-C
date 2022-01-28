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

//Bubble Sort prototype
void bubbleSort(item *, int, int, int);

int main(void) {

    item v[10000];
    for(int i = 0; i < 10000; i++){
        v[i] = rand();
    }
    
   /* for(int i = 0; i < 10000; i++){
        printf("%d\n", v[i]);
    }
    printf("\n");
    */
    
    bubbleSort(v, 0, 9999, 0);

    for(int i = 0; i < 10000; i++){
        printf("%d\n", v[i]);
    }
    printf("\n");
    
    return 0;
}

//Bubble Sort definition
void bubbleSort(item *v, int l, int r, int i){
    if(i == r-l) return;
    for(int j = l; j < r; j++){
        cmpexch(v[j+1], v[j]) 
    }
    i++;
    bubbleSort(v, l, r, i);
}
