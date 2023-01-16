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
item * merge2(item *, item *, int, int, int, int);

//MergeSort prototype
void mergeSort(item *, int, int);

int main(void) {

    item v[100], v2[100], *v3;

    for(int i = 0; i < 15; i++){
        v[i] = rand();
        v2[i] = rand();
    }
    
    printf("v1: {");
    for(int i = 0; i < 15; i++){
        if(i < 14) printf("%d, ", v[i]);
        else printf("%d", v[i]);
    }
    printf("}\n");
    
    printf("v2: {");
    for(int i = 0; i < 15; i++){
        if(i < 14) printf("%d, ", v2[i]);
        else printf("%d", v2[i]);
    }
    printf("}\n");

    v3 = merge2(v, v2, 0, 14, 0, 14);


    printf("vf: {");
    for(int i = 0; i < 30; i++){
        if(i < 29) printf("%d, ", v3[i]);
        else printf("%d", v3[i]);
    }
    printf("}\n");

    return 0;
}


//Merge definition
item * merge2(item *v, item *v3, int l1, int r1, int l2, int r2){
    int totalSize = (r2-l2+1) + (r1-l1+1);
    item *v2 = malloc(sizeof(int)*(totalSize));
    int k = 0, i = l1, j = l2;
    while(k <= totalSize){
        if(i <= r1 && j <= r2){
            if(v[i] < v3[j]){
                v2[k++] = v[i++];
            }
            else {
                v2[k++] = v3[j++];
            }
        } 
        else {
            if(i > r1){
                v2[k++] = v3[j++];
            }
            else{
                v2[k++] = v[i++];
            }
        }
    }
    /*for(k = 0; k < totalSize; k++){
        v[k] = v2[k];
    }*/
    return v2;
}

//MergeSort prototype
void mergeSort(item *, int, int);
