#include<iostream>
#include<stdlib.h>
using namespace std;

int n;
int g_cost[10][10];
int visited[10];

void DFS(int v) {
    int i;

    visited[v] = 1;
    cout << v;

    for (i = 0; i < n; i++)
        if (i != v && g_cost[v][i] != 0 && !visited[i])
            DFS(i);
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

    DFS(v);
    for (i = 0; i < n; i++) {
        if (!visited[i] && i != v)
            DFS(i);
    }

    cout << "\n";
}

/*
  enter no of vertices
  8
  inter no of edges
  9
  EDGES
  0 1
  1 3
  1 4
  2 5
  2 0
  3 7
  4 7
  6 5
  6 2
  enter initial vertices
  0
  order of visited vertices
  01374256
*/