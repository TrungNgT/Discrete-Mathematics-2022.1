/* Le Van Son 20210752 - Nguyen Thanh Trung 20215492
    Thuat toan Kruskal su dung HeapSort (do phuc tap O(ElogE)) de sap xep trong so cac canh
    va kiem tra chu trinh bang DFS (do phuc tap O(V+E))

    Tong cong: O(ElogE + E(V+E)).
*/

#include <bits/stdc++.h>
using namespace std;

int V, E;
int u[1001], v[1001], w[1001], visited[1001], parent[1001], choose[1001];      // u la dinh dau, v la dinh cuoi cua canh (u,v)
                                                                        // w la trong so canh (u,v) 
int value = 0;                                                          // do dai MST
                                                
vector<int> adj[1001];                                       // danh sach dinh ke 

vector<int> u1, v1;                                    // do thi G1 chua cac canh duoc nap; dung G1 de kiem tra chu trinh

void input() {
    cin >> V >> E;
    for(int i=0; i<E; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
            // arr1 tuong ung u; arr2 tuong ung v, arr3 tuong ung w
void Heapify(int arr1[], int arr2[], int arr3[],  int N, int i) {   // day la ham doi cho khi nut con lon hon nut cha
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<N && arr3[left]>arr3[largest]) largest = left;          // so sanh trong so nut cha va nut con
    if(right<N && arr3[right]>arr3[largest]) largest = right;
    if(largest != i) {
        Swap(&arr3[i], &arr3[largest]);                             // doi cho 2 trong so tren cay heap
        Swap(&arr1[i], &arr1[largest]);                             // doi cho 2 dinh dau tuong ung 
        Swap(&arr2[i], &arr2[largest]);                             // doi cho 2 dinh cuoi tuong ung
        Heapify(arr1, arr2, arr3, N, largest);                      // tiep tuc di sau xuong duoi
    }
}

    // thuat toan HeapSort chi quan tam w, nhung phai swap 3 lan de thay doi u, v tuong ung

void HeapSort(int arr1[], int arr2[], int arr3[], int N) {   
    // xay dung cay heap
    for(int i=N/2; i>=0; i--) {
        Heapify(arr1, arr2, arr3, N, i);
    }
    // bat dau sort: 
    for(int i=N-1; i>= 0; i--) {
        Swap(&arr3[0], &arr3[i]);
        Swap(&arr1[0], &arr1[i]);
        Swap(&arr2[0], &arr2[i]);
        Heapify(arr1, arr2, arr3, i, 0);  
    }
}

int DetectCycle(int x) {                    // su dung DFS de kiem tra chu trinh, bat dau tu dinh x
    visited[x] = 1;
    for(int y : adj[x]) {
        if(visited[y] == 0) {
            parent[y] = x;
            if(DetectCycle(y) == 1) return 1;   // neu cay xuat phat tu y co chu trinh

        }
        else if(y != parent[x]) return 1;       // xuat hien canh nguoc
    }
    return 0;                                   
}

void Kruskal() {
    HeapSort(u, v, w, E);
    int nE=0;
    
    for(int i=0; i<E; i++) {
        u1.push_back(u[i]);                     // nap dinh dau cua canh (u[i], v[i]) vao tap u1 cac dinh dau cua G1
        v1.push_back(v[i]);                     // nap dinh cuoi cua canh (u[i], v[i]) vao tap v1 cac dinh cuoi cua G1
        adj[u[i]].push_back(v[i]);              // them v[i] vao danh sach ke cua u[i] trong G1
        adj[v[i]].push_back(u[i]);              // them u[i] vao danh sach ke cua v[i] trong G1
        memset(visited, 0, sizeof(visited));       // set tat ca visited := 0
        if(DetectCycle(u1[0]) == 0) {               // kiem tra G1 co chu trinh hay khong, xuat phat tu u1[0].
            value += w[i];                          // neu khong co chu trinh thi nap canh.
            choose[i] = 1;                          // danh dau canh duoc chon
            nE ++;
        }
        else {                                      // neu G1 co chu trinh
            u1.pop_back();                          // loai u[i] khoi u1, loai v[i] khoi v1         
            v1.pop_back();
            adj[u[i]].pop_back();                   // loai bo v[i] khoi danh sach ke u[i] va nguoc lai
            adj[v[i]].pop_back();
        }
        memset(visited, 0, sizeof(visited));        // set lai tat ca visited <-  0   
        if(nE == V-1) break;                        // khi cay co du |V|-1 canh thi dung
    }
}

void output() {
    cout << "Do dai MST = " << value;
    cout << "\nDanh sach canh cua MST: \n";
    for(int i=0; i<E; i++) {
        if(choose[i] == 1) cout << u[i] << "   " << v[i] << "\n";
    }
}

int main() {
    input();
    Kruskal();
    output();

    return 0;
}