#include <iostream>
using namespace std;

void init(int V, int g[100][100]) {
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            g[i][j] = 0;
        }
    }
}

void addEdge(int g[100][100], int u, int v) {
    g[u-1][v-1] = 1;
    g[v-1][u-1] = 1;
}

void addDirectedEdge(int g[100][100], int u, int v) {
    g[u-1][v-1] = 1;
}

void print(int V, int g[100][100]) {
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cout << g[i][j] << "   ";
        }
        cout << "\n";
    }
}
int main() {
    int gA[100][100];
    init(8, gA);
    addEdge(gA, 1, 2);
    addEdge(gA, 1, 3);
    addEdge(gA, 1, 5);
    addEdge(gA, 2, 4);
    addEdge(gA, 2, 6);
    addEdge(gA, 3, 4);
    addEdge(gA, 3, 6);
    addEdge(gA, 3, 7);
    addEdge(gA, 4, 5);
    addEdge(gA, 4, 8);
    addEdge(gA, 5, 6);
    addEdge(gA, 5, 7);
    addEdge(gA, 6, 8);
    addEdge(gA, 7, 8);

    int gB[100][100];
    init(8, gB);
    addDirectedEdge(gB, 1, 2);
    addDirectedEdge(gB, 1, 3);
    addDirectedEdge(gB, 1, 5);
    addDirectedEdge(gB, 2, 6);
    addDirectedEdge(gB, 3, 4);
    addDirectedEdge(gB, 3, 6);
    addDirectedEdge(gB, 3, 7);
    addDirectedEdge(gB, 4, 2);
    addDirectedEdge(gB, 4, 5);
    addDirectedEdge(gB, 4, 8);
    addDirectedEdge(gB, 5, 6);
    addDirectedEdge(gB, 6, 8);
    addDirectedEdge(gB, 7, 5);
    addDirectedEdge(gB, 7, 8);

    int gC[100][100];
    init(9, gC);
    addDirectedEdge(gC, 1, 2);
    addDirectedEdge(gC, 3, 1);
    addDirectedEdge(gC, 3, 4);
    addDirectedEdge(gC, 4, 5);
    addDirectedEdge(gC, 5, 7);
    addDirectedEdge(gC, 5, 8);
    addDirectedEdge(gC, 6, 5);
    addDirectedEdge(gC, 7, 3);
    addDirectedEdge(gC, 7, 9);
    addDirectedEdge(gC, 8, 6);

    print(8, gA);
    cout << "\n\n\n";
    print(8, gB);
    cout << "\n\n\n";
    print(9, gC);
    cout << "\n\n\n";
    return 0;
}