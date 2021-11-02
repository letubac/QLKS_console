#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"login.h"
#include"XulyDeTai.h"

int main()
{
//	system("color 32");
	fullscreen();
	LIST_KHACHHANG lkh;
	LIST_NHANVIEN lnv;
	LIST_PHONG lp;
	PHONG p;
	KHACHHANG kh;
	NHANVIEN nv;
	//char d;
	//c = getch();
	Khoitaolist(lkh);
	KhoiTaoListNV(lnv);
	KhoitaoPhong(lp);
	/*user d;
	init(d);*/
	/*d.Create();
	Save(d);
	d.print();*/
	/*ShowCur(0);
	menu();
	Sleep(500);
	DangNhap();
	Sleep(1000);
	loading();
	Sleep(2000);*/
	while (true){
		Logo1(75,4);
//		MainMenu();
		Xuly();
		Sleep(50);
	}
	/*for (int i = 0; i < 255; i++)
	{
	
		textcolor(i);
		cout << i<<"a";
	}*/

}

// Giới tính chọn Nam Nữ
