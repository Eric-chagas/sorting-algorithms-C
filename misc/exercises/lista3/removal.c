#include <stdio.h>
#include <stdlib.h>

//Define item type for the elements which will be sorted
typedef long long unsigned int item;

//Macro to return our desired item
#define key(A) (A)

//Macro that returns if item A is less than item B | if true returns 1, else returns 0
#define less(A, B) (key(A) < key(B))

//Macro to exchange two items
#define exch(A, B) {item T = A; A = B; B = T;}

//Macro to compare AND exchange items
#define cmpexch(A, B) {if(less(A, B)) exch(A, B)}

//Merge prototype
void merge(item *, item *, item *, int, int, int);

//MergeSort prototype
void mergeSort(item *, item *, item *, int, int);

//Binary Search prototype
int binarySearch(item *, int, int, item);

int main(void) {

    item remove[250000], current[250000], prev[250000], next[250000], first[3], last[3], auxCurrent, auxPrev, auxNext;
    int k;
    
    scanf("%llx %llx %llx", &auxCurrent, &auxPrev, &auxNext);
    first[0] = auxCurrent; 
    first[1] = auxPrev;
    first[2] = auxNext;
    
    scanf("%llx %llx %llx", &auxCurrent, &auxPrev, &auxNext);
    last[0] = auxCurrent; 
    last[1] = auxPrev;
    last[2] = auxNext;
    
    k = 0;
    while(scanf("%llx %llx %llx", &auxCurrent, &auxPrev, &auxNext) == 3){
        current[k] = auxCurrent;
        prev[k] = auxPrev;
        next[k++] = auxNext;
    }
    //printf("\nK = %d\n\n", k);
    mergeSort(current, prev, next, 0, k-1);
    
    int start = binarySearch(current, 0, k-1, first[1]);
    //Get first of list
    while(prev[start]!=NULL){
        //printf("%d current: %llx\n", start, current[start]); 
        //printf("%llx %llx %llx\n", current[start], prev[start], next[start]);
        //printf("%d\n", start);
        if(binarySearch(current, 0, k-1, prev[start]) == -1){ 
            //printf("PREV IS NULL\n");
            break;
        }
        start = binarySearch(current, 0, k-1, prev[start]);
    }

    /*for(int i = 0; i < k; i++){
        printf("%llx %llx %llx\n\n", current[i], prev[i], next[i]);
    }*/
    int resolver, pos = binarySearch(current, 0, k-1, first[2]), posRemove = 0;
    item resolverNext, resolverPrev;
    remove[posRemove] = first[posRemove];
    posRemove++;
    
    while(next[pos] != last[0]){
        //printf("loop %d.\n", posRemove); 
        remove[posRemove] = current[pos];
        
        //Resolve pointers

       // resolverPrev = prev[pos];
        //resolverNext = next[pos];
        //Prev
        //resolver = binarySearch(current, 0, k-1, prev[pos]);
        //next[resolver] = resolverNext;
        
        //printf("resolverPrev: %llx, resolverNext: %llx\n", prev[resolverPrev], next[resolverNext]); 
        //printf("next of %llx: %llx\n", current[resolver], next[resolver]); 
        //Next
        //resolver = binarySearch(current, 0, k-1, next[resolver]);
        //prev[resolver] = resolverPrev;

        //Resolve pointers end
        
        prev[pos] = -231312;
        //printf("%llx %llx %llx\n", current[pos], prev[pos], next[pos]);
        //printf("pos = %d\n", pos);
        pos = binarySearch(current, 0, k-1, next[pos]);
        //printf("pos = %d\n", pos);
        //printf("inserting %llx from current[%d] in remove[%d]\n", current[pos], pos, posRemove);
        //remove[posRemove] = current[pos];
        //printf("inserted %llx from current[%d] in remove[%d]\n", current[pos], pos, posRemove);
        posRemove++;
    }
    remove[posRemove] = current[pos];
    
    //Resolve pointers

    //resolverPrev = prev[pos];
    //resolverNext = next[pos];
    //Prev
    //printf("current: %llx, resolverPrev: %llx, resolverNext: %llx\n", current[resolver], prev[resolverPrev], next[resolverNext]); 
    //printf("next of %llx: %llx\n", current[resolver], next[resolver]); 
    //resolver = binarySearch(current, 0, k-1, prev[pos]);
    //next[resolver] = resolverNext;
        
    //printf("resolverPrev: %llx, resolverNext: %llx\n", prev[resolverPrev], next[resolverNext]); 
    //printf("next of %llx: %llx\n", current[resolver], next[resolver]); 
    //Next
    //resolver = binarySearch(current, 0, k-1, next[resolver]);
    //prev[resolver] = resolverPrev;

    //Resolve pointers end
    
    prev[pos] = -231312;
    posRemove++;
    remove[posRemove++] = last[0]; 
    //printf("%d\n", start);
    while(start != -1){
        //printf("%d\n", start);
        //printf("\n%llx %llx %llx\n", current[start], prev[start], next[start]);
        if(next[start] == first[0]){
            next[start] = last[2];
        }
        if(next[start] == last[0]){
            next[start] = last[2];
        }
        if(prev[start] != -231312) {
            //printf("next: %llx\n", next[start]);
            if(next[start] == first[0]){
                //printf("next is first. last[2] = %llx\n", last[2]);
                printf("%llx %llx %llx\n", current[start], prev[start], last[2]);
            }
            else if(prev[start] == last[0]){ 
                printf("%llx %llx %llx\n", current[start], first[1], next[start]);
            }
            else { 
                printf("%llx %llx %llx\n", current[start], prev[start], next[start]);
            }
        }
        start = binarySearch(current, 0, k-1, next[start]);
    }
    printf("\n"); 
    for(int i = 0; i < posRemove; i++){
        printf("%llx\n", remove[i]);
    }

    return 0;
}

