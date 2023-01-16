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
void insertionSort(item *, int, int);
void merge(item *, int, int, int);
void mergeSort(item *, int, int);


int main(void){
    
    int n, aux, sum = 0;
    item v[100000];
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &aux);
        v[i] = aux;
    }

    mergeSort(v, 0, n-1);
    aux = -1;
    for(int i = 0; i < n; i++){
        if(v[i] != aux){
            aux = v[i];
            sum++;
        }
    }

    printf("%d\n", sum);

	return 0; 
}


void insertionSort(item *v, int l, int r){
    item tmp;
    int j;
    for(int i = r; i>l; i--){
        comparelessex(v[i], v[i-1]);
    }
    for(int i = l+2; i<=r; i++){
        tmp = v[i], j=i;
        while(less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

void merge(item *v, int l, int r1, int r2){
    int ia = l, ib = r1+1, k = 0;
    item *v2 = (int *)malloc(sizeof(int)*(r2-l+1));
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




