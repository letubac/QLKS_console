#pragma once
#include <iostream>
#include "DoHoa.h"
#include <stdio.h>
#include <windows.h> 
#include <cstdlib>
#include <ctime>
#include <conio.h>

//hàm in chữ XIN CHAO QUY KHACH DEN VOI KHACH SAN CHUNG TOI chạy ngang
void menu() {
	int i = 0, a = 0;
	int c = 1;
	int q = 0;
	AnConTro();
	while (q < 121) {
		gotoXY(i, 7);
		if (c > 7)
			c = 1;
		textcolor(c++);
		string str = "XIN CHAO QUY KHACH DEN VOI KHACH SAN CHUNG TOI";
		cout << str;
		ThanhVienNhom();
//		setphong(str);
		Sleep(20);
		if (i == 120 - str.length()) a = 0;
		if (i == 0) a = 1;
		if (a == 1) i++;
		if (a == 0) i--;
		//system("cls");
		XoaManHinhTuyChon(0, 7, 200, 2);
		q++;
	}
	textcolor(7);
	//XoaManHinhChinh();
	system("cls");
	Sleep(3000);
}

//============================VE KHUNG=============================
void VeKhung() // 160:45 (Ti le 16:9)
{
	//gotoxy(1,1);
	char doc = 186;//dòng thẳng bên trái và dòng thẳng bên phải
	char ngang = 205;// dòng ngang trên và dòng ngang dưới
	char traitren = 201;// cái móc câu bên trái phía trên
	char traiduoi = 200;// cái móc câu bên trái phía dưới
	char phaitren = 187;// cái móc câu bên phải phía trên
	char phaiduoi = 188;// cái móc câu bên phải phía dưới
	gotoXY(24, 3);
	for (int i = 1; i <= 45; i++)
	{
		for (int j = 1; j <= 160; j++)
		{
			if (i == 1 || i == 45)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 160)
						{
							cout << phaitren;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == 160)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}
				}
			}
			else
			{
				if (j == 1 || j == 160)
				{
					cout << doc;
				}
				else
				{
					cout << " ";
				}
			}
		}
		gotoXY(24, 3 + i);
		//		cout << endl;
	}
}
// ========================= CAC HAM XU LY CUA MENU =====================
void XoayLen(string* Menu)
{
	for (int i = 0; i < 6; i++)
	{
		Menu[i] = Menu[i + 1];
	}
	/*	Menu[0] = Menu[1]; // Menu[0] vai tro la o nho tam
		Menu[1] = Menu[2];
		Menu[2] = Menu[3];
		Menu[3] = Menu[4];
		Menu[4] = Menu[5]; */
	Menu[6] = Menu[0];
}
void XoayXuong(string* Menu)
{
	Menu[0] = Menu[11]; // Menu[0] vai tro la bien tam
	for (int i = 6; i > 0; i--)
	{
		Menu[i] = Menu[i - 1];
	}
	/*
	Menu[5] = Menu[4];
	Menu[4] = Menu[3];
	Menu[3] = Menu[2];
	Menu[2] = Menu[1];
	Menu[1] = Menu[0];  */
}
//============================MENU CHINH==============================
// Menu
string Main[] = {
"             Quan Li Nhan Vien             ", //1
"             Quan Li Khach Hang            ", //2
"           Xem Quy Dinh Khach San          ", //3
"               Quan Li Phong               ", //4
"              Quan Li Dich Vu              ", //5
"              Quan Li Hoa Don              ", //6
"                   Thoat                   "  //0
};
void Menu()
{
	textcolor(240);
	int j = 33;
	for (int i = 0; i < sizeof(Main) / sizeof(*Main); i++)
	{
		gotoXY(8, j++);
		cout << Main[i];
	}
}


