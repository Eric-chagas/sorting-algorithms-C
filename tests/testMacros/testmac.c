#include <stdio.h>

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

int main(void) {

    item a, b;

    printf("Insert the value of A and B:\n");

    scanf("%d %d", &a, &b);

    printf("You have defined two elements: %d and %d\n\n", key(a), key(b));
    
    //Testing less
    for(int i = 0; i < 40; i++){ printf("*"); }; printf("\n");
    printf("less(A, B) = %d\n", less(a, b));
    for(int i = 0; i < 40; i++){ printf("*"); }; printf("\n");
    
    printf("\n");

    //Testing exch
    for(int i = 0; i < 40; i++){ printf("*"); }; printf("\n"); 
    printf("A: %d B: %d\n\n", key(a), key(b));
    printf("running exch(A, B)...\n\n");
    exch(a, b);
    printf("A: %d B: %d\n", key(a), key(b));
    for(int i = 0; i < 40; i++){ printf("*"); }; printf("\n");
 
    printf("\n");

    //Testing cmpexch
    for(int i = 0; i < 40; i++){ printf("*"); }; printf("\n"); 
    printf("A: %d B: %d\n\n", key(a), key(b));
    printf("running cmpexch(A, B)...\n\n");
    cmpexch(a, b);
    printf("A: %d B: %d\n", key(a), key(b));
    for(int i = 0; i < 40; i++){ printf("*"); }; printf("\n");


    return 0;
}
