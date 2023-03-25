/* Le Van Son 20210752 - Nguyen Thanh Trung 20215492
	Thuat toan Prim su dung ly thuyet lat cat va nap canh an toan de tim cay khung nho nhat

	Do phuc tap thuat toan: O(V^3)
*/

#include<iostream>
#include<conio.h>
using namespace std;

// Dat ten hang so
#define TRUE 1
#define FALSE 0
#define MAX 1000001

// Khai bao bien
int a[1001][1001]; 						// Ma tran trong so cua do thi
int V, E; 								// So dinh, so canh cua do thi
int sc;									// So canh cua cay khung nho nhat
int w; 									// Do dai cua cay khung nho nhat
int chuatham[1001]; 						// Mang danh dau danh sach dinh da them vao cay khung nho nhat
int cck[1001][3]; 						// Danh sach canh cua cay khung nho nhat

// Ham nhap du lieu
void nhap(void){
	int i, j, k;
	cin >> V >> E;

	// Khoi tao ma tran trong so cua do thi a[i][j] = MAX
	for(i=1; i<=V; i++){
		chuatham[i] = TRUE;
		for(j=1; j<=V; j++)
			a[i][j] = MAX;
	}
	
	// Nhap danh sach cac canh
	for(int p=1; p<=E; p++){
		cin >> i >> j >> k;
		a[i][j] = k;
		a[j][i] = k;
	}
}

// Ham Prim tim cay khung nho nhat
void PRIM(void){
	int k, top, min, l, t, u;
	int s[1001]; 				// Mang chua cac dinh cua cay khung nho nhat
	sc = 0; w = 0; u = 1;		// so canh, do dai cua cay khung MST
	top = 1; 					// So dinh trong tap S
	s[top] = u; 				// Them dinh u bat ky vao mang s[]
	chuatham[u] = FALSE;
	while(sc<V-1){
		// tim min w: s -> V\s
		min = MAX;
		for(int i=1; i<=top; i++){
			t = s[i];
			for(int j =1; j<=V; j++){
				if(chuatham[j] && min>a[t][j]){
					min = a[t][j];
					k = t;
					l = j;
				}
			}
		}
		sc++;
		w = w + min;    			// nap canh an toan 
		cck[sc][1] = k;				// danh dau canh duoc chon
		cck[sc][2] = l;
		chuatham[l] = FALSE;
		top++;						
		s[top] = l;					// nap dinh moi vao MST
	}
}

// Ham xuat ket qua ra man hinh
void ketQua(void){
	cout <<"Do dai ngan nhat: "<< w << endl;
	cout <<"Cac canh cua cay khung nho nhat: "<< endl;
	for(int i=1; i<=sc; i++)
		cout << cck[i][1] << " " << cck[i][2] << endl;
}
int main(){
	nhap();
	PRIM();
	ketQua();
	getch();
}