int MainMenu(int a)
{
	
	//string* Menu = new string[12];
	//Menu[0] = ""; // bien tam
	//Menu[1] = "1.Quan li Nhan Vien";
	//gotoXY(5, 13);
	//Menu[2] = "2.Khach San";
	//gotoXY(5, 14);
	//Menu[3] = "3.Khach Hang";
	//gotoXY(5, 15);
	//Menu[4] = "4.Phong";
	//gotoXY(5, 16);
	//Menu[5] = "5.Dich Vu";
	//gotoXY(5, 17);
	//Menu[6] = "6.Hoa Don";
	//AnConTro();
	VeHCN(5, 4, 60, 48, 4);
	VeHCN(7, 5, 50, 15, 3);
	gotoXY(22, 6);
	cout << "HUONG DAN SU DUNG";
	gotoXY(8, 7);
	cout << "Huong dan 1";
	gotoXY(6, 23);
	cout << "----------------------------------------------------";
	gotoXY(6, 26);
	cout << "----------------------------------------------------";
	VeHCN(6, 30, 50, 20, 3); // Khung quan ly khach san
	//gotoXY(7, 31);
	//cout <<"1.Quan li Nhan Vien";
	//gotoXY(7, 32);
	//cout << "2.Khach San";
	//gotoXY(7, 33);
	//cout << "3.Khach Hang";
	//gotoXY(7, 34);
	//cout << "4.Phong";
	//gotoXY(7, 35);
	//cout << "5.Dich Vu";
	//gotoXY(7, 36);
	//cout << "6.Hoa Don";
	Menu();
	AnConTro();
	cout << endl;
	
	//string tam = Menu[a];
	//for (int j = 0; j <= 6; j++)
	//{
	//	if (Menu[3] == tam)
	//	{
	//		break;
	//	}
	//	XoayXuong(Menu);
	//}
	//for (int i = 1; i <= 6; i++)
	//{
	//	if (i < 3)
	//	{
	//		ChangeColor(8);
	//		for (int j = 1; j <= i - 1; j++)
	//		{
	//			cout << "  ";
	//		}
	//		cout << Menu[i] << endl << endl;
	//	}
	//	if (i == 3)
	//	{
	//		ChangeColor(15);
	//		cout << ">> ";
	//		for (int j = 1; j <= i - 1; j++)
	//		{
	//			cout << "  ";
	//		}
	//		cout << Menu[3] << endl << endl;
	//	}
	//	if (i > 3)
	//	{
	//		ChangeColor(8);
	//		for (int j = 1; j <= 6 - 2 * (i - 3); j++)
	//		{
	//			cout << " ";
	//		}
	//		cout << Menu[i] << endl << endl;
	//	}
	//}
	//int i = a;
	//int hoanhdo = whereX();
	//int tungdo = whereY();
	//while (!_kbhit())
	//{
	//	ChangeColor(15);
	//	gotoXY(175, 0);
	//	InThoiGian();
	//}
	//gotoXY(hoanhdo, tungdo);
	//ChangeColor(8);
	//char x = _getch();
	//bool kytu;
	//if (x == -32 || x == 0)
	//{
	//	x = _getch();
	//	kytu = 0;
	//}
	//else
	//{
	//	kytu = 1;
	//}
	//while (x != 27 && x != 13) // Enter or Esc
	//{
	//	if (x == 72 && !kytu) // Up
	//	{
	//		if (i != 1)
	//		{
	//			i--;
	//		}
	//		else
	//		{
	//			i = 6;
	//		}
	//		XoayXuong(Menu);
	//		gotoXY(0, 0);
	//		for (int i = 1; i <= 6; i++) // Xu ly hinh anh
	//		{
	//			if (i < 3)
	//			{
	//				ChangeColor(8);
	//				cout << "                                                         ";
	//				gotoXY(0, whereY());
	//				for (int j = 1; j <= i - 1; j++)
	//				{
	//					cout << "  ";
	//				}
	//				cout << Menu[i] << endl << endl;
	//			}
	//			if (i == 3)
	//			{
	//				ChangeColor(15);
	//				cout << "                                                         ";
	//				gotoXY(0, whereY());
	//				cout << ">> ";
	//				for (int j = 2; j <= i - 1; j++)
	//				{
	//					cout << "  ";
	//				}
	//				cout << Menu[3] << endl << endl;
	//			}
	//			if (i > 3)
	//			{
	//				ChangeColor(8);
	//				cout << "                                                         ";
	//				gotoXY(0, whereY());
	//				for (int j = 1; j <= 6 - 2 * (i - 3); j++)
	//				{
	//					cout << " ";
	//				}
	//				cout << Menu[i] << endl << endl;
	//			}
	//		}
	//		//	gotoxy(0,60);
	//		//	cout << "Phim Up voi char la " << int(x);
	//	}
	//	if (x == 80 && !kytu) // Down
	//	{
	//		if (i != 6)
	//		{
	//			i++;
	//		}
	//		else
	//		{
	//			i = 1;
	//		}
	//		XoayLen(Menu);
	//		gotoXY(0, 0);
	//		for (int i = 1; i <= 6; i++) // Xu ly hinh anh
	//		{
	//			if (i < 3)
	//			{
	//				ChangeColor(8);
	//				cout << "                                                         ";
	//				gotoXY(0, whereY());
	//				for (int j = 1; j <= i - 1; j++)
	//				{
	//					cout << "  ";
	//				}
	//				cout << Menu[i] << endl << endl;
	//			}
	//			if (i == 3)
	//			{
	//				ChangeColor(15);
	//				cout << "                                                         ";
	//				gotoXY(0, whereY());
	//				cout << ">> ";
	//				for (int j = 1; j <= i - 1; j++)
	//				{
	//					cout << "  ";
	//				}
	//				cout << Menu[3] << endl << endl;
	//			}
	//			if (i > 3)
	//			{
	//				ChangeColor(8);
	//				cout << "                                                         ";
	//				gotoXY(0, whereY());
	//				for (int j = 1; j <= 6 - 2 * (i - 3); j++)
	//				{
	//					cout << " ";
	//				}
	//				cout << Menu[i] << endl << endl;
	//			}
	//		}
	//		//	gotoxy(0,0);
	//		//	cout << "Phim Down voi char la " << int(x);
	//	}
	//	int hoanhdo = whereX();
	//	int tungdo = whereY();
	//	while (!_kbhit())
	//	{
	//		ChangeColor(15);
	//		gotoXY(175, 0);
	//		InThoiGian();
	//	}
	//	gotoXY(hoanhdo, tungdo);
	//	ChangeColor(8);
	//	x = _getch();
	//	if (x == -32 || x == 0)
	//	{
	//		x = _getch();
	//		kytu = 0;
	//	}
	//	else
	//	{
	//		kytu = 1;
	//	}
	//}
	//if (x == 13) // Enter
	//{
	//	gotoXY(0, 30);
	//	return i;
	//}
	//if (x == 27)
	//{
	//	gotoXY(0, 30);
	//	return 0;
	//}
	return 0;
}