//Merge definition
void merge(item *v, item *prev, item *next, int l, int r1, int r2){
    // Two arrays
    // Array 1: l -> r1
    // Array 2: r1+1 -> r2
    
    item *v2 = malloc(sizeof(item)*(r2-l+1));
    item *v3 = malloc(sizeof(item)*(r2-l+1));
    item *v4 = malloc(sizeof(item)*(r2-l+1));
    
    int k = 0, i = l, j = r1+1;
    while(i <= r1 && j <= r2){
        if(v[i] < v[j]){
            v2[k] = v[i];
            v3[k] = prev[i];
            v4[k++] = next[i++];
        }
        else {
            v2[k] = v[j];
            v3[k] = prev[j];
            v4[k++] = next[j++];
        }
    }
    while(i <= r1){
        v2[k] = v[i];
        v3[k] = prev[i];
        v4[k++] = next[i++];
    }
    while(j <= r2){
        v2[k] = v[j];
        v3[k] = prev[j];
        v4[k++] = next[j++];
    }
    k = 0;
    for(i = l; i <= r2; i++){
        v[i] = v2[k];
        prev[i] = v3[k];
        next[i] = v4[k++];
    }
    free(v2);
    free(v3);
    free(v4);
}

//MergeSort prototype
void mergeSort(item *v, item *prev, item *next, int l, int r){
    //Sort smallest possible arrays and combine them
    if(l >= r) return;
    int h = (l+r)/2;
    mergeSort(v, prev, next, l, h);
    mergeSort(v, prev, next, h+1, r);
    merge(v, prev, next, l, h, r);
}

//Binary Search definition
int binarySearch(item *v, int l, int r, item element){
    int h = (r+l)/2;
    //printf("h: %d\n", h);
    
    //Stop condition
    if(h < 0 || l > r) {
        return -1;
    }
    else{
        if(element < v[h]){
            //printf("element(%llx) < %llx\n", element, v[h]);
            //printf("calling binarySearch(v, %d, %d, %llx)\n", l, h, element);
            return binarySearch(v, l, h-1, element);
        }
        else if(element > v[h]) {
            //printf("element(%llx) > %llx\n", element, v[h]); 
            //printf("calling binarySearch(v, %d, %d, %llx)\n", h+1, r, element);
            return binarySearch(v, h+1, r, element);
        }
        else { //element == v[h]
            return h;
        }
    }
}
