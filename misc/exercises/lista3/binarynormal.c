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

//Merge prototype
void merge(item *, item*, int, int, int);

//MergeSort prototype
void mergeSort(item *, item *, int, int);

//Binary Search prototype
int binarySearch(item *, int, int, int);

int main(void) {

    item v[50000], pos[900000];
    int n, m, aux, j;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        v[i] = aux;
        pos[i] = i;
    }
    
    mergeSort(v, pos, 0, n-1);
    //shellSort(v, 0, n-1);
    
    for(int i = 0; i < m; i++){
        scanf("%d", &aux);
        j = binarySearch(v, 0, n-1, aux);
        if(j != -1){
            printf("%d\n", pos[j]);
        }
        else {
            printf("%d\n", j);
        }
    }
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

//Binary Search definition
int binarySearch(item *v, int l, int r, int element){
    int h = (r+l)/2;
    //printf("h: %d\n", h);
    
    //Stop condition
    if(h < 0 || l > r) {
        return -1;
    }
    else{
        if(element < v[h]){
            //printf("element(%d) < %d\n", element, v[h]);
            //printf("calling binarySearch(v, %d, %d, %d)\n", l, h, element);
            return binarySearch(v, l, h-1, element);
        }
        else if(element > v[h]) {
            //printf("element(%d) > %d\n", element, v[h]); 
            //printf("calling binarySearch(v, %d, %d, %d)\n", h+1, r, element);
            return binarySearch(v, h+1, r, element);
        }
        else {
            return h;
        }
    }
}
//Merge definition
void merge(item *v, item *pos, int l, int r1, int r2){
    // Two arrays
    // Array 1: l -> r1
    // Array 2: r1+1 -> r2
    item *v2 = malloc(sizeof(item)*(r2-l+1));
    item *vpos = malloc(sizeof(item)*(r2-l+1));
    int k = 0, i = l, j = r1+1;
    while(i <= r1 && j <= r2){
        if(v[i] < v[j]){
            v2[k] = v[i];
            vpos[k++] = pos[i++];
        }
        else {
            v2[k] = v[j];
            vpos[k++] = pos[j++];
        }
    }
    while(i <= r1){
        v2[k] = v[i];
        vpos[k++] = pos[i++];
    }
    while(j <= r2){
        v2[k] = v[j];
        vpos[k++] = pos[j++];
    }
    k = 0;
    for(i = l; i <= r2; i++){
        v[i] = v2[k];
        pos[i] = vpos[k++];
    }
    free(v2);
    free(vpos);
}

//MergeSort prototype
void mergeSort(item *v, item *pos, int l, int r){
    //Sort smallest possible arrays and combine them
    if(l >= r) return;
    int h = (l+r)/2;
    mergeSort(v, pos, l, h);
    mergeSort(v, pos, h+1, r);
    merge(v, pos, l, h, r);
}