//==============================DANG NHAP=============================
void DangNhap()
{
	//=======================FRONT END===============================
	gotoXY(74, 19);
	cout << "DANG NHAP";
	char doc = 186;
	char ngang = 205;
	char traitren = 201;
	char traiduoi = 200;
	char phaitren = 187;
	char phaiduoi = 188;
	gotoXY(57, 21);
	for (int i = 1; i <= 10; i++) // Ke khung ngoai
	{
		for (int j = 1; j <= 40; j++)
		{
			if (i == 1 || i == 10)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 40)
						{
							cout << phaitren;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == 40)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}
				}
			}
			else
			{
				if (j == 1 || j == 40)
				{
					cout << doc;
				}
				else
				{
					cout << " ";
				}
			}
		}
		gotoXY(57, 21 + i);
	}
	traitren = 218;
	phaitren = 191;
	traiduoi = 192;
	phaiduoi = 217;
	ngang = 196;
	doc = 179;
	gotoXY(59, 21 + 3);
	cout << "Ten dang nhap "; // 14 kytu
	gotoXY(59 + 14, 2 + 21);
	//	gotoxy(0,15);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 22; j++)
		{
			if (i == 1 || i == 3)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 22)
						{
							cout << phaitren;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == 22)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}
				}
			}
			else
			{
				if (j == 1 || j == 22)
				{
					cout << doc;
				}
				else
				{
					cout << " ";
				}
			}
		}
		//	cout << endl;
		gotoXY(14 + 59, i + 2 + 21);
	}
	gotoXY(59, 21 + 6);
	cout << "Mat khau "; // 9 kytu
	gotoXY(59 + 14, 5 + 21);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 22; j++)
		{
			if (i == 1 || i == 3)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 22)
						{
							cout << phaitren;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == 22)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}
				}
			}
			else
			{
				if (j == 1 || j == 22)
				{
					cout << doc;
				}
				else
				{
					cout << " ";
				}
			}
		}
		//	cout << endl;
		gotoXY(14 + 59, 21 + i + 5);
	}
	//=======================BACK END=================================
	char a; // Bat phim
	bool kytu;
	int line = 0;
	string User = ""; // Luu ten nguoi dung
	string Pass = ""; // Luu password
