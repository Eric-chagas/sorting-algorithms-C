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
    int s, aux, l1, r1, l2, r2, totalsize;

    scanf("%d", &s);
    for(r1 = 0; r1 < s; r1++){
        scanf("%d", &aux);
        v[r1] = aux;
    }
    scanf("%d", &s);
    for(r2 = 0; r2 < s; r2++){
        scanf("%d", &aux);
        v2[r2] = aux;
    }
    
    totalsize = (r2-0) + (r1-0);

    v3 = merge2(v, v2, 0, r1-1, 0, r2-1);

    for(r1 = 0; r1 < totalsize; r1++){
        printf("%d ", v3[r1]);
    }
    printf("\n");

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
