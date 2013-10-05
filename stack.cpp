#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
}node;

typedef struct stack {
    struct node *base;
    struct node *top;
}stack;

int initStack(stack *S) {
    S->base = S->top = (node *)malloc(sizeof(node));
    if (!S->base)
        return 0;
    S->base->next = NULL;
    return 1;
}

int push(stack *S, int *x) {
    node *p;
    p = (node *)malloc(sizeof(node));
    if (!p)
        return 0;
    p->data = *x;
    p->next = S->top;
    S->top = p;
    return 1;
}

int pop(stack *S, int *x) {
    node *p;
    if (S->top == S->base)
        return 0;
    p = S->top;
    *x = p->data;
    S->top = p->next;
    free(p);
    return 1;
}

int getTop(stack *S, int *x) {
    if (S->top == S->base)
        return 0;
    *x = S->top->data;
    return 1;
}

int destroyStack(stack *S) {
    while (S->top) {
        S->base = S->top->next;
        free(S->top);
        S->top = S->base;
    }
    return 1;
}

int emptyStack(stack *S) {
    if (S->top == S->base)
        return 1;
    else
        return 0;
}

int main() {
    stack S;
    int i, result;

    initStack(&S);

    while (scanf("%d", &i) != EOF) {
        push(&S, &i);
    }

    // destroyStack(&S);

    cout << "\n";

    while(!emptyStack(&S)) {
        pop(&S, &result);
        cout << result << "\n";
    }

    destroyStack(&S);
}