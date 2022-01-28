#include <stdlib.h>
#include <stdio.h>

typedef int item;

//Macros
#define key(A)(A) 
#define less(A, B)(key(A) < key(B))
#define lesseq(A,B)(key(A) <= key(B))
#define exchange(A,B){item aux=A; A=B; B=aux;}
#define comparelessex(A,B){if(less(A,B)) exchange(A,B);}


//Functions
void merge(item *, int, int, int);
void mergeSort(item *, int, int);


int main(void){
    item v[6] = {7, 3, 2, 5, 4, 3};
    /*
    for(int i = 0; i < 10; i++){
        scanf("%d", &aux);
        v[i] = aux;
    } 
    */
    mergeSort(v, 0, 5);
    
    for(int i = 0; i < 6; i++){
        printf("v[%d] = %d\n", i, v[i]);
    }
    
	return 0; 
}


void merge(item *v, int l, int r1, int r2){
    int ia = l, ib = r1+1, k = 0;
    item *v2 = malloc(sizeof(int)*(r2-l+1));
    while(ia <= r1 && ib <= r2){
        if(less(v[ia], v[ib])){
            v2[k++] = v[ia++];
        }
        else{
            v2[k++] = v[ib++];
        }
    }
    if(ia > r1){
        while(ib <= r2){
            v2[k++] = v[ib++];
        }
    }
    else if(ib > r2){
        while(ia <= r1){
            v2[k++] = v[ia++];
        }
    }
    k = 0;
    for(int i = l; i <= r2; i++){
        v[i] = v2[k++];
    }
    
    free(v2);
}


void mergeSort(item *v, int l, int r){
    if(l >= r) return;
    int m = (r+l)/2;
    mergeSort(v, l, m);
    mergeSort(v, m+1, r);
    
    merge(v, l, m, r);
    //l++;
    
}




