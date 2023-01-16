#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define item type for the elements which will be sorted
typedef char item;

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

int main(void) {
    
    int n, sum[100], sumIndex = 0, j;
    char s[100];

    scanf("%d", &n);
        
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        int size = strlen(s);
        j = 0;
        shellSort(s, 0, size-1);
        sum[sumIndex] = 0;
        while(s[j] <=57 && s[j] >= 48){
             sum[sumIndex] += s[j]-48;
             j++;
        }
        sumIndex++;
    }
    
    for(int i = 0; i < n; i++){
        printf("%d\n", sum[i]);
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



