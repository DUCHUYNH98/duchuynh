#include <iostream>
using namespace std;


int main(){
	int month, year;
	cout << "nhap thang: ";
	cin >> month;
	cout << "\nnhap nam: ";
	cin >> year;
	if (year < 1582){
		cout << "nam khong hop le ";
		return 1;
	}
	if (month < 1 || month > 12){
		cout << "thang khong hop le";
		return 2;
	}
	int top = 31;
	switch(month){
		case 4: case 6: case 9: case 11:
			top = 30;
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0)
				top = 29;
			else
				top = 28;
				
			break;
	}
	int d = 1;
	int a = (14 - month)/12;
	int y = year - a;
	int m = month + 12*a - 2;
	int dow = (d + y + y/4 - y/100 + y/400 + (31*m)/12 )%7;// tim ngay dau tien trong thang la thu may
	cout << "S\t"<< "M\t"<<"T\t"<<"W\t"<<"T\t"<<"F\t"<<"S\t"<<endl;
	// chen ngay dau tien vao thu minh da tim
	for (int i = 0; i < 7; i++)
		if (i < dow)
			cout << "\t";
		else {
			cout << d;
			cout << "\t";
			d++;
		}
			cout << endl;	
		do{
			for (int i = 0; i < 7; i++){
			if (d <= top){
				cout << d;
			cout << "\t";
			d++;
			}
			
		}
		cout << endl;
		}while (d <= top);
	return 0;
}
