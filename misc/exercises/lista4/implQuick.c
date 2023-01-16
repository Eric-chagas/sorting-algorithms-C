#include <stdio.h>
#include <stdlib.h>

//Define item type for the elements which will be sorted
typedef int item;

//Macro to return our desired item
#define key(A) (A)

//Macro that returns if item A is less than item B | if true returns 1, else returns 0
#define less(A, B) (key(A) < key(B))

//Macro that returns if item A is less or equal than item B | if true returns 1, else returns 0
#define lesseq(A, B) (key(A) <= key(B))

//Macro to exchange two items
#define exch(A, B) {item T = A; A = B; B = T;}

//Macro to compare AND exchange items
#define cmpexch(A, B) {if(less(A, B)) exch(A, B)}

//Insertion Sort prototype
void insertionSort(item *, int, int);

// Partition function prototype
int partition(item *, int, int);

// Quick Sort prototype
void quickSort(item *, int, int);

int main(void) {

    int n, aux;
    item v[500000];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        v[i] = aux;
    }

    quickSort(v, 0, n-1);
    insertionSort(v, 0, n-1);

    for(int i = 0; i < n; i++){
        if(i == n-1) printf("%d\n", v[i]);
        else printf("%d ", v[i]);
    }

    return 0;
}

// Partition function impl
int partition(item *v, int l, int r) {
    item itemPivot = v[r];
    int lesser = l;
    for(int i = l; i < r; i++){
        if(lesseq(v[i], itemPivot)){
            exch(v[lesser], v[i]);
            lesser++;
        }
    }
    exch(v[lesser], v[r]);
    return lesser;
}

// Quick Sort impl
void quickSort(item *v, int l, int r){
    if(r-l <= 32) {
        return;
    }
    else {
        exch(v[r-1], v[(l+r)/2]);
        cmpexch(v[l], v[r-1]);
        cmpexch(v[l], v[r]);
        cmpexch(v[r-1], v[r]);
        int pivot = partition(v, l, r);
        quickSort(v, l, pivot-1);
        quickSort(v, pivot+1, r);
    }
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