//	cout << "Ten dang nhap: " << endl;
//	cout << "Mat khau: ";
//	gotoxy(15,line);
	gotoXY(59 + 16, 21 + 3);
	a = _getch();
	if (a == -32 || a == 0)
	{
		kytu = 0;
		a = _getch();
	}
	else
	{
		kytu = 1;
	}

	while (1)
	{
		while (a != 13)
		{
			if (((a == 72 || a == 80) && !kytu) || (a == 9 && kytu))
			{
				if (line) // line = 1
				{
					line--;
					gotoXY(59 + 16 + User.length(), 21 + 3);
				}
				else // line = 0
				{
					line++;
					gotoXY(59 + 16 + Pass.length(), 21 + 6);
				}
			}
			if (line)
			{
				gotoXY(59 + 16 + Pass.length(), 21 + 6); //line = 1
			}
			else
			{
				gotoXY(59 + 16 + User.length(), 21 + 3);//line = 0
			}
			if (a == 8 && kytu) // Backspace
			{
				if (!line)
				{
					if (User.length() == 0)
					{
						int hoanhdo = whereX();
						int tungdo = whereY();
						cout << "Khong the xoa";
						AnConTro();
						Sleep(200);
						gotoXY(hoanhdo, tungdo);
						cout << "              ";
						gotoXY(hoanhdo, tungdo);
						HienConTro();
					}
					else
					{
						int hoanhdo = whereX();
						int tungdo = whereY();
						gotoXY(hoanhdo - 1, tungdo);
						cout << " ";
						gotoXY(hoanhdo - 1, tungdo);
						//===Xu ly chuoi===========
						User.erase(User.end() - 1, User.end());
					}
				}
				else
				{
					if (Pass.length() == 0)
					{
						int hoanhdo = whereX();
						int tungdo = whereY();
						cout << "Khong the xoa";
						AnConTro();
						Sleep(200);
						gotoXY(hoanhdo, tungdo);
						cout << "             ";
						gotoXY(hoanhdo, tungdo);
						HienConTro();
					}
					else
					{
						int hoanhdo = whereX();
						int tungdo = whereY();
						gotoXY(hoanhdo - 1, tungdo);
						cout << " ";
						gotoXY(hoanhdo - 1, tungdo);
						//===Xu ly chuoi===========
						Pass.erase(Pass.end() - 1, Pass.end());
					}
				}
			}
			if (((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122)) && kytu) // kytu
			{
				if (!line)
				{
					if (User.length() < 15)
					{
						cout << a;
						User = User + a;
					}
					else
					{
						gotoXY(15 + 60, 3 + 21);
						cout << "Khong qua 15 ky tu";
						AnConTro();
						Sleep(600);
						gotoXY(15 + 60, 3 + 21);
						cout << "                  ";
						gotoXY(15 + 60, 3 + 21);
						cout << User;
						HienConTro();
					}
				}
				else
				{
					if (Pass.length() < 15)
					{
						cout << "*";
						Pass = Pass + a;
					}
					else
					{
						gotoXY(15 + 60, 6 + 21);
						cout << "Khong qua 15 ky tu";
						AnConTro();
						Sleep(600);
						gotoXY(15 + 60, 6 + 21);
						cout << "                  ";
						gotoXY(15 + 60, 6 + 21);
						for (int i = 1; i <= Pass.length(); i++)
						{
							cout << "*";
						}
						HienConTro();
					}
				}
			}
			a = _getch();
			if (a == -32 || a == 0)
			{
				kytu = 0;
				a = _getch();
			}
			else
			{
				kytu = 1;
			}
		}
		if (User.length() == 0 || Pass.length() == 0)
		{
			gotoXY(3 + 57, 8 + 21);
			cout << "Dien ten dang nhap hoac mat khau";
			AnConTro();
			Sleep(500);
			gotoXY(3 + 57, 8 + 21);
			cout << "                                 ";
			HienConTro();
			if (User.length() == 0)
			{
				gotoXY(59 + 16, 21 + 3); //  Quay lai user
				line = 0;
			}
			else
			{
				gotoXY(59 + 16, 21 + 6); // Quay lai pass
				line = 1;
			}
		}
		else // Co user va pass
		{
			user t;
			init(t);
			if (t.checkUserName(User) && t.checkPsswd(Pass))
			{
				break;
			}
			else
			{
				gotoXY(3 + 57, 8 + 21);
				cout << "Dang nhap that bai. Xin vui long nhap lai";
				AnConTro();
				Sleep(2000);
				User = ""; // clear
				Pass = ""; // clear
				gotoXY(3 + 57, 8 + 21);
				cout << "                                ";
				gotoXY(59 + 16, 21 + 3);
				cout << "                 "; // Clear user
				gotoXY(59 + 16, 21 + 6);
				cout << "                 "; // Clear pass
				line = 0;
				gotoXY(59 + 16 + User.length(), 21 + 3);
				HienConTro();
			}
		}
		a = _getch();
		if (a == -32 || a == 0)
		{
			kytu = 0;
			a = _getch();
		}
		else
		{
			kytu = 1;
		}
	}
	gotoXY(10 + 57, 8 + 21);
	cout << "Dang nhap thanh cong";
	AnConTro();
	Sleep(500);
	HienConTro();
}

