/* Le Van Son 20210752 - Nguyen Thanh Trung 20215492
    Thuat toan Kruskal su dung HeapSort (do phuc tap O(ElogE)) de sap xep trong so cac canh
    va su dung cau truc Union-Find (hay DSU) (do phuc tap O(ElogE))

    Tong cong: O(ElogE)
*/

#include <iostream>
using namespace std;

int V, E;                                       // khai bao so dinh, so canh cua do thi 
int  u[1001], v[1001], w[1001], parent[1001];       // u la dinh dau, v la dinh cuoi cua canh (u,v) trong so w
   // khai bao parent la nut goc trong ham Union()

int value = 0;                                    // do dai cua MST
int choose[1001];                                // danh dau cac canh duoc chon

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
void Heapify(int arr1[], int arr2[], int arr3[],  int N, int i) {   //day la ham doi cho khi nut con lon hon nut cha
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<N && arr3[left]>arr3[largest]) largest = left;              // so sanh trong so nut cha, nut con
    if(right<N && arr3[right]>arr3[largest]) largest = right;
    if(largest != i) {
        Swap(&arr3[i], &arr3[largest]);                                  // doi cho 2 trong so tren cay heap
        Swap(&arr1[i], &arr1[largest]);                                  // doi cho 2 dinh dau tuong ung
        Swap(&arr2[i], &arr2[largest]);                                  // doi cho 2 dinh cuoi tuong ung
        Heapify(arr1, arr2, arr3, N, largest);                           // tiep tuc di sau xuong duoi
    }
}

void HeapSort(int arr1[], int arr2[], int arr3[], int N) {
    // xay dung cay Heap:
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

void MakeSet(int i) {           // ban dau cho moi dinh thuoc 1 tap hop
    parent[i] = i;              // gan moi dinh luc dau chinh la nut goc
}

int Find(int i) {               // tim ra goc cua mot cay phan hoach
    while(i != parent[i]) {     
        i = parent[i];          
    }
    return i;
}

void Union(int a, int b) {      // hop nhat 2 tap hop khong giao nhau
    int r1 = Find(a);           // goc cua nut a
    int r2 = Find(b);           // goc cua nut b
    parent[r1] = r2;            // noi tu r1 sang r2 -> ket hop 2 phan hoach
}

void Kruskal() {                        
    int i;
    for(i=0; i<V; i++) {
        MakeSet(i);
    }
    HeapSort(u, v, w, E);                       // sap xep cac canh cua G theo thu tu tang dan
    for(i=0; i<E; i++) {                        // xet tung canh 
        if(Find(u[i]) != Find(v[i])) {          // neu u[i] va v[i]o hai tap phan hoach khac nhau
            value += w[i];                     // thi thoa man -> nap vao MST
            Union(u[i], v[i]);                 // hop nhat 2 phan hoach
            choose[i] = 1;                     // danh dau canh duoc chon  
        }
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