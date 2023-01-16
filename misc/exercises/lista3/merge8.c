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

    item v[800000], indexes[8];
    int s, aux, k = 0, last;
    
    scanf("%d", &s);

    for(int i = 0; i < s; i++){
        scanf("%d", &aux);
        v[k++] = aux;
    }
    //indexes[0] = k;
    
    for(int i = 0; i < 7; i++){
        last = k-1;
        scanf("%d", &s);
        //printf("\n\nr1: %d , r2: %d\n\n", last, last+s);
        for(int j = 0; j < s; j++){
            scanf("%d", &aux);
            v[k++] = aux;
        }
        //indexes[i+1] = k;
        /*printf("v1 = { ");
        for(int z = 0; z <= last; z++){
            printf("%d ", v[z]);
        }
        printf(" }\n");
        printf("v2 = { ");
        for(int z = last+1; z <= last+s; z++){
            printf("%d ", v[z]);
        }
        printf(" }\n");*/
        merge(v, 0, last, last+s);

        /*printf("vf = { ");
        for(int z = 0; z <= last+s; z++){
            printf("%d ", v[z]);
        }
        printf(" }\n");
        */
    }
    
    //printf("totalsize = %d\n", k);

    /*for(int i = 0; i < 8; i++){
        printf("%d ", indexes[i]);
    }
    printf("\n");
    */
    for(int i = 0; i < k; i++){
        if(i < k-1) printf("%d ", v[i]);
        else printf("%d\n", v[i]);
    }

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
    for(k = l; k <= r2; k++){
        v[k] = v2[k];
    }
    free(v2);
}

//MergeSort prototype
void mergeSort(item *, int, int);
