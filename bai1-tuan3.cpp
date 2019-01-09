#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
/* input: cho 1 so nguyen va 1 mang de chua cac phan tu
	output: nhap so nguyen vao mang 
*/
void nhap(int m, int a[]){
	for (int i = 0; i <= m; i++){
		 a[i] = i;
	}
}
/*input: cho 1 so nguyen n , 1 mang a, va 1 so nguyen m
	output: se cho ra 1 day so ngau ngien
	nhung day so ngau nhien do nam trong mang m
*/
void nhapngaunhien(int n, int a[], int m){
	for (int  i = 0; i <= n; i++){
		a[i] = rand()%(m+1);
		cout << a[i]<<"\t";

		
	}
}
/* input: cho 1 so nguyen va 1 mang de chua cac phan tu
	output: xuat mang ra console 
*/
void xuat(int n , int a[]){
	for (int i = 0 ; i <= n; i ++){
		cout << a[i]<<"\t";
	}
}
int main(){
	int m, n;
	cout <<	"nhap m: ";
	cin >> m;
	int a[m];
	do {
		cout << "nhap n: ";
		cin >> n;
	}while(n < 1 || n > m);
	nhap(m, a);
	xuat(m, a);
	cout << endl<<n<<" so ngau nhien "<<":\t";
	srand(time(0));
	nhapngaunhien(n, a, m);
	}
