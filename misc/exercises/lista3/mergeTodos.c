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

    item v[100000], v2[100000], *v3;
    int s, aux, previousEnd; 

    scanf("%d", &s);
    k += s-1;
    for(int i = 0; i < s; i++){
        scanf("%d", &aux);
        v[i] = aux;
    }
    previousEnd = s-1;
    for(int i = 0; i < 7; i++){
        scanf("%d", &s);
        for(int j = 0; j < s; j++){
            scanf("%d", &aux);
            v2[j] = aux;
        }

        
        printf("k = %d\n", k);
    }
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
