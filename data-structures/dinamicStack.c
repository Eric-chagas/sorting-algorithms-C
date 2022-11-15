#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    struct cell *next;
    int data;
} cell;

typedef struct stack {
    struct cell *top;
} stack;

void initStack();
void push(stack *, int);
int pop(stack *);
void printStack(stack *);

int main() {

    struct stack *s = (stack*) malloc(sizeof(stack));

    initStack(s);
    printStack(s);

    push(s, 10);
    push(s, 15);
    push(s, 21);
    push(s, 13);

    printStack(s);

    pop(s);
    pop(s);

    printStack(s);

    return 0;
}

void initStack(stack *s) {
    s->top = NULL;
}

void push(stack *s, int x) {
    struct cell *element = (cell*) malloc(sizeof(cell));
    element->data = x;
    element->next = s->top;
    s->top = element;
}

int pop(stack *s) {
    if(s->top == NULL) {
        printf("Empty stack.\n");
        return 0;
    }
    else {
        struct cell *element = s->top;
        int data;
        s->top = element->next;
        data = element->data;
        free(element);
        return data;
    }
}

void printStack(stack *s) {
    if(s->top == NULL) {
        printf("Empty stack.\n");
    }
    else {
        struct cell *element = s->top;
        while(element->next != NULL){
            printf("%d -> ", element->data);
            element = element->next;
        }
        printf("%d -> NULL\n", element->data);
    }
}