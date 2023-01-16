#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct choice {
    int size;
    char c;
    int pos;
};

//Define item type for the elements which will be sorted
typedef struct choice item;

//Macro to return our desired item
#define key(A) (A.size)

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

int main(void) {

    item v[500000], repetidos[500000];
    char s[100000];

    scanf("%s", s);
    
    int i = 0, j = 0, z = 0;
    v[j].size += 1;
    v[j].c = s[i];
    v[j].pos = i;
    repetidos[j].size += 1;
    repetidos[j].c = s[i];
    repetidos[j].pos = i;
    i++;
    while(s[i] != '\n'){
        if(s[i-1] == '\n' || s[i-1] == '\0') break;
        if(s[i] == s[i-1]){
            v[j].size++;
            repetidos[j].size++;
        }
        else if(s[i] != s[i-1]){
            j++;
            v[j].size += 1;
            v[j].c = s[i];
            v[j].pos = i;
            repetidos[j].size += 1;
            repetidos[j].c = s[i];
            repetidos[j].pos = i;
        }
        i++;
    }
    //printf("\n\nj=%d\n\n", j);
    introSort(v, 0, j-1);

    int k = j-1;
    while(k >= 0){
        if(v[k].size == v[k-1].size && k > 0){
            int l = k, aux = 0, sizeRepetido = v[l].size;
            while(v[l].size == sizeRepetido){
                aux++;
                l--;
            }
            int n = 0;
            while(repetidos[n].size != sizeRepetido){
                n++; 
            }
            while(repetidos[n].size == sizeRepetido){ 
                printf("%d %c %d\n", repetidos[n].size, repetidos[n].c, repetidos[n].pos);
                n++;
            }
            k = k-aux;
        }
        //else if(k <= 0){
        //    printf("%d %c %d\n", v[0].size, v[0].c, v[0].pos);
        //}
        else{
            printf("%d %c %d\n", v[k].size, v[k].c, v[k].pos);
            k--;
        }
    }
    /*for(int k = j-1; k > 0; k--){
        if(v[k].size == v[k-1].size){
            int aux = 0, l = k, sizeRepetido = v[k].size;
            while(v[l].size == sizeRepetido){
                printf("repetido: %d %c %d\n", v[k].size, v[k].c, v[k].pos);
                aux++;
                l++;
                printf("\n\n Aux: %d\n\n", aux);
            }
            
            introSort(v, l-aux, l);
           for(l = k-aux; l < aux; l++){
               printf("%d %c %d\n", v[l].size, v[l].c, v[l].pos);
           }
        }
        else{
            //printf("%d %c %d\n", v[k].size, v[k].c, v[k].pos);
        }
    }*/

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
    if(r-l <= 32) return;
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
        if(key(v[i]) < key(v[j])){
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