//=========================== KHUNG NHÂN VIÊN ===============================
void NhanVienvien()
{
	char ngangngoai = 205;
	char docngoai = 186;
	char traitren = 201;
	char phaitren = 187;
	char traiduoi = 200;
	char phaiduoi = 188;
	char ngangtrong = 196;
	char doctrong = 179;
	char ngangxuong = 209;
	char nganglen = 207;
	char docphai = 199;
	char doctrai = 182;
	char ngatu = 197;

	for (int i = 1; i <= 23; i++)
	{
		for (int j = 1; j <= 60; j++)
		{
			if (i == 1 || i == 23)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 60)
						{
							cout << phaitren;
						}
						else
						{
							if (j % 20 == 0)
							{
								cout << ngangxuong;
							}
							else
							{
								cout << ngangngoai;
							}
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == 60)
						{
							cout << phaiduoi;
						}
						else
						{
							if (j % 20 == 0)
							{
								cout << nganglen;
							}
							else
							{
								cout << ngangngoai;
							}
						}
					}
				}
			}
			else // khac dong dau va cuoi
			{
				if (i % 2 == 1)
				{
					if (j == 1)
					{
						cout << docphai;
					}
					else
					{
						if (j == 60)
						{
							cout << doctrai;
						}
						else
						{
							if (j % 20 == 0)
							{
								cout << ngatu;
							}
							else
							{
								cout << ngangtrong;
							}
						}
					}
				}
				else // i%2 == 0
				{
					if (j == 1 || j % 20 == 0)
					{
						if (j == 1 || j == 60)
						{
							cout << docngoai;
						}
						else
						{
							cout << doctrong;
						}
					}
					else
						cout << " ";
				}
			}
		}
		cout << endl;
	}
}