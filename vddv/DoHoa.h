#ifndef _DOHOA_H
#define _DOHOA_H


#pragma warning(disable : 4996)
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;

//===============Tạo phông chữ cỡ lớn ============================
void setphong(string& a)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 30;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	//fflush(stdin);
	//wcscpy_s(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	fflush(stdin);
	cout << a;
}
//Ham Do Hoa 
// ==================== FULL SCREEN ==========================
void fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}
//=====================HÀM GOTOXY==============================
void gotoXY(int x, int y)//di chuyển tọa độ con trỏ trong hệ tọa độ De-cat
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//hàm thiết lập màu chữ
//Hàm thay đổi màu nền hiện thị.Ví dụ, khi gọi hàm SetColor(BLUE) hoặc SetColor(4) sẽ hiện thị nền màu xanh
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//===================== HÀM TEXTCOLOR ================================
void textcolor(int x)//Hàm thay đổi màu chữ hiện thị. Ví dụ, khi gọi hàm TextColor(1) hoặc TextColor(RED) sẽ hiện thị chữ màu đỏ
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
//hàm hiện con trỏ hoặc ẩn con trỏ đi: nếu là 1 thì hiện con trỏ và 0 là ẩn con trỏ
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//hàm thay đổi bảng điều khiển trong đồ họa
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
//=========================== TRẢ VỀ VỊ TRÍ X CỦA CON TROE ======================
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//=========================== TRẢ VỀ VỊ TRÍ X CỦA CON TROE ======================
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

//==============================AN CO TRO MAN HINH CONSOLE=======================
void AnConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//==============================HIEN CON TRO MAN HINH CONSOLE================
void HienConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
// ============= DOI MAU CHU ================
void ChangeColor(int k)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, k);
}

string CanDeuChuoi(string str, int ChieuRong)
{
	if (str.empty())
	{
		return str;
	}
	else if (str.length() > ChieuRong)
	{
		return str;
	}
	return string((ChieuRong - str.length()) / 2, ' ') + str;
}

void DeMuc(string x)
{
	SetColor(14);
	gotoXY(51, 7);
	cout << CanDeuChuoi(x, 126);
	textcolor(7);
}
//=============================SO NGAY TRONG THANG===================
int DaysOfMounth(int mm, int yy) // So ngay toi da cua thang
{
	if (mm == 4 || mm == 6 || mm == 9 || mm == 11) return 30; // Thang co 30 ngay
	if (mm == 2) // Thang 2
	{
		if (yy % 4 == 0) return 29; // Nam nhuan
		return 28; // Nam khong nhuan
	}
	return 31; // Thang co 31 ngay
}
//===========================KIEM TRA NGAY HOP LE====================
bool CheckDay(int dd, int mm, int yy)
{
	if (dd > 31 || dd <= 0) return 0; // Ngay khong am hoac lon hon 31
	if (mm > 12 || mm <= 0) return 0; // Khong co thang am hoac lon hon 12
	if (mm == 4 || mm == 6 || mm == 9 || mm == 11) // Thang co 30 ngay
	{
		if (dd > 30) return 0;
	}
	if (mm == 2) // Thang 2
	{
		if (yy % 4 == 0) // Nam nhuan
		{
			if (dd > 29) return 0; // Nam nhuan
		}
		if (dd > 28) return 0; // Nam khong nhuan
	}
	if (dd > 31) return 0; // Thang co 31 ngay
	return 1;
}
//============================DO DAI SO DUONG==================
int DoDaiSoDuong(int a)
{
	if (a == 0) return 1;
	int dem = 0;
	while (a != 0)
	{
		a = a / 10;
		dem++;
	}
	return dem;
}
//=========================LOC LAY SO=================================
int LaySo(int giatri, bool DiChuyenDeThoat, char& a) // Kiem tra Di chuyen co thoat khong va nhan phim vua nhan
{
	int i = DoDaiSoDuong(giatri); // chống tràn bít + khong cho backspace khong hop le
	HienConTro();
	unsigned int so = giatri;
	int b;
	//	if (a <= 0) a = getch(); // clear a
	a = getch();
	while (a != 13)
	{
		if ((DiChuyenDeThoat && a == -32) || a == 27 || a == 19)
		{
			break;
		}
		if ((a >= 48 && a <= 57) && i < 10) // nuot phim khi khong phai la so
		{
			if (so == 0 && a == 48)
			{

			}
			else
			{
				i++;
				b = a - 48;
				cout << b;
				so = so * 10 + b;
			}
		}
		if (a == 8 && i > 0) // Nguoi dung nhan backspace
		{
			i--;
			so = so / 10;
			int x = whereX();
			int y = whereY();
			gotoXY(x - 1, y);
			cout << " ";
			if (!x) gotoXY(0, 0);
			else gotoXY(x - 1, y);
		}
		a = getch();
	}
	return so;
}

// ===================== CANH GIUA ============================== // Tra ve vi tri giua de canh
void CanhGiua(int vitrigiua, int dodai)
{
	int tungdo =whereY();
	gotoXY(vitrigiua - dodai / 2, tungdo);
}

//=================================CHU IN HOA=====================
char InHoa(char a)
{
	if (a >= 97 && a <= 122) // tu 'a' toi 'z'
	{
		a = a - 32;
	}
	return a;
}
//Xoa Man Hinh
void XoaManHinhChinh()
{
	textcolor(7);
	for (int i = 6; i < 36; i++)
	{
		for (int j = 51; j < 176; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}
void XoaManHinhTuyChon(int toadoX, int toadoY, int chieudai, int chieucao)
{
	textcolor(7);
	for (int i = toadoY; i < chieucao + toadoY; i++)
	{
		for (int j = toadoX; j < toadoX + chieudai; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}

// ========================= IN THOI GIAN HIEN TAI ===================
void InThoiGian()
{
	time_t hientai;
	time(&hientai);
	tm* thoigian = localtime(&hientai);
	switch (thoigian->tm_wday)
	{
	case 1:
	{
		cout << "Monday";
		break;
	}
	case 2:
	{
		cout << "Tuesday";
		break;
	}
	case 3:
	{
		cout << "Wednesday";
		break;
	}
	case 4:
	{
		cout << "Thursday";
		break;
	}
	case 5:
	{
		cout << "Friday";
		break;
	}
	case 6:
	{
		cout << "Saturday";
		break;
	}
	case 7:
	{
		cout << "Sunday";
		break;
	}
	}
	cout << ", " << thoigian->tm_mday << "/" << thoigian->tm_mon + 1 << "/" << 1900 + thoigian->tm_year;
	gotoXY(whereX() - 11, whereY() + 2);
	cout << thoigian->tm_hour;
	if (thoigian->tm_sec % 2 == 0)
	{
		cout << " ";
	}
	else
	{
		cout << ":";
	}
	if (thoigian->tm_min < 10)
	{
		cout << "0" << thoigian->tm_min;
	}
	else
	{
		cout << thoigian->tm_min;
	}
}

void XuatPage(int page)
{
	gotoXY(111, 34);
	cout << char(174);
	gotoXY(115, 34);
	cout << char(175);
	gotoXY(113, 34);
	cout << page;
}
void Logo1(int toadoX, int toadoY)
{
	string str;
	ifstream FileIn;
	FileIn.open("logo.txt", ios::in);
	int h = toadoY;
	int mamau;
	while (true)
	{
		getline(FileIn, str);
		mamau = 10 + rand() % 6;
		SetColor(mamau);
		gotoXY(toadoX, h++);
		cout << str << endl;
		if (FileIn.eof())
		{
			break;
		}
	}
	textcolor(7);
	FileIn.close();
}
//Ve HCN
void HCNTextDong(int toadoX, int toadoY, int chieudai, int chieucao)
{
	for (int i = toadoX; i < toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY; i < toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai - 1, i);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao - 1);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
}
void HCNTextDong1(int toadoX, int toadoY, int chieudai, int chieucao)
{
	for (int i = toadoX; i <= toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		//textcolor(1926);
		textcolor(77);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY; i <= toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai, i);
		textcolor(77);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao );
		textcolor(77);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		textcolor(77);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
}
//void HCNText(int toadoX, int toadoY, int chieudai, int chieucao)
//{
//	for (int i = toadoX; i < toadoX + chieudai; i++)
//	{
//		gotoXY(i, toadoY);
//		textcolor(1926);
//		cout << " ";
//		textcolor(7);
//	}
//	for (int i = toadoY; i < toadoY + chieucao; i++)
//	{
//		gotoXY(toadoX + chieudai - 1, i);
//		textcolor(1926);
//		cout << " ";
//		textcolor(7);
//	}
//	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
//	{
//		gotoXY(i, toadoY + chieucao - 1);
//		textcolor(1926);
//		cout << " ";
//		textcolor(7);
//	}
//	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
//	{
//		gotoXY(toadoX, i);
//		textcolor(1926);
//		cout << " ";
//		textcolor(7);
//	}
//}

void HCNText(int toadoX, int toadoY, int chieudai, int chieucao)
{
	for (int i = toadoX; i < toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoY; i < toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai - 1, i);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao - 1);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
}
void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauSet)
{
	SetColor(mauSet);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}
	SetColor(7);
}
void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	textcolor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}
void XoaHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mau)
{
	textcolor(mau);
	for (int j = toadoY + 1; j < toadoY + chieucao; j++)
	{
		for (int i = toadoX + 1; i < toadoX + chieudai; i++)
		{
			gotoXY(i, j);
			cout << " ";
		}
	}
}

