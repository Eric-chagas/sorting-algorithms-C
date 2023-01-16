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

//Merge prototype
void merge(item *, int, int, int);

//MergeSort prototype
void mergeSort(item *, int, int);

int main(void) {

    int n = 0, aux;
    item v[500000];

    while(scanf("%d", &aux) == 1){ 
        v[n++] = aux;
    }

    mergeSort(v, 0, n-1);

    for(int i = 0; i < n; i++){
        if(i < n-1) printf("%d ", v[i]);
        else printf("%d\n", v[i]);
    }

    return 0;
}

//Merge definition
void merge(item *v, int l, int r1, int r2){
    // Two arrays
    // Array 1: l -> r1
    // Array 2: r1+1 -> r2
    item *v2 = malloc(sizeof(item)*(r2-l+1));
    int k = 0, i = l, j = r1+1;
    while(i <= r1 && j <= r2){
        if(v[i] < v[j]){
            v2[k++] = v[i++];
        }
        else {
            v2[k++] = v[j++];
        }
    }
    while(i <= r1){
        v2[k++] = v[i++];
    }
    while(j <= r2){
        v2[k++] = v[j++];
    }
    k = 0;
    for(i = l; i <= r2; i++){
        v[i] = v2[k++];
    }
    free(v2);
}

//MergeSort prototype
void mergeSort(item *v, int l, int r){
    //Sort smallest possible arrays and combine them
    if(l >= r) return;
    int h = (l+r)/2;
    mergeSort(v, l, h);
    mergeSort(v, h+1, r);
    merge(v, l, h, r);
}
