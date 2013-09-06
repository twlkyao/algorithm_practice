#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr rear;
    QueuePtr front;
} LinkQueue;

int initQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
        return 0;
    Q->front->next = NULL;
    return 1;
}

int EnQueue(LinkQueue *Q, int e) {
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        return 0;
    p->data = e;
    p->next = NULL;

    Q->rear->next = p;
    Q->rear = p;

    return 1;
}

int DeQueue(LinkQueue *Q, int *e) {
    QueuePtr p;
    if (Q->front == Q->rear)
        return 0;

    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;

    if (Q->rear == p)
        Q->rear = Q->front;
    free (p);

    return 1;
}

int EmptyQueue(LinkQueue *Q) {
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

int main() {
    LinkQueue Q;
    int i, Result;
    char in;

    initQueue(&Q);

    while((in = getchar()) != EOF) {
            i = atoi(&in);
            EnQueue(&Q, i);
    }

    cout << "\n";
    while(!EmptyQueue(&Q)) {
        DeQueue(&Q, &Result);
        cout << Result << "\n";
    }

}