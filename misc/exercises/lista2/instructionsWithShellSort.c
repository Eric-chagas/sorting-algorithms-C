#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void insertionSortH(item *, char (*)[16], int, int, int);
void shellSort(item *, char (*)[16], int, int);

//Binary Search definition
int binarySearch(item v[100000], int, int, int);

int main(void) {

    int n, v[100000], aux, i, element;
    char s[100000][16], auxStr[16];

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d %s", &aux, auxStr);
        v[i] = aux;
        strcpy(s[i], auxStr);
    }

    shellSort(v, s, 0, n-1);
    
    while(scanf("%d", &aux) == 1){
        element = binarySearch(v, 0, n-1, aux);
        if(element == -1) printf("undefined\n");
        else printf("%s\n", s[element]);
    }

    /*   
    while(scanf("%d", &aux) == 1){
        i = 0;
        //printf("i = 0 OK\n");
        
        //Search in array
        while(aux != v[i] && i < n){
            //printf("v[%d]: %d, aux: %d\n", i, v[i], aux); 
            i++;
        }
        if(aux != v[i]) printf("undefined\n");
        else printf("%s\n", s[i]); 
    }
*/
/*    for(i = 0; i < n; i++){
        printf("v[%d]: %d, s[%d]:  %s\n", i, v[i], i, s[i]);
    }
  */  
    
    return 0;
}

//Insertion Sort H and shell Sort definition
void insertionSortH(item *v, char (*s)[16], int l, int r, int h){
    for(int i = l+h; i<=r; i++) {
        int j = i;
        int tempInt = v[j];
        char tempStr[16];
        strcpy(tempStr, s[j]);
        while(less(tempInt, v[j-h]) && j >= l+h){
            v[j] = v[j-h];
            strcpy(s[j], s[j-h]);
            j-=h;
        }
        v[j] = tempInt;
        strcpy(s[j], tempStr);
    }
}

void shellSort(item *v, char (*s)[16], int l, int r){
    int h;
    for(h = 1; h <= r-l; h=3*h+1){
    }
    for (; h > 0; h=h/3) {
        insertionSortH(v, s, l, r, h);
    }

}

//Binary Search definition
int binarySearch(item v[100000], int l, int r, int element){
    if (r >= l) {
        int h = l+((r-l)/2);
        //printf("h: %d, %d\n", h, v[h]);
        //printf("%d = %d\n", element, v[h]);
        //printf("%d", element == v[h]);
        if(v[h] == element) {
            return h;
        }
        if(v[h] > element){
            //printf("element(%d) < %d\n", element, v[h]);
            //printf("calling binarySearch(v, %d, %d, %d)\n", l, h, element);
           return binarySearch(v, l, h-1, element);
        }
        //printf("element(%d) > %d\n", element, v[h]); 
        //printf("calling binarySearch(v, %d, %d, %d)\n", h+1, r, element);
        return binarySearch(v, h+1, r, element);
    }
    return -1;
}


