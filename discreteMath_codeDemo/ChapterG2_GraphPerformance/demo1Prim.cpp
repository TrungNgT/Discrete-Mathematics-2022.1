#include<iostream>
#include<conio.h>
using namespace std;
#define TRUE 1 
#define FALSE  0 
#define MAX  10000 
int a[100][100];//ma trận trọng số của đồ thị.
int n;//số đỉnh của đồ thị
int m;//số cạnh của đồ thị.
int sc;//số cạnh của cây khung nhỏ nhất.
int w;//Độ dài của cây khung nhỏ nhất.
int chuaxet[100];//mảng đánh dấu danh sách đỉnh đã thêm vào cây khung nhỏ nhất.
int cck[100][3];//danh sách cạnh của cây khung nhỏ nhất.
void nhap(void){
 int i, j, k;
 cin>>n>>m;
 cout<<"So dinh: "<<n<<endl;
 cout<<"So canh: "<<m<<endl;
 //khỏi tạo ma trận trọng số của đồ thị a[i][j] = MAX.
 for (i = 1; i <= n; i++){
  chuaxet[i] = TRUE;//Gán nhãn cho các đỉnh.
  for (j = 1; j <= n; j++)
   a[i][j] = MAX;
 }

 //nhập danh sách cạnh.
 for (int p = 1; p <= m; p++){
  cin>>i>>j>>k;
  a[i][j] = k;
  a[j][i] = k;
 }
}
void PRIM(){
 int k, top, min, l, t, u;
 int s[100];//mảng chứa các đỉnh của cây khung nhỏ nhất.
 sc = 0; w = 0; u = 1;
 top = 1;
 s[top] = u;// thêm đỉnh u bất kỳ vào mảng s[]
 chuaxet[u] = FALSE;
 while (sc<n - 1) {
  min = MAX;
  //tìm cạnh có độ dài nhỏ nhất với các đỉnh trong mảng s[].
  for (int i = 1; i <= top; i++){
   t = s[i];
   for (int j = 1; j <= n; j++){
    if (chuaxet[j] && min>a[t][j]){
     min = a[t][j];
     k = t;
     l = j;
    }
   }
  }
  sc++;
  w = w + min;
  //thêm vào danh sách cạnh của cây khung.
  cck[sc][1] = k;
  cck[sc][2] = l;
  chuaxet[l] = FALSE; 
  top++;
  s[top] = l;
 }
}
void Result(void){
 cout<<"Do dai ngan nhat:"<< w<<endl;
 cout<<"Cac canh cua cay khung nho nhat"<<endl;
 for (int i = 1; i <= sc; i++)
  cout<< cck[i][1]<<" "<< cck[i][2]<<endl;
}
int main(){
 nhap(); 
 PRIM();
 Result();
 getch();
}