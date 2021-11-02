#pragma once
#pragma once
#include <iostream>
#include "DoHoa.h"
#include"user.h"
#include <stdio.h>
#include <windows.h> 
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include<fstream>

//hàm in chữ XIN CHAO QUY KHACH DEN VOI KHACH SAN CHUNG TOI chạy ngang
void menu() {
	ShowCur(0);
	int i = 0, a = 0;
	int c = 1;
	int q = 0;
	AnConTro();
	while (q < 176) {
		gotoXY(i, 7);
		if (c > 7)
			c = 1;
		textcolor(c++);
		string str = "XIN CHAO QUY KHACH DEN VOI KHACH SAN CHUNG TOI";
		cout << str;
		ThanhVienNhom();
		//		setphong(str);
		Sleep(20);
		if (i == 175 - str.length()) a = 0;
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
	Sleep(1000);
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
//};
void Menu()
{
	gotoXY(10, 31);
	cout<<"             Quan Li Nhan Vien             "; //1
	gotoXY(10, 33);
	cout << "             Quan Li Khach Hang            "; //2
	gotoXY(10, 35);
	cout << "           Xem Quy Dinh Khach San          "; //3
	gotoXY(10, 37);
	cout << "               Quan Li Phong               "; //4
	gotoXY(10, 39);
	cout << "             Lap Phieu Dang Ki             "; //5
	gotoXY(10, 41);
	cout << "              Quan Li Dich Vu              "; //6
	gotoXY(10, 43);
	cout << "              Quan Li Hoa Don              "; //7
	gotoXY(10, 45);
	cout << "             Thong ke Chi Tieu             "; //8
	gotoXY(10, 47);
	cout << "             Lich Su Khach San             "; //9
	gotoXY(10, 49);
	cout << "                   Thoat                   "; //10

}

//logo
void logo(int toadoX, int toadoY)
{
	string str;
	ifstream file;
	file.open("logo.txt");
	int h = toadoY;
	int mamau;
	while (true)
	{
		getline(file, str);
		mamau = 10 + rand() % 6;
		SetColor(mamau);
		gotoXY(toadoX, h++);
		cout << str << endl;
		if (file.eof())
		{
			break;
		}
	}
	textcolor(7);
	file.close();
}



//==============================DANG NHAP=============================
void DangNhap()
{
	ShowCur(1);
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
						gotoXY(75, 24);
						cout << "Khong qua 15 ky tu";
						AnConTro();
						Sleep(600);
						gotoXY(75, 24);
						cout << "                  ";
						gotoXY(75, 24);
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
						gotoXY(75, 27);
						cout << "Khong qua 15 ky tu";
						AnConTro();
						Sleep(600);
						gotoXY(75, 27);
						cout << "                  ";
						gotoXY(75, 27);
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
			gotoXY(60, 29);
			cout << "Dien ten dang nhap hoac mat khau";
			AnConTro();
			Sleep(500);
			gotoXY(60, 29);
			cout << "                                 ";
			HienConTro();
			if (User.length() == 0)
			{
				gotoXY(75, 24); //  Quay lai user
				line = 0;
			}
			else
			{
				gotoXY(75, 27); // Quay lai pass
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
				gotoXY(60, 29);
				cout << "Dang nhap that bai. Nhap lai!!!";
				AnConTro();
				Sleep(2000);
				User = ""; // clear
				Pass = ""; // clear
				gotoXY(60, 29);
				cout << "                                ";
				gotoXY(75, 24);
				cout << "                 "; // Clear user
				gotoXY(75, 27);
				cout << "                 "; // Clear pass
				line = 0;
				gotoXY(75 + User.length(), 24);
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
	gotoXY(67, 29);
	cout << "Dang nhap thanh cong";
	AnConTro();
	Sleep(500);
	HienConTro();

}
//=========================== KHUNG NHÂN VIÊN ===============================
void NhanVien()
{
//	gotoXY(80, 10);
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
	gotoXY(7, 1);
	cout << "So Hieu";
	gotoXY(28, 1);
	cout << "Loai";
	gotoXY(47, 1);
	cout << "So Cho";
}
