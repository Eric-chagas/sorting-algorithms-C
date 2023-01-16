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

    int v[100];

    for(int i = 0; i < 15; i++){
        v[i] = rand();
    }
    
    printf("v1: {");
    for(int i = 0; i < 10; i++){
        if(i < 9) printf("%d, ", v[i]);
        else printf("%d", v[i]);
    }
    printf("}\n");
    
    printf("v2: {");
    for(int i = 10; i < 15; i++){
        if(i < 14) printf("%d, ", v[i]);
        else printf("%d", v[i]);
    }
    printf("}\n");

    merge(v, 0, 9, 9);


    printf("vf: {");
    for(int i = 0; i < 10; i++){
        if(i < 9) printf("%d, ", v[i]);
        else printf("%d", v[i]);
    }
    printf("}\n");

    return 0;
}


//Merge definition
void merge(item *v, int l, int r1, int r2){
    // Two arrays
    // Array 1: l -> r1
    // Array 2: r1+1 -> r2
    item *v2 = malloc(sizeof(int)*(r2-l+1));
    int k = 0, i = l, j = r1+1;
    while(k <= r2){
        if(i <= r1 && j <= r2){
            if(v[i] < v[j]){
                v2[k++] = v[i++];
            }
            else {
                v2[k++] = v[j++];
            }
        } 
        else {
            if(i > r1){
                v2[k++] = v[j++];
            }
            else{
                v2[k++] = v[i++];
            }
        }
    }
    for(k = l; k < r2; k++){
        v[k] = v2[k];
    }
    free(v2);
}

//MergeSort prototype
void mergeSort(item *, int, int);
