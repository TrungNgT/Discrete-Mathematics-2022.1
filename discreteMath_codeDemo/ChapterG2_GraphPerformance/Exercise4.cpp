// xay dung cac ma tran lien thuoc dinh canh
#include <iostream>
using namespace std;

void init(int V, int E, int g[100][100] ) {
    for(int i=0; i<V; i++) {
        for(int j=0; j<E; j++) {
            g[i][j] = 0;
        }
    }
}

void addEdge(int order, int g[100][100], int u, int v) {
    g[u-1][order] = g[v-1][order] = 1;
}

void addDirectedEdge(int order, int g[100][100], int u, int v) {
    g[u-1][order] = 1;
    g[v-1][order] = -1;
}

void print(int V, int E, int g[100][100]) {
    for(int i=0; i<V; i++) {
        for(int j=0; j<E; j++) {
            printf("%5d", g[i][j]);
        }
        cout << "\n";
    }
}

int main() {
    int V_A = 4, E_A = 6;
    int gA[100][100];
    init(V_A, E_A, gA);
    addEdge(0, gA, 1, 2);
    addEdge(1, gA, 1, 3);
    addEdge(2, gA, 1, 4);
    addEdge(3, gA, 2, 3);
    addEdge(4, gA, 2, 4);
    addEdge(5, gA, 3, 4);
    cout << "Ma tran lien thuoc dinh - canh cua do thi A la: \n";
    print(V_A, E_A, gA);

    int V_B = 4, E_B = 5;
    int gB[100][100];
    init(V_B, E_B, gB);
    addDirectedEdge(0, gB, 1, 4);
    addDirectedEdge(1, gB, 2, 1);
    addDirectedEdge(2, gB, 2, 4);
    addDirectedEdge(3, gB, 3, 2);
    addDirectedEdge(4, gB, 4, 1);
    cout <<"Na tran lien thuoc dinh - canh cua do thi B la: \n";
    print(V_B, E_B, gB);
    return 0;
}