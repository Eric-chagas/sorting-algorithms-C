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

//Insertion Sort H and shell Sort prototypes
void insertionSortH(item *, int, int, int);
void shellSort(item *, int, int);

int main(void) {
    
    int n, i, aux, v[100000000], sum = 0;
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &aux);
        v[i] = aux;    
    }

    /*for(i = 0, j = 100000000; j >= 0, i < 1000000; i++, j--){
        v[i] = j;    
    }*/

    shellSort(v, 0, n-1);
    
    sum++;
    aux = v[0];

    for(i = 0; i < n; i++){
        if(v[i] != aux){
            sum++;
            aux = v[i];
        }
    }
    printf("%d\n", sum);

    return 0;
}

//Insertion Sort H and shell Sort definition
void insertionSortH(item *v, int l, int r, int h){
    for(int i = l+h; i<=r; i++) {
        int j = i;
        int temp = v[j];
        while(less(temp, v[j-h]) && j >= l+h){
            v[j] = v[j-h];
            j-=h;
        }
        v[j] = temp;
    }
}

void shellSort(item *v, int l, int r){
    int h;
    for(h = 1; h <= r-l; h=3*h+1){
    }
    for (; h > 0; h=h/3) {
        insertionSortH(v, l, r, h);
    }
}