bool batSuKien(int toaDoX, int toaDoY, int dai, int rong) {
	//int i = 1;
	while (true) {
		
		POINT pos_cursor;

		if (GetAsyncKeyState(MOUSEEVENTF_LEFTDOWN)) {
			Sleep(100);
			int x = 0, y = 0;
			//mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			//Sleep(500);
			GetCursorPos(&pos_cursor);
			// may execute too fast so wait a bit
			//Sleep(10);

			 x = (pos_cursor.x - 5) / 8;
			 y = (pos_cursor.y - 25) / 12;
			cout << "X: " << x << "\tY: " << y << endl;
			if (x >= toaDoX && x <= dai + toaDoX && y >= toaDoY && y <= rong + toaDoY) {
				return true;
				//break;
			}
			else {
				return false;
				//break;
			}
		}

	}
}

void GiaoDienThongBaoThanhCong(string x)
{
	ToMauHCN(90, 17, 50, 10, 95);
	textcolor(95);
	gotoXY(91, 20);
	cout << CanDeuChuoi(x, 49);
	gotoXY(103, 23);
	system("pause");
	textcolor(7);
}


//void XoaLogo1(int toadoX, int toadoY)
//{
//	int h = toadoY;
//	string str = "                                               ";
//	while (h < 13 + toadoY)
//	{
//		gotoXY(toadoX, h++);
//		cout << str << endl;
//	}
//}


// ==================== XOA MAN HINH ========================
void ThanhVienNhom()
{
//	system("cls");
	VeHCN(11, 17, 30, 8, 3);
	gotoXY(14, 18);
	ChangeColor(11);
	cout << "THANH VIEN NHOM GOM: ";
	gotoXY(13, 20);
	ChangeColor(11);
	cout << "LE VAN BAC - D18CQAT01";
	ChangeColor(15);

	gotoXY(12, 21);
	ChangeColor(11);
	cout << "NGUYEN TUAN KIET - D18CQAT01";
	ChangeColor(15);

	gotoXY(12, 22);
	ChangeColor(11);
	cout << "HUYNH DINH VU - D18CQAT01";
	ChangeColor(15);

	gotoXY(12, 23);
	ChangeColor(11);
	cout << "PHAM VIET HOC - D18CQAT02";
	ChangeColor(15);

	gotoXY(60, 28);
	ChangeColor(11);
	cout << "HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO TAI THANH PHO HO CHI MINH";
	ChangeColor(15);

	VeHCN(150, 17, 30, 8, 3);
	gotoXY(153, 18);
	ChangeColor(11);
	cout << "GIAO VIEN HUONG DAN: ";
	ChangeColor(15);

	gotoXY(151, 20);
	ChangeColor(11);
	cout << "GIAO VIEN: NGUYEN THI THUY AN";
	ChangeColor(15);

//	gotoXY(0, 0);
}
#endif