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

int n;
int g_cost[10][10];
int visited[10];
LinkQueue Q;

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

int BFS(int v) {
    int u;
    cout << v << "\n";
    visited[v] = 1;
    EnQueue(&Q, v);

    while(!EmptyQueue(&Q)) {
        DeQueue(&Q, &u);
        for (int i = 0; i < n; ++i) {
            if (visited[i] != 1 && g_cost[u][i] != 0) {
                cout << i << "\n";
                visited[i] = 1;
                EnQueue(&Q, i);
            }
        }
    }
}

int main() {
    int i, j, k, l, v;
    int e;
    cout << "enter no of vertices\n";
    cin >> n;
    cout << "inter no of edges\n";
    cin >> e;
    cout << "EDGES\n";


    for (k = 1; k <= e; k++) {
        for (l = 1; l <= e; l++) {
            g_cost[k][l] = 0;
        }
    }

    for (k = 0; k < e; k++) {
        cin >> i >> j;
        g_cost[j][i] = g_cost[i][j] = 1;
    }

    cout << "enter initial vertices\n";
    cin >> v;
    cout << "order of visited vertices\n";

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    initQueue(&Q);

    BFS(v);
    for (i = 0; i < n; ++i) {
        if (i != v && visited[i] != 1)
            BFS(i);
    }
}

/*
enter no of vertices
8
inter no of edges
9
EDGES
0 1
0 2
1 3
1 4
2 5
2 6
3 7
4 7
5 6
enter initial vertices
2
order of visited vertices
2
0
5
6
1
3
4
7
 */