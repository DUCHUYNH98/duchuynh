#include<iostream>
#include<conio.h>
using namespace std;
#define TRUE 1 
#define FALSE  0 
#define MAX  10000 
int a[100][100];// ma tran trong so cua do thi
int n;//so dinh cua do thi
int m;//so canh cua do thi
int sc;//so canh cay khung nho nhat
int w;//do dai cua cay khung
int tt[100];//trang thai cua cac dinh
int lck[100][3];//danh sach canh cay khung nho nhat


void nhap(){
 int i, j, k;
 cout << "nhap so dinh :  ";
 cin>>n;
 cout << "\nnhap so canh: ";
 cin >>m;
 cout<<"So dinh: "<<n<<endl;
 cout<<"So canh: "<<m<<endl;
 // khoi tao ma tran trong so cua do thi a[i][j] = MAX
 for (i = 1; i <= n; i++){
  tt[i] = TRUE;//gan trang thai cho cac dinh
  for (j = 1; j <= n; j++)
   a[i][j] = MAX;
 }
 
 //nhap danh sach canh
 for (int p = 1; p <= m; p++){
 	cout << "nhap danh sach canh i,j,k: ";
  cin>>i>>j>>k;
  a[i][j] = k;
  a[j][i] = k;
 }
}



void PRIM(){
 int k, top, min, l, t, u;
 int s[100];//mang chua cac dinh cay khung nho nhat
 sc = 0; w = 0; u = 1;
 top = 1;
 s[top] = u;// them dinh bat ki vao mang s[]
 tt[u] = FALSE;
 while (sc<n - 1) {
  min = MAX;
  //tim canh co do dai nho nhat voi cac dinh trong mang s[].
  for (int i = 1; i <= top; i++){
   t = s[i];
   for (int j = 1; j <= n; j++){
    if (tt[j] && min>a[t][j]){
     min = a[t][j];
     k = t;
     l = j;
    }
   }
  }
  sc++;
  w = w + min;
  //them vao danh sach canh cay khung
  lck[sc][1] = k;
  lck[sc][2] = l;
  tt[l] = FALSE; 
  top++;
  s[top] = l;
 }
}



void xuat(){
 cout<<"Do dai ngan nhat:"<< w<<endl;
 cout<<"Cac canh cua cay khung nho nhat"<<endl;
 for (int i = 1; i <= sc; i++)
  cout<< lck[i][1]<<" "<< lck[i][2]<<endl;
}
int main(){
 nhap(); 
 PRIM();
 cout << endl;
 xuat();
 getch();
}
