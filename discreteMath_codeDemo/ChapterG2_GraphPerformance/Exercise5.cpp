// Xay dung ma tran trong so cua cac do thi da cho
#include <iostream>
using namespace std;

void init(int V, int g[100][100]){
    for(int i=0;i<V; i++) {
        for(int j=0; j<V; j++) {
            g[i][j] = 0;
        }
    }
}

void addEdge(int g[100][100], int u, int v, int c) {
    g[u-1][v-1] = g[v-1][u-1] = c;
}

void addDirectedEdge(int g[100][100], int u, int v, int c) {
    g[u-1][v-1] = c;
}

void print(int V, int g[100][100]) {
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            printf("%5d", g[i][j]);
        }
        cout << "\n";
    }
}

int main() {
    int V, E, i, ans;
    cout << "Nhap vao so dinh cua do thi: ";
    cin >> V;
    cout << "Nhap vao so canh cua do thi: ";
    cin >> E;
    int u[E], v[E], c[E];
    int g[100][100];
    init(V, g);

    cout << "Do thi da cho co phai do thi co huong khong (1/0): ";
    cin >> ans;

    cout << "Nhap vao danh sach canh va trong so: \n";
    for(i=0; i<E; i++) {
        cin >> u[i] >> v[i] >> c[i];
    }

    if(ans == 1) {
        for(i=0; i<E; i++) {
            addDirectedEdge(g, u[i], v[i], c[i]);
        }
    } else {
        for(i=0; i<E; i++) {
            addEdge(g, u[i], v[i], c[i]);
        }
    }

print(V, g);

    return 0;
}