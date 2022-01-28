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
void bubbleSort(item *, int, int);
void selectionSort(item *, int, int);
void insertionSort(item *, int, int);
void merge(item *, int, int, int);
void mergeSort(item *, int, int);
int divide(item *, int, int);
void quickSort(item * , int , int );


int main(void){
    
    int n, p, x, aux, indicePagina = 0;
    item v[30000000];

    scanf("%d %d %d", &n, &p, &x);

    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        v[i] = aux;
    }
    
    //printf("PASSEI\n");
    
    quickSort(v, 0, n-1);

    for(int i = 0; i < n; i+=x){
        if(p == indicePagina){
            for(int j = i; j < i+x; j++){
                printf("%d\n", v[j]);  
            }
            break;
           
        }
        else { 
            indicePagina++;
        }
    }


	return 0; 
}

void bubbleSort(item *v, int l, int r){
    for(int i = 0; i < (r-l+1); i++){
        for(int j = l; j <= r-1; j++){
            comparelessex(v[j+1], v[j]);
        }
    }
}

void selectionSort(item *v, int l, int r){
    int min;
    while (l < r){
        min = l;
        for(int i = l; i <= r; i++){
            if(less(v[i], v[min])){
                min = i;
            }
        }
        exchange(v[l], v[min]);
        l++;
    }
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



int divide(item * v, int l, int r){
    item c = v[r];
    int j = l;

    for(int k = l; k<r ; k++){
        if(lesseq(v[k], c)){
            exchange(v[k], v[j]);
            j++;
        }
    }
    exchange(v[j], v[r]);
    return j;
}

void quickSort(item * v, int l, int r){
    
    int j;
    if(r-l <= 32){
        insertionSort(v, l, r);
    } else{
    if(r <= l){
        return;
    }
    
    comparelessex(v[(l+r)/2], v[r]);
    comparelessex(v[l], v[(l+r)/2]);
    comparelessex(v[r], v[(l+r)/2]);

    j = divide(v, l, r);

    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
    }
}


