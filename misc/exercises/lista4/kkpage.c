#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define item type for the elements which will be sorted
typedef long int item;

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

//Merge prototype
void merge(item *, int, int, int);

//MergeSort prototype
void mergeSort(item *, int, int);

// Partition function prototype
int partition(item *, int, int);

// Quick Sort prototype
void quickSort(item *, int, int, int);

// Intro sort prototype
void introSort(item *, int, int);

//Insertion Sort H and shell Sort prototypes
void insertionSortH(item *, int, int, int);
void shellSort(item *, int, int);

//Selection Sort prototype
void selectionSort(item *, int, int);

int main(void) {

    int n, x, p; 
    //long int aux;
    item v[10000000];

    scanf("%d %d %d", &n, &p, &x);

    for(int i = 0; i < n; i++){
        scanf("%ld", &v[i]);
        //if(i >= (x*p) && i < ((x*p)+x)){
        //    kkpage[k++] = aux;        
        //}
        //v[i] = aux;
    }

    introSort(v, 0, n-1);

    for(int i = x*p; i < (x*p)+x; i++){
        if (i == n) break;
        else printf("%ld\n", v[i]); 
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

int quickTrapStop = 0;
// Quick Sort impl
void quickSort(item *v, int l, int r, int recLimit){
    if(quickTrapStop == 1) return;
    if(recLimit == 0) {
        quickTrapStop = 1;
        return;
    }
    if(r-l <= 20) return;
    exch(v[r-1], v[(l+r)/2]);
    cmpexch(v[l], v[r-1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r-1], v[r]);
    int pivot = partition(v, l, r);
    quickSort(v, l, pivot-1, recLimit-1);
    quickSort(v, pivot+1, r, recLimit-1);
}

//Insertion Sort definition
void insertionSort(item *v, int l, int r){
    for(int i = r; i > l; i--){
        cmpexch(v[i], v[i-1]);
    }

    for(int i = l+2; i<=r; i++) {
        int j = i;
        item temp = v[j];
        while(less(temp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }
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

//MergeSort definition
void mergeSort(item *v, int l, int r){
    //Sort smallest possible arrays and combine them
    if(l >= r) return;
    int h = (l+r)/2;
    mergeSort(v, l, h);
    mergeSort(v, h+1, r);
    merge(v, l, h, r);
}

// Intro sort prototype
void introSort(item *v, int l, int r){
    int recLimit = (int)(2*log2((r-l+1)));
    quickSort(v, l, r, recLimit);
    if(quickTrapStop == 1){
        mergeSort(v, l, r);
    }
    else{
        insertionSort(v, l, r);
    }
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

//Selection Sort definition
void selectionSort(item *v, int l, int r){
    if(l == r) return;
    int min = l;
    for(int j = l+1; j <= r; j++){
        if (less(v[j], v[min])){
            min = j;
        }
    }
    exch(v[min], v[l]);
    selectionSort(v, l+1, r);
}
