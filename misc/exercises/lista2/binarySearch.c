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

//Binary Search prototype
int binarySearch(item[50000] , int, int, int);

int main(void) {

    item v[50000];
    for(int i = 0; i < 10; i++){
        v[i] = i;
    }
    
   /* for(int i = 0; i < 50000; i++){
        printf("%d\n", v[i]);
    }
    printf("\n");
    */
    
    shellSort(v, 0, 9);

    for(int i = 0; i < 10; i++){
        printf("%d\n", v[i]);
    }
    printf("\n");

    int t = binarySearch(v, 0, 9, 7);
    
    printf("%d\n", t);

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
int binarySearch(item v[50000], int l, int r, int element){
    int h = (r+l)/2;
    printf("h: %d\n", h);
    
    //Stop condition
    if(h <= 0 || l > r) {
        return -1;
    }
    else{
        if(element < v[h]){
            printf("element(%d) < %d\n", element, v[h]);
            printf("calling binarySearch(v, %d, %d, %d)\n", l, h, element);
            binarySearch(v, l, h, element);
        }
        else if(element > v[h]) {
            printf("element(%d) > %d\n", element, v[h]); 
            printf("calling binarySearch(v, %d, %d, %d)\n", h+1, r, element);
            binarySearch(v, h+1, r, element);
        }
        else if(element == v[h]) {
            return h;
        }
    }
}
