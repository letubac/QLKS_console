#pragma once
#define _XULYDETAI_H

#include<iostream>
#include<stdlib.h>
#include "graph.h"
#include<string.h>
#include<string>
using namespace std;


//khởi tạo struct khách hàng
struct khachhang
{
	string MaKH;
	string TenKH;
	string SoDT;
	string DiaChi;
	string CMND;
	string GioiTinh;//1 la nam, 0 la nu
	string QuocTich;
};
typedef struct khachhang KHACHHANG;

//khởi tạo node khách hàng 
struct node_khachhang
{
	KHACHHANG khachhang;
	node_khachhang* pNext;
};
typedef struct node_khachhang NODE_KHACHHANG;

//khởi tạo danh sách khách hàng
struct list_khachhang
{
	NODE_KHACHHANG* pHead;
	NODE_KHACHHANG* pTail;
};
typedef struct list_khachhang LIST_KHACHHANG;

//========================================= DANH SÁCH NHÂN VIÊN =================================
struct NhanVien
{
	string MaNV;
	string TenNV;
	string MaCV;
	string SoDT;
	string GioiTinh;
	string DiaChi;
	string NgaySinh;
	string NgayNhanViec;
	string NgayHetHanCV;
};
typedef struct NhanVien NHANVIEN;

struct node_nhanvien
{
	NHANVIEN Nhanvien;
	node_nhanvien* pNext;
};
typedef struct node_nhanvien NODE_NHANVIEN;

struct list_nhanvien
{
	NODE_NHANVIEN* pHead;
	NODE_NHANVIEN* pTail;
};
typedef struct list_nhanvien LIST_NHANVIEN;

//tạo node khách hàng
NODE_KHACHHANG* khoitaoNode(KHACHHANG kh)
{
    NODE_KHACHHANG* p = new NODE_KHACHHANG;
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        p->khachhang = kh;
        p->pNext = NULL;
        return p;
    }
}
void DinhDangChuoi(string& str)
{
	//Xoa khoang trong
	while (str[0] == ' ') //nếu kí tự đầu là khoảng cách thì nó sẽ xóa khoảng cách
	{
		str.erase(str.begin() + 0);
	}
	while (str[str.length() - 1] == ' ') //nếu kí tự cuối là khoảng cách thì nó cũng xóa khoảng cách đó
	{
		str.erase(str.begin() + (str.length() - 1));
	}

	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i + 1] == ' ' && str[i] == ' ') //nếu 2 kí tự tiên liếp cách nhau bởi nhiều khoảng trắng thì nó sẽ xóa đến khi còn 1 khoảng trắng
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	//Viet thuong all lai
	for (int i = 0; i < str.length(); i++)
	{
		if ((65 <= str[i] && str[i] <= 90) && str[i] != ' ') //nếu kí tự nằm từ 65->90 trong bảng ascii là chữ hoa
		{
			str[i] = str[i] + 32; //thì nó sẽ cộng lên 32 là nằm trong khoảng 97->122 là đổi về chữ thường
		}
	}
	//Viet hoa
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (97 <= str[i] && str[i] <= 122)) //giống như chữ thường nhưng ngược lại
		{
			str[0] = str[0] - 32;
		}
		if (str[i] == ' ' && (97 <= str[i + 1] && str[i + 1] <= 122))//hàm in chữ hoa sau mỗi khoảng trắng
		{
			str[i + 1] = str[i + 1] - 32;
		}
	}

}

//============================================================================ Khách hàng ===============================================================

void Khoitaolist(LIST_KHACHHANG& lkh)
{
	lkh.pHead = NULL;
	lkh.pTail = NULL;
}

void addhead(LIST_KHACHHANG& lkh, NODE_KHACHHANG* p)
{
	if (lkh.pHead == NULL)
	{
		lkh.pHead = lkh.pTail = p;
	}
	else {
		p->pNext = lkh.pHead;

		lkh.pHead = p;
	}
}

void addTail(LIST_KHACHHANG& lkh, NODE_KHACHHANG* p)
{
	if (lkh.pHead == NULL)
	{
		lkh.pHead = lkh.pTail = p;
	}
	else
	{
		lkh.pTail->pNext = p;
		lkh.pTail = p;
	}
}

int CheckMaKH(LIST_KHACHHANG lkh,string t) //kiểm tra mã khách hàng có tồn tại trong list
{
	NODE_KHACHHANG* p = lkh.pHead;
	while (p != NULL)
	{
		if (p->khachhang.MaKH == t) return true;
		p = p->pNext;
	}
	return false;
}

int CheckTenKH(LIST_KHACHHANG lkh, string t) //kiểm tra tên khách hàng có tồn tại trong list
{
	NODE_KHACHHANG* p = lkh.pHead;
	while (p != NULL)
	{
		if (p->khachhang.TenKH == t) return true;
		p = p->pNext;
	}
	return false;
}

int CheckSoDTKH(LIST_KHACHHANG lkh, string t) //kiểm tra Số điện thoại khách hàng có tồn tại trong list
{
	NODE_KHACHHANG* p = lkh.pHead;
	while (p != NULL)
	{
		if (p->khachhang.SoDT == t) return true;
		p = p->pNext;
	}
	return false;
}

int CheckDiachiKH(LIST_KHACHHANG lkh, string t) //kiểm tra Dịa chỉ khách hàng có tồn tại trong list
{
	NODE_KHACHHANG* p = lkh.pHead;
	while (p != NULL)
	{
		if (p->khachhang.DiaChi == t) return true;
		p = p->pNext;
	}
	return false;
}

int CheckCmndKH(LIST_KHACHHANG lkh, string t) //kiểm tra chứng minh nhân dân khách hàng có tồn tại trong list
{
	NODE_KHACHHANG* p = lkh.pHead;
	while (p != NULL)
	{
		if (p->khachhang.CMND == t) return true;
		p = p->pNext;
	}
	return false;
}

int CheckGioiTinhKH(LIST_KHACHHANG lkh, string t) //kiểm tra Giới tính khách hàng có tồn tại trong list
{
	NODE_KHACHHANG* p = lkh.pHead;
	while (p != NULL)
	{
		if (p->khachhang.GioiTinh == t) return true;
		p = p->pNext;
	}
	return false;
}

int CheckQuoctichKH(LIST_KHACHHANG lkh, string t) //kiểm tra Quốc tịch khách hàng có tồn tại trong list
{
	NODE_KHACHHANG* p = lkh.pHead;
	while (p != NULL)
	{
		if (p->khachhang.QuocTich == t) return true;
		p = p->pNext;
	}
	return false;
}

//====================================== KIỂM TRA THÔNG TIN NHẬP VÀO KHÁCH HÀNG =====================================
//================ kiểm tra có rỗng thông tin khách hàng khi nhập vào không ==================
int KT_RongMaKH(KHACHHANG kh)
{
	if (kh.MaKH == "")
		return 1;
	return 0;
}
int KT_RongTenKH(KHACHHANG kh)
{
	if (kh.TenKH == "")
		return 1;
	return 0;
}
int KT_RongSodtKH(KHACHHANG kh)
{
	if (kh.SoDT == "")
		return 1;
	return 0;
}
int KT_RongDiachiKH(KHACHHANG kh)
{
	if (kh.DiaChi == "")
		return 1;
	return 0;
}
int KT_RongGtKH(KHACHHANG kh)
{
	if (kh.GioiTinh == "")
		return 1;
	return 0;
}
int KT_RongCmndKH(KHACHHANG kh)
{
	if (kh.CMND == "")
		return 1;
	return 0;
}
int KT_RongQuocTichKH(KHACHHANG kh)
{
	if (kh.QuocTich == "")
		return 1;
	return 0;
}

// =============== kiem tra trung mã khách hàng khi nhập ==================
int KT_TrungMaKH(LIST_KHACHHANG lkh, KHACHHANG kh)
{
	int dem = 0;
	for (NODE_KHACHHANG* k = lkh.pHead; k != NULL; k = k->pNext)
	{
		if (k->khachhang.MaKH == kh.MaKH)
		{
			dem++;
		}
	}
	if (dem != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//================ Kiem Tra trung chứng minh nhân dân khách hàng =================
int KT_TrungCmndKH(LIST_KHACHHANG& lkh, KHACHHANG kh)
{
	int dem = 0;
	for (NODE_KHACHHANG* k = lkh.pHead; k != NULL; k = k->pNext)
	{
		if (k->khachhang.CMND == kh.CMND)
		{
			dem++;
		}
	}
	if (dem != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//================= Kiem Tra trung So Dien Thoai khách hàng ===================
int KT_TrungSodtKH(LIST_KHACHHANG& lkh, KHACHHANG kh)
{
	int dem = 0;
	for (NODE_KHACHHANG* k = lkh.pHead; k != NULL; k = k->pNext)
	{
		if (k->khachhang.SoDT == kh.SoDT)
		{
			dem++;
		}
	}
	if (dem != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//================== Kiem tra ten khách hàng có phải chữ không ================= 
int KT_DinhDangTenKH(KHACHHANG kh)
{
	int n = kh.TenKH.length();
	int dem = 0;
	if (kh.TenKH[0] == ' ')
	{
		return 0;
	}
	if (kh.TenKH[n - 1] == ' ')
	{
		return 0;
	}
	for (int i = 0; i < kh.TenKH.length(); i++)
	{
		if (kh.TenKH[i] >= 'a' && kh.TenKH[i] <= 'z' || kh.TenKH[i] >= 'A' && kh.TenKH[i] <= 'Z' || kh.TenKH[i] == ' ')
		{
			dem = dem + 1;
		}
		else if (kh.TenKH[i] >= '0' && kh.TenKH[i] <= '9' || kh.TenKH[i] < 'a' || kh.TenKH[i] > 'z' || kh.TenKH[i] < 'A' || kh.TenKH[i] > 'Z')
		{
			return 0;
		}
	}
	if (dem == kh.TenKH.length())
		return 1;
	else
		return 0;
}

//================== Kiem tra Quốc tịch khách hàng co phải chữ không ================= 
int KT_DinhDangQuocTichKH(KHACHHANG kh)
{
	int n = kh.QuocTich.length();
	int dem = 0;
	if (kh.QuocTich[0] == ' ')
	{
		return 0;
	}
	if (kh.QuocTich[n - 1] == ' ')
	{
		return 0;
	}
	for (int i = 0; i < kh.QuocTich.length(); i++)
	{
		if (kh.QuocTich[i] >= 'a' && kh.QuocTich[i] <= 'z' || kh.QuocTich[i] >= 'A' && kh.QuocTich[i] <= 'Z' || kh.QuocTich[i] == ' ')
		{
			dem = dem + 1;
		}
		else if (kh.QuocTich[i] >= '0' && kh.QuocTich[i] <= '9' || kh.QuocTich[i] < 'a' || kh.QuocTich[i] > 'z' || kh.QuocTich[i] < 'A' || kh.QuocTich[i] > 'Z')
		{
			return 0;
		}
	}
	if (dem == kh.QuocTich.length())
		return 1;
	else
		return 0;
}

//================== Kiem tra Dia Chi khách hàng co phải chữ không ================= 
int KT_DinhDangDiaChiKH(KHACHHANG kh)
{
	int n = kh.DiaChi.length();
	int dem = 0;
	if (kh.DiaChi[0] == ' ')
	{
		return 0;
	}
	if (kh.DiaChi[n - 1] == ' ')
	{
		return 0;
	}
	for (int i = 0; i < kh.DiaChi.length(); i++)
	{
		if (kh.DiaChi[i] >= 'a' && kh.DiaChi[i] <= 'z' || kh.DiaChi[i] >= 'A' && kh.DiaChi[i] <= 'Z' || kh.DiaChi[i] == ' ')
		{
			dem = dem + 1;
		}
		else if (kh.DiaChi[i] >= '0' && kh.DiaChi[i] <= '9' || kh.DiaChi[i] < 'a' || kh.DiaChi[i] > 'z' || kh.DiaChi[i] < 'A' || kh.DiaChi[i] > 'Z')
		{
			return 0;
		}
	}
	if (dem == kh.DiaChi.length())
		return 1;
	else
		return 0;
}

int KT_DinhDangSodtKH(KHACHHANG kh)
{
	int dem = 0;
	for (int i = 0; i < kh.SoDT.length(); i++)
	{
		if (!(kh.SoDT[i] >= '0' && kh.SoDT[i] <= '9'))
		{
			return 0;
			break;
		}
		else
		{
			dem++;
		}
	}
	if (dem == kh.SoDT.length())
		return 1;
	else
		return 0;
}

int KT_DinhDangCMNDKH(KHACHHANG kh)
{
	int dem = 0;
	for (int i = 0; i < kh.CMND.length(); i++)
	{
		if (!(kh.CMND[i] >= '0' && kh.CMND[i] <= '9'))
		{
			return 0;
			break;
		}
		else
		{
			dem++;
		}
	}
	if (dem == kh.CMND.length())
		return 1;
	else
		return 0;
}

int KT_DinhDangGoiTinhKH(KHACHHANG kh)
{
	int dem = 0;
	for (int i = 0; i < kh.GioiTinh.length(); i++)
	{
		if (kh.GioiTinh[i] >= 'a' && kh.GioiTinh[i] <= 'z' || kh.GioiTinh[i] >= 'A' && kh.GioiTinh[i] <= 'Z')
		{
			dem = dem + 1;
		}
		else if (kh.GioiTinh[i] >= '0' && kh.GioiTinh[i] <= '9' || kh.GioiTinh[i] < 'a' || kh.GioiTinh[i] > 'z' || kh.GioiTinh[i] < 'A' || kh.GioiTinh[i] > 'Z')
		{
			return 0;
		}
	}
	if (dem == kh.GioiTinh.length())
		return 1;
	else
		return 0;
}

void DocFileKH(LIST_KHACHHANG &lkh)
{
	/*int k = 0;
	fstream fin;
	fin.open("DanhsachKH.txt", fstream::in | fstream::app);
	if (fin.is_open()) {
		string word;
		while (getline(fin, word)) {
			cout << word << "\n";
			for (int i = 0; i < word.length(); i++)
			{
				if (word[i] == ',') {
					k = k + 1;
				}
				else {
					if (k == 0)
					{
						kh.MaKH = kh.MaKH + word[i];
					}
					else if (k == 1) {
						kh.TenKH = kh.TenKH + word[i];
					}
					else if (k == 2) {
						kh.SoDT = kh.SoDT + word[i];
					}
					else if (k == 3) {
						kh.DiaChi = kh.DiaChi + word[i];
					}
					else if (k == 4) {
						kh.CMND = kh.CMND + word[i];
					}
					else if (k == 5) {
						kh.GioiTinh = kh.GioiTinh + word[i];
					}
					else if (k == 6)
					{
						kh.QuocTich = kh.QuocTich + word[i];
					}
				}
			}
			NODE_KHACHHANG* p = khoitaoNode(kh);
			addhead(lkh,p);

		}
		fin.close();
	}*/
	ifstream fin;
	fin.open("DanhsachKH.txt", ios_base::in);
	while (fin.eof() == false)
	{
		KHACHHANG kh;
		getline(fin, kh.MaKH, ',');
		getline(fin, kh.TenKH, ',');
		getline(fin, kh.SoDT, ',');
		getline(fin, kh.CMND, ',');
		getline(fin, kh.GioiTinh, ',');
		getline(fin, kh.DiaChi, ',');
		getline(fin, kh.QuocTich);

		NODE_KHACHHANG* p = khoitaoNode(kh);
		addTail(lkh, p);
		//cout << "\n";
		//        f.ignore(1);
		
	}
	fin.close();
}

void SaveKH(LIST_KHACHHANG& lkh,KHACHHANG kh)
{
	fstream f;
	f.open("DanhsachKH.txt",ios::out);
	for (NODE_KHACHHANG* k = lkh.pHead; k != NULL; k = k->pNext)
	   {

		f << k->khachhang.MaKH << ",";
		f << k->khachhang.TenKH << ",";
		f << k->khachhang.SoDT << ",";
		f << k->khachhang.CMND << ",";
		f << k->khachhang.GioiTinh << ",";
		f << k->khachhang.DiaChi << ",";
		f << k->khachhang.QuocTich;
		if (k->pNext != NULL)
		{
			f << endl;
		}
		else
		{
			break;
		}
		}
	f.close();
}

void create(LIST_KHACHHANG& lkh, KHACHHANG kh)
{
//	Khoitaolist(lkh);
//	DocFileKH(lkh);
	ShowCur(1);
	do
	{
		gotoXY(97, 15);
		getline(cin, kh.MaKH);
		XoaManHinhTuyChon(148, 15, 35, 1);
		if (KT_RongMaKH(kh) == 1)
		{
			gotoXY(148, 15);
			cout << "=> Ma Khach Hang Dang Rong,Nhap Lai";
		}
		if (KT_TrungMaKH(lkh,kh) == 0)
		{
			XoaManHinhTuyChon(97, 15, 35, 1);
			gotoXY(148, 15);
			cout << "=> Ma Khach Hang Bi Trung,Nhap Lai";
		}
	} while (KT_RongMaKH(kh) == 1 || KT_TrungMaKH(lkh, kh) == 0);

	do
	{
		gotoXY(97, 18);
		getline(cin, kh.TenKH);
		DinhDangChuoi(kh.TenKH);
		XoaManHinhTuyChon(148, 18, 35, 1);
		if (KT_RongTenKH(kh) == 1)
		{
			gotoXY(148, 18);
			cout << "=> Ten Khach Hang Rong,Nhap Lai";
		}
		if (KT_DinhDangTenKH(kh) == 0)
		{
			XoaManHinhTuyChon(97, 18, 35, 1);
			gotoXY(148, 18);
			cout << "=>Ten Khach Hang Chua So,Nhap Lai";
		}
	} while (KT_RongTenKH(kh) == 1 || KT_DinhDangTenKH(kh) == 0);

	do
	{
		gotoXY(97, 21);
		getline(cin, kh.SoDT);
		XoaManHinhTuyChon(148,21,35,1);
		if (KT_RongSodtKH(kh) == 1)
		{
			gotoXY(148, 21);
			cout << "=>So Dien Thoai Rong,Nhap Lai";
		}
		if (KT_DinhDangSodtKH(kh) == 0)
		{
			XoaManHinhTuyChon(97, 21, 35, 1);
			gotoXY(148, 21);
			cout << "=>SDT Sai Dinh Dang, Nhap Lai";
		}
		if (KT_TrungSodtKH(lkh,kh) == 1)
		{
			XoaManHinhTuyChon(97, 21, 35, 1);
			gotoXY(148, 21);
			cout << "=>SDT Bi Trung, Nhap Lai";
		}
	} while (KT_RongSodtKH(kh) == 1 || KT_DinhDangSodtKH(kh) == 0 || KT_TrungSodtKH(lkh, kh) == 1);

	do
	{
		gotoXY(97, 24);
		getline(cin, kh.DiaChi);
		XoaManHinhTuyChon(148, 24, 35, 1);
		if (KT_RongDiachiKH(kh) == 1)
		{
			gotoXY(148, 24);
			cout << "=>Dia Chi Rong,Nhap Lai";
		}
		if (KT_DinhDangDiaChiKH(kh) == 0)

		{
			XoaManHinhTuyChon(97, 24, 35, 1);
			gotoXY(148, 24);
			cout << "=>Dia Chi Dinh Dang Sai, Nhap Lai";
		}
	} while (KT_RongDiachiKH(kh) == 1 || KT_DinhDangDiaChiKH(kh) == 0);

	do
	{
		gotoXY(97, 27);
		getline(cin, kh.CMND);
		XoaManHinhTuyChon(148, 27, 35, 1);
		if (KT_RongCmndKH(kh) == 1)
		{
			gotoXY(148, 27);
			cout << "=>CMND Rong, Nhap Lai";
		}
		if (KT_DinhDangCMNDKH(kh) == 0)
		{
			XoaManHinhTuyChon(97, 27, 35, 1);
			gotoXY(148, 27);
			cout << "=>CMND Dinh Dang Sai,Nhap Lai";
		}
		if (KT_TrungCmndKH(lkh, kh) == 1)
		{
			XoaManHinhTuyChon(97, 27, 35, 1);
			gotoXY(148, 27);
			cout << "=>CMND Bi Trung,Nhap Lai";
		}
	} while (KT_RongCmndKH(kh) == 1 || KT_DinhDangCMNDKH(kh) == 0 || KT_TrungCmndKH(lkh, kh) == 1);

	do
	{
		gotoXY(97, 30);
		getline(cin, kh.GioiTinh);
		XoaManHinhTuyChon(148, 30, 35, 1);
		if (KT_RongGtKH(kh) == 1)
		{
			gotoXY(148, 30);
			cout << "=>Gioi Tinh Rong,Nhap Lai";
		}
		if (KT_DinhDangGoiTinhKH(kh) == 0)
		{
			XoaManHinhTuyChon(97, 30, 35, 1);
			gotoXY(148, 30);
			cout << "=>Gioi Tinh Sai, Nhap Lai";
		}
	} while (KT_RongGtKH(kh) == 1 || KT_DinhDangGoiTinhKH(kh) == 0);

	do
	{
		gotoXY(97, 33);
		getline(cin, kh.QuocTich);
		XoaManHinhTuyChon(148, 33, 35, 1);
		if (KT_RongQuocTichKH(kh) == 1)
		{
			gotoXY(148, 33);
			cout << "Quoc Tich Rong,Nhap Lai";
		}
		if (KT_DinhDangQuocTichKH(kh) == 0)
		{
			XoaManHinhTuyChon(97, 33, 35, 1);
			gotoXY(148, 33);
			cout << "Quoc Tich Chua So,Nhap Lai";
		}
	} while (KT_RongQuocTichKH(kh) == 1 || KT_DinhDangQuocTichKH(kh) == 0);

	/*HienConTro();
	gotoXY(71, 55);
	cout << "Luu thanh Cong";
	system("pause");*/ 

	NODE_KHACHHANG* p = khoitaoNode(kh);
	addTail(lkh, p);
	SaveKH(lkh,kh);
}

void Print(LIST_KHACHHANG lkh) //xuất danh sách khách hàng từ file ra
{
	int j = 17;
	for (NODE_KHACHHANG* p = lkh.pHead; p != NULL; p = p->pNext)
	{
		VeHCN(65, 16, 10, 2, 3);
		gotoXY(66, j);
		cout << p->khachhang.MaKH;
		VeHCN(76, 16, 32, 2, 3);
		gotoXY(77, j);
		cout << p->khachhang.TenKH;
		VeHCN(109, 16, 15, 2, 3);
		gotoXY(110, j);
		cout << p->khachhang.SoDT;
		VeHCN(125, 16, 15, 2, 3);
		gotoXY(126, j);
		cout << p->khachhang.DiaChi;
		VeHCN(141, 16, 15, 2, 3);
		gotoXY(142, j);
		cout << p->khachhang.CMND;
		VeHCN(157, 16, 15, 2, 3);
		gotoXY(158, j);
		cout << p->khachhang.GioiTinh;
		VeHCN(173, 16, 15, 2, 3);
		gotoXY(174, j);
		cout << p->khachhang.QuocTich;
		cout << endl;
		j + 3;
	}
}

void Print_1_KH(KHACHHANG kh, int x, int y)
{
	gotoXY(x, y);
	cout << "Ma Khach Hang: " << kh.MaKH << endl;
	gotoXY(x, y+1);
	cout << "Ten Khach Hang: " << kh.TenKH << endl;
	gotoXY(x, y+2);
	cout << "CMND: " << kh.CMND << endl;
	gotoXY(x, y+3);
	cout << "So Dien Thoai: " << kh.SoDT << endl;
	gotoXY(x, y+4);
	cout << "Gioi Tinh: " << kh.GioiTinh << endl;
	gotoXY(x, y+5);
	cout << "Dia Chi: " << kh.DiaChi << endl;
	gotoXY(x, y+6);
	cout << "Quoc Tich: " << kh.QuocTich << endl;
}

void ThuocTinhKH()
{
	gotoXY(68, 17);
	cout << "Ma Khach Hang: ";
	gotoXY(68, 19);
	cout << "Ten Khach Hang: ";
	gotoXY(68, 21);
	cout << "CMND: ";
	gotoXY(68, 23);
	cout << "So Dien Thoai: ";
	gotoXY(68, 25);
	cout << "Gioi Tinh: ";
	gotoXY(68, 27);
	cout << "Dia Chi: ";
	gotoXY(68, 29);
	cout << "Quoc Tich: ";
}

void XoaDauKH(LIST_KHACHHANG& lkh) {
	//nếu danh sách rỗngg
	if (lkh.pHead == NULL) {
		return;
	}
	else {
		NODE_KHACHHANG* p = lkh.pHead;//node p là node sẽ xóa
		lkh.pHead = lkh.pHead->pNext;
		delete p;
	}
}

void XoaCuoiKH(LIST_KHACHHANG& lkh)
{
	//nếu danh sách rỗng
	if (lkh.pHead == NULL)
	{
		return;
	}
	//trường hợp danh sách có phần tử
	if (lkh.pHead->pNext == NULL)
	{
		XoaDauKH(lkh);
		return;
	}
	//duyệt từ đầu danh sách tới thằng kế cuối
	for (NODE_KHACHHANG* k = lkh.pHead; k != NULL; k = k->pNext)
	{
		//phát hiện thằng kế cuối
		if (k->pNext == lkh.pTail)
		{
			delete lkh.pTail; //xóa đi phần tử cuối
			k->pNext = NULL;//cho con trỏ của node thằng kế cuối trỏ đến vùng nhớ null
			lkh.pTail = k;
		}
	}
}

int checkThuocTinhKH(string thuocTinh) {
	if (thuocTinh == "Ma Khach Hang" || thuocTinh == "Ten Khach Hang" || thuocTinh == "So Dien Thoai" || thuocTinh == "Dia Chi" || thuocTinh == "CMND" || thuocTinh == "Gioi Tinh" || thuocTinh == "Quoc Tich ") {
		return 1;
	}
	return 0;
}

int soKhachHang(LIST_KHACHHANG lkh);

void TimKiemTTMaKH(LIST_KHACHHANG lkh )
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

	VeHCN(75, 13, 35, 2, 3); // Vẽ khung Tìm kiếm thông tin
//	ToMauHCN(80, 13, 30, 2, 255);
	gotoXY(81, 14);
	textcolor(7);
	cout << "Tim Kiem Thong Tin Khach Hang";
	VeHCN(75, 16, 35, 2, 3);
	gotoXY(76, 17);
	cout << "Nhap Ma KH can tim kiem: |";
	VeHCN(73, 25 + soKhachHang(lkh) + 9, 10, 2, 3); // Vẽ khung quay lai
	gotoXY(74, 25 + soKhachHang(lkh) + 10);
	cout << "Quay lai.";
	//VeHCN(120, 25 + soKhachHang(lkh) + 9, 10, 2, 3); // Vẽ khung Tiếp tục
	//gotoXY(121, 25 + soKhachHang(lkh) + 10);
	//cout << "Tiep tuc.";
	int x = 100;
	char c[100];
	int y = 10;
	int z = 0;
	int dem = 1;
	int demBreak = 0;

	do
	{
		ShowCur(1);
		do {
		
			gotoXY(x++, 17);
			ShowCur(1);
			c[z] = _getche();// A
			if (c[z] >= 'a' && c[z] <= 'z') {
				c[z] -= 32;
			}
			XoaManHinhTuyChon(84, 19, 39, soKhachHang(lkh) + 10); //rs khung thông tin
		} while (c[z] == '\r');
		int Y = 20;
		ShowCur(0);

		VeHCN(83, 19, 40, 1 + soKhachHang(lkh) + 10, 2); // Khung thong tin
//		ToMauHCN(83, 17, 40, 12, 244);
		textcolor(7);
		for (NODE_KHACHHANG* k = lkh.pHead; k != NULL; k = k->pNext)
		{
			for (int i = 0; i < k->khachhang.MaKH.length(); i++)
			{
				if (i == z)
				{
					if (z == 0) {
						if (c[z] == k->khachhang.MaKH[i])
						{
							gotoXY(85, Y++);
							cout << k->khachhang.MaKH << "  " << k->khachhang.TenKH << endl;
							gotoXY(85, Y++);
							cout << "-------------------------------------" << endl;
							demBreak = 0;
							//break;
						}
					}
					else if (z > 0 && z < k->khachhang.MaKH.length() - 1) {
						if (c[z] == k->khachhang.MaKH[i] && c[z - 1] == k->khachhang.MaKH[i - 1])
						{
							gotoXY(85, Y++);
							cout << k->khachhang.MaKH << "  " << k->khachhang.TenKH << endl;
							gotoXY(85, Y++);
							cout << "-------------------------------------" << endl;
							demBreak = 0;
							//break;

						}
					}
					else if (z == k->khachhang.MaKH.length() - 1) {
						int dem = 0;
						for (int i = 0; i < k->khachhang.MaKH.length(); i++) {
							if (k->khachhang.MaKH[i] == c[i]) {
								dem++;
							}
						}
						if (dem == k->khachhang.MaKH.length()) {
							XoaManHinhTuyChon(84,22, 39, 12);
							Print_1_KH(k->khachhang, 85, 20);
							Sleep(2000);
							break;
							//if (batSuKien(63, 30 + soKhachHang(lkh) + 7, 10, 2)) { // Bắt sự kiện quay lại
							//	demBreak = 3;
							////	break;
							//}
							
						}
						
					}
					
				}
				
			}
			
		}
		z++;
	} while (demBreak <= 2);
	if (batSuKien(63, 30 + soKhachHang(lkh) + 7, 10, 2)) { // Bắt sự kiện quay lại
		//demBreak = 3;
		return;
	}
}

int soKhachHang(LIST_KHACHHANG lkh) {
	int soKH = 1;
	for (NODE_KHACHHANG* p = lkh.pHead; p != NULL; p = p->pNext) {
		soKH++;
	}
	return soKH;
}

void listTenKH(LIST_KHACHHANG l) {
	int i = 1;
	int Y = 15;
	for (NODE_KHACHHANG* p = l.pHead; p != NULL; p = p->pNext) {
		gotoXY(80, Y++);
		cout << "Ten khach hang thu " << i++ << ": " << p->khachhang.TenKH << endl;
	}
}
void ChangeKH(LIST_KHACHHANG& l, KHACHHANG kh) {//hàm thay đổi thông tin khách hàng
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

	string thuocTinh;
	string changed;
	int dem = 0;
	VeHCN(79, 13, 50, 1 + soKhachHang(l), 2); // Khung hien ten khach hang có số khách hàng là int
	gotoXY(81, 14);
	cout << "Danh sach ten khach hang." << endl;
	listTenKH(l);
	gotoXY(70, 18 + soKhachHang(l) + 4); // Khi số KH tăng thì cái này
	cout << "Nhap ten khach hang can Sua: ";
	rewind(stdin);
	VeHCN(113, 18 + soKhachHang(l) + 3, 20, 2, 5); // Khung nhap ten khach hang can xoa
	VeHCN(90, 18 + soKhachHang(l) + 7, 10, 2, 3); // Khung huy
	gotoXY(91, 18 + soKhachHang(l) + 8);
	cout << "Huy";
	VeHCN(120, 18 + soKhachHang(l) + 7, 10, 2, 3); // Khung dong y
	gotoXY(121, 18 + soKhachHang(l) + 8);
	cout << "Dong y";
	do {
		gotoXY(114, 18 + soKhachHang(l) + 4);
		ShowCur(1); // Hien con tro
		getline(cin, kh.TenKH);
		XoaManHinhTuyChon(114, 18 + soKhachHang(l) + 4, 33, 1);
		if (!(CheckTenKH(l, kh.TenKH)))
		{
			XoaManHinhTuyChon(116, 18 + soKhachHang(l) + 4,60,1);
			gotoXY(116, 18 + soKhachHang(l));
			cout << "=>Ten Khach hang khong co trong danh sach, Nhap lai";
		}
		if (KT_DinhDangTenKH(kh) == 0)
		{
			XoaManHinhTuyChon(116, 18 + soKhachHang(l) + 4, 60, 1);
			gotoXY(116, 18 + soKhachHang(l));
			cout << "=>Ten Khach hang Dinh dang khong dung, Nhap lai";
		}
		if (KT_RongTenKH(kh) == 1)
		{
			XoaManHinhTuyChon(116, 18 + soKhachHang(l) + 4, 60, 1);
			gotoXY(116, 18 + soKhachHang(l));
			cout << "=>Ten Khach hang dang rong, Nhap lai";
		}
	} while (!(CheckTenKH(l, kh.TenKH)) || KT_DinhDangTenKH(kh) == 0 || KT_RongTenKH(kh) == 1);

	if (batSuKien(81, 34 + soKhachHang(l), 8, 2)) {//bắt sự kiện hủy
		return;
	}

	else if (batSuKien(107, 34 + soKhachHang(l), 10, 2)) {//bắt sự kiện đồng ý
		ShowCur(0);
		VeHCN(63, 12, 133, 39, 3);
		ToMauHCN(63, 12, 133, 39, 3);
//		system("cls");

		VeHCN(79, 14, 50, 10, 2); // Vẽ HCN cho thông tin Khach hang
		for (NODE_KHACHHANG* q = l.pHead; q != NULL; q = q->pNext) {
			if (q->khachhang.TenKH == kh.TenKH) {
				Print_1_KH(q->khachhang,80,15);
				dem++;
			}
		}
		// Vẽ các khung thuộc tính
		VeHCN(75, 30, 10, 2, 3); // Vẽ khung Mã KH
		gotoXY(78, 31);
		cout << "Ma KH";

		VeHCN(92, 30, 10, 2, 3); // Vẽ khung Tên KH
		gotoXY(94, 31);
		cout << "Ten KH";

		VeHCN(109, 30, 12, 2, 3); // Vẽ khung Gioi tinh
		gotoXY(111, 31);
		cout << "So DT";

		VeHCN(126, 30, 10, 2, 3); // Vẽ khung So Dt
		gotoXY(128, 31);
		cout << "CMND";

		VeHCN(75, 34, 10, 2, 3); // Vẽ khung Dia chi
		gotoXY(76, 35);
		cout << "Gioi Tinh";

		VeHCN(92, 34, 11, 2, 3); // Vẽ khung So dien thoai
		gotoXY(93, 35);
		cout << "Dia Chi";

		VeHCN(109, 34, 12, 2, 3); // Vẽ khung Quoc Tich
		gotoXY(111, 35);
		cout << "Quoc Tich";
	}

	for (NODE_KHACHHANG* q = l.pHead; q != NULL; q = q->pNext) {
		if (q->khachhang.TenKH == kh.TenKH) {
			if (batSuKien(67, 38, 10, 2)) { // Ma khach hang
				do {
					
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->khachhang.MaKH << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					kh.MaKH = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_TrungMaKH(l, kh) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ma khach hang trung, vui long nhap lai!!!";
					}
					if (KT_RongMaKH(kh) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ma khach hang dang rong, vui long nhap lai!!!";
					}
				} while (KT_TrungMaKH(l,kh) == 0 || KT_RongMaKH(kh) == 1);
				q->khachhang.MaKH = kh.MaKH = changed;
			}
			else if (batSuKien(82, 38, 10, 2)) { // Ten khach hang
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->khachhang.TenKH << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(105, 45);
					getline(cin, changed);
					kh.TenKH = changed;
					XoaManHinhTuyChon(105, 47, 50, 1);
					if (KT_RongTenKH(kh) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ten khach hang dang rong, vui long nhap lai!!!";
					}
					if (KT_DinhDangTenKH(kh) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ten khach hang dinh dang sai, vui long nhap lai!!!";
					}
				} while ( KT_RongTenKH(kh) == 1 || KT_DinhDangTenKH(kh) == 0);
				q->khachhang.TenKH = kh.TenKH = changed;
			}
			else if (batSuKien(114, 38, 10, 2)) { // chứng minh nhân dân
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->khachhang.CMND << " muon thanh doi thanh: ";
					rewind(stdin); 
					gotoXY(100, 45);
					getline(cin, changed);
					kh.CMND = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_RongCmndKH(kh) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>CMND khach hang dang rong, vui long nhap lai!!!";
					}
					if (KT_TrungCmndKH(l, kh) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>CMND khach hang bi trung, vui long nhap lai!!!";
					}
					if (KT_DinhDangCMNDKH(kh) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>CMND khach hang dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongCmndKH(kh) == 1 || KT_TrungCmndKH(l,kh) == 1 || KT_DinhDangCMNDKH(kh) == 0);
				q->khachhang.CMND = kh.CMND = changed;
			}
			else if (batSuKien(98, 38, 10, 2)) { // số điện thoại
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->khachhang.SoDT << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					kh.SoDT = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_RongSodtKH(kh) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>So dien thoai khach hang dang rong, vui long nhap lai!!!";
					}
					if (KT_TrungSodtKH(l, kh) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>So dien thoai khach hang bi trung, vui long nhap lai!!!";
					}
					if (KT_DinhDangSodtKH(kh) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>So dien thoai khach hang dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongSodtKH(kh) == 1 ||KT_TrungSodtKH(l,kh) == 1 || KT_DinhDangSodtKH(kh) == 0);
				q->khachhang.SoDT = kh.SoDT = changed;
			}
			else if (batSuKien(67, 43, 10, 2)) { // giới tính
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->khachhang.GioiTinh << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(95, 45);
					getline(cin, changed);
					kh.GioiTinh = changed;
					XoaManHinhTuyChon(95, 47, 50, 1);
					if (KT_RongGtKH(kh) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Gioi tinh khach hang dang rong, vui long nhap lai!!!";
					}
					/*if (KT_DinhDangGoiTinhKH(kh) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Gioi tinh khach hang dinh dang sai, vui long nhap lai!!!";
					}*/
				} while (KT_RongGtKH(kh) == 1);
				q->khachhang.GioiTinh = kh.GioiTinh = changed;
			}
			else if (batSuKien(82, 43, 11, 2)) { // Địa Chỉ
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->khachhang.DiaChi << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(105, 45);
					getline(cin, changed);
					kh.DiaChi = changed;
					XoaManHinhTuyChon(105, 47, 50, 1);
					if (KT_RongDiachiKH(kh) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Dia chi khach hang dang rong, vui long nhap lai!!!";
					}
					if (KT_DinhDangDiaChiKH(kh) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Dia chi khach hang dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongDiachiKH(kh) == 1 || KT_DinhDangDiaChiKH(kh) == 0);
				q->khachhang.DiaChi = kh.DiaChi = changed;
			}
			else if (batSuKien(98, 44, 10, 2)) { // Quốc tịch
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->khachhang.QuocTich << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					kh.QuocTich = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_RongQuocTichKH(kh) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Quoc tich khach hang dang rong, vui long nhap lai!!!";
					}
					if (KT_DinhDangQuocTichKH(kh) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Quoc tich khach hang dangdinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongQuocTichKH(kh) == 1 || KT_DinhDangQuocTichKH(kh) == 0);
				q->khachhang.QuocTich = kh.QuocTich = changed;
			}
		}
	}
	gotoXY(70, 50);
	cout << thuocTinh << " da duoc thay doi!!!" << endl;
	gotoXY(140, 50);
	system("pause");
}

void XoaBatKiKH(LIST_KHACHHANG& l, KHACHHANG kh)
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);
	ShowCur(1);
	VeHCN(79, 13, 50, 1 + soKhachHang(l), 2); // Khung hien ten khach hang có số khách hàng là int
	gotoXY(81, 14);
	cout << "Danh sach ten khach hang." << endl;
	listTenKH(l);
	gotoXY(70, 18 + soKhachHang(l) + 4); // Khi số KH tăng thì cái này
	cout << "Nhap ten khach hang can xoa: ";
	rewind(stdin);
	VeHCN(113, 18 + soKhachHang(l) + 3, 20, 2, 5); // Khung nhap ten khach hang can xoa
	VeHCN(90, 18 + soKhachHang(l) + 7, 10, 2, 3); // Khung huy
	gotoXY(91, 18 + soKhachHang(l) + 8);
	cout << "Huy";
	VeHCN(120, 18 + soKhachHang(l) + 7, 10, 2, 3); // Khung dong y
	gotoXY(121, 18 + soKhachHang(l) + 8);
	cout << "Dong y";
	do {
		gotoXY(114, 18 + soKhachHang(l) + 4);
		getline(cin, kh.TenKH);
		XoaManHinhTuyChon(114, 18 + soKhachHang(l) + 4, 33, 1);
		if ((CheckTenKH(l, kh.TenKH)) == 0)
		{
			XoaManHinhTuyChon(116, 18 + soKhachHang(l) + 4, 60, 1);
			gotoXY(116, 18 + soKhachHang(l));
			cout << "=>Ten Khach hang khong co trong danh sach, Nhap lai";
		}
		if (KT_DinhDangTenKH(kh) == 0)
		{
			XoaManHinhTuyChon(116, 18 + soKhachHang(l) + 4, 60, 1);
			gotoXY(116, 18 + soKhachHang(l));
			cout << "=>Ten Khach hang Dinh dang khong dung, Nhap lai";
		}
		if (KT_RongTenKH(kh) == 1)
		{
			XoaManHinhTuyChon(116, 18 + soKhachHang(l) + 4, 60, 1);
			gotoXY(116, 18 + soKhachHang(l));
			cout << "=>Ten Khach hang dang rong, Nhap lai";
		}
	} while ((CheckTenKH(l,kh.TenKH)) == 0 || KT_DinhDangTenKH(kh) == 0 || KT_RongTenKH(kh) == 1 || kh.TenKH == "\r");


	if (batSuKien(81, 34 + soKhachHang(l), 8, 2)) { // Bắt sự kiện hủy
		return;
	}

	else if (batSuKien(107, 34 + soKhachHang(l), 10, 2)) { // Bắt sự kiện đồng ý
		int dem = 0; // Xem tên khách hàng cần xóa có trong danh sách hay không
		for (NODE_KHACHHANG* p = l.pHead; p != NULL; p = p->pNext) {
			if (kh.TenKH == l.pHead->khachhang.TenKH) {
				XoaDauKH(l);
				gotoXY(100, 50);
				cout << "Xoa thanh cong." << endl;
				system("pause");
				dem++; // Nếu có tăng 1
				break;
			}
			else if (kh.TenKH == l.pTail->khachhang.TenKH) {
				XoaCuoiKH(l);
				gotoXY(100,50);
				cout << "Xoa thanh cong." << endl;
				system("pause");
				dem++;
				break;
			}
			else {
				NODE_KHACHHANG* q = p->pNext;
				if (q->khachhang.TenKH == kh.TenKH) {
					p->pNext = q->pNext;
					gotoXY(100, 50);
					cout << "Xoa thanh cong." << endl;
					system("pause");
					dem++;
					break;
				}
			}
		}
		if (dem == 0) { //  Nếu tên khách hàng cần xóa không có trong danh sách khách hàng
			gotoXY(45, 18);
			cout << kh.TenKH << " khong co trong danh sach." << endl;
			system("pause");
		}
	}
}

//hàm lấy tên của Khách hàng ra để đi sắp xếp
string Ten_Khach_hang(KHACHHANG kh)
{
	//khởi tạo độ dài chuỗi nhập tên kh
	int length = kh.TenKH.length();
	int i;
	//duyệt từ cuối về đầu chuỗi
	for (i = length - 1; i >= 0; i--)
	{
		//nếu duyệt cho phần tử thứ i gặp khoảng trống đầu tiên thì sẽ kết thúc lấy chuỗi
		if (kh.TenKH[i] == ' ')
		{
			break;
		}
	}
	//hàm trả về chuỗi mình đã cắt
	return kh.TenKH.substr(i + 1);

}

void DoiCho(KHACHHANG& a, KHACHHANG& b)
{
	KHACHHANG temp = a;
	a = b;
	b = temp;
}

//hàm sắp xếp theo tên khách hàng
void SapXeptheoTenKhachhang(LIST_KHACHHANG& lkh, KHACHHANG kh)
{
	int dem = 1;
	//hàm duyệt list khách hàng từ đầu đến cuối danh sách
	for (NODE_KHACHHANG* h = lkh.pHead; h != NULL; h = h->pNext)
	{
		for (NODE_KHACHHANG* g = lkh.pHead; g != NULL; g = g->pNext)
		{
			//tạo 2 thằng khách hàng để đi so sánh với nhau
			string TenKH = Ten_Khach_hang(h->khachhang);
			string TenKH1 = Ten_Khach_hang(g->khachhang);
			//hàm so sánh từng phần tử trong Tên khách hàng
			//nếu hàm trả về 0 thì 2 chuỗi bằng nhau
			if (TenKH != "" && TenKH1 != "") {
				if (_stricmp((char*)TenKH.c_str(), (char*)TenKH1.c_str()) == 0)
				{
					dem++;
				}
				//ngược lại nếu hèm trả về <0 tức là chuỗi tên khách hàng trước lớn hơn mã sau
				else if (_stricmp((char*)TenKH.c_str(), (char*)TenKH1.c_str()) < 0)
				{
					DoiCho(h->khachhang, g->khachhang);
				}
			}
		}
	}
	SaveKH(lkh, kh);
}

//hàm sắp xếp theo Mã khách hàng
void SapXeptheoMaKhachhang(LIST_KHACHHANG& lkh, KHACHHANG kh)
{
	int dem = 1;
	//hàm duyệt list khách hàng từ đầu đến cuối danh sách
	for (NODE_KHACHHANG* h = lkh.pHead; h != NULL; h = h->pNext)
	{
		for (NODE_KHACHHANG* g = lkh.pHead; g != NULL; g = g->pNext)
		{
			//tạo 2 thằng khách hàng để đi so sánh với nhau
			string MaKH = h->khachhang.MaKH;
			string MaKH1 = g->khachhang.MaKH;
			//hàm so sánh từng phần tử trong Tên khách hàng
			//nếu hàm trả về 0 thì 2 chuỗi bằng nhau
			if (MaKH != "" && MaKH1 != "") {                   // =================== Neu ko so sanh khi xuong dong MaKh = "" no se len dau
				if (_stricmp((char*)MaKH.c_str(), (char*)MaKH1.c_str()) == 0)
				{
					dem++;
				}
				//ngược lại nếu hèm trả về <0 tức là chuỗi tên khách hàng trước lớn hơn mã sau
				else if (_stricmp((char*)MaKH.c_str(), (char*)MaKH1.c_str()) < 0)
				{
					DoiCho(h->khachhang, g->khachhang);
				}
			}
		}
	}
	//SaveKH(lkh, kh);

}

void xuatdanhsachKhachHang(LIST_KHACHHANG l)
{

	ToMauHCN(63, 12, 133, 10, 76);//tô màu thanh thông tin
	ToMauHCN(63, 20, 133, 5, 111);//tô màu thanh trạng thái
	VeHCN(63, 12, 133, 39, 3);
	//VeHCN(63, 20, 133, 31, 1926);
	ToMauHCN(63, 24, 133, 29, 1926);//tô màu danh sách khách hàng
	HCNTextDong(63, 24, 134, 29);
	HCNText(63, 24, 134, 29);
	textcolor(1926);

	KHACHHANG kh;
	gotoXY(114, 15);
	textcolor(76);
	cout << "THONG TIN KHACH HANG";
	textcolor(1926);
	VeHCN(63, 20, 133, 31, 3);
	
	VeHCN(64, 14, 6, 2, 76);
	gotoXY(65, 15);
	cout << "Thoat";

	int j = 64;
	while (j < 196)
	{
		gotoXY(j, 23);
		cout << "_";
		j++;
	}
	textcolor(111);
	gotoXY(68, 22);
	cout << "MaKH";
	gotoXY(89, 22);
	cout << "TenKH";
	gotoXY(110, 22);
	cout << "SoDT";
	gotoXY(127, 22);
	cout << "CMND";
	gotoXY(140, 22);
	cout << "Gioi tinh";
	gotoXY(157, 22);
	cout <<"Dia Chi";
	gotoXY(178, 22);
	cout << "Quoc Tich";
	int a = 1;
	textcolor(1926);
		for (NODE_KHACHHANG* k = l.pHead; k != NULL; k = k->pNext)
		{
			gotoXY(66, 24 + a);
			cout << k->khachhang.MaKH;
			gotoXY(76, 24 + a);
			cout << k->khachhang.TenKH;
			gotoXY(108, 24 + a);
			cout << k->khachhang.SoDT;
			gotoXY(122, 24 + a);
			cout << k->khachhang.CMND;
			gotoXY(138, 24 + a);
			cout << k->khachhang.GioiTinh;
			gotoXY(151, 24 + a);
			cout << k->khachhang.DiaChi;
			gotoXY(172, 24 + a);
			cout << k->khachhang.QuocTich;

			//cout << endl;

			a = a + 2;

		}
		textcolor(7);
		do
		{
		if (batSuKien(57, 17, 5, 2))
		{
			break;
		}
		//break;
		} while (true);
}


//============================================================================= DANH SÁCH NHÂN VIÊN =================================================================

void KhoiTaoListNV(LIST_NHANVIEN& lnv)
{
	lnv.pHead = NULL;
	lnv.pTail = NULL;
}

NODE_NHANVIEN* KhoiTaoNodeNV(NHANVIEN nv)
{
    NODE_NHANVIEN* p = new NODE_NHANVIEN;
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        p->Nhanvien = nv;
        p->pNext = NULL;
        return p;
    }
}

//================ Kiem tra rong nhan vien ==================
int KT_RongTenNV(NHANVIEN nv)
{
	if (nv.TenNV == "")
		return 1;
	return 0;
}
bool KT_RongMaNV(NHANVIEN nv)
{
	if (nv.MaNV == "")
		return 1;
	return 0;
}
bool KT_RongMaCV(NHANVIEN nv)
{
	if (nv.MaCV == "")
		return 1;
	return 0;
}
int KT_RongSodtNV(NHANVIEN nv)
{
	if (nv.SoDT == "")
		return 1;
	return 0;
}
int KT_RongDiachiNV(NHANVIEN nv)
{
	if (nv.DiaChi == "")
		return 1;
	return 0;
}
int KT_RongGtNV(NHANVIEN nv)
{
	if (nv.GioiTinh == "")
		return 1;
	return 0;
}
int KT_RongNgaysinhNV(NHANVIEN nv)
{
	if (nv.NgaySinh == "")
		return 1;
	return 0;
}
int KT_RongNgayBdNV(NHANVIEN nv)
{
	if (nv.NgayNhanViec == "")
		return 1;
	return 0;
}
int KT_RongHethanNV(NHANVIEN nv)
{
	if (nv.NgayHetHanCV == "")
		return 1;
	return 0;
}

// =============== kiem tra trung ma nhan vien khi nhap ==================
int KT_TrungMaNV(LIST_NHANVIEN lnv, NHANVIEN nv)
{
	int dem = 0;
	for (NODE_NHANVIEN* k = lnv.pHead; k != NULL; k = k->pNext)
	{
		if (k->Nhanvien.MaNV == nv.MaNV)
		{
			dem++;
		}
	}
	if (dem != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//================ Kiem Tra trung ma cong viec nhan vien =================
int KT_TrungMaCV(LIST_NHANVIEN& lnv, NHANVIEN nv)
{
	int dem = 0;
	for (NODE_NHANVIEN* k = lnv.pHead; k != NULL; k = k->pNext)
	{
		if (k->Nhanvien.MaCV == nv.MaCV)
		{
			dem++;
		}
	}
	if (dem != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//================= Kiem Tra trung So Dien Thoai Nhan Vien ===================
int KT_TrungSDTNV(LIST_NHANVIEN& lnv, NHANVIEN nv)
{
	int dem = 0;
	for (NODE_NHANVIEN* k = lnv.pHead; k != NULL; k = k->pNext)
	{
		if (k->Nhanvien.SoDT == nv.SoDT)
		{
			dem++;
		}
	}
	if (dem != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int DinhDangGioiTinhNV(NHANVIEN nv)
{
	int dem = 0;
	for (int i = 0; i < nv.GioiTinh.length(); i++)
	{
		if (nv.GioiTinh[i] >= 'a' && nv.GioiTinh[i] <= 'z' || nv.GioiTinh[i] >= 'A' && nv.GioiTinh[i] <= 'Z')
		{
			dem = dem + 1;
		}
		else if (nv.GioiTinh[i] >= '0' && nv.GioiTinh[i] <= '9' || nv.GioiTinh[i] < 'a' || nv.GioiTinh[i] > 'z' || nv.GioiTinh[i] < 'A' || nv.GioiTinh[i] > 'Z')
		{
			return 0;
		}
	}
	if (dem == nv.GioiTinh.length())
		return 1;
	else
		return 0;
}

//================== Kiem tra ten nhan vien co phải chữ không ================= 
int KT_DinhDangTenNV(NHANVIEN nv)
{
	int n = nv.TenNV.length();
	int dem = 0;
	if (nv.TenNV[0] == ' ')
	{
		return 0;
	}
	if (nv.TenNV[n-1] == ' ')
	{
		return 0;
	}
	for (int i = 0; i < nv.TenNV.length(); i++)
	{
		if (nv.TenNV[i] >= 'a' && nv.TenNV[i] <= 'z' || nv.TenNV[i] >= 'A' && nv.TenNV[i] <= 'Z' || nv.TenNV[i] == ' ')
		{
			dem = dem + 1;
		}
		else if (nv.TenNV[i] >= '0' && nv.TenNV[i] <= '9' || nv.TenNV[i] < 'a' || nv.TenNV[i] > 'z' || nv.TenNV[i] < 'A' || nv.TenNV[i] > 'Z')
		{
			return 0;
		}
	}
	if (dem == nv.TenNV.length())
		return 1;
	else
		return 0;
}

//================== Kiem tra Số Điện Thoại nhan vien co phải chữ không ================= 
int KT_DinhDangSodtNV(NHANVIEN nv)
{
	int dem = 0;
	for (int i = 0; i < nv.SoDT.length(); i++)
	{
		if (!(nv.SoDT[i] >= '0' && nv.SoDT[i] <= '9') )
		{
			return 0;
			break;
		}
		else 
		{
			dem++;
		}
	}
	if (dem == nv.SoDT.length())
		return 1;
	else
		return 0;
}

//================== Kiem tra Dia Chi nhan vien co phải chữ không ================= 
int KT_DinhDangDiaChiNV(NHANVIEN nv)
{
	int n = nv.DiaChi.length();
	int dem = 0;
	if (nv.DiaChi[0] == ' ')
	{
		return 0;
	}
	if (nv.DiaChi[n - 1] == ' ')
	{
		return 0;
	}
	for (int i = 0; i < nv.DiaChi.length(); i++)
	{
		if (nv.DiaChi[i] >= 'a' && nv.DiaChi[i] <= 'z' || nv.DiaChi[i] >= 'A' && nv.DiaChi[i] <= 'Z' || nv.DiaChi[i] == ' ')
		{
			dem = dem + 1;
		}
		else if (nv.DiaChi[i] >= '0' && nv.DiaChi[i] <= '9' || nv.DiaChi[i] < 'a' || nv.DiaChi[i] > 'z' || nv.DiaChi[i] < 'A' || nv.DiaChi[i] > 'Z')
		{
			return 0;
		}
	}
	if (dem == nv.DiaChi.length())
		return 1;
	else
		return 0;
}

//======================= Kiểm tra định dạng ngày-Tháng-Năm ===========================
int DinhDangNgayNhanViec(NHANVIEN nv)
{
	for (int i = 0; i < nv.NgayNhanViec.length(); i++) {
		if (!(nv.NgayNhanViec[0] >= '0' && nv.NgayNhanViec[0] <= '9' && nv.NgayNhanViec[1] >= '0' && nv.NgayNhanViec[1] <= '9' && nv.NgayNhanViec[2] == '/' && nv.NgayNhanViec[3] >= '0' && nv.NgayNhanViec[3] <= '9' && nv.NgayNhanViec[4] >= '0' && nv.NgayNhanViec[4] <= '9' && nv.NgayNhanViec[5] == '/' && nv.NgayNhanViec[6] >= '0' && nv.NgayNhanViec[6] <= '9' && nv.NgayNhanViec[7] >= '0' && nv.NgayNhanViec[7] <= '9')) {
			return 0;
		}
	}
	return 1;
}

int DinhDangNgayHetHan(NHANVIEN nv)
{
	for (int i = 0; i < nv.NgayHetHanCV.length(); i++) {
		if (!(nv.NgayHetHanCV[0] >= '0' && nv.NgayHetHanCV[0] <= '9' && nv.NgayHetHanCV[1] >= '0' && nv.NgayHetHanCV[1] <= '9' && nv.NgayHetHanCV[2] == '/' && nv.NgayHetHanCV[3] >= '0' && nv.NgayHetHanCV[3] <= '9' && nv.NgayHetHanCV[4] >= '0' && nv.NgayHetHanCV[4] <= '9' && nv.NgayHetHanCV[5] == '/' && nv.NgayHetHanCV[6] >= '0' && nv.NgayHetHanCV[6] <= '9' && nv.NgayHetHanCV[7] >= '0' && nv.NgayHetHanCV[7] <= '9')) {
			return 0;
		}
	}
	return 1;
}

int DinhDangNgaySinhNV(NHANVIEN nv)
{
	for (int i = 0; i < nv.NgaySinh.length(); i++) {
		if (!(nv.NgaySinh[0] >= '0' && nv.NgaySinh[0] <= '9' && nv.NgaySinh[1] >= '0' && nv.NgaySinh[1] <= '9' && nv.NgaySinh[2] == '/' && nv.NgaySinh[3] >= '0' && nv.NgaySinh[3] <= '9' && nv.NgaySinh[4] >= '0' && nv.NgaySinh[4] <= '9' && nv.NgaySinh[5] == '/' && nv.NgaySinh[6] >= '0' && nv.NgaySinh[6] <= '9' && nv.NgaySinh[7] >= '0' && nv.NgaySinh[7] <= '9')) {
			return 0;
		}
	}
	return 1;
}

//========================================= Đọc file Nhân Viên ===============================================

void Addhead(LIST_NHANVIEN& lnv, NODE_NHANVIEN* p)
{
	if (lnv.pHead == NULL)
	{
		lnv.pHead = lnv.pTail = p;
	}
	else {
		p->pNext = lnv.pHead;

		lnv.pHead = p;
	}
}

void AddTail(LIST_NHANVIEN& lnv, NODE_NHANVIEN* p)
{
	if (lnv.pHead == NULL)
	{
		lnv.pHead = lnv.pTail = p;
	}
	else
	{
		lnv.pTail->pNext = p;
		lnv.pTail = p;
	}
}

void XoaDauNV(LIST_NHANVIEN& lnv) {
	//nếu danh sách rỗngg
	if (lnv.pHead == NULL) {
		return;
	}
	else {
		NODE_NHANVIEN* p = lnv.pHead;//node p là node sẽ xóa
		lnv.pHead = lnv.pHead->pNext;
		delete p;
	}
}

void XoaCuoiNV(LIST_NHANVIEN& lnv)
{
	//nếu danh sách rỗng
	if (lnv.pHead == NULL)
	{
		return;
	}
	//trường hợp danh sách có phần tử
	if (lnv.pHead->pNext == NULL)
	{
		XoaDauNV(lnv);
		return;
	}
	//duyệt từ đầu danh sách tới thằng kế cuối
	for (NODE_NHANVIEN* k = lnv.pHead; k != NULL; k = k->pNext)
	{
		//phát hiện thằng kế cuối
		if (k->pNext == lnv.pTail)
		{
			delete lnv.pTail; //xóa đi phần tử cuối
			k->pNext = NULL;//cho con trỏ của node thằng kế cuối trỏ đến vùng nhớ null
			lnv.pTail = k;
		}
	}
}

int CheckMaNV(NHANVIEN nv) //kiểm tra mã nhân viên có tồn tại trong list
{
	LIST_NHANVIEN lnv{};
	NODE_NHANVIEN* p = lnv.pHead;
	while (p != NULL)
	{
		if (p->Nhanvien.MaNV == nv.MaNV) return true;
		p = p->pNext;
	}
	return false;
}

int CheckTenNV(LIST_NHANVIEN& lnv,NHANVIEN nv) //kiểm tra tên nhân viên có tồn tại trong list
{
	NODE_NHANVIEN* p = lnv.pHead;
	while (p != NULL)
	{
		if (p->Nhanvien.TenNV == nv.TenNV) return true;
		p = p->pNext;
	}
	return false;
}

int CheckSoDTNV(NHANVIEN nv) //kiểm tra Số điện thoại nhân viên có tồn tại trong list
{
	LIST_NHANVIEN lnv{};
	NODE_NHANVIEN* p = lnv.pHead;
	while (p != NULL)
	{
		if (p->Nhanvien.SoDT == nv.SoDT) return true;
		p = p->pNext;
	}
	return false;
}

int CheckDiachiNV(NHANVIEN nv) //kiểm tra Dịa chỉ nhân viên có tồn tại trong list
{
	LIST_NHANVIEN lnv{};
	NODE_NHANVIEN* p = lnv.pHead;
	while (p != NULL)
	{
		if (p->Nhanvien.DiaChi == nv.DiaChi) return true;
		p = p->pNext;
	}
	return false;
}

int CheckMaCV(NHANVIEN nv) //kiểm tra mã công việc nhân viên có tồn tại trong list có tồn tại trong list
{
	LIST_NHANVIEN lnv{};
	NODE_NHANVIEN* p = lnv.pHead;
	while (p != NULL)
	{
		if (p->Nhanvien.MaCV == nv.MaCV) return true;
		p = p->pNext;
	}
	return false;
}

int CheckGioiTinhNV(NHANVIEN nv) //kiểm tra Giới tính nhân viên có tồn tại trong list
{
	LIST_NHANVIEN lnv{};
	NODE_NHANVIEN* p = lnv.pHead;
	while (p != NULL)
	{
		if (p->Nhanvien.GioiTinh == nv.GioiTinh) return true;
		p = p->pNext;
	}
	return false;
}

int CheckNgaysinhNV(NHANVIEN nv) //kiểm tra Ngày Sinh Nhân viên có tồn tại trong list
{
	LIST_NHANVIEN lnv{};
	NODE_NHANVIEN* p = lnv.pHead;
	while (p != NULL)
	{
		if (p->Nhanvien.NgaySinh == nv.NgaySinh) return true;
		p = p->pNext;
	}
	return false;
}

int CheckNgayNhanViecNV(NHANVIEN nv) //kiểm tra Ngày bắt đầu nhận việc Nhân viên có tồn tại trong list
{
	LIST_NHANVIEN lnv{};
	NODE_NHANVIEN* p = lnv.pHead;
	while (p != NULL)
	{
		if (p->Nhanvien.NgayNhanViec == nv.NgayNhanViec) return true;
		p = p->pNext;
	}
	return false;
}

int CheckNgayHetHanNV(NHANVIEN nv) //kiểm tra Ngày hết hạn làm việc của Nhân viên có tồn tại trong list
{
	LIST_NHANVIEN lnv{};
	NODE_NHANVIEN* p = lnv.pHead;
	while (p != NULL)
	{
		if (p->Nhanvien.NgayHetHanCV == nv.NgayHetHanCV) return true;
		p = p->pNext;
	}
	return false;
}

void SaveNV(LIST_NHANVIEN& lnv, NHANVIEN nv)

{
	fstream f;
	f.open("Danhsachnhanvien.txt", ios::out);
	for (NODE_NHANVIEN* p = lnv.pHead; p != NULL; p = p->pNext)
	{
		f << p->Nhanvien.MaNV << ",";
		f << p->Nhanvien.TenNV << ",";
		f << p->Nhanvien.MaCV << ",";
		f << p->Nhanvien.SoDT << ",";
		f << p->Nhanvien.GioiTinh << ",";
		f << p->Nhanvien.DiaChi << ",";
		f << p->Nhanvien.NgaySinh << ",";
		f << p->Nhanvien.NgayNhanViec << ",";
		f << p->Nhanvien.NgayHetHanCV;
		if (p->pNext != NULL)
		{
			f << endl;
		}
		else
		{
			break;
		}
	}
	f.close();
}

void DocFileNV(LIST_NHANVIEN& lnv)
{
	/*int k = 0;
	fstream fin;
	fin.open("Danhsachnhanvien.txt", fstream::in | fstream::app);
	if (fin.is_open()) {
		string word;
		while (getline(fin, word)) {
			cout << word << "\n";
			for (int i = 0; i < word.length(); i++)
			{
				if (word[i] == ',') {
					k = k + 1;
				}
				else {
					if (k == 0)
					{
						nv.MaNV = nv.MaNV + word[i];
					}
					else if (k == 1) {
						nv.TenNV = nv.TenNV + word[i];
					}
					else if (k == 2) {
						nv.MaCV = nv.MaCV + word[i];
					}
					else if (k == 3) {
						nv.SoDT = nv.SoDT + word[i];
					}
					else if (k == 4) {
						nv.GioiTinh = nv.GioiTinh + word[i];
					}
					else if (k == 5) {
						nv.DiaChi = nv.DiaChi + word[i];
					}
					else if (k == 6)
					{
						nv.NgaySinh = nv.NgaySinh + word[i];
					}
					else if (k == 7) {
						nv.NgayNhanViec = nv.NgayNhanViec + word[i];
					}
					else if (k == 8) {
						nv.NgayHetHanCV = nv.NgayHetHanCV + word[i];
					}
				}
			}
			NODE_NHANVIEN* p = KhoiTaoNodeNV(nv);
			Addhead(lnv, p);

		}
		fin.close();
	}*/

	ifstream fin;
	fin.open("Danhsachnhanvien.txt",ios_base::in);
	while (!fin.eof())
	{
		NHANVIEN nv;
		getline(fin, nv.MaNV, ',');
		getline(fin, nv.TenNV, ',');
		getline(fin, nv.MaCV, ',');
		getline(fin, nv.SoDT, ',');
		getline(fin, nv.GioiTinh, ',');
		getline(fin, nv.DiaChi, ',');
		getline(fin, nv.NgaySinh, ',');
		getline(fin, nv.NgayNhanViec, ',');
		getline(fin, nv.NgayHetHanCV);

		NODE_NHANVIEN* p = KhoiTaoNodeNV(nv);
		Addhead(lnv, p);
	}
	fin.close();
}

void createNV(LIST_NHANVIEN& lnv, NHANVIEN nv)
{
	KhoiTaoListNV(lnv);
//	DocFileNV(lnv);
	ShowCur(1);
	do
	{
		gotoXY(97, 15);
		fflush(stdin);
		getline(cin, nv.MaNV);
		XoaManHinhTuyChon(148, 15, 35, 1);
		if (KT_RongMaNV(nv) == 1)
		{
			gotoXY(148, 15);
			cout << "=> Ma nhan vien dang rong, Nhap Lai";
		}
		if (KT_TrungMaNV(lnv, nv) ==0)
		{
			XoaManHinhTuyChon(97, 15, 30, 1);
			gotoXY(148, 15);
			cout << "=> Ma Nhan Vien Bi Trung, Nhap Lai";
		}
	} while (KT_RongMaNV(nv) == 1 || KT_TrungMaNV(lnv, nv) == 0);

	do
	{
		gotoXY(97, 18);
		getline(cin, nv.TenNV);
		XoaManHinhTuyChon(148, 18, 40, 1);
		if (KT_RongTenNV(nv) == 1)
		{
			gotoXY(148, 18);
			cout << "=> Ten Nhan Vien dang rong ";
		}
		if (KT_DinhDangTenNV(nv) == 0)
		{
			XoaManHinhTuyChon(97, 18, 30, 1);
			gotoXY(148, 18);
			cout << "=>Ten Nhan Vien Chua Ki Tu So, Nhap Lai";
		}
	} while (KT_RongTenNV(nv) == 1 || (KT_DinhDangTenNV(nv) == 0));

	do
	{
		gotoXY(97, 21);
		getline(cin, nv.MaCV);
		XoaManHinhTuyChon(148, 21, 35, 1);
		if (KT_RongMaCV(nv) == 1)
		{
			gotoXY(148, 21);
			cout << "=> Ma Cong Viec Dang Rong, Nhap Lai";
		}
		if (KT_TrungMaCV(lnv,nv) == 1)
		{
			XoaManHinhTuyChon(97, 21, 30, 1);
			gotoXY(148, 21);
			cout << "=> Ma Cong Viec Bi Trung, Nhap Lai";
		}
	} while (KT_RongMaCV(nv) == 1 || KT_TrungMaCV(lnv, nv) == 1);

	do
	{
		gotoXY(97, 24);
		getline(cin, nv.SoDT);
		XoaManHinhTuyChon(148, 24, 35, 1);
		if (KT_RongSodtNV(nv) == 1)
		{
			gotoXY(148, 24);
			cout << "=>So Dien Thoai Dang Rong, Nhap Lai";
		}
		if (KT_TrungSDTNV(lnv, nv) == 1)
		{
			XoaManHinhTuyChon(97, 24, 30, 1);
			gotoXY(148, 24);
			cout << "=>So Dien Thoai Bi Trung, Nhap Lai";
		}
		if (KT_DinhDangSodtNV(nv) == 0)
		{
			XoaManHinhTuyChon(97, 24, 30, 1);
			gotoXY(148, 24);
			cout << "=> So Dien Thoai Sai, Nhap Lai";
		}
	} while (KT_RongSodtNV(nv) == 1 || KT_TrungSDTNV(lnv, nv) == 1 || KT_DinhDangSodtNV(nv) == 0);

	do
	{
		gotoXY(97, 27);
		getline(cin, nv.GioiTinh);
		XoaManHinhTuyChon(148, 27, 35, 1);
		if (KT_RongGtNV(nv) == 1)
		{
			gotoXY(148, 27);
			cout << "=>Gioi Tinh Rong,Nhap Lai";
		}
		if (DinhDangGioiTinhNV(nv) == 0)
		{
			XoaManHinhTuyChon(97, 27,30,1);
			gotoXY(148, 27);
			cout << "=>Dinh Dang Sai,Nhap Lai";
		}
	} while (KT_RongGtNV(nv) == 1 || DinhDangGioiTinhNV(nv) == 0);

	do
	{
		gotoXY(97, 30);
		getline(cin, nv.DiaChi);
		XoaManHinhTuyChon(148, 30, 35, 1);
		if (KT_RongDiachiNV(nv) == 1)
		{
			gotoXY(148, 30);
			cout << "=>Dia Chi Nhan Vien Rong, Nhap Lai";
		}
		if (KT_DinhDangDiaChiNV(nv) == 0)
		{
			XoaManHinhTuyChon(97, 30, 30, 1);
			gotoXY(148, 30);
			cout << "=>Dia Chi Dang Chua So, Nhap Lai";
	    }
	} while (KT_RongDiachiNV(nv) == 1 || KT_DinhDangDiaChiNV(nv) == 0);

	do
	{
		gotoXY(97, 33);
		getline(cin, nv.NgaySinh);
		XoaManHinhTuyChon(148, 33, 35, 1);
		if (KT_RongNgaysinhNV(nv) == 1)
		{
			gotoXY(148, 33);
			cout << "=> Ngay sinh dang rong, Nhap Lai";
		}
		if (DinhDangNgaySinhNV(nv) == 0)
		{
			XoaManHinhTuyChon(97, 33, 30, 1);
			gotoXY(148, 33);
			cout << "=> Dinh Dang sai, Nhap Lai";
		}
	} while (KT_RongNgaysinhNV(nv) == 1 || DinhDangNgaySinhNV(nv) == 0);

	do
	{
		gotoXY(97, 36);
		getline(cin, nv.NgayNhanViec);
		XoaManHinhTuyChon(148, 36, 37, 1);
		if (KT_RongNgayBdNV(nv) == 1)
		{
			gotoXY(148, 36);
			cout << "=> Ngay Nhan Viec Dang Rong, Nhap Lai";
		}
		if (DinhDangNgayNhanViec(nv) == 0)
		{
			XoaManHinhTuyChon(97, 36, 30, 1);
			gotoXY(148, 36);
			cout << "=> Dinh Dang sai, Nhap Lai";
		}
	} while (KT_RongNgayBdNV(nv) == 1 || DinhDangNgayNhanViec(nv) == 0);

	do
	{
		gotoXY(97, 39);
		getline(cin, nv.NgayHetHanCV);
		XoaManHinhTuyChon(148, 39, 35, 1);
		if (KT_RongHethanNV(nv) == 1)
		{
			gotoXY(148, 39);
			cout << "=> Ngay Het Han Dang Rong, Nhap Lai";
		}
		if (DinhDangNgayHetHan(nv) == 0)
		{
			XoaManHinhTuyChon(97, 39, 30, 1);
			gotoXY(148, 39);
			cout << "=> Dinh Dang sai, Nhap Lai";
		}
	}while(KT_RongHethanNV(nv) == 1 || DinhDangNgayHetHan(nv) == 0);

	NODE_NHANVIEN* p = KhoiTaoNodeNV(nv);
	Addhead(lnv, p);
	SaveNV(lnv,nv);
}

void PrintNV(LIST_NHANVIEN lnv)
{

	for (NODE_NHANVIEN* p = lnv.pHead; p != NULL; p = p->pNext)
	{

		VeHCN(64, 16, 10, 2, 3);
		gotoXY(65, 17);
		cout << p->Nhanvien.MaNV;

		VeHCN(75, 16, 32, 2, 3);
		gotoXY(76, 17);
		cout << p->Nhanvien.TenNV;

		VeHCN(108, 16, 10, 2, 3);
		gotoXY(109, 17);
		cout << p->Nhanvien.MaCV;

		VeHCN(119, 16, 10, 2, 3);
		gotoXY(120, 17);
		cout << p->Nhanvien.SoDT;

		VeHCN(130, 16, 10, 2, 3);
		gotoXY(131, 17);
		cout << p->Nhanvien.GioiTinh;

		VeHCN(141, 16, 10, 2, 3);
		gotoXY(142, 17);
		cout << p->Nhanvien.DiaChi;

		VeHCN(152, 16, 10, 2, 3);
		gotoXY(153, 17);
		cout << p->Nhanvien.NgaySinh;

		VeHCN(163, 16, 15, 2, 3);
		gotoXY(164, 17);
		cout << p->Nhanvien.NgayNhanViec;

		VeHCN(179, 16, 15, 2, 3);
		gotoXY(180, 17);
		cout << p->Nhanvien.NgayHetHanCV;

	}
}

void Print_1_NV(NHANVIEN nv, int x, int y)
{
	gotoXY(x, y);
	cout <<"Ma Nhan Vien: "<< nv.MaNV << endl;
	gotoXY(x, y + 1);
	cout << "Ten Nhan Vien: " << nv.TenNV << endl;
	gotoXY(x, y + 2);
	cout << "Ma Cong Viec: " << nv.MaCV << endl;
	gotoXY(x, y + 3);
	cout << "So Dien Thoai: " << nv.SoDT << endl;
	gotoXY(x, y + 4);
	cout << "Gioi Tinh: " << nv.GioiTinh << endl;
	gotoXY(x, y + 5);
	cout << "Dia Chi: " << nv.DiaChi << endl;
	gotoXY(x, y + 6);
	cout << "Ngay Sinh: " << nv.NgaySinh << endl;
	gotoXY(x, y + 7);
	cout << "Ngay Nhan Viec: " << nv.NgayNhanViec << endl;
	gotoXY(x, y + 8);
	cout << "Ngay Het Han: " << nv.NgayHetHanCV << endl;
}

int soNhanVien(LIST_NHANVIEN lnv) {
	int soKH = 1;
	for (NODE_NHANVIEN* p = lnv.pHead; p != NULL; p = p->pNext) {
		soKH++;
	}
	return soKH;
}

void listTenNV(LIST_NHANVIEN lnv) {
	int i = 1;
	int Y = 15;
	for (NODE_NHANVIEN* p = lnv.pHead; p != NULL; p = p->pNext) {
		gotoXY(80, Y++);
		cout << "Ten khach hang thu " << i++ << ": " << p->Nhanvien.TenNV << endl;
	}
}

void XoaBatKiNV(LIST_NHANVIEN& lnv, NHANVIEN nv)
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);
//	ShowCur(1);
	VeHCN(79, 13, 50, 1 + soNhanVien(lnv), 2); // Khung hien ten Nhân Viên với số nhân viên là kiểu int
	gotoXY(81, 14);
	cout << "Danh sach ten khach hang." << endl;
	listTenNV(lnv);
	gotoXY(70, 18 + soNhanVien(lnv) + 4); // Khi số nhan vien tăng thì cái này
	cout << "Nhap ten Nhan Vien can xoa: ";
	rewind(stdin);
	VeHCN(113, 18 + soNhanVien(lnv) + 3, 20, 2, 5); // Khung nhap ten Nhân Vien can xoa
	VeHCN(90, 18 + soNhanVien(lnv) + 7, 10, 2, 3); // Khung huy
	gotoXY(91, 18 + soNhanVien(lnv) + 8);
	cout << "Huy";
	VeHCN(120, 18 + soNhanVien(lnv) + 7, 10, 2, 3); // Khung dong y
	gotoXY(121, 18 + soNhanVien(lnv) + 8);
	cout << "Dong y";
	do {
		gotoXY(114, 18 + soNhanVien(lnv) + 4);
		getline(cin, nv.TenNV);
		XoaManHinhTuyChon(114, 18 + soNhanVien(lnv) + 4, 33, 1);
		if (KT_RongTenNV(nv) == 1)
		{
			XoaManHinhTuyChon(135, 18 + soNhanVien(lnv) + 4, 60, 1);
			gotoXY(135, 18 + soNhanVien(lnv));
			cout << "=>Ten Khach hang dang rong, Nhap lai";
		}
		if (!(CheckTenNV(lnv,nv)))
		{
			XoaManHinhTuyChon(135, 18 + soNhanVien(lnv) + 4, 60, 1);
			gotoXY(135, 18 + soNhanVien(lnv));
			cout << "=>Ten Khach hang khong co trong danh sach, Nhap lai";
		}
		if (KT_DinhDangTenNV(nv) == 0)
		{
			XoaManHinhTuyChon(135, 18 + soNhanVien(lnv) + 4, 60, 1);
			gotoXY(135, 18 + soNhanVien(lnv));
			cout << "=>Ten Khach hang Dinh dang khong dung, Nhap lai";
		}
	} while (!(CheckTenNV(lnv, nv)) || KT_DinhDangTenNV(nv) == 0 || KT_RongTenNV(nv) == 1 || nv.TenNV == "\r");


	if (batSuKien(81, 34 + soNhanVien(lnv), 8, 2)) { // Bắt sự kiện hủy
		return;
	}

	else if (batSuKien(107, 34 + soNhanVien(lnv), 10, 2)) { // Bắt sự kiện đồng ý
		int dem = 0; // Xem tên Nhân Viên cần xóa có trong danh sách hay không
		for (NODE_NHANVIEN* p = lnv.pHead; p != NULL; p = p->pNext) {
			if (nv.TenNV == lnv.pHead->Nhanvien.TenNV) {
				XoaDauNV(lnv);
				gotoXY(100, 50);
				cout << "Xoa thanh cong." << endl;
				dem++; // Nếu có tăng 1
				break;
			}
			else if (nv.TenNV == lnv.pTail->Nhanvien.TenNV) {
				XoaCuoiNV(lnv);
				gotoXY(100, 50);
				cout << "Xoa thanh cong." << endl;
				dem++;
				break;
			}
			else {
				NODE_NHANVIEN* q = p->pNext;
				if (q->Nhanvien.TenNV == nv.TenNV) {
					p->pNext = q->pNext;
					gotoXY(100, 50);
					cout << "Xoa thanh cong." << endl;
					dem++;
					break;
				}
			}
		}
		if (dem == 0) { //  Nếu tên Nhân Viên cần xóa không có trong danh sách Nhân Viên
			gotoXY(45, 18);
			cout << nv.TenNV << " khong co trong danh sach." << endl;
		}
	}
}

int SoNhanVien(LIST_NHANVIEN lnv) {
	int SoNV = 1;
	for (NODE_NHANVIEN* p = lnv.pHead; p != NULL; p = p->pNext) {
		SoNV++;
	}
	return SoNV;
}
void listMaNV(LIST_NHANVIEN l) {
	int i = 1;
	int Y = 15;
	for (NODE_NHANVIEN* p = l.pHead; p != NULL; p = p->pNext) {
		gotoXY(80, Y++);
		cout << "Ma nhan vien "<<p->Nhanvien.TenNV  << ": " << p->Nhanvien.MaNV << endl;
	}
}


void ChangeTenNV(LIST_NHANVIEN& l, NHANVIEN nv)
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

	string thuocTinh;
	string changed;
	int dem = 0;
	VeHCN(79, 13, 50, 1 + SoNhanVien(l), 2); // Khung hien ten và mã nhân viên có số nhân viên là int
	gotoXY(81, 14);
	cout << "Danh sach Ten and Ma nhan vien." << endl;
	listMaNV(l);
	gotoXY(70, 18 + SoNhanVien(l) + 4); // Khi số Nhân viên tăng thì cái này
	cout << "Nhap Ma Nhan Vien Can Sua: ";
	rewind(stdin);
	VeHCN(113, 18 + SoNhanVien(l) + 3, 20, 2, 5); // Khung nhap Ma khach hang can sua
	VeHCN(90, 18 + SoNhanVien(l) + 7, 10, 2, 3); // Khung huy
	gotoXY(91, 18 + SoNhanVien(l) + 8);
	cout << "Huy";
	VeHCN(120, 18 + SoNhanVien(l) + 7, 10, 2, 3); // Khung dong y
	gotoXY(121, 18 + SoNhanVien(l) + 8);
	cout << "Dong y";
	do {
		gotoXY(114, 18 + SoNhanVien(l) + 4);
		ShowCur(1); // Hien con tro
		getline(cin, nv.MaNV);
		XoaManHinhTuyChon(114, 18 + SoNhanVien(l) + 4, 33, 1);
		if ((CheckMaNV(nv)) == 1)
		{
			XoaManHinhTuyChon(116, 18 + SoNhanVien(l) + 4, 60, 1);
			gotoXY(116, 18 + SoNhanVien(l));
			cout << "=>Ma Nhan Vien khong co trong danh sach, Nhap lai";
		}
		if (KT_RongMaNV(nv) == 1)
		{
			XoaManHinhTuyChon(116, 18 + SoNhanVien(l) + 4, 60, 1);
			gotoXY(116, 18 + SoNhanVien(l));
			cout << "=>Ma nhan vien dang rong, Nhap lai";
		}
	} while ((CheckMaNV(nv)) == 1 || KT_RongMaNV(nv) == 1);

	if (batSuKien(81, 34 + SoNhanVien(l), 8, 2)) {//bắt sự kiện hủy
		return;
	}

	else if (batSuKien(107, 34 + SoNhanVien(l), 10, 2)) {//bắt sự kiện đồng ý
		ShowCur(0);
		VeHCN(63, 12, 133, 39, 3);
		ToMauHCN(63, 12, 133, 39, 3);

		VeHCN(79, 14, 50, 10, 2); // Vẽ HCN cho thông tin Nhân Viên
		for (NODE_NHANVIEN* q = l.pHead; q != NULL; q = q->pNext) {
			if (q->Nhanvien.MaNV == nv.MaNV) {
				Print_1_NV(q->Nhanvien, 80, 15);
				dem++;
			}
		}
		// Vẽ các khung thuộc tính
		VeHCN(75, 30, 10, 2, 3); // Vẽ khung Mã Nhân viên
		gotoXY(78, 31);
		cout << "Ma NV";

		VeHCN(92, 30, 10, 2, 3); // Vẽ khung Tên nhân viên
		gotoXY(94, 31);
		cout << "Ten NV";

		VeHCN(109, 30, 12, 2, 3); // Vẽ khung Mã công việc
		gotoXY(111, 31);
		cout << "Ma CV";

		VeHCN(126, 30, 10, 2, 3); // Vẽ khung So Dt
		gotoXY(128, 31);
		cout << "So DT";

		VeHCN(75, 34, 10, 2, 3); // Vẽ khung Giới Tính
		gotoXY(76, 35);
		cout << "Gioi Tinh";

		VeHCN(92, 34, 11, 2, 3); // Vẽ khung Dia Chi
		gotoXY(93, 35);
		cout << "Dia Chi";

		VeHCN(109, 34, 12, 2, 3); // Vẽ khung Ngày sinh
		gotoXY(111, 35);
		cout << "Ngay Sinh";

		VeHCN(126, 34, 16, 2, 3); // Vẽ khung nhận việc
		gotoXY(127, 35);
		cout << "Ngay nhan viec";

		VeHCN(144, 34, 14, 2, 3); // Vẽ khung hết hạn
		gotoXY(145, 35);
		cout << "Ngay het han";
	}

	for (NODE_NHANVIEN* q = l.pHead; q != NULL; q = q->pNext) {
		if (q->Nhanvien.MaNV == nv.MaNV) {
			if (batSuKien(67, 38, 10, 2)) { // Ma Nhân viên
				do {

					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->Nhanvien.MaNV << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					nv.MaNV = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_TrungMaNV(l, nv) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ma nhan vien trung, vui long nhap lai!!!";
					}
					if (KT_RongMaNV(nv) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ma nhan vien dang rong, vui long nhap lai!!!";
					}
				} while (KT_TrungMaNV(l, nv) == 0 || KT_RongMaNV(nv) == 1);
				q->Nhanvien.MaNV = nv.MaNV = changed;
			}
			else if (batSuKien(82, 38, 10, 2)) { // Ten Nhân viên
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->Nhanvien.TenNV << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(105, 45);
					getline(cin, changed);
					nv.TenNV = changed;
					XoaManHinhTuyChon(105, 47, 50, 1);
					if (KT_RongTenNV(nv) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ten nhan vien dang rong, vui long nhap lai!!!";
					}
					if (KT_DinhDangTenNV(nv) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ten nhan vien dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongTenNV(nv) == 1 || KT_DinhDangTenNV(nv) == 0);
				q->Nhanvien.TenNV = nv.TenNV = changed;
			}
			else if (batSuKien(114, 38, 10, 2)) { // Số điện thoại
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->Nhanvien.SoDT << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					nv.SoDT = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_RongSodtNV(nv) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>SDT dang rong, vui long nhap lai!!!";
					}
					if (KT_TrungSDTNV(l, nv) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>SDT bi trung, vui long nhap lai!!!";
					}
					if (KT_DinhDangSodtNV(nv) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>SDT dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongSodtNV(nv) == 1 || KT_TrungSDTNV(l, nv) == 1 || KT_DinhDangSodtNV(nv) == 0);
				q->Nhanvien.SoDT = nv.SoDT = changed;
			}
			else if (batSuKien(98, 38, 10, 2)) { // Mã Công việc
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->Nhanvien.MaCV << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					nv.MaCV = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_RongMaCV(nv) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ma cong viec khach hang dang rong, vui long nhap lai!!!";
					}
				} while (KT_RongMaCV(nv) == 1);
				q->Nhanvien.MaCV = nv.MaCV = changed;
			}
			else if (batSuKien(67, 43, 10, 2)) { // giới tính
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->Nhanvien.GioiTinh << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(95, 45);
					getline(cin, changed);
					nv.GioiTinh = changed;
					XoaManHinhTuyChon(95, 47, 50, 1);
					if (KT_RongGtNV(nv) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Gioi tinh nhan vien dang rong, vui long nhap lai!!!";
					}
					if (DinhDangGioiTinhNV(nv) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Gioi tinh nhan vien dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongGtNV(nv) == 1 || DinhDangGioiTinhNV(nv) == 0);
				q->Nhanvien.GioiTinh = nv.GioiTinh = changed;
			}
			else if (batSuKien(82, 43, 11, 2)) { // Địa Chỉ
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->Nhanvien.DiaChi << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(105, 45);
					getline(cin, changed);
					nv.DiaChi = changed;
					XoaManHinhTuyChon(105, 47, 50, 1);
					if (KT_RongDiachiNV(nv) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Dia chi nhan vien dang rong, vui long nhap lai!!!";
					}
					if (KT_DinhDangDiaChiNV(nv) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Dia chi nhan vien dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongDiachiNV(nv) == 1 || KT_DinhDangDiaChiNV(nv) == 0);
				q->Nhanvien.DiaChi = nv.DiaChi = changed;
			}
			else if (batSuKien(98, 44, 10, 2)) { // Ngày sinh
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->Nhanvien.NgaySinh << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					nv.NgaySinh = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_RongNgaysinhNV(nv) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ngay Sinh nhan vien dang rong, vui long nhap lai!!!";
					}
					if (DinhDangNgaySinhNV(nv) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ngay sinh dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongNgaysinhNV(nv) == 1 || DinhDangNgaySinhNV(nv) == 0);
				q->Nhanvien.NgaySinh = nv.NgaySinh = changed;
			}
			else if (batSuKien(113,44,14,2))//ngày bắt đầu
			{
			   do
			    {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->Nhanvien.NgayNhanViec << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					nv.NgayNhanViec = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_RongNgayBdNV(nv) == 1)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ngay Bat dau lam dang rong, vui long nhap lai!!!";
					}
					if (DinhDangNgayNhanViec(nv) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ngay BD lam dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_RongNgayBdNV(nv) == 1 || DinhDangNgayNhanViec(nv) == 0);
				q->Nhanvien.NgayNhanViec = nv.NgayNhanViec = changed;
            }
		    else if (batSuKien(129, 44, 14, 1))
		    {
			do
			{
				gotoXY(67, 45);
				ShowCur(1); // Hien con tro
				cout << q->Nhanvien.NgayHetHanCV << " muon thanh doi thanh: ";
				rewind(stdin);
				gotoXY(100, 45);
				getline(cin, changed);
				nv.NgayHetHanCV = changed;
				XoaManHinhTuyChon(100, 47, 50, 1);
				if (KT_RongHethanNV(nv) == 1)
				{
					XoaManHinhTuyChon(95, 45, 32, 1);
					gotoXY(95, 47);
					cout << "=>Ngay Het Han dang rong, vui long nhap lai!!!";
				}
				if (DinhDangNgayHetHan(nv) == 0)
				{
					XoaManHinhTuyChon(95, 45, 32, 1);
					gotoXY(95, 47);
					cout << "=>Ngay Het Han dinh dang sai, vui long nhap lai!!!";
				}
			} while (KT_RongHethanNV(nv) == 1 || DinhDangNgayHetHan(nv) == 0);
			q->Nhanvien.NgayHetHanCV = nv.NgayHetHanCV = changed;
		    }
		}
	}
	gotoXY(70, 50);
	cout << thuocTinh << " da duoc thay doi!!!" << endl;
	gotoXY(140, 50);
	system("pause");
}

//hàm lấy tên của Nhân Viên ra để đi sắp xếp
string Ten_Nhan_Vien(NHANVIEN nv)
{
	//khởi tạo độ dài chuỗi nhập tên nhân viên
	int length = nv.TenNV.length();
	int i;
	//duyệt từ cuối về đầu chuỗi
	for (i = length - 1; i >= 0; i--)
	{
		//nếu duyệt cho phần tử thứ i gặp khoảng trống đầu tiên thì sẽ kết thúc lấy chuỗi
		if (nv.TenNV[i] == ' ')
		{
			break;
		}
	}
	//hàm trả về chuỗi mình đã cắt
	return nv.TenNV.substr(i + 1);

}

void DoiChoNV(NHANVIEN& a, NHANVIEN& b)
{
	NHANVIEN temp = a;
	a = b;
	b = temp;
}

//hàm sắp xếp theo tên Nhân Viên
void SapXeptheoTenNhanVien(LIST_NHANVIEN& lnv, NHANVIEN nv)
{
	int dem = 1;
	//hàm duyệt list nhân viên từ đầu đến cuối danh sách
	for (NODE_NHANVIEN* h = lnv.pHead; h != NULL; h = h->pNext)
	{
		for (NODE_NHANVIEN* g = lnv.pHead; g != NULL; g = g->pNext)
		{
			//tạo 2 thằng Nhân Viên để đi so sánh với nhau
			string TenNV = Ten_Nhan_Vien(h->Nhanvien);
			string TenNV1 = Ten_Nhan_Vien(g->Nhanvien);
			//hàm so sánh từng phần tử trong Tên Nhân Viên
			//ngược lại nếu hèm trả về <0 tức là chuỗi tên Nhân Viên trước lớn hơn mã sau
			if (_stricmp((char*)TenNV.c_str(), (char*)TenNV1.c_str()) < 0)
			{
				DoiChoNV(h->Nhanvien, g->Nhanvien);
			}
		}
	}
}

//hàm sắp xếp theo Mã Nhân Viên
void SapXeptheoMaNhanVien(LIST_NHANVIEN& lnv, NHANVIEN nv)
{
	//hàm duyệt list nhân viên từ đầu đến cuối danh sách
	for (NODE_NHANVIEN* h = lnv.pHead; h != NULL; h = h->pNext)
	{
		for (NODE_NHANVIEN* g = lnv.pHead; g != NULL; g = g->pNext)
		{
			//tạo 2 thằng mã nhân viên để đi so sánh với nhau
			string MaNV = h->Nhanvien.MaNV;
			string MaNV1 = g->Nhanvien.MaNV;
			//hàm so sánh từng phần tử trong mã nhân viên/ngược lại nếu hèm trả về <0 tức là chuỗi mã khách hàng trước lớn hơn mã sau
			if (_stricmp((char*)MaNV.c_str(), (char*)MaNV1.c_str()) < 0)
			{
				DoiChoNV(h->Nhanvien, g->Nhanvien);
			}
		}
	}
}

//hàm sắp xếp theo Mã Công Việc
void SapXeptheoMaCongViec(LIST_NHANVIEN& lnv, NHANVIEN nv)
{
	//hàm duyệt list nhân viên từ đầu đến cuối danh sách
	for (NODE_NHANVIEN* h = lnv.pHead; h != NULL; h = h->pNext)
	{
		for (NODE_NHANVIEN* g = lnv.pHead; g != NULL; g = g->pNext)
		{
			//tạo 2 thằng mã công việc để đi so sánh với nhau
			string MaCV = h->Nhanvien.MaCV;
			string MaCV1 = g->Nhanvien.MaCV;
			//hàm so sánh từng phần tử trong mã nhân viên
			//ngược lại nếu hèm trả về <0 tức là chuỗi mã công việc trước lớn hơn mã sau
			if (_stricmp((char*)MaCV.c_str(), (char*)MaCV1.c_str()) < 0)
			{
				DoiChoNV(h->Nhanvien, g->Nhanvien);
			}
		}
	}
}

void xuatdanhsachNhanVien(LIST_NHANVIEN l)
{
	ToMauHCN(63, 12, 133, 10, 76);//tô màu thanh thông tin
	ToMauHCN(63, 20, 133, 5, 111);//tô màu thanh trạng thái
	VeHCN(63, 12, 133, 38, 3);
	//VeHCN(63, 20, 133, 31, 1926);
	ToMauHCN(63, 24, 133, 28, 1926);//tô màu danh sách Nhân Viên
	HCNTextDong(63, 24, 134, 28);
	HCNText(63, 24, 134, 28);
	textcolor(1926);

	NHANVIEN nv;
	gotoXY(114, 15);
	textcolor(76);
	cout << "THONG TIN NHAN VIEN";
	textcolor(1926);
	VeHCN(63, 20, 133, 31, 3);

	VeHCN(64,14,6,2,76);
	gotoXY(65, 15);
	cout << "Thoat";

	int j = 64;
	while (j < 196)
	{
		gotoXY(j, 24);
		cout << "_";
		j++;
	}
	textcolor(111);
	gotoXY(65, 22);
	cout << "MaNV";
	gotoXY(83, 22);
	cout << "TenNV";
	gotoXY(103, 22);
	cout << "MaCV";
	gotoXY(115, 22);
	cout << "SoDT";
	gotoXY(125, 22);
	cout << "Gioi tinh";
	gotoXY(138, 22);
	cout << "Dia Chi";
	gotoXY(151, 22);
	cout << "Ngay Sinh";
	gotoXY(164, 22);
	cout << "Ngay Bat Dau";
	gotoXY(181, 22);
	cout << "Ngay Het Han";
	int a = 1;
	textcolor(1926);
		for (NODE_NHANVIEN* k = l.pHead; k != NULL; k = k->pNext)
		{
			
			gotoXY(65, 24 + a);
			cout << k->Nhanvien.MaNV;
			gotoXY(74, 24 + a);
			cout << k->Nhanvien.TenNV;
			gotoXY(102, 24 + a);
			cout << k->Nhanvien.MaCV;
			gotoXY(112, 24 + a);
			cout << k->Nhanvien.SoDT;
			gotoXY(125, 24 + a);
			cout << k->Nhanvien.GioiTinh;
			gotoXY(137, 24 + a);
			cout << k->Nhanvien.DiaChi;
			gotoXY(149, 24 + a);
			cout << k->Nhanvien.NgaySinh;
			gotoXY(164, 24 + a);
			cout << k->Nhanvien.NgayNhanViec;
			gotoXY(180, 24 + a);
			cout << k->Nhanvien.NgayHetHanCV;
			//cout << endl;

			a = a + 2;

		}
		textcolor(7);
		do
		{
		if (batSuKien(57, 17, 5, 2))
		{
			break;
		}
		} while (true);
}

//======================================================= QUẢN LÍ PHÒNG ===================================================================================
// ============================= STRUCT PHONG ========================================
struct phong
{
	string MaPhong;
	string TenPhong;
	string MaLoaiPhong;
	string GiaPhong;
	string TinhTrangPhong;
};
typedef struct phong PHONG;

struct node_phong
{
	PHONG data;
	struct node_phong* pNext;
};
typedef struct node_phong NODE_PHONG;

struct list_phong
{
	NODE_PHONG* pHead;
	NODE_PHONG* pTail;
};
typedef struct list_phong LIST_PHONG;
// ======================================== KHOI TAO PHONG ===================================
void KhoitaoPhong(LIST_PHONG& lp)
{
	lp.pHead = lp.pTail = NULL;
}
NODE_PHONG* Khoitaonodephong(PHONG ph)
{
	NODE_PHONG* i = new NODE_PHONG;
	if (i == NULL)
	{
		cout << "\n Khong du bo nho de cap phat ";
		return 0;
	}
	else
	{
		i->data = ph;
		i->pNext = NULL;
		return i;
	}
}
// ======================================= THEM PHONG ========================================
void ThemPhong(LIST_PHONG& lp, NODE_PHONG* i)
{
	if (lp.pHead == NULL)
	{
		lp.pHead = lp.pTail = i;
	}
	else
	{
		lp.pTail->pNext = i;
		lp.pTail = i;
	}
}
// ========================================= DIEU KIEN ===============================================
bool KT_Rong_MaPhong(PHONG ph)
{
	if (ph.MaPhong == "")
		return false;
	return true;
}
bool KT_Rong_TenPhong(PHONG ph)
{
	if (ph.TenPhong == "")
		return false;
	return true;
}
bool KT_Rong_MaLoaiPhong(PHONG ph)
{
	if (ph.MaLoaiPhong == "")
		return false;
	return true;
}
bool KT_Rong_GiaPhong(PHONG ph)
{
	if (ph.GiaPhong == "")
		return false;
	return true;
}
bool KT_Rong_TinhTrangPhong(PHONG ph)
{
	if (ph.TinhTrangPhong == "")
		return false;
	return true;
}
// Kiem tra phong trung nhau
bool KT_Trung_Phong(LIST_PHONG lph, PHONG ph)
{
	for (NODE_PHONG* i = lph.pHead; i != NULL; i++)
	{
		if ((i->data.MaPhong == ph.MaPhong) || (i->data.TenPhong == ph.TenPhong))
		{
			return true;
		}
	}
	return false;
}
bool KT_Trung_MaPhong(LIST_PHONG lph, PHONG ph)
{
	for (NODE_PHONG* i = lph.pHead; i != NULL; i = i->pNext)
	{
		if ((i->data.MaPhong == ph.MaPhong))
		{
			return true;
		}
	}
	return false;
}
bool KT_Trung_TenPhong(LIST_PHONG lph, PHONG ph)
{
	for (NODE_PHONG* i = lph.pHead; i != NULL; i = i->pNext)
	{
		if ((i->data.TenPhong == ph.TenPhong))
		{
			return true;
		}
	}
	return false;
}
// Kiem tra ten phong la so
int KT_Ten_Phong(PHONG ph)
{
	int dem = 0;
	int n = ph.TenPhong.length();

	if (ph.TenPhong[0] == ' ')
	{
		return 0;
	}
	if (ph.TenPhong[n - 1] == ' ')
	{
		return 0;
	}
	for (int i = 0; i < ph.TenPhong.length(); i++) {
		if (ph.TenPhong[i] < '0' || ph.TenPhong[i] >'9' || ph.TenPhong[i] >= 'a' && ph.TenPhong[i] <= 'z' || ph.TenPhong[i] >= 'A' && ph.TenPhong[i] <= 'Z')
		{
			return 0;
			break;
		}
		else if (ph.TenPhong[i] >= '0' && ph.TenPhong[i] <= '9')
			dem++;
	}
	if (dem == ph.TenPhong.length())
		return 1;
}
// Kiem tra gia phong la so
int KT_Gia_Phong(PHONG ph)
{
	int dem = 0;
	for (int i = 0; i < ph.GiaPhong.length(); i++) {
		if (ph.GiaPhong[i] < '0' || ph.GiaPhong[i] >'9' || ph.GiaPhong[i] >= 'a' && ph.GiaPhong[i] <= 'z' || ph.GiaPhong[i] >= 'A' && ph.GiaPhong[i] <= 'Z')
		{
			return 0;
			break;
		}
		else if (ph.GiaPhong[i] >= '0' && ph.GiaPhong[i] <= '9')
			dem++;
	}
	if (dem == ph.GiaPhong.length())
		return 1;
}
bool PhongRong(LIST_PHONG lp)
{
	if (lp.pHead == NULL)
		return true;
	return false;
}
int KT_TinhTrangPhong(PHONG p)
{
	if ((p.TinhTrangPhong == "Rong") || (p.TinhTrangPhong == "Day"))
		return 1;
	else
		return 0;
}
int KT_MaLoaiPhong(PHONG p)
{
	if ((p.MaLoaiPhong == "vip") || (p.MaLoaiPhong == "thuong"))
		return 1;
	else
		return 0;
}
int KT_CuPhapMaPhong(PHONG ph)
{
	int dem = 0;
	int dem1 = 0;
	int n = ph.MaPhong.length();
	if (ph.MaPhong[0] == ' ')
	{
		return 0;
	}
	if (ph.MaPhong[n - 1] == ' ')
	{
		return 0;
	}
	for (int i = 1; i < ph.MaPhong.length(); i++)
	{

		if (!(ph.MaPhong[0] >= 'a' && ph.MaPhong[0] <= 'z' || ph.MaPhong[0] >= 'A' && ph.MaPhong[0] <= 'Z'))
		{
			return 0;
			break;
		}
		else
			dem1 = 1;

		if (ph.MaPhong[i] < '0' || ph.MaPhong[i] >'9' || ph.MaPhong[i] >= 'a' && ph.MaPhong[i] <= 'z' || ph.MaPhong[i] >= 'A' && ph.MaPhong[i] <= 'Z')
		{
			return 0;
			break;
		}
		else if (ph.MaPhong[i] >= '0' && ph.MaPhong[i] <= '9')
			dem++;
	}
	//if ((ph.MaPhong[0] >= 'a' && ph.MaPhong[0] <= 'z' || ph.MaPhong[0] >= 'A' && ph.MaPhong[0] <= 'Z') && (dem == ph.MaPhong.length() - 1))
	//	return 1;
	if ((dem1 == 1) && (dem == ph.MaPhong.length() - 1))
		return 1;
}
int CheckMaPhong(LIST_PHONG lp, string t) //kiểm tra tên khách hàng có tồn tại trong list
{
	NODE_PHONG* p = lp.pHead;
	while (p != NULL)
	{
		if (p->data.MaPhong == t) return true;
		p = p->pNext;
	}
	return false;
}
void XoaDauPhong(LIST_PHONG& lp)
{
	//nếu danh sách rỗngg
	if (lp.pHead == NULL) {
		return;
	}
	else {
		NODE_PHONG* p = lp.pHead;//node p là node sẽ xóa
		lp.pHead = lp.pHead->pNext;
		delete p;
	}
}
void XoaCuoiPhong(LIST_PHONG& lp)
{
	//nếu danh sách rỗng
	if (lp.pHead == NULL)
	{
		return;
	}
	//trường hợp danh sách có phần tử
	if (lp.pHead->pNext == NULL)
	{
		XoaDauPhong(lp);
		return;
	}
	//duyệt từ đầu danh sách tới thằng kế cuối
	for (NODE_PHONG* k = lp.pHead; k != NULL; k = k->pNext)
	{
		//phát hiện thằng kế cuối
		if (k->pNext == lp.pTail)
		{
			delete lp.pTail; //xóa đi phần tử cuối
			k->pNext = NULL;//cho con trỏ của node thằng kế cuối trỏ đến vùng nhớ null
			lp.pTail = k;
		}
	}
}

void GiaoDienNhoPhong(LIST_PHONG& lp, PHONG& p)
{
	VeHCN(79, 14, 30, 2, 4);
	gotoXY(80, 15);
	cout << "	Them Phong";

	VeHCN(79, 17, 30, 2, 4);
	gotoXY(80, 18);
	cout << "	Tra Cuu Phong";

	VeHCN(79, 20, 30, 2, 4);
	gotoXY(80, 21);
	cout << "	Thong Tin Phong";

	VeHCN(79, 23, 30, 2, 4);
	gotoXY(80, 24);
	cout << "	Dat Phong";

	VeHCN(79, 26, 30, 2, 4);
	gotoXY(80, 27);
	cout << "	Thay doi Phong";

	VeHCN(79, 29, 30, 2, 4);
	gotoXY(80, 30);
	cout << "	Xoa Phong";

	VeHCN(79, 32, 30, 2, 4);
	gotoXY(80, 33);
	cout << "   Danh Sach Phong";

	VeHCN(79, 35, 30, 2, 4);
	gotoXY(80, 36);
	cout << "     Thoat";
}
void GiaoDienThemPhong(LIST_PHONG& lp, PHONG& p)
{
	VeHCN(79, 14, 16, 2, 4);
	gotoXY(80, 15);
	cout << "Ma Phong:";
	VeHCN(96, 14, 50, 2, 4);

	VeHCN(79, 17, 16, 2, 4);
	gotoXY(80, 18);
	cout << "Ten Phong:";
	VeHCN(96, 17, 50, 2, 4);

	VeHCN(79, 20, 16, 2, 4);
	gotoXY(80, 21);
	cout << "Ma loai Phong:";
	VeHCN(96, 20, 50, 2, 4);

	VeHCN(79, 23, 16, 2, 4);
	gotoXY(80, 24);
	cout << "Gia Phong:";
	VeHCN(96, 23, 50, 2, 4);

	VeHCN(79, 26, 16, 2, 4);
	gotoXY(80, 27);
	cout << "Tinh Trang Phong:";
	VeHCN(96, 26, 50, 2, 4);

	VeHCN(79, 35, 16, 2, 4);
	gotoXY(80, 36);
	cout << " Luu Lai";

	VeHCN(125, 35, 16, 2, 4);
	gotoXY(126, 36);
	cout << " Tro Ve ";
}
void GiaoDienTraCuuPhong(LIST_PHONG& lp, PHONG& p)
{
	VeHCN(79, 14, 30, 2, 4);
	gotoXY(80, 15);
	cout << "Tra cuu theo ma phong";

	VeHCN(79, 17, 30, 2, 4);
	gotoXY(80, 18);
	cout << "           Thoat";
}
void GiaoDienThayDoiPhong(LIST_PHONG& lp, PHONG& p)
{
	VeHCN(79, 14, 30, 2, 4);
	gotoXY(80, 15);
	cout << "Thay doi theo ma phong";

	VeHCN(79, 17, 30, 2, 4);
	gotoXY(80, 18);
	cout << "	Thoat";
}
void GiaoDienXoaPhong(LIST_PHONG& lp, PHONG& p)
{
	VeHCN(79, 14, 30, 2, 4);
	gotoXY(80, 15);
	cout << "  Xoa theo ma phong";

	VeHCN(79, 17, 30, 2, 4);
	gotoXY(80, 18);
	cout << "	Thoat";

}
void Docfilephong(LIST_PHONG& lp)
{
	ifstream filein;
	filein.open("DSPhong.txt", ios_base::in);

	while (!filein.eof()) {
		PHONG p;
		getline(filein, p.MaPhong, ',');
		getline(filein, p.TenPhong, ',');
		getline(filein, p.MaLoaiPhong, ',');
		getline(filein, p.GiaPhong, ',');
		getline(filein, p.TinhTrangPhong);
		NODE_PHONG* i = Khoitaonodephong(p);
		ThemPhong(lp, i);
	}

	filein.close();
}
void Ghifilephong(LIST_PHONG& lp)
{
	ofstream fileout;
	fileout.open("DSPhong.txt");

	for (NODE_PHONG* i = lp.pHead; i != NULL; i = i->pNext)
	{
		//if ((i->data.MaPhong.length() - 3) >= 'a' && (i->data.MaPhong.length() - 3) <= 'z')
		//{
		//	i->data.MaPhong.length() - 3 -= 32;
		//}
		fileout << i->data.MaPhong << ",";
		fileout << i->data.TenPhong << ",";
		fileout << i->data.MaLoaiPhong << ",";
		fileout << i->data.GiaPhong << ",";
		fileout << i->data.TinhTrangPhong;
		if (i->pNext != NULL)
		{
			fileout << endl;
		}
		else
		{
			break;
		}
	}
	fileout.close();

}
void XuatPhong(LIST_PHONG lp)
{
	VeHCN(60, 12, 100, 35, 3);
	ToMauHCN(60, 12, 100, 35, 3);
	gotoXY(80, 15);
	int y = 15;

	for (NODE_PHONG* i = lp.pHead; i != NULL; i = i->pNext)
	{
		y++;
		gotoXY(80, y);
		cout << i->data.MaPhong << "," << i->data.TenPhong << "," << i->data.MaLoaiPhong << "," << i->data.GiaPhong << "," << i->data.TinhTrangPhong << endl;

	}
}
void Print_1_MaPhong(PHONG p, int x, int y)
{
	gotoXY(x, y);
	cout << p.MaPhong << endl;
	gotoXY(x, y + 1);
	cout << p.TenPhong << endl;
	gotoXY(x, y + 2);
	cout << p.MaLoaiPhong << endl;
	gotoXY(x, y + 3);
	cout << p.GiaPhong << endl;
	gotoXY(x, y + 4);
	cout << p.TinhTrangPhong << endl;
}
void createphong(LIST_PHONG& lp, PHONG& p)
{
	//KhoitaoPhong(lp);
	do
	{
		XoaManHinhTuyChon(97, 15, 45, 1);
		gotoXY(97, 15);
		fflush(stdin);
		getline(cin, p.MaPhong);
		XoaManHinhTuyChon(147, 15, 30, 2);
		if (p.MaPhong.length() == 1)
		{
			fflush(stdin);
			XoaManHinhTuyChon(97, 15, 45, 1);
			gotoXY(147, 15);
			cout << "MP qua ngan";
		}
		if (KT_Rong_MaPhong(p) == false)
		{
			fflush(stdin);
			XoaManHinhTuyChon(97, 15, 45, 1);
			gotoXY(147, 15);
			cout << "MP rong ";

		}
		if ((KT_Trung_MaPhong(lp, p) == true))
		{
			fflush(stdin);
			XoaManHinhTuyChon(97, 15, 45, 1);
			gotoXY(147, 15);
			cout << "MP trung ";
		}


		if (KT_CuPhapMaPhong(p) == 0)
		{
			fflush(stdin);
			XoaManHinhTuyChon(97, 15, 45, 1);
			gotoXY(147, 15);
			cout << "Sai cu phap";
		}
		if (p.MaPhong.length() > 10)
		{
			fflush(stdin);
			XoaManHinhTuyChon(97, 15, 45, 1);
			gotoXY(147, 15);
			cout << "MP k qua 10 kt ";
		}
	} while ((KT_Rong_MaPhong(p) == false) || (KT_Trung_MaPhong(lp, p) == true) || (KT_CuPhapMaPhong(p) == 0) || (p.MaPhong.length() > 10) || (p.MaPhong.length() == 1));

	do
	{
		gotoXY(97, 18);
		rewind(stdin);
		getline(cin, p.TenPhong);
		XoaManHinhTuyChon(147, 18, 30, 2);

		if (KT_Rong_TenPhong(p) == false)
		{
			XoaManHinhTuyChon(97, 18, 45, 1);
			gotoXY(147, 18);
			cout << "TP rong ";

		}
		if ((KT_Trung_TenPhong(lp, p) == true))
		{
			XoaManHinhTuyChon(97, 18, 45, 1);
			gotoXY(147, 18);
			cout << "TP trung ";
		}
		if ((KT_Ten_Phong(p) == 0))
		{
			XoaManHinhTuyChon(97, 18, 45, 1);
			gotoXY(147, 18);
			cout << "la so";
		}

	} while ((KT_Rong_TenPhong(p) == false) || (KT_Trung_TenPhong(lp, p) == true) || (KT_Ten_Phong(p) == 0));

	do
	{
		gotoXY(97, 21);
		rewind(stdin);
		getline(cin, p.MaLoaiPhong);
		XoaManHinhTuyChon(147, 21, 30, 2);
		if ((KT_Rong_MaLoaiPhong(p) == false))
		{
			XoaManHinhTuyChon(97, 21, 45, 1);
			gotoXY(147, 21);
			cout << "MLP rong ";
		}
		if (KT_MaLoaiPhong(p) == 0)
		{
			XoaManHinhTuyChon(97, 21, 45, 1);
			gotoXY(147, 21);
			cout << "MLP: 'vip' or 'thuong'";
		}
	} while ((KT_Rong_MaLoaiPhong(p) == false) || (KT_MaLoaiPhong(p) == 0));
	do
	{
		gotoXY(97, 24);
		rewind(stdin);
		getline(cin, p.GiaPhong);
		XoaManHinhTuyChon(147, 24, 30, 2);
		if ((KT_Rong_GiaPhong(p) == false))
		{
			XoaManHinhTuyChon(97, 24, 45, 1);
			gotoXY(147, 24);
			cout << "Gia Phong rong ";
		}
		if (KT_Gia_Phong(p) == 0)
		{
			XoaManHinhTuyChon(97, 24, 45, 1);
			gotoXY(147, 24);
			cout << "la so";
		}
	} while ((KT_Rong_GiaPhong(p) == false) || (KT_Gia_Phong(p) == 0));
	do
	{
		gotoXY(97, 27);
		rewind(stdin);
		getline(cin, p.TinhTrangPhong);
		XoaManHinhTuyChon(147, 27, 30, 2);
		if (KT_Rong_TinhTrangPhong(p) == false)
		{
			XoaManHinhTuyChon(97, 27, 45, 1);
			gotoXY(147, 27);
			cout << "TTP rong ";
		}
		if (KT_TinhTrangPhong(p) == 0)
		{
			XoaManHinhTuyChon(97, 27, 45, 1);
			gotoXY(147, 27);
			cout << "TTP: 'Rong' or 'Day'";
		}
	} while ((KT_Rong_TinhTrangPhong(p) == false) || (KT_TinhTrangPhong(p) == 0));
	//transform(p.MaPhong.begin(), p.MaPhong.begin(), p.MaPhong.begin(), ::toupper);
	//XoaManHinhTuyChon(147, 27, 10, 2);
	//XoaManHinhTuyChon(147, 24, 10, 2);
	NODE_PHONG* i = Khoitaonodephong(p);
	ThemPhong(lp, i);

}

void GiaoDienThongBaoThatBai(string x)
{
	ToMauHCN(90, 17, 50, 10, 95);
	textcolor(95);
	gotoXY(91, 20);
	cout << CanDeuChuoi(x, 49);
	gotoXY(103, 23);
	system("pause");
	//Sleep(2000);
	textcolor(7);
}
int sophong(LIST_PHONG lp)
{
	int soKH = 1;
	for (NODE_PHONG* p = lp.pHead; p != NULL; p = p->pNext)
	{
		soKH++;
	}
	return soKH;
}
void output1Phong(PHONG p, int x, int y) {
	//int x = 1, y = 1;
	gotoXY(x, y);
	cout << "\t\tThong tin ma phong!!!" << endl;
	gotoXY(x, y + 1);
	cout << "Ma phong: " << p.MaPhong << endl;
	gotoXY(x, y + 2);
	cout << "Ten phong:" << p.TenPhong << endl;
	gotoXY(x, y + 3);
	cout << "Ma loai phong: " << p.MaLoaiPhong << endl;
	gotoXY(x, y + 4);
	cout << "Gia phong:	" << p.GiaPhong << endl;
	gotoXY(x, y + 5);
	cout << "Tinh trang phong: " << p.TinhTrangPhong << endl;

}
void ListMaPhong(LIST_PHONG lp)
{
	int i = 1;
	int Y = 15;
	for (NODE_PHONG* p = lp.pHead; p != NULL; p = p->pNext) {
		gotoXY(106, Y++);
		cout << "Ma phong thu " << i++ << ": " << p->data.MaPhong << endl;
	}
}

void TimKiemPhong_MP(LIST_PHONG lp)
{
	VeHCN(80, 13, 30, 2, 3); // Vẽ khung Tìm kiếm thông tin
	//ToMauHCN(80, 13, 30, 2, 255);
	gotoXY(81, 14);
	textcolor(7);
	cout << "Tim Kiem Thong Tin Khach Hang";
	VeHCN(75, 15, 30, 2, 3);
	gotoXY(76, 16);
	cout << "Nhap Ma KH can tim kiem:";
	VeHCN(73, 18 + sophong(lp) + 9, 10, 2, 3); // Vẽ khung quay lai
	gotoXY(74, 18 + sophong(lp) + 10);
	cout << "Quay lai.";
	VeHCN(120, 18 + sophong(lp) + 9, 10, 2, 3); // Vẽ khung Tiếp tục
	gotoXY(121, 18 + sophong(lp) + 10);
	cout << "Tiep tuc.";
	int x = 100;
	char c[100];
	int y = 10;
	int z = 0;
	int dem = 1;
	int demBreak = 0;
	do
	{
		ShowCur(1);
		do {

			gotoXY(x++, 16);
			c[z] = _getche();// A
			if (c[z] >= 'a' && c[z] <= 'z')
			{
				c[z] -= 32;
			}
			XoaManHinhTuyChon(84, 18, 39, sophong(lp) + 6); //rs khung thông tin
		} while (c[z] == '\r');
		int Y = 18;
		ShowCur(0);

		VeHCN(83, 17, 40, 1 + sophong(lp) + 6, 2); // Khung thong tin
		//ToMauHCN(83, 17, 40, 12, 244);
		textcolor(7);
		for (NODE_PHONG* k = lp.pHead; k != NULL; k = k->pNext)
		{
			for (int i = 0; i < k->data.MaPhong.length(); i++)
			{
				if (i == z)
				{
					if (z == 0) {
						if (c[z] == k->data.MaPhong[i])
						{
							gotoXY(85, Y++);
							cout << k->data.MaPhong << "  " << k->data.MaPhong << endl;
							gotoXY(85, Y++);
							cout << "-------------------------------------" << endl;
							demBreak = 0;
							//break;
						}
					}
					else if (z > 0 && z < k->data.MaPhong.length() - 1) {
						if (c[z] == k->data.MaPhong[i] && c[z - 1] == k->data.MaPhong[i - 1])
						{
							gotoXY(85, Y++);
							cout << k->data.MaPhong << "  " << k->data.MaPhong << endl;
							gotoXY(85, Y++);
							cout << "-------------------------------------" << endl;
							demBreak = 0;
							//break;
						}
					}
					else if (z == k->data.MaPhong.length() - 1) {
						int dem = 0;
						for (int i = 0; i < k->data.MaPhong.length(); i++) {
							if (k->data.MaPhong[i] == c[i]) {
								dem++;
							}
						}
						if (dem == k->data.MaPhong.length()) {
							XoaManHinhTuyChon(84, 18, 39, 9);
							output1Phong(k->data, 85, 18);
							if (batSuKien(73, 30 + sophong(lp) + 8, 10, 2)) {// Bắt sự kiện quay lại
								HCNTextDong1(74, 18 + sophong(lp) + 10, 10, 2);
								demBreak = 3;
								//break;

							}
							// ==========================Lỗi tiếp tục=========================//
							else if (batSuKien(115, 38, 10, 2)) { // Bắt sự kiện tiếp tục
								/*system("cls");
								continue;*/
								XoaManHinhTuyChon(100, 16, 10, 1);
								//PDK_TimKiem(lpdk);	
								demBreak = 1;
							}
						}
					}

				}

			}
		}
		z++;
		
	} while (demBreak <= 2);
}

void ThayDoiPhong(LIST_PHONG& lp, PHONG p)
{//hàm thay đổi thông tin khách hàng
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);
	string thuocTinh;
	string changed;
	int dem = 0;
	VeHCN(105, 13, 50, 1 + sophong(lp), 2); // Khung hien ten khach hang có số khách hàng là int
	gotoXY(106, 14);
	cout << "Danh sach ma phong" << endl;
	ListMaPhong(lp);
	gotoXY(90, 18 + sophong(lp) + 4); // Khi số KH tăng thì cái này
	cout << "Nhap Ma phong can Sua: ";
	rewind(stdin);
	VeHCN(120, 18 + sophong(lp) + 3, 30, 2, 5); // Khung nhap ten khach hang can xoa
	VeHCN(100, 18 + sophong(lp) + 7, 10, 2, 3); // Khung huy
	gotoXY(103, 18 + sophong(lp) + 8);
	cout << "Huy";
	VeHCN(130, 18 + sophong(lp) + 7, 10, 2, 3); // Khung dong y
	gotoXY(131, 18 + sophong(lp) + 8);
	cout << "Dong y";

	do
	{
		XoaManHinhTuyChon(123, 18 + sophong(lp) + 4, 20, 1);
		gotoXY(123, 18 + sophong(lp) + 4);
		ShowCur(1); // Hien con tro
		rewind(stdin);
		getline(cin, p.MaPhong);
		//XoaManHinhTuyChon(114, 18 + sophong(lp) + 4, 33, 1);
		if (!(CheckMaPhong(lp, p.MaPhong)))
		{
			XoaManHinhTuyChon(116, 18 + sophong(lp) + 4, 60, 1);
			gotoXY(116, 18 + sophong(lp));
			cout << "=>Ma phong khong co trong danh sach";
		}
		if (KT_CuPhapMaPhong(p) == 0)
		{
			XoaManHinhTuyChon(116, 18 + sophong(lp) + 4, 60, 1);
			gotoXY(116, 18 + sophong(lp));
			cout << "=>Ma phong sai cu phap ";
		}
		if (KT_Rong_MaPhong(p) == false)
		{
			XoaManHinhTuyChon(116, 18 + sophong(lp) + 4, 60, 1);
			gotoXY(116, 18 + sophong(lp));
			cout << "=>Ma phong dang rong ";
		}
	} while (!(CheckMaPhong(lp, p.MaPhong)) || KT_CuPhapMaPhong(p) == 0 || KT_Rong_MaPhong(p) == false);

	//while(true)
	//{
	//	VeHCN(60, 12, 100, 35, 3);
	//	ToMauHCN(60, 12, 100, 35, 3);
	//	VeHCN(75, 30, 10, 2, 3); // Vẽ khung Mã KH
	//	gotoXY(75, 31);
	//	cout << "Ma Phong";

	//	VeHCN(92, 30, 10, 2, 3); // Vẽ khung Tên KH
	//	gotoXY(92, 31);
	//	cout << "Ten Phong";

	//	VeHCN(109, 30, 12, 2, 3); // Vẽ khung Gioi tinh
	//	gotoXY(111, 31);
	//	cout << "ML Phong";

	//	VeHCN(126, 30, 10, 2, 3); // Vẽ khung So Dt
	//	gotoXY(128, 31);
	//	cout << "Gia Phong";

	//	VeHCN(75, 34, 10, 2, 3); // Vẽ khung Dia chi
	//	gotoXY(76, 35);
	//	cout << "TT Phong";
	//
	//	if (batSuKien(10, 10, 2, 10))
	//	{
	//		cout << "aaaa";
	//	}
	//}

	if (batSuKien(89, 34 + sophong(lp), 9, 2))
	{//bắt sự kiện hủy
		return;
	}
	else if (batSuKien(117, 34 + sophong(lp), 9, 2))
	{//bắt sự kiện đồng ý

		ShowCur(0);
		/*VeHCN(63, 12, 133, 39, 3);
		ToMauHCN(63, 12, 133, 39, 3);*/
		VeHCN(63, 12, 133, 39, 3);
		ToMauHCN(63, 12, 133, 39, 3);
		//		system("cls");

		VeHCN(79, 14, 50, 10, 2); // Vẽ HCN cho thông tin Khach hang
		for (NODE_PHONG* q = lp.pHead; q != NULL; q = q->pNext) {
			if (q->data.MaPhong == p.MaPhong) {
				Print_1_MaPhong(q->data, 80, 15);
				dem++;
			}
		}
		// Vẽ các khung thuộc tính
		VeHCN(75, 30, 10, 2, 3); // Vẽ khung Mã KH
		gotoXY(77, 31);
		cout << "Ma Phong";

		VeHCN(92, 30, 10, 2, 3); // Vẽ khung Tên KH
		gotoXY(93, 31);
		cout << "Ten Phong";

		VeHCN(109, 30, 12, 2, 3); // Vẽ khung Gioi tinh
		gotoXY(111, 31);
		cout << "ML Phong";

		VeHCN(126, 30, 11, 2, 3); // Vẽ khung So Dt
		gotoXY(128, 31);
		cout << "Gia Phong";

		VeHCN(144, 30, 10, 2, 3); // Vẽ khung Dia chi
		gotoXY(145, 31);
		cout << "TT Phong";
	}
	//do 
	//{
	//	if (batSuKien(1, 1, 1, 1))
	//	{
	//		cout << "aaaaaa";

	//	}
	//} while (true);
	for (NODE_PHONG* q = lp.pHead; q != NULL; q = q->pNext)
	{
		if (q->data.MaPhong == p.MaPhong)
		{
			if (batSuKien(67, 38, 10, 2))
			{ // Ma phong
				//cout << "aaaaaa";
				do {

					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->data.MaPhong << " muon thanh doi thanh: ";
					//fflush(stdin);
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					p.MaPhong = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_Trung_MaPhong(lp, p) == true)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ma phong trung, vui long nhap lai!!!";
					}
					if (KT_Rong_MaPhong(p) == false)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ma phong dang rong, vui long nhap lai!!!";
					}
				} while (KT_Trung_MaPhong(lp, p) == true || KT_Rong_MaPhong(p) == false);
				q->data.MaPhong = p.MaPhong = changed;
				//cout << "1"<<q->data.MaPhong << endl;
				//cout << "2"<<p.MaPhong << endl;
				//cout << "3"<<changed << endl;
			}
			else if (batSuKien(82, 38, 10, 2))
			{ // Ten phong
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->data.TenPhong << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(105, 45);
					getline(cin, changed);
					p.TenPhong = changed;
					XoaManHinhTuyChon(105, 47, 50, 1);
					if (KT_Rong_TenPhong(p) == false)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ten phong dang rong, vui long nhap lai!!!";
					}
					if (KT_Ten_Phong(p) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ten Phong dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_Rong_TenPhong(p) == false || KT_Ten_Phong(p) == 0);
				q->data.TenPhong = p.TenPhong = changed;
			}
			else if (batSuKien(98, 38, 10, 2))
			{ // Ma loai phong
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->data.MaLoaiPhong << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					p.MaLoaiPhong = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if ((KT_Rong_MaLoaiPhong(p) == false))
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ma Loai Phong dang rong";
					}
					if (KT_MaLoaiPhong(p) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Ma Loai Phong dinh dang sai ";
					}
				} while ((KT_Rong_MaLoaiPhong(p) == false || KT_MaLoaiPhong(p) == 0));
				q->data.MaLoaiPhong = p.MaLoaiPhong = changed;
			}
			else if (batSuKien(123, 38, 10, 2))
			{ // Gia phong
				do {
					gotoXY(67, 45);
					ShowCur(1); // Hien con tro
					cout << q->data.GiaPhong << " muon thanh doi thanh: ";
					rewind(stdin);
					gotoXY(100, 45);
					getline(cin, changed);
					p.GiaPhong = changed;
					XoaManHinhTuyChon(100, 47, 50, 1);
					if (KT_Rong_GiaPhong(p) == false)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>Gia phong dang rong!!";
					}
					if (KT_Gia_Phong(p) == 0)
					{
						XoaManHinhTuyChon(95, 45, 32, 1);
						gotoXY(95, 47);
						cout << "=>TTP dinh dang sai, vui long nhap lai!!!";
					}
				} while (KT_Rong_GiaPhong(p) == false || KT_Gia_Phong(p) == 0);
				q->data.GiaPhong = p.GiaPhong = changed;
			}
			else if (batSuKien(129, 38, 10, 2))
			{ // Gia phong
			do {
				gotoXY(67, 45);
				ShowCur(1); // Hien con tro
				cout << q->data.TinhTrangPhong << " muon thanh doi thanh: ";
				rewind(stdin);
				gotoXY(100, 45);
				getline(cin, changed);
				p.TinhTrangPhong = changed;
				XoaManHinhTuyChon(100, 47, 50, 1);
				if (KT_Rong_TinhTrangPhong(p) == false)
				{
					XoaManHinhTuyChon(95, 45, 32, 1);
					gotoXY(95, 47);
					cout << "=>TTP phong dang rong!!";
				}
				if (KT_TinhTrangPhong(p) == 0)
				{
					XoaManHinhTuyChon(95, 45, 32, 1);
					gotoXY(95, 47);
					cout << "=>TTP dinh dang sai, vui long nhap lai!!!";
				}
			} while (KT_Rong_TinhTrangPhong(p) == false || KT_TinhTrangPhong(p) == 0);
			q->data.TinhTrangPhong = p.TinhTrangPhong = changed;
			}
		}
	}
	gotoXY(70, 40);
	cout << thuocTinh << " da duoc thay doi!!!" << endl;
	Ghifilephong(lp);
	//gotoXY(140, 40);
	system("pause");
}

void XoaBatKiPhong(LIST_PHONG& lp, PHONG p)
{
	ShowCur(1);
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);
	VeHCN(79, 13, 50, 1 + sophong(lp), 2); // Khung hien ten khach hang có số khách hàng là int
	gotoXY(81, 14);
	cout << "Danh sach Ma Phong." << endl;
	ListMaPhong(lp);
	gotoXY(70, 18 + sophong(lp) + 4); // Khi số KH tăng thì cái này
	cout << "Nhap Ma phong can xoa: ";
	rewind(stdin);
	VeHCN(113, 18 + sophong(lp) + 3, 20, 2, 5); // Khung nhap ten khach hang can xoa
	VeHCN(90, 18 + sophong(lp) + 7, 10, 2, 3); // Khung huy
	gotoXY(91, 18 + sophong(lp) + 8);
	cout << "Huy";
	VeHCN(120, 18 + sophong(lp) + 7, 10, 2, 3); // Khung dong y
	gotoXY(121, 18 + sophong(lp) + 8);
	cout << "Dong y";
	//do
	//{
	//	VeHCN(113, 18 + sophong(lp) + 3, 20, 2, 5); // Khung nhap ten khach hang can xoa
	//	VeHCN(90, 18 + sophong(lp) + 7, 10, 2, 3); // Khung huy
	//	gotoXY(91, 18 + sophong(lp) + 8);
	//	cout << "Huy";
	//	VeHCN(120, 18 + sophong(lp) + 7, 10, 2, 3); // Khung dong y
	//	gotoXY(121, 18 + sophong(lp) + 8);
	//	cout << "Dong y";
	//	if (batSuKien(1, 1, 1, 1))
	//	{
	//		cout << "aaaaaaa";
	//	}
	//} while (true);
	do {
		gotoXY(114, 18 + sophong(lp) + 4);
		getline(cin, p.MaPhong);
		XoaManHinhTuyChon(114, 18 + sophong(lp) + 4, 20, 1);
		if ((CheckMaPhong(lp, p.MaPhong)) == 0)
		{
			XoaManHinhTuyChon(116, 18 + sophong(lp) + 4, 60, 1);
			gotoXY(116, 18 + sophong(lp));
			cout << "=>Ma phong khong co trong danh sach";
		}
		if (KT_CuPhapMaPhong(p) == 0)
		{
			XoaManHinhTuyChon(116, 18 + sophong(lp) + 4, 60, 1);
			gotoXY(116, 18 + sophong(lp));
			cout << "=>Ma phong sai cu phap ";
		}
		if (KT_Rong_MaPhong(p) == false)
		{
			XoaManHinhTuyChon(116, 18 + sophong(lp) + 4, 60, 1);
			gotoXY(116, 18 + sophong(lp));
			cout << "=>Ten Khach hang dang rong, Nhap lai";
		}
	} while (!(CheckMaPhong(lp, p.MaPhong)) || KT_CuPhapMaPhong(p) == 0 || KT_Rong_MaPhong(p) == false);


	if (batSuKien(81, 36 + sophong(lp), 8, 2))
	{ // Bắt sự kiện hủy
		return;
	}

	else if (batSuKien(107, 34 + sophong(lp), 10, 2))
	{ // Bắt sự kiện đồng ý
		int dem = 0; // Xem tên khách hàng cần xóa có trong danh sách hay không
		for (NODE_PHONG* k = lp.pHead; k != NULL; k = k->pNext)
		{
			if (p.MaPhong == lp.pHead->data.MaPhong)
			{
				XoaDauPhong(lp);
				gotoXY(100, 50);
				cout << "Xoa thanh cong." << endl;
				system("pause");
				dem++; // Nếu có tăng 1
				break;
			}
			else if (p.MaPhong == lp.pTail->data.MaPhong)
			{
				XoaCuoiPhong(lp);
				gotoXY(100, 50);
				cout << "Xoa thanh cong." << endl;
				system("pause");
				dem++;
				break;
			}
			else
			{
				NODE_PHONG* q = k->pNext;
				if (q->data.MaPhong == p.MaPhong)
				{
					k->pNext = q->pNext;
					gotoXY(100, 50);
					cout << "Xoa thanh cong." << endl;
					system("pause");
					dem++;
					break;
				}
			}
		}

		if (dem == 0)
		{ //  Nếu tên khách hàng cần xóa không có trong danh sách khách hàng
			gotoXY(45, 18);
			cout << p.MaPhong << " khong co trong danh sach." << endl;
			system("pause");
		}
		/*Ghifilephong(lp);*/
	}
}

void xuatdanhsachPhong(LIST_PHONG lp)
{
	VeHCN(63, 12, 133, 38, 3);
	ToMauHCN(63, 24, 133, 28, 1926);//tô màu danh sách Nhân Viên
	HCNTextDong(63, 24, 134, 28);
	HCNText(63, 24, 134, 28);
	ToMauHCN(63, 12, 133, 10, 76);//tô màu thanh thông tin
	ToMauHCN(63, 20, 133, 5, 111);//tô màu thanh trạng thái
	textcolor(1926);

	PHONG p;
	gotoXY(114, 15);
	textcolor(4);
	cout << "THONG TIN PHONG";
	textcolor(4);
	VeHCN(63, 20, 133, 31, 3);

	VeHCN(64, 14, 6, 2, 76);
	gotoXY(65, 15);
	cout << "Thoat";

	int j = 64;
	while (j < 196)
	{
		gotoXY(j, 24);
		cout << "_";
		j++;
	}
	textcolor(111);
	gotoXY(65, 22);
	cout << "Ma Phong";
	gotoXY(90, 22);
	cout << "Ten Phong";
	gotoXY(110, 22);
	cout << "Ma LP";
	gotoXY(140, 22);
	cout << "Gia";
	gotoXY(171, 22);
	cout << "Tinh Trang";
	int a = 1;
	textcolor(1926);
		for (NODE_PHONG* k = lp.pHead; k != NULL; k = k->pNext)
		{

			gotoXY(67, 24 + a);
			cout << k->data.MaPhong;
			gotoXY(92, 24 + a);
			cout << k->data.TenPhong;
			gotoXY(112, 24 + a);
			cout << k->data.MaLoaiPhong;
			gotoXY(142, 24 + a);
			cout << k->data.GiaPhong;
			gotoXY(173, 24 + a);
			cout << k->data.TinhTrangPhong;
			//cout << endl;

			a = a + 2;

		}
		textcolor(7);
		do
		{
		if (batSuKien(57, 16, 5, 2))
		{
			break;
		}
		} while (true);
}

//hàm lấy tên của Phòng ra để đi sắp xếp
//string Ten_Phong(PHONG p)
//{
//	//khởi tạo độ dài chuỗi nhập tên Phòng
//	int length = p.TenPhong.length();
//	int i;
//	//duyệt từ cuối về đầu chuỗi
//	for (i = length - 1; i >= 0; i--)
//	{
//		//nếu duyệt cho phần tử thứ i gặp khoảng trống đầu tiên thì sẽ kết thúc lấy chuỗi
//		if (p.TenPhong[i] == ' ')
//		{
//			break;
//		}
//	}
//	//hàm trả về chuỗi mình đã cắt
//	return p.TenPhong.substr(i + 1);
//
//}

void DoiCho(PHONG& a, PHONG& b)
{
	PHONG temp = a;
	a = b;
	b = temp;
}

void SapXeptheoMaPhong(LIST_PHONG& lp, PHONG p)
{
	int dem = 1;
	//hàm duyệt list phòng từ đầu đến cuối danh sách
	for (NODE_PHONG* h = lp.pHead; h != NULL; h = h->pNext)
	{
		for (NODE_PHONG* g = lp.pHead; g != NULL; g = g->pNext)
		{
			//tạo 2 thằng mã phòng để đi so sánh với nhau
			string MaPhong = h->data.MaPhong;
			string MaPhong1 = g->data.MaPhong;
			//hàm so sánh từng phần tử trong mã phòng
			//nếu hàm trả về 0 thì 2 chuỗi bằng nhau
			if (MaPhong != "" && MaPhong1 != "") {// =================== Neu ko so sanh khi xuong dong Mã phòng = "" no se len dau
				if (_stricmp((char*)MaPhong.c_str(), (char*)MaPhong1.c_str()) == 0)
				{
					dem++;
				}
				//ngược lại nếu hèm trả về <0 tức là chuỗi mã phòng trước lớn hơn mã sau
				else if (_stricmp((char*)MaPhong.c_str(), (char*)MaPhong1.c_str()) < 0)
				{
					DoiCho(h->data, g->data);
				}
			}
		}
	}

}

void SapXeptheoGiaPhong(LIST_PHONG& lp, PHONG p)
{
	int dem = 1;
	//hàm duyệt list Phòng từ đầu đến cuối danh sách
	for (NODE_PHONG* h = lp.pHead; h != NULL; h = h->pNext)
	{
		for (NODE_PHONG* g = lp.pHead; g != NULL; g = g->pNext)
		{
			//tạo 2 thằng Giá Phòng để đi so sánh với nhau
			string GiaPhong = h->data.GiaPhong;
			string GiaPhong1 = g->data.GiaPhong;;
			//hàm so sánh từng phần tử trong giá phòng
			//nếu hàm trả về 0 thì 2 chuỗi bằng nhau
			if (GiaPhong != "" && GiaPhong1 != "") {
				if (_stricmp((char*)GiaPhong.c_str(), (char*)GiaPhong1.c_str()) == 0)
				{
					dem++;
				}
				//ngược lại nếu hèm trả về <0 tức là chuỗi giá phòng trước lớn hơn mã sau
				else if (_stricmp((char*)GiaPhong.c_str(), (char*)GiaPhong1.c_str()) < 0)
				{
					DoiCho(h->data, g->data);
				}
			}
		}
	}
}

// ============================= STRUCT THONG TIN PHONG ========================================
struct thongtinphong
{
	string MaPhong;
	string SoGiuongDon;
	string SoGiuongDoi;
	string ThietBi;
	string ViewPhong;
	string TienIch;
};
typedef struct thongtinphong THONGTINPHONG;

struct node_thongtinphong
{
	THONGTINPHONG data;
	struct node_thongtinphong* pNext;
};
typedef struct node_thongtinphong NODE_THONGTINPHONG;

struct list_thongtinphong
{
	NODE_THONGTINPHONG* pHead;
	NODE_THONGTINPHONG* pTail;
};
typedef struct list_thongtinphong LIST_THONGTINPHONG;
// ======================================== KHOI TAO THONG TIN PHONG ===================================
void KhoitaoThongTinPhong(LIST_THONGTINPHONG& lttp)
{
	lttp.pHead = lttp.pTail = NULL;
}
NODE_THONGTINPHONG* Khoitaonodethongtinphong(THONGTINPHONG ttp)
{
	NODE_THONGTINPHONG* i = new NODE_THONGTINPHONG;
	if (i == NULL)
	{
		cout << "\n Khong du bo nho de cap phat ";
		return 0;
	}
	else
	{
		i->data = ttp;
		i->pNext = NULL;
		return i;
	}
}

// ======================================= THEM THONG TIN PHONG ========================================
void ThemThongTinPhong(LIST_THONGTINPHONG& lttp, NODE_THONGTINPHONG* i)
{
	if (lttp.pHead == NULL)
	{
		lttp.pHead = lttp.pTail = i;
	}
	else
	{
		lttp.pTail->pNext = i;
		lttp.pTail = i;
	}
}
// ========================================= DIEU KIEN ===============================================
int KT_SoGiuongDoi(THONGTINPHONG ttp)
{
	int dem = 0;
	int n = ttp.SoGiuongDoi.length();

	if (ttp.SoGiuongDoi[0] == ' ')
	{
		return 0;
	}
	if (ttp.SoGiuongDoi[n - 1] == ' ')
	{
		return 0;
	}
	for (int i = 0; i < ttp.SoGiuongDoi.length(); i++) {
		if (ttp.SoGiuongDoi[i] < '0' || ttp.SoGiuongDoi[i] >'9' || ttp.SoGiuongDoi[i] >= 'a' && ttp.SoGiuongDoi[i] <= 'z' || ttp.SoGiuongDoi[i] >= 'A' && ttp.SoGiuongDoi[i] <= 'Z')
		{
			return 0;
			break;
		}
		else if (ttp.SoGiuongDoi[i] >= '0' && ttp.SoGiuongDoi[i] <= '9')
			dem++;
	}
	if (dem == ttp.SoGiuongDoi.length())
		return 1;
}
int KT_SoGiuongDon(THONGTINPHONG ttp)
{
	int dem = 0;
	int n = ttp.SoGiuongDon.length();

	if (ttp.SoGiuongDon[0] == ' ')
	{
		return 0;
	}
	if (ttp.SoGiuongDon[n - 1] == ' ')
	{
		return 0;
	}
	for (int i = 0; i < ttp.SoGiuongDon.length(); i++) {
		if (ttp.SoGiuongDon[i] < '0' || ttp.SoGiuongDon[i] >'9' || ttp.SoGiuongDon[i] >= 'a' && ttp.SoGiuongDon[i] <= 'z' || ttp.SoGiuongDon[i] >= 'A' && ttp.SoGiuongDon[i] <= 'Z')
		{
			return 0;
			break;
		}
		else if (ttp.SoGiuongDon[i] >= '1' && ttp.SoGiuongDon[i] <= '9')
			dem++;
	}
	if (dem == ttp.SoGiuongDon.length())
		return 1;
}
bool KT_Rong_GiuongDoi(THONGTINPHONG ttp)
{
	if (ttp.SoGiuongDoi == "")
		return false;
	return true;
}
bool KT_Rong_GiuongDon(THONGTINPHONG ttp)
{
	if (ttp.SoGiuongDon == "")
		return false;
	return true;
}
bool KT_Rong_ThietBi(THONGTINPHONG ttp)
{
	if (ttp.ThietBi == "")
		return false;
	return true;
}
bool KT_Rong_ViewPhong(THONGTINPHONG ttp)
{
	if (ttp.ViewPhong == "")
		return false;
	return true;
}
bool KT_Rong_TienIch(THONGTINPHONG ttp)
{
	if (ttp.TienIch == "")
		return false;
	return true;
}
void GiaoDienThongTinPhong()
{
	VeHCN(79, 14, 30, 2, 4);
	gotoXY(80, 15);
	cout << "Them Thong Tin Phong";

	VeHCN(79, 17, 30, 2, 4);
	gotoXY(80, 18);
	cout << "Sua Thong Tin Phong";

	VeHCN(79, 20, 30, 2, 4);
	gotoXY(80, 21);
	cout << "	Thoat";

}
void GiaoDienThemThongTinPhong()
{
	VeHCN(79, 14, 16, 2, 4);
	gotoXY(80, 15);
	cout << "Ma Phong";
	VeHCN(96, 14, 50, 2, 4);

	VeHCN(79, 17, 16, 2, 4);
	gotoXY(80, 18);
	cout << "Giuong Doi";
	VeHCN(96, 17, 50, 2, 4);

	VeHCN(79, 20, 16, 2, 4);
	gotoXY(80, 21);
	cout << "Giuong Don";
	VeHCN(96, 20, 50, 2, 4);

	VeHCN(79, 23, 16, 2, 4);
	gotoXY(80, 24);
	cout << "Thiet Bi";
	VeHCN(96, 23, 50, 2, 4);

	VeHCN(79, 26, 16, 2, 4);
	gotoXY(80, 27);
	cout << "View Phong";
	VeHCN(96, 26, 50, 2, 4);

	VeHCN(79, 29, 16, 2, 4);
	gotoXY(80, 30);
	cout << "Tien Ich";
	VeHCN(96, 29, 50, 2, 4);


	VeHCN(79, 35, 16, 2, 4);
	gotoXY(80, 36);
	cout << " Luu Lai";

	VeHCN(125, 35, 16, 2, 4);
	gotoXY(126, 36);
	cout << " Tro Ve ";
}
void createthongtinphong(LIST_THONGTINPHONG& lttp, THONGTINPHONG& ttp,PHONG p)
{
	//KhoitaoPhong(lp);
	do
	{
		XoaManHinhTuyChon(97, 15, 45, 1);
		gotoXY(97, 15);
		fflush(stdin);
		getline(cin, ttp.MaPhong);
		XoaManHinhTuyChon(147, 15, 50, 2);
		if (ttp.MaPhong != p.MaPhong)
		{
			fflush(stdin);
			XoaManHinhTuyChon(97, 15, 45, 1);
			gotoXY(147, 15);
			cout << "MP khong co trong danh sach";
		}
	} while (ttp.MaPhong != p.MaPhong);

	do
	{
		gotoXY(97, 18);
		rewind(stdin);
		getline(cin, ttp.SoGiuongDoi);
		XoaManHinhTuyChon(147, 18, 10, 2);

		if (KT_Rong_GiuongDoi(ttp) == false)
		{
			XoaManHinhTuyChon(97, 18, 45, 1);
			gotoXY(147, 18);
			cout << "So giuong doi rong ";

		}

		if ((KT_SoGiuongDoi(ttp) == 0))
		{
			XoaManHinhTuyChon(97, 18, 45, 1);
			gotoXY(147, 18);
			cout << "Sai cu phap";
		}

	} while (KT_Rong_GiuongDoi(ttp) == false || KT_SoGiuongDoi(ttp) == 0);

	do
	{
		gotoXY(97, 18);
		rewind(stdin);
		getline(cin, ttp.SoGiuongDon);
		XoaManHinhTuyChon(147, 18, 10, 2);

		if (KT_Rong_GiuongDon(ttp) == false)
		{
			XoaManHinhTuyChon(97, 18, 45, 1);
			gotoXY(147, 18);
			cout << "So giuong don rong ";

		}

		if ((KT_SoGiuongDon(ttp) == 0))
		{
			XoaManHinhTuyChon(97, 18, 45, 1);
			gotoXY(147, 18);
			cout << "Sai cu phap";
		}

	} while (KT_Rong_GiuongDoi(ttp) == false || KT_SoGiuongDoi(ttp) == 0);
	do
	{
		gotoXY(97, 21);
		rewind(stdin);
		getline(cin, p.MaLoaiPhong);
		XoaManHinhTuyChon(147, 21, 10, 2);
		if ((KT_Rong_MaLoaiPhong(p) == false))
		{
			XoaManHinhTuyChon(97, 21, 45, 1);
			gotoXY(147, 21);
			cout << "MLP rong ";
		}
		if (KT_MaLoaiPhong(p) == 0)
		{
			XoaManHinhTuyChon(97, 21, 45, 1);
			gotoXY(147, 21);
			cout << "MLP: 'vip' or 'thuong'";
		}
	} while ((KT_Rong_MaLoaiPhong(p) == false) || (KT_MaLoaiPhong(p) == 0));
	do
	{
		gotoXY(97, 24);
		rewind(stdin);
		getline(cin, p.GiaPhong);
		XoaManHinhTuyChon(147, 24, 10, 2);
		if ((KT_Rong_GiaPhong(p) == false))
		{
			XoaManHinhTuyChon(97, 24, 45, 1);
			gotoXY(147, 24);
			cout << "Gia Phong rong ";
		}
		if (KT_Gia_Phong(p) == 0)
		{
			XoaManHinhTuyChon(97, 24, 45, 1);
			gotoXY(147, 24);
			cout << "la so";
		}
	} while ((KT_Rong_GiaPhong(p) == false) || (KT_Gia_Phong(p) == 0));
	do
	{
		gotoXY(97, 27);
		rewind(stdin);
		getline(cin, p.TinhTrangPhong);
		XoaManHinhTuyChon(147, 27, 10, 2);
		if (KT_Rong_TinhTrangPhong(p) == false)
		{
			XoaManHinhTuyChon(97, 27, 45, 1);
			gotoXY(147, 27);
			cout << "TTP rong ";
		}
		if (KT_TinhTrangPhong(p) == 0)
		{
			XoaManHinhTuyChon(97, 27, 45, 1);
			gotoXY(147, 27);
			cout << "TTP: 'Rong' or 'Day'";
		}
	} while ((KT_Rong_TinhTrangPhong(p) == false) || (KT_TinhTrangPhong(p) == 0));
	//transform(p.MaPhong.begin(), p.MaPhong.begin(), p.MaPhong.begin(), ::toupper);
	//XoaManHinhTuyChon(147, 27, 10, 2);
	//XoaManHinhTuyChon(147, 24, 10, 2);
//	NODE_PHONG* i = Khoitaonodephong(p);
//	ThemPhong(lp, i);

}
//==================================================================== QUẢN LÍ ĐẶT PHÒNG - PHIẾU ĐĂNG KÍ =================================================================================
/*Danh sách đặt phòng: Danh sách liên kết đơn
(MAKH, TenKH, SoDT, CMND, MaPhong, LoaiPhong, NgayLap, NgayDi,).
*/

/*===============================DAT PHONG==================================*/

struct datPhong {
	string MaKH;
	string TenKH;
	string SoDT;
	string CMND;
	string MaPhong;
	string LoaiPhong;
	string NgayLap;
	string NgayDi;
};
typedef struct datPhong DATPHONG;

struct nodeDatPhong {
	DATPHONG data;
	struct nodeDatPhong* next;
};
typedef struct nodeDatPhong NODEDP;

struct listDatPhong {
	NODEDP* pHead = NULL;
	NODEDP* pTail = NULL;
};
typedef struct listDatPhong LISTDP;

void Menu();


void DP_init(LISTDP& l) {

	l.pHead = l.pTail = NULL;
}

NODEDP* getNodeDP(DATPHONG a) {
	NODEDP* p = new NODEDP;
	if (p == NULL) {
		cout << "Khong du bo nho!!!" << endl;
		return NULL;
	}
	p->data = a;
	p->next = NULL;
	return p;
}


void DP_addTail(LISTDP& l, NODEDP* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->next = p;
		l.pTail = p;
	}
}

int DP_checkMaKH(LISTDP l, DATPHONG dp) {
	int dem = 0;
	if (dp.MaKH == "") {
		gotoXY(122, 17);
		cout << "Ma khach hang khong duoc de trong! Vui long nhap lai!" << endl;
		return 0;
	}
	else {
		for (NODEDP* a = l.pHead; a != NULL; a = a->next) {
			if (a->data.MaKH == dp.MaKH)
				dem++;
		}
	}
	if (dem != 0) {
		gotoXY(122, 17);
		cout << "Ma khach hang da trung! Vui long nhap lai!" << endl;
		return 0;
	}
	return 1;
}

int DP_checkTenKH(DATPHONG dp) {
	if (dp.TenKH == "") {
		gotoXY(122, 20);
		cout << "Ten khach hang khong duoc de trong! Vui long nhap lai!" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < dp.TenKH.length(); i++) {
			if (dp.TenKH[i] >= '0' && dp.TenKH[i] <= '9') {

				gotoXY(122, 20);
				cout << "Ten khach hang la chu! Vui long nhap lai!" << endl;
				return 0;
				break;
			}
		}
	}
	return 1;
}

int DP_checkSoDT(LISTDP& l, DATPHONG dp) {
	int dem = 0;
	if (dp.SoDT == "") {
		gotoXY(122, 23);
		cout << "So dien thoai khong duoc de trong! Vui long nhap lai!" << endl;
		return 0;
	}
	else {
		for (NODEDP* a = l.pHead; a != NULL; a = a->next) {
			if (a->data.SoDT == dp.SoDT)
				dem++;
		}
	}
	if (dem != 0) {
		gotoXY(122, 23);
		cout << "So dien thoai bi trung! Vui long kiem tra lai!" << endl;
		return 0;
	}
	return 1;
}

int DP_soDTIsNum(DATPHONG dp) {
	for (int i = 0; i < dp.SoDT.length(); i++) {
		if (!(dp.SoDT[i] >= '0' && dp.SoDT[i] <= '9')) {
			gotoXY(122, 23);
			cout << "So dien thoai la so! Vui long nhap lai!" << endl;
			return 0;
			break;
		}
	}
	return 1;
}

int DP_checkCMND(LISTDP l, DATPHONG dp) {
	int dem = 0;
	if (dp.CMND == "") {
		gotoXY(122, 26);
		cout << "CMND khong duoc de trong! Vui long nhap lai!" << endl;
		return 0;
	}
	else {
		for (NODEDP* a = l.pHead; a != NULL; a = a->next) {
			if (a->data.CMND == dp.CMND)
				dem++;
		}
	}
	if (dem != 0) {
		gotoXY(122, 26);
		cout << "CMND da bi trung! Vui long kiem tra lai!" << endl;
		return 0;
	}
	return 1;
}

int DP_cmndIsNum(DATPHONG dp) {
	for (int i = 0; i < dp.CMND.length(); i++) {
		if (!(dp.CMND[i] >= '0' && dp.CMND[i] <= '9')) {
			gotoXY(122, 26);
			cout << "CMND la so! Vui long kiem tra lai!" << endl;
			return 0;
		}
	}
	return 1;
}

int DP_checkMaPhong(LISTDP l, DATPHONG dp) {
	int dem = 0;
	if (dp.MaPhong == "") {
		gotoXY(122, 29);
		cout << "Ma phong khong duoc de trong! Vui long nhap lai!" << endl;
		return 0;
	}
	else {
		for (NODEDP* a = l.pHead; a != NULL; a = a->next) {
			if (a->data.MaPhong == dp.MaPhong)
				dem++;
		}
	}
	if (dem != 0) {
		gotoXY(122, 29);
		cout << "Ma phong da bi trung! Vui long kiem tra lai!" << endl;
		return 0;
	}
	return 1;
}

int DP_checkLoaiPhong(DATPHONG dp) {
	if (dp.LoaiPhong == "") {
		gotoXY(122, 32);
		cout << "Loai phong khong duoc de trong! Vui long nhap lai!" << endl;
		return 0;
	}
	else if (dp.LoaiPhong != "Vip" && dp.LoaiPhong != "Thuong") {
		gotoXY(122, 32);
		cout << "Vui long nhap loai phong la  1:Vip - 2:Thuong!" << endl;
		return 0;
	}
	return 1;
}

int DP_checkNgayDangKi(DATPHONG dp) {
	if (dp.NgayLap == "") {
		gotoXY(122, 35);
		cout << "Ngay dat phong khong duoc de trong! Vui long nhap lai!" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < dp.NgayLap.length(); i++) {
			if (!(dp.NgayLap[0] >= '0' && dp.NgayLap[0] <= '9' && dp.NgayLap[1] >= '0' && dp.NgayLap[1] <= '9' && dp.NgayLap[2] == '/' && dp.NgayLap[3] >= '0' && dp.NgayLap[3] <= '9' && dp.NgayLap[4] >= '0' && dp.NgayLap[4] <= '9' && dp.NgayLap[5] == '/' && dp.NgayLap[6] >= '0' && dp.NgayLap[6] <= '9' && dp.NgayLap[7] >= '0' && dp.NgayLap[7] <= '9')) {
				gotoXY(122, 35);
				cout << "Ngay dang ky theo: dd/mm/yy! Vui long nhap lai!" << endl;
				return 0;
			}
		}
	}
	return 1;
}

int DP_checkNgayDi(DATPHONG dp) {
	if (dp.NgayDi == "") {
		gotoXY(122, 38);
		cout << "Ngay di khong duoc de trong! Vui long nhap lai!" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < dp.NgayDi.length(); i++) {
			if (!(dp.NgayDi[0] >= '0' && dp.NgayDi[0] <= '9' && dp.NgayDi[1] >= '0' && dp.NgayDi[1] <= '9' && dp.NgayDi[2] == '/' && dp.NgayDi[3] >= '0' && dp.NgayDi[3] <= '9' && dp.NgayDi[4] >= '0' && dp.NgayDi[4] <= '9' && dp.NgayDi[5] == '/' && dp.NgayDi[6] >= '0' && dp.NgayDi[6] <= '9' && dp.NgayDi[7] >= '0' && dp.NgayDi[7] <= '9')) {
				gotoXY(122, 38);
				cout << "Ngay di theo: dd/mm/yy! Vui long nhap lai!" << endl;
				return 0;
			}
		}
	}
	return 1;
}

void DP_xoaDau(LISTDP& l) {
	if (l.pHead == NULL) {
		cout << "Chua co danh sach dat phong!!!" << endl;
	}
	else {
		l.pHead->next = l.pHead->next;
		l.pHead = l.pHead->next;
	}
}

void DP_xoaCuoi(LISTDP& l) {
	if (l.pHead == NULL) {
		cout << "Danh sach dat phong dang trong!!!" << endl;
	}
	else {
		for (NODEDP* p = l.pHead; p != NULL; p = p->next) {
			NODEDP* q = p->next;
			if (q->next == NULL) {
				p->next = NULL;
				l.pTail = p;
			}
		}
	}
}

int soKhachHangDP(LISTDP ldp) {
	int soKH = 1;
	for (NODEDP* p = ldp.pHead; p != NULL; p = p->next) {
		soKH++;
	}
	return soKH;
}

void DP_listTenKH(LISTDP l) {
	int i = 1;
	int Y = 15;
	for (NODEDP* p = l.pHead; p != NULL; p = p->next) {
		gotoXY(80, Y++);
		cout << "Ten khach hang thu " << i++ << ": " << p->data.TenKH << endl;
	}
}

void giaiphong(LISTDP& ldp)
{
	NODEDP* p = NULL;
	while (ldp.pHead != NULL)
	{
		p = ldp.pHead;
		ldp.pHead = ldp.pHead->next;
		delete p;
	}
}

int DP_checkTenKHTonTai(LISTDP, DATPHONG);

void DP_xoaBatKy(LISTDP& ldp, DATPHONG xoa) {
	VeHCN(79, 13, 40, 1 + soKhachHangDP(ldp), 2); // Khung hien ten khach hang có số khách hàng là int
	gotoXY(81, 14);
	cout << "Danh sach ten khach hang da dat phong." << endl;
	DP_listTenKH(ldp);
	gotoXY(70, 18 + soKhachHangDP(ldp) + 4); // Khi số KH tăng thì cái này cũng tăng	
	cout << "Nhap ten khach hang can xoa dat phong: ";
	rewind(stdin);
	VeHCN(110, 18 + soKhachHangDP(ldp) + 3, 20, 2, 5); // Khung nhap ten khach hang can xoa
	VeHCN(90, 18 + soKhachHangDP(ldp) + 7, 10, 2, 3); // Khung huy
	gotoXY(91, 18 + soKhachHangDP(ldp) + 8);
	cout << "Huy";
	VeHCN(120, 18 + soKhachHangDP(ldp) + 7, 10, 2, 3); // Khung dong y
	gotoXY(121, 18 + soKhachHangDP(ldp) + 8);
	cout << "Dong y";
	do {
		gotoXY(111, 18 + soKhachHangDP(ldp) + 4);
		getline(cin, xoa.TenKH);
	} while (!(DP_checkTenKHTonTai(ldp, xoa)));
	if (batSuKien(90, soKhachHangDP(ldp) + 33, 10, 2)) { // Bắt sự kiện hủy
		return;
	}

	else if (batSuKien(120, soKhachHangDP(ldp) + 34, 10, 2)) { // Bắt sự kiện đồng ý
		int dem = 0; // Xem tên khách hàng cần xóa có trong danh sách hay không
		for (NODEDP* p = ldp.pHead; p != NULL; p = p->next) {
			if (xoa.TenKH == ldp.pHead->data.TenKH) {
				DP_xoaDau(ldp);
				gotoXY(100, 32);
				cout << "Xoa thanh cong." << endl;
				system("pause");
				dem++; // Nếu có tăng 1
				break;
			}
			else if (xoa.TenKH == ldp.pTail->data.TenKH) {
				DP_xoaCuoi(ldp);
				gotoXY(100, 32);
				cout << "Xoa thanh cong." << endl;
				system("pause");
				dem++;
				break;
			}
			else {
				NODEDP* q = p->next;
				if (q->data.TenKH == xoa.TenKH) {
					p->next = q->next;
					gotoXY(100, 32);
					cout << "Xoa thanh cong." << endl;
					system("pause");
					dem++;
					break;
				}
			}
		}
		if (dem == 0) { //  Nếu tên khách hàng cần xóa không có trong danh sách khách hàng
			gotoXY(45, 18);
			cout << xoa.TenKH << " khong co trong danh sach dat phong." << endl;
			system("pause");
		}
	}
	else {
		cout << "nhap lai";
	}
}

int DP_checkTenKHTonTai(LISTDP l, DATPHONG dp) {
	int dem = 0;
	for (NODEDP* q = l.pHead; q != NULL; q = q->next) {
		if (q->data.TenKH == dp.TenKH)
			dem++;
	}
	if (dem == 0) {
		cout << "Ten khach hang khong ton tai! Vui long nhap lai!!!" << endl;
		return 0;
	}
	return 1;
}

void output1DatPhong(DATPHONG dp) {
	int x = 80;
	gotoXY(x, 5);
	cout << "\tThong tin dat phong!" << endl;
	gotoXY(x, 6);
	cout << "Ma khach hang: " << dp.MaKH << endl;
	gotoXY(x, 7);
	cout << "Ten khach hang: " << dp.TenKH << endl;
	gotoXY(x, 8);
	cout << "So dien thoai: " << dp.SoDT << endl;
	gotoXY(x, 9);
	cout << "CMND: " << dp.CMND << endl;
	gotoXY(x, 10);
	cout << "Ma phong: " << dp.MaPhong << endl;
	gotoXY(x, 11);
	cout << "Loai phong: " << dp.LoaiPhong << endl;
	gotoXY(x, 12);
	cout << "Ngay dang ki: " << dp.NgayLap << endl;
	gotoXY(x, 13);
	cout << "Ngay di: " << dp.NgayDi << endl << endl;
}

int DP_checkThuocTinh(string thuocTinh) {
	if (thuocTinh != "Ma khach hang" && thuocTinh != "Ten khach hang" && thuocTinh != "So dien thoai" && thuocTinh != "Cmnd" && thuocTinh != "Ma phong" && thuocTinh != "Loai phong" && thuocTinh != "Ngay dang ky" && thuocTinh != "Ngay di") {
		cout << "Vui long chon: Ma khach hang\t\tTen khach hang\tSo dien thoai\tCmnd\tMa phong\tLoai phong\tNgay dang ky\tNgay di!!!" << endl;
		return 0;
	}
	return 1;
}

void DP_change(LISTDP& l, DATPHONG dp) {
	string thuocTinh;
	string changed;
	int dem = 0;
	ShowCur(1); // Hien con tro
	VeHCN(79, 13, 50, 1 + soKhachHangDP(l), 2); // Khung hien ten khach hang có số khách hàng là int
	gotoXY(81, 14);
	cout << "Danh sach ten khach hang da dat phieu dang ky." << endl;
	DP_listTenKH(l);
	gotoXY(70, 18 + soKhachHangDP(l) + 4); // Khi số KH tăng thì cái này
	cout << "Nhap ten khach hang can xoa phieu dang ky: ";
	rewind(stdin);
	VeHCN(113, 18 + soKhachHangDP(l) + 3, 20, 2, 5); // Khung nhap ten khach hang can xoa
	VeHCN(90, 18 + soKhachHangDP(l) + 7, 10, 2, 3); // Khung huy
	gotoXY(91, 18 + soKhachHangDP(l) + 8);
	cout << "Huy";
	VeHCN(120, 18 + soKhachHangDP(l) + 7, 10, 2, 3); // Khung dong y
	gotoXY(121, 18 + soKhachHangDP(l) + 8);
	cout << "Dong y";
	do {
		gotoXY(114, 18 + soKhachHangDP(l) + 4);
		getline(cin, dp.TenKH);
	} while (!(DP_checkTenKHTonTai(l, dp)));

	if (batSuKien(90, 33 + soKhachHangDP(l), 10, 2)) { // Bắt sự kiện hủy
		return;
	}

	else if (batSuKien(120, 33 + soKhachHangDP(l), 10, 2)) { // Bắt sự kiện đồng ý
		ShowCur(0);
		system("cls");
		VeHCN(79, 4, 50, 10, 2); // Vẽ HCN cho thông tin phòng
		for (NODEDP* q = l.pHead; q != NULL; q = q->next) {
			if (q->data.TenKH == dp.TenKH) {
				output1DatPhong(q->data);
				dem++;
			}
		}
		// Vẽ các khung thuộc tính
		VeHCN(75, 20, 10, 2, 3); // Vẽ khung Mã KH
		gotoXY(78, 21);
		cout << "Ma KH";

		VeHCN(92, 20, 10, 2, 3); // Vẽ khung Tên KH
		gotoXY(94, 21);
		cout << "Ten KH";

		VeHCN(109, 20, 10, 2, 3); // Vẽ khung Số đt
		gotoXY(111, 21);
		cout << "So dt";

		VeHCN(126, 20, 10, 2, 3); // Vẽ khung CMND
		gotoXY(128, 21);
		cout << "CMND";

		VeHCN(75, 24, 10, 2, 3); // Vẽ khung số Ma phong
		gotoXY(76, 25);
		cout << "Ma Phong";

		VeHCN(92, 24, 11, 2, 3); // Vẽ khung Loai phong
		gotoXY(93, 25);
		cout << "Loai phong";

		VeHCN(109, 24, 10, 2, 3); // Vẽ khung Ngay dang ky
		gotoXY(111, 25);
		cout << "Ngay dk";

		VeHCN(126, 24, 10, 2, 3); // Vẽ khung Ngay di
		gotoXY(128, 25);
		cout << "Ngay di";
	}

	for (NODEDP* q = l.pHead; q != NULL; q = q->next) {
		if (q->data.TenKH == dp.TenKH) {
			if (batSuKien(75, 25, 10, 2)) { // Ma khach hang
				do {
					gotoXY(75, 30);
					ShowCur(1); // Hien con tro
					cout << q->data.MaKH << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					dp.MaKH = changed;
				} while (!(DP_checkMaKH(l, dp)));
				q->data.MaKH = dp.MaKH = changed;
			}
			else if (batSuKien(92, 25, 10, 2)) { // Ten khach hang
				do {
					gotoXY(75, 30);
					ShowCur(1); // Hien con tro
					cout << q->data.TenKH << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					dp.TenKH = changed;
				} while (!(DP_checkTenKH(dp)));
				q->data.TenKH = dp.TenKH = changed;
			}
			else if (batSuKien(109, 25, 10, 2)) { // So dien thoai
				do {
					gotoXY(75, 30);
					ShowCur(1); // Hien con tro
					cout << q->data.SoDT << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					dp.SoDT = changed;
				} while (!(DP_checkSoDT(l, dp) && DP_soDTIsNum(dp)));
				q->data.SoDT = dp.SoDT = changed;
			}
			else if (batSuKien(126, 25, 10, 2)) { // CMND
				do {
					gotoXY(75, 30);
					ShowCur(1); // Hien con tro
					cout << q->data.CMND << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					dp.CMND = changed;
				} while (!(DP_checkCMND(l, dp) && DP_cmndIsNum(dp)));
				q->data.CMND = dp.CMND = changed;
			}
			else if (batSuKien(75, 30, 10, 2)) { // Ma phong
				do {
					gotoXY(75, 30);
					ShowCur(1); // Hien con tro
					cout << q->data.MaPhong << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					dp.MaPhong = changed;
				} while (!(DP_checkMaPhong(l, dp)));
				q->data.MaPhong = dp.MaPhong = changed;
			}
			else if (batSuKien(92, 30, 11, 2)) { // Loai phong
				do {
					gotoXY(75, 30);
					ShowCur(1); // Hien con tro
					cout << q->data.LoaiPhong << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					dp.LoaiPhong = changed;
				} while (!(DP_checkLoaiPhong(dp)));
				q->data.LoaiPhong = dp.LoaiPhong = changed;
			}
			else if (batSuKien(109, 30, 10, 2)) { // Ngay dang ky
				do {
					gotoXY(75, 30);
					ShowCur(1); // Hien con tro
					cout << q->data.NgayLap << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					dp.NgayLap = changed;
				} while (!(DP_checkNgayDangKi(dp)));
				q->data.NgayLap = dp.NgayLap = changed;
			}
			else if (batSuKien(126, 30, 10, 2)) { // Ngay di
				do {
					gotoXY(75, 30);
					ShowCur(1); // Hien con tro
					cout << q->data.NgayDi << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					dp.NgayDi = changed;
				} while (!(DP_checkNgayDi(dp)));
				q->data.NgayDi = dp.NgayDi = changed;
			}
		}
	}
	gotoXY(80, 31);
	cout << thuocTinh << " da duoc thay doi!!!" << endl;
	system("pause");
}

// Đọc từ file vào list

void DP_docFile(LISTDP& ldp) {
	ifstream filein;
	filein.open("fileDP.txt", ios_base::in);

	while (!filein.eof()) {
		DATPHONG dp;
		getline(filein, dp.MaKH, ',');
		getline(filein, dp.TenKH, ',');
		getline(filein, dp.SoDT, ',');
		getline(filein, dp.CMND, ',');
		getline(filein, dp.MaPhong, ',');
		getline(filein, dp.LoaiPhong, ',');
		getline(filein, dp.NgayLap, ',');
		getline(filein, dp.NgayDi);
		NODEDP* p = getNodeDP(dp);
		DP_addTail(ldp, p);
	}

	filein.close();
}

void DP_ghiFile(LISTDP ldp) {
	ofstream fileout;
	fileout.open("fileDP.txt");
	for (NODEDP* p = ldp.pHead; p != NULL; p = p->next) {
		fileout << p->data.MaKH << ",";
		fileout << p->data.TenKH << ",";
		fileout << p->data.SoDT << ",";
		fileout << p->data.CMND << ",";
		fileout << p->data.MaPhong << ",";
		fileout << p->data.LoaiPhong << ",";
		fileout << p->data.NgayLap << ",";
		fileout << p->data.NgayDi;
		fileout << endl;
	}


	fileout.close();
}



void DP_output(LISTDP l);

void DP_input(LISTDP& ldp) {
	DATPHONG dp;
	string luaChon;
	do
	{
		gotoXY(66, 15);
		cout << "\t\tNhap thong tin dang ky dat phong:" << endl;
		gotoXY(66, 17);
		cout << "Nhap ma khach hang: ";
		VeHCN(90, 16, 20, 2, 3); // Khung ma khach hang
		gotoXY(66, 20);
		cout << "Nhap ten khach hang: ";
		VeHCN(90, 19, 20, 2, 3); // Khung ten khach hang
		gotoXY(66, 23);
		cout << "Nhap so dien thoai: ";
		VeHCN(90, 22, 20, 2, 3); // khung sdt
		gotoXY(66, 26);
		cout << "Nhap cmnd: ";
		VeHCN(90, 25, 20, 2, 3); // Khung cmnd
		gotoXY(66, 29);
		cout << "Nhap ma phong: ";
		VeHCN(90, 28, 20, 2, 3); // Khung ma phong
		gotoXY(66, 32);
		cout << "Nhap loai phong: ";
		VeHCN(90, 31, 20, 2, 3); // Khung loai phong
		gotoXY(66, 35);
		cout << "Ngay dang ki(dd/mm/yy):";
		VeHCN(90, 34, 20, 2, 3); // Khung ngay dang ky
		gotoXY(66, 38);
		cout << "Ngay di(dd/mm/yy): ";
		VeHCN(90, 37, 20, 2, 3);// Khung ngay di
		VeHCN(80, 40, 10, 2, 3); // Khung Huy
		gotoXY(81, 41);
		cout << "Huy";
		VeHCN(100, 40, 10, 2, 3);
		gotoXY(101, 41);
		cout << "Dang ky";
		gotoXY(91, 17); // Đưa con trỏ về lại ô nhập đầu tiên
		if (batSuKien(80, 19, 18, 2))
		{
			ShowCur(1);
			do {
				gotoXY(91, 17);
				rewind(stdin);
				getline(cin, dp.MaKH);
				XoaManHinhTuyChon(122, 17, 54, 1);
				if (!(DP_checkMaKH(ldp, dp))) {
					XoaManHinhTuyChon(91, 17, 19, 1);
				}
			} while (!(DP_checkMaKH(ldp, dp)));
			do {
				gotoXY(91, 20);

				rewind(stdin);
				getline(cin, dp.TenKH);
				XoaManHinhTuyChon(122, 20, 54, 1);
				if (!(DP_checkTenKH(dp))) {
					XoaManHinhTuyChon(91, 20, 19, 1); // rs ô nhập khi nhập sai
				}

			} while (!(DP_checkTenKH(dp)));
			do {
				gotoXY(91, 23);
				rewind(stdin);
				getline(cin, dp.SoDT);
				XoaManHinhTuyChon(122, 23, 54, 1);
				if (!((DP_checkSoDT(ldp, dp)) && DP_soDTIsNum(dp))) {
					XoaManHinhTuyChon(91, 23, 19, 1);
				}
			} while (!((DP_checkSoDT(ldp, dp)) && DP_soDTIsNum(dp)));
			do {
				gotoXY(91, 26);
				rewind(stdin);
				getline(cin, dp.CMND);
				XoaManHinhTuyChon(122, 26, 54, 1);
				if (!((DP_checkCMND(ldp, dp)) && DP_cmndIsNum(dp))) {
					XoaManHinhTuyChon(91, 26, 19, 1);
				}
			} while (!((DP_checkCMND(ldp, dp)) && DP_cmndIsNum(dp)));
			do {
				gotoXY(91, 29);
				rewind(stdin);
				getline(cin, dp.MaPhong);
				XoaManHinhTuyChon(122, 29, 54, 1);
				if (!(DP_checkMaPhong(ldp, dp))) {
					XoaManHinhTuyChon(91, 29, 19, 1);
				}
			} while (!(DP_checkMaPhong(ldp, dp)));
			do {
				gotoXY(91, 32);
				rewind(stdin);
				getline(cin, dp.LoaiPhong);
				XoaManHinhTuyChon(122, 32, 54, 1);
				if (!(DP_checkLoaiPhong(dp))) {
					XoaManHinhTuyChon(91, 32, 19, 1);
				}
			} while (!(DP_checkLoaiPhong(dp)));
			do {
				gotoXY(91, 35);
				rewind(stdin);
				getline(cin, dp.NgayLap);
				XoaManHinhTuyChon(122, 35, 54, 1);
				if (!(DP_checkNgayDangKi(dp))) {
					XoaManHinhTuyChon(91, 35, 19, 1);
				}
			} while (!(DP_checkNgayDangKi(dp)));

			do {
				gotoXY(91, 38);
				rewind(stdin);
				getline(cin, dp.NgayDi);
				XoaManHinhTuyChon(122, 38, 54, 3);
				if (!(DP_checkNgayDi(dp))) {
					XoaManHinhTuyChon(91, 38, 19, 1);
				}
			} while (!(DP_checkNgayDi(dp)));

			// Xem chỗ này mới thêm return;
			if (batSuKien(71, 50, 10, 2)) { // Bắt sự kiện nút hủy
				break;
			}

			else if (batSuKien(89, 50, 10, 2)) { // Bắt sự kiện nút đăng ký 
				NODEDP* p = getNodeDP(dp);
				DP_addTail(ldp, p);
				DP_ghiFile(ldp);
				gotoXY(122, 38);
				cout << "=>>>>Dang ky thanh cong";
			}
		}
		if (batSuKien(89, 50, 10, 2))
		{
			GiaoDienThongBaoThatBai("Dang Ki That Bai!!!");
			break;
		}
		else if (batSuKien(71, 50, 10, 2)) { // Bắt sự kiện nút hủy
			break;
		}
	}while (true);
	//=====================Lỗi nút hủy và đăng ký==================

	/*else {
		do {
			gotoXY(90, 43);
			cout << "Nhan 'Huy' hoac 'Dang ky'!";
		} while (!(batSuKien(89, 50, 10, 2)) && !(batSuKien(71, 50, 10, 2)));
	}*/
	//system("pause");
}



void DP_output(LISTDP ldp) {
	system("cls");
	cout << "\t\tThong tin cac phieu dang ky:" << endl;
	int i = 1;
	if (ldp.pHead == NULL) {
		cout << "Chua co danh sach dat phong!!!" << endl;
	}
	else {
		for (NODEDP* a = ldp.pHead; a != NULL; a = a->next) {
			cout << "Thong tin dat phong thu " << i++ << " :" << endl;
			cout << "\tMa khach hang: " << a->data.MaKH << endl;
			cout << "\tTen khach hang: " << a->data.TenKH << endl;
			cout << "\tSo dien thoai: " << a->data.SoDT << endl;
			cout << "\tCMND: " << a->data.CMND << endl;
			cout << "\tMa phong: " << a->data.MaPhong << endl;
			cout << "\tLoai phong: " << a->data.LoaiPhong << endl;
			cout << "\tNgay dang ki: " << a->data.NgayLap << endl;
			cout << "\tNgay di: " << a->data.NgayDi << endl << endl;
		}
	}
	cout << endl;
	system("pause");
}

/* Danh sách phiếu đăng kí: Danh sách liên kết đơn
(MaPDK, MaKH, MaNV, NgayLap, NgayDi, MaPhong, LoaiPhong, SoTienTraTruoc)
*/

//================================================ XỬ LÍ PHIẾU ĐĂNG KÍ =================================
struct phieuDangKy {
	string MaPDK;
	string TenKH;
	string MaKH;
	string MaNV;
	string NgayLap;
	string NgayDi;
	string MaPhong;
	string LoaiPhong;
	string SoTienTraTruoc;
};
typedef struct phieuDangKy PDK;

struct nodePDK {
	PDK data;
	struct nodePDK* next;
};
typedef struct nodePDK NODEPDK;

struct listPDK {
	NODEPDK* pHead;
	NODEPDK* pTail;
};
typedef struct listPDK LISTPDK;

void PDK_init(LISTPDK& pdk) {
	pdk.pHead = pdk.pTail = NULL;
}

NODEPDK* getNodePDK(PDK pdk) {
	NODEPDK* p = new NODEPDK;
	if (p == NULL) {
		cout << "Khong du bo nho!!!" << endl;
		return NULL;
	}
	p->data = pdk;
	p->next = NULL;
	return p;
}
void PDK_addTail(LISTPDK& l, NODEPDK* pdk) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = pdk;
	}
	else {
		l.pTail->next = pdk;
		l.pTail = pdk;
	}
}

int PDK_checkMaKH(LISTPDK l, PDK pdk) {
	int dem = 0;
	int x = 122;
	int y = 23;
	if (pdk.MaKH == "") {
		for (int i = 1; i <= 7; i++) {
			string str = "=>>> Ma khach hang khong duoc de trong!Vui long nhap lai!!!";
			gotoXY(x++, y);
			if (x > 195-str.length())
				break;
			textcolor(i);
			
			cout << str << endl;
			if (i == 7)
				i = 1;
			Sleep(50);
		}
		return 0;
	}
	else {
		for (NODEPDK* a = l.pHead; a != NULL; a = a->next) {
			if (a->data.MaKH == pdk.MaKH)
				dem++;
		}
	}
	if (dem != 0) {
		for (int i = 1; i <= 7; i++) {
			string str = "=>>> Ma khach hang da trung!Vui long nhap lai!!!";
			gotoXY(x++, y);
			if (x > 195 - str.length())
				break;
			textcolor(i);

			cout << str << endl;
			if (i == 7)
				i = 1;
			Sleep(50);
		}
		return 0;
	}
	return 1;
}

int PDK_checkMaPDK(LISTPDK l, PDK pdk) {
	int dem = 0;
	if (pdk.MaPDK == "") {
		gotoXY(125, 17);
		cout << "==>>Ma phieu dang ky khong duoc de trong! Vui long nhap lai!!!" << endl;
		return 0;
	}
	else {
		for (NODEPDK* a = l.pHead; a != NULL; a = a->next) {
			if (a->data.MaPDK == pdk.MaPDK)
				dem++;
		}
	}
	if (dem != 0) {
		gotoXY(125, 17);
		cout << "Ma phieu dang ky da trung! Vui long nhap lai!!!" << endl;
		return 0;
	}
	return 1;
}

int PDK_checkTenKH(PDK pdk) {
	if (pdk.TenKH == "") {
		gotoXY(122, 20);
		cout << "Ten khach hang khong duoc de trong! Vui long nhap lai!!!" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < pdk.TenKH.length(); i++) {
			if (pdk.TenKH[i] >= '0' && pdk.TenKH[i] <= '9') {
				gotoXY(122, 20);
				cout << "Ten khach hang la chu! Vui long nhap lai!!!" << endl;
				return 0;
				break;
			}
		}
	}
	return 1;
}

int PDK_checkMaNV(LISTPDK lpdk, PDK pdk) {
	int dem = 0;
	if (pdk.MaNV == "") {
		gotoXY(122, 26);
		cout << "Ma nhan vien khong duoc de trong! Vui long nhap lai!!!" << endl;
		return 0;
	}
	else {
		for (NODEPDK* a = lpdk.pHead; a != NULL; a = a->next) {
			if (a->data.MaNV == pdk.MaNV)
				dem++;
		}
	}
	if (dem != 0) {
		gotoXY(122, 26);
		cout << "Ma phong da bi trung! Vui long kiem tra lai!!!" << endl;
		return 0;
	}
	return 1;
}

int PDK_checkMaPhong(LISTPDK l, PDK pdk) {
	int dem = 0;
	if (pdk.MaPhong == "") {
		gotoXY(122, 29);
		cout << "Ma phong khong duoc de trong! Vui long nhap lai!!!" << endl;
		return 0;
	}
	else {
		for (NODEPDK* a = l.pHead; a != NULL; a = a->next) {
			if (a->data.MaPhong == pdk.MaPhong)
				dem++;
		}
	}
	if (dem != 0) {
		gotoXY(122, 29);
		cout << "Ma phong da bi trung! Vui long kiem tra lai!!!" << endl;
		return 0;
	}
	return 1;
}

int PDK_checkLoaiPhong(PDK pdk) {
	if (pdk.LoaiPhong == "") {
		gotoXY(122, 32);
		cout << "Loai phong khong duoc de trong! Vui long nhap lai!!!" << endl;
		return 0;
	}
	else if (pdk.LoaiPhong != "Vip" && pdk.LoaiPhong != "Thuong") {
		gotoXY(122, 32);
		cout << "Vui long nhap loai phong   1:Vip   2:Thuong!" << endl;
		return 0;
	}
	return 1;
}

int PDK_checkNgayDangKi(PDK pdk) {
	if (pdk.NgayLap == "") {
		gotoXY(122, 35);
		cout << "Ngay dat phong khong duoc de trong! Vui long nhap lai!!!" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < pdk.NgayLap.length(); i++) {
			if (!(pdk.NgayLap[0] >= '0' && pdk.NgayLap[0] <= '9' && pdk.NgayLap[1] >= '0' && pdk.NgayLap[1] <= '9' && pdk.NgayLap[2] == '/' && pdk.NgayLap[3] >= '0' && pdk.NgayLap[3] <= '9' && pdk.NgayLap[4] >= '0' && pdk.NgayLap[4] <= '9' && pdk.NgayLap[5] == '/' && pdk.NgayLap[6] >= '0' && pdk.NgayLap[6] <= '9' && pdk.NgayLap[7] >= '0' && pdk.NgayLap[7] <= '9')) {
				gotoXY(122, 35);
				cout << "Ngay dang ky theo format: dd/mm/yy! Vui long nhap lai!!!" << endl;
				return 0;
			}
		}
	}
	return 1;
}

int PDK_checkNgayDi(PDK pdk) {
	if (pdk.NgayLap == "") {
		gotoXY(122, 38);
		cout << "Ngay di khong duoc de trong! Vui long nhap lai!!!" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < pdk.NgayLap.length(); i++) {
			if (!(pdk.NgayDi[0] >= '0' && pdk.NgayDi[0] <= '9' && pdk.NgayDi[1] >= '0' && pdk.NgayDi[1] <= '9' && pdk.NgayDi[2] == '/' && pdk.NgayDi[3] >= '0' && pdk.NgayDi[3] <= '9' && pdk.NgayDi[4] >= '0' && pdk.NgayDi[4] <= '9' && pdk.NgayDi[5] == '/' && pdk.NgayDi[6] >= '0' && pdk.NgayDi[6] <= '9' && pdk.NgayDi[7] >= '0' && pdk.NgayDi[7] <= '9')) {
				gotoXY(122, 38);
				cout << "Ngay di theo format: dd/mm/yy! Vui long nhap lai!!!" << endl;
				return 0;
			}
		}
	}
	return 1;
}

int PDK_soTienIsNum(PDK pdk) {
	if (pdk.SoTienTraTruoc == "") {
		gotoXY(122, 41);
		cout << "So tien tra truoc khong duoc de trong! Vui long nhap lai!!!" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < pdk.SoTienTraTruoc.length(); i++) {
			if (!(pdk.SoTienTraTruoc[i] >= '0' && pdk.SoTienTraTruoc[i] <= '9')) {
				gotoXY(122, 41);
				cout << "So tien tra truoc la so! Vui long kiem tra lai!!!" << endl;
				return 0;
			}
		}
	}
	return 1;
}

void PDK_veKhungTenKHPDK(LISTPDK lpdk) {
	//VeHCN(60, 12, 100, 30, 3); // Khung to
	VeHCN(62, 12, 100, 39, 3);
	VeHCN(89, 14, 40, 4, 3); // Khung tên khách hàng
	gotoXY(90, 15);
	cout << "---------------------------------------\n";
	gotoXY(90, 16);
	cout << "|Danh sach ten khach hang dang ky PDK!|\n";
	gotoXY(90, 17);
	cout << "---------------------------------------\n";
	int x = 65; // Tọa độ tên khách hàng
	int y = 21;
	int i = 1;
	for (NODEPDK* p = lpdk.pHead; p != NULL; p = p->next) {
		VeHCN(x - 1, y - 1, 35, 2, 3);
		gotoXY(x, y);
		cout << "Khach hang " << i++ << ":| " << p->data.TenKH << endl;
		y += 3; // Tăng 3
	}
}

void PDK_docFile(LISTPDK& lpdk) {
	ifstream filein;
	filein.open("filePDK.txt", ios_base::in);

	while (!filein.eof()) {
		PDK pdk;
		getline(filein, pdk.MaPDK, ',');
		getline(filein, pdk.TenKH, ',');
		getline(filein, pdk.MaKH, ',');
		getline(filein, pdk.MaNV, ',');
		getline(filein, pdk.MaPhong, ',');
		getline(filein, pdk.LoaiPhong, ',');
		getline(filein, pdk.NgayLap, ',');
		getline(filein, pdk.NgayDi, ',');
		getline(filein, pdk.SoTienTraTruoc);
		NODEPDK* p = getNodePDK(pdk);
		PDK_addTail(lpdk, p);
	}

	filein.close();
}

void PDK_ghiFile(LISTPDK lpdk) {
	ofstream fileout;
	fileout.open("filePDK.txt");
	for (NODEPDK* p = lpdk.pHead; p != NULL; p = p->next) {
		fileout << p->data.MaPDK << ",";
		fileout << p->data.TenKH << ",";
		fileout << p->data.MaKH << ",";
		fileout << p->data.MaNV << ",";
		fileout << p->data.MaPhong << ",";
		fileout << p->data.LoaiPhong << ",";
		fileout << p->data.NgayLap << ",";
		fileout << p->data.NgayDi << ",";
		fileout << p->data.SoTienTraTruoc;
		fileout << endl;
	}


	fileout.close();
}

void PDK_input(LISTPDK& lpdk) {
	PDK pdk;
	string luaChon;

	//==============================Vẽ khung pdk============================
	gotoXY(66, 15);
	cout << "Nhap thong tin dang ky Phieu Dang Ky:" << endl;
	gotoXY(66, 17);
	cout << "Nhap ma PDK: ";
	VeHCN(90, 16, 20, 2, 3); // Khung ma khach hang
	gotoXY(66, 20);
	cout << "Nhap ten khach hang: ";
	VeHCN(90, 19, 20, 2, 3); // Khung ten khach hang
	gotoXY(66, 23);
	cout << "Nhap ma khach hang: ";
	VeHCN(90, 22, 20, 2, 3); // khung sdt
	gotoXY(66, 26);
	cout << "Nhap ma nhan vien: ";
	VeHCN(90, 25, 20, 2, 3); // Khung cmnd
	gotoXY(66, 29);
	cout << "Nhap ma phong: ";
	VeHCN(90, 28, 20, 2, 3); // Khung ma phong
	gotoXY(66, 32);
	cout << "Nhap loai phong: ";
	VeHCN(90, 31, 20, 2, 3); // Khung loai phong
	gotoXY(66, 35);
	cout << "Ngay dang ki(dd/mm/yy):";
	VeHCN(90, 34, 20, 2, 3); // Khung ngay dang ky
	gotoXY(66, 38);
	cout << "Ngay di(dd/mm/yy): ";
	VeHCN(90, 37, 20, 2, 3);// Khung ngay di
	gotoXY(66, 41);
	cout << "Nhap so tien tra truoc: ";
	VeHCN(90, 40, 20, 2, 3); // Khung tien tra truoc
	VeHCN(80, 43, 10, 2, 3); // Khung Huy
	gotoXY(81, 44);
	cout << "Huy";
	VeHCN(100, 43, 10, 2, 3);
	gotoXY(101, 44);
	cout << "Dang ky";
	gotoXY(91, 17); // Đưa con trỏ về lại ô nhập đầu tiên

	do {
		gotoXY(91, 17);
		rewind(stdin);
		getline(cin, pdk.MaPDK);
		XoaManHinhTuyChon(122, 17, 70, 3);
		if (!(PDK_checkMaPDK(lpdk, pdk))) {
			XoaManHinhTuyChon(91, 17, 19, 1);
		//	XoaManHinhTuyChon(3, 16, 54, 4);
		}
	} while (!(PDK_checkMaPDK(lpdk, pdk)));
	do {
		gotoXY(91, 20);
		rewind(stdin);
		getline(cin, pdk.TenKH);
		XoaManHinhTuyChon(122, 20, 70, 3);
		if (!(PDK_checkTenKH(pdk))) {
			XoaManHinhTuyChon(91, 20, 19, 1); // rs ô nhập khi nhập sai
		}
	} while (!(PDK_checkTenKH(pdk)));
	do {
		gotoXY(91, 23);
		rewind(stdin);
		getline(cin, pdk.MaKH);
		XoaManHinhTuyChon(122, 23, 70, 3);
		if (!(PDK_checkMaKH(lpdk, pdk))) {
			XoaManHinhTuyChon(91, 23, 19, 1);
		}
	} while (!(PDK_checkMaKH(lpdk, pdk)));
	do {
		gotoXY(91, 26);
		rewind(stdin);
		getline(cin, pdk.MaNV);
		XoaManHinhTuyChon(122, 26, 70, 3);
		if (!(PDK_checkMaNV(lpdk, pdk))) {
			XoaManHinhTuyChon(91, 26, 19, 1);
			//XoaManHinhTuyChon(4, 17, 54, 3);
		}
	} while (!(PDK_checkMaNV(lpdk, pdk)));
	do {
		gotoXY(91, 29);
		rewind(stdin);
		getline(cin, pdk.MaPhong);
		XoaManHinhTuyChon(122, 29, 70, 3);
		if (!(PDK_checkMaPhong(lpdk, pdk))) {
			XoaManHinhTuyChon(91, 29, 19, 1);
			//XoaManHinhTuyChon(4, 17, 54, 3);
		}
	} while (!(PDK_checkMaPhong(lpdk, pdk)));
	do {
		gotoXY(91, 32);
		rewind(stdin);
		getline(cin, pdk.LoaiPhong);
		XoaManHinhTuyChon(122, 32, 70, 3);
		if (!(PDK_checkLoaiPhong(pdk))) {
			XoaManHinhTuyChon(91, 32, 19, 1);
			//XoaManHinhTuyChon(4, 17, 54, 3);
		}
	} while (!(PDK_checkLoaiPhong(pdk)));
	do {
		gotoXY(91, 35);
		rewind(stdin);
		getline(cin, pdk.NgayLap);
		XoaManHinhTuyChon(122, 35, 70, 3);
		if (!(PDK_checkNgayDangKi(pdk))) {
			XoaManHinhTuyChon(91, 35, 19, 1);
			//XoaManHinhTuyChon(4, 17, 54, 3);
		}
	} while (!(PDK_checkNgayDangKi(pdk)));
	do {
		gotoXY(91, 38);
		rewind(stdin);
		getline(cin, pdk.NgayDi);
		XoaManHinhTuyChon(122, 38, 70, 3);
		if (!(PDK_checkNgayDi(pdk))) {
			XoaManHinhTuyChon(91, 38, 19, 1);
			//XoaManHinhTuyChon(4, 17, 54, 3);
		}
	} while (!(PDK_checkNgayDi(pdk)));

	
	do {
		gotoXY(91, 41);
		rewind(stdin);
		getline(cin, pdk.SoTienTraTruoc);
		XoaManHinhTuyChon(122, 41, 70, 3);
		if (!(PDK_soTienIsNum(pdk))) {
			XoaManHinhTuyChon(91, 38, 19, 1);
			//XoaManHinhTuyChon(4, 17, 54, 3);
		}
	} while (!(PDK_soTienIsNum(pdk)));

	//===============Mới thêm return xem lại
	if (batSuKien(80, 55, 10, 2)) { // Bắt sự kiện nút hủy
		return;
	}

	else if (batSuKien(90, 55, 10, 2)) { // Bắt sự kiện nút đăng ký 
		NODEPDK* p = getNodePDK(pdk);
		PDK_addTail(lpdk, p);
		PDK_ghiFile(lpdk);

		gotoXY(90, 47);
		cout << "Dang ky thanh cong";
	}

}

void output1PDK(PDK pdk, int x, int y) {
	//int x = 1, y = 1;
	gotoXY(x, y);
	cout << "\t\tThong tin phieu dang ky!!!" << endl;
	gotoXY(x, y + 1);
	cout << "Ma phieu dang ky: " << pdk.MaPDK << endl;
	gotoXY(x, y + 2);
	cout << "Ten khach hang: " << pdk.TenKH << endl;
	gotoXY(x, y + 3);
	cout << "Ma khach hang: " << pdk.MaKH << endl;
	gotoXY(x, y + 4);
	cout << "Ma nhan vien:	" << pdk.MaNV << endl;
	gotoXY(x, y + 5);
	cout << "Ma phong: " << pdk.MaPhong << endl;
	gotoXY(x, y + 6);
	cout << "Loai phong :" << pdk.LoaiPhong << endl;
	gotoXY(x, y + 7);
	cout << "So tien tra truoc: " << pdk.SoTienTraTruoc << endl;
	gotoXY(x, y + 8);
	cout << "Ngay dang ky: " << pdk.NgayLap << endl;
	gotoXY(x, y + 9);
	cout << "Ngay di: " << pdk.NgayDi << endl;
}


int PDK_checkTenKHTonTai(LISTPDK lpdk, PDK pdk) {
	int dem = 0;
	for (NODEPDK* q = lpdk.pHead; q != NULL; q = q->next) {
		if (q->data.TenKH == pdk.TenKH)
			dem++;
	}
	if (dem == 0) {
		cout << "Ten khach hang khong ton tai! Vui long nhap lai!!!" << endl;
		return 0;
	}
	return 1;
}


void PDK_output(LISTPDK l) {
	int i = 1;
	if (l.pHead == NULL) {
		cout << "Chua co phieu dang ky!!!" << endl;
		system("pause");
	}
	else {
		cout << "\t\tDanh sach phieu dang ky!!!" << endl;
		for (NODEPDK* p = l.pHead; p != NULL; p = p->next) {
			cout << "Thong tin phieu dang ky thu " << i++ << " :" << endl;
			//int x = 80, y = 15;
			//gotoXY(x, y);
			//cout << "\t\tThong tin phieu dang ky!!!" << endl;
			//gotoXY(x, y + 1);
			cout << "Ma phieu dang ky: " << p->data.MaPDK << endl;
			//gotoXY(x, y + 2);
			cout << "Ten khach hang: " << p->data.TenKH << endl;
			//gotoXY(x, y + 3);
			cout << "Ma khach hang: " << p->data.MaKH << endl;
			//gotoXY(x, y + 4);
			cout << "Ma nhan vien:	" << p->data.MaNV << endl;
			//gotoXY(x, y + 5);
			cout << "Ma phong: " << p->data.MaPhong << endl;
			//gotoXY(x, y + 6);
			cout << "Loai phong :" << p->data.LoaiPhong << endl;
			//gotoXY(x, y + 7);
			cout << "So tien tra truoc: " << p->data.SoTienTraTruoc << endl;
			//gotoXY(x, y + 8);
			cout << "Ngay dang ky: " << p->data.NgayLap << endl;
			//gotoXY(x, y + 9);
			cout << "Ngay di: " << p->data.NgayDi << endl;
			//output1PDK(p->data);
		}
		system("pause");
	}
	cout << endl;

}

void PDK_xoaDau(LISTPDK& l) {
	if (l.pHead == NULL) {
		cout << "Chua co danh sach phieu dang ky!!!" << endl;
	}
	else {
		l.pHead->next = l.pHead->next;
		l.pHead = l.pHead->next;
	}
}

void PDK_xoaCuoi(LISTPDK& l) {
	if (l.pHead == NULL) {
		cout << "Danh sach phieu dang dang trong!!!" << endl;
	}
	else {
		for (NODEPDK* p = l.pHead; p != NULL; p = p->next) {
			NODEPDK* q = p->next;
			if (q->next == NULL) {
				p->next = NULL;
				l.pTail = p;
			}
		}
	}
}

int soKhachHangPDK(LISTPDK l) {
	int soKH = 1;
	for (NODEPDK* p = l.pHead; p != NULL; p = p->next) {
		soKH++;
	}
	return soKH;
}

void PDK_listTenKH(LISTPDK lpdk) {
	int i = 1;
	int Y = 15;
	for (NODEPDK* p = lpdk.pHead; p != NULL; p = p->next) {
		gotoXY(80, Y++);
		cout << "Ten khach hang thu " << i++ << ": " << p->data.TenKH << endl;
	}
}

//if (batSuKien(88, 34 + soKhachHangPDK(lpdk), 10, 2)) { // Bắt sự kiện nút hủy
//	return;
//}
//
//else if (batSuKien(120, 34 + soKhachHangPDK(lpdk), 10, 2)) { // Bắt sự kiện đồng ý

void PDK_xoaBatKy(LISTPDK& lpdk, PDK xoa) {
	VeHCN(79, 13, 50, 1 + soKhachHangPDK(lpdk), 2); // Khung hien ten khach hang có số khách hàng là int
	gotoXY(81, 14);
	cout << "Danh sach ten khach hang da dat phieu dang ky." << endl;
	PDK_listTenKH(lpdk);
	gotoXY(70, 18 + soKhachHangPDK(lpdk) + 4); // Khi số KH tăng thì cái này
	cout << "Nhap ten khach hang can xoa phieu dang ky: ";
	rewind(stdin);
	VeHCN(113, 18 + soKhachHangPDK(lpdk) + 3, 20, 2, 5); // Khung nhap ten khach hang can xoa
	VeHCN(90, 18 + soKhachHangPDK(lpdk) + 7, 10, 2, 3); // Khung huy
	gotoXY(91, 18 + soKhachHangPDK(lpdk) + 8);
	cout << "Huy";
	VeHCN(120, 18 + soKhachHangPDK(lpdk) + 7, 10, 2, 3); // Khung dong y
	gotoXY(121, 18 + soKhachHangPDK(lpdk) + 8);
	cout << "Dong y";
	do {
		gotoXY(114, 18 + soKhachHangPDK(lpdk) + 4);
		getline(cin, xoa.TenKH);
	} while ((!(PDK_checkTenKHTonTai(lpdk, xoa))) || xoa.TenKH == "\r");


	if (batSuKien(90, 36 + soKhachHangPDK(lpdk), 10, 2)) { // Bắt sự kiện hủy
		return;
	}

	else if (batSuKien(105, 36 + soKhachHangPDK(lpdk), 10, 2)) { // Bắt sự kiện đồng ý
		int dem = 0; // Xem tên khách hàng cần xóa có trong danh sách hay không
		for (NODEPDK* p = lpdk.pHead; p != NULL; p = p->next) {
			if (xoa.TenKH == lpdk.pHead->data.TenKH) {
				PDK_xoaDau(lpdk);
				gotoXY(100, 29);
				cout << "Xoa thanh cong." << endl;
				system("pause");
				dem++; // Nếu có tăng 1
				break;
			}
			else if (xoa.TenKH == lpdk.pTail->data.TenKH) {
				PDK_xoaCuoi(lpdk);
				gotoXY(100, 29);
				cout << "Xoa thanh cong." << endl;
				system("pause");
				dem++;
				break;
			}
			else {
				NODEPDK* q = p->next;
				if (q->data.TenKH == xoa.TenKH) {
					p->next = q->next;
					gotoXY(100, 29);
					cout << "Xoa thanh cong." << endl;
					system("pause");
					dem++;
					break;
				}
			}
		}
		if (dem == 0) { //  Nếu tên khách hàng cần xóa không có trong danh sách khách hàng
			gotoXY(45, 18);
			cout << xoa.TenKH << " khong co trong danh sach Phieu dang ky." << endl;
			system("pause");
		}
	}
}






int PDK_checkThuocTinh(string thuocTinh) {
	if (thuocTinh != "Ma khach hang" && thuocTinh != "Ten khach hang" && thuocTinh != "Ma phieu dang ky" && thuocTinh != "Ma nhan vien" && thuocTinh != "Ma phong" && thuocTinh != "Loai phong" && thuocTinh != "Ngay dang ky" && thuocTinh != "Ngay di" && thuocTinh != "So tien tra truoc") {
		cout << "Vui long chon: Ma khach hang\tTen khach hang\tMa phieu dang ky\tMa nhan vien\tMa phong\tLoai phong\tNgay dang ky\tNgay di\tSo tien tra truoc!!!" << endl;
		return 0;
	}
	return 1;
}



void PDK_change(LISTPDK& lpdk, PDK pdk) {
	string thuocTinh;
	string changed;
	int dem = 0;
	ShowCur(1); // An con tro
	VeHCN(79, 13, 50, 1 + soKhachHangPDK(lpdk), 2); // Khung hien ten khach hang có số khách hàng là int
	gotoXY(81, 14);
	cout << "Danh sach ten khach hang da dat phieu dang ky." << endl;
	PDK_listTenKH(lpdk);
	gotoXY(70, 18 + soKhachHangPDK(lpdk) + 4); // Khi số KH tăng thì cái này
	cout << "Nhap ten khach hang can change phieu dang ky: ";
	rewind(stdin);
	VeHCN(113, 18 + soKhachHangPDK(lpdk) + 3, 20, 2, 5); // Khung nhap ten khach hang can xoa
	VeHCN(90, 18 + soKhachHangPDK(lpdk) + 7, 10, 2, 3); // Khung huy
	gotoXY(91, 18 + soKhachHangPDK(lpdk) + 8);
	cout << "Huy";
	VeHCN(120, 18 + soKhachHangPDK(lpdk) + 7, 10, 2, 3); // Khung dong y
	gotoXY(121, 18 + soKhachHangPDK(lpdk) + 8);
	cout << "Dong y";
	do {
		gotoXY(114, 18 + soKhachHangPDK(lpdk) + 4);
		getline(cin, pdk.TenKH); // Nhập tên KH cần xóa
	} while (!(PDK_checkTenKHTonTai(lpdk, pdk)));

	if (batSuKien(81, 37 + soKhachHangPDK(lpdk), 10, 2)) { // Bắt sự kiện nút hủy
		return;
	}

	else if (batSuKien(107, 37 + soKhachHangPDK(lpdk), 10, 2)) { // Bắt sự kiện đồng ý
		ShowCur(0);
		system("cls");
		VeHCN(79, 14, 50, 11, 2); // Vẽ HCN cho thông tin Phieu dang ky
		for (NODEPDK* q = lpdk.pHead; q != NULL; q = q->next) {
			if (q->data.TenKH == pdk.TenKH) {
				output1PDK(q->data, 80, 15);
				dem++;
			}
		}

		// Vẽ các khung thuộc tính
		int y = 26;
		VeHCN(75, y, 10, 2, 3); // Vẽ khung Mã KH
		gotoXY(78, y + 1);
		cout << "Ma PDK";

		VeHCN(92, y, 10, 2, 3); // Vẽ khung Tên KH
		gotoXY(94, y + 1);
		cout << "Ten KH";

		VeHCN(109, y, 10, 2, 3); // Vẽ khung Số đt
		gotoXY(111, y + 1);
		cout << "Ma KH";

		VeHCN(126, y, 10, 2, 3); // Vẽ khung CMND
		gotoXY(128, y + 1);
		cout << "Ma NV";

		int Y = 29;
		VeHCN(75, Y, 10, 2, 3); // Vẽ khung số Ma phong
		gotoXY(76, Y + 1);
		cout << "Ma Phong";

		VeHCN(92, Y, 11, 2, 3); // Vẽ khung Loai phong
		gotoXY(93, Y + 1);
		cout << "Loai phong";

		VeHCN(109, Y, 10, 2, 3); // Vẽ khung Ngay dang ky
		gotoXY(111, Y + 1);
		cout << "Ngay dk";

		VeHCN(126, Y, 10, 2, 3); // Vẽ khung Ngay di
		gotoXY(128, Y + 1);
		cout << "Ngay di";

		VeHCN(142, Y, 20, 2, 3); // Vẽ khung số tiền trả trước
		gotoXY(143, Y + 1);
		cout << "Tien tra truoc";
	}


	int y = 33;
	int Y = 37;
	for (NODEPDK* q = lpdk.pHead; q != NULL; q = q->next) {
		if (q->data.TenKH == pdk.TenKH) {
			if (batSuKien(67, y, 10, 2)) { // Mã phiếu đăng ký
				do {
					gotoXY(75, 33);
					ShowCur(1);
					cout << q->data.MaPDK << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					pdk.MaPDK = changed;
				} while (!(PDK_checkMaPDK(lpdk, pdk)));
				q->data.MaPDK = pdk.MaPDK;
			}
			else if (batSuKien(82, y, 10, 2)) { // Tên khách hàng
				do {
					gotoXY(75, 33);
					ShowCur(1);
					cout << q->data.TenKH << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					pdk.TenKH = changed;
				} while (!(PDK_checkTenKH(pdk)));
				q->data.TenKH = pdk.TenKH = changed;
			}
			else if (batSuKien(98, y, 10, 2)) { // Mã khách hàng
				do {
					gotoXY(75, 33);
					ShowCur(1);
					cout << q->data.MaKH << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					pdk.MaKH = changed;
				} while (!(PDK_checkMaKH(lpdk, pdk)));
				q->data.MaKH = pdk.MaKH = changed;
			}
			else if (batSuKien(113, y, 10, 2)) { // Mã nhân viên
				do {
					gotoXY(75, 33);
					ShowCur(1);
					cout << q->data.MaNV << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					pdk.MaNV = changed;
				} while (!(PDK_checkMaNV(lpdk, pdk)));
				q->data.MaNV = pdk.MaNV = changed;
			}
			else if (batSuKien(67, Y, 10, 2)) { // Mã phòng
				do {
					gotoXY(75, 33);
					ShowCur(1);
					cout << q->data.MaPhong << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					pdk.MaPhong = changed;
				} while (!(PDK_checkMaPhong(lpdk, pdk)));
				q->data.MaPhong = pdk.MaPhong = changed;
			}
			else if (batSuKien(82, Y, 11, 2)) { // Loại phòng
				do {
					gotoXY(75, 33);
					ShowCur(1);
					cout << q->data.LoaiPhong << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					pdk.LoaiPhong = changed;
				} while (!(PDK_checkLoaiPhong(pdk)));
				q->data.LoaiPhong = pdk.LoaiPhong = changed;
			}
			else if (batSuKien(97, Y, 10, 2)) { // Ngày đk
				do {
					gotoXY(75, 33);
					ShowCur(1);
					cout << q->data.NgayLap << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					pdk.NgayLap = changed;
				} while (!(PDK_checkNgayDangKi(pdk)));
				q->data.NgayLap = pdk.NgayLap = changed;
			}
			else if (batSuKien(113, Y, 10, 2)) { // Ngày đi
				do {
					gotoXY(75, 33);
					ShowCur(1);
					cout << q->data.NgayDi << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					pdk.NgayDi = changed;
				} while (!(PDK_checkNgayDi(pdk)));
				q->data.NgayDi = pdk.NgayDi = changed;
			}
			else if (batSuKien(127, Y, 20, 2)) { // Tiền trả trước
				do {
					gotoXY(75, 33);
					ShowCur(1);
					cout << q->data.SoTienTraTruoc << " muon thanh doi thanh: ";
					rewind(stdin);
					getline(cin, changed);
					pdk.SoTienTraTruoc = changed;
				} while (!(PDK_soTienIsNum(pdk)));
				q->data.SoTienTraTruoc = pdk.SoTienTraTruoc = changed;
			}
		}
	}
	gotoXY(75, 34);
	cout << thuocTinh << " da duoc thay doi!!!" << endl;
	system("pause");
}

void DP_veKhungTenKHDP(LISTDP ldp) {
	VeHCN(62, 12, 100, 39, 3);
	VeHCN(89, 14, 40, 4, 3); // Khung tên khách hàng
	gotoXY(90, 15);
	cout << "---------------------------------------\n";
	gotoXY(90, 16);
	cout << "|Danh sach ten khach hang dat phong!!!|\n";
	gotoXY(90, 17);
	cout << "---------------------------------------\n";
	int x = 65; // Tọa độ tên khách hàng
	int y = 21;
	int i = 1;
	for (NODEDP* p = ldp.pHead; p != NULL; p = p->next) {
		VeHCN(x - 1, y - 1, 35, 2, 3);
		gotoXY(x, y);
		cout << "Khach hang " << i++ << ":| " << p->data.TenKH << endl;
		y += 3; // Tăng 3
	}
	VeHCN(110, 42, 20, 2, 3); // Vẽ khung Quay lại
	gotoXY(111, 43);
	cout << "Quay lai.";
	NODEDP* p = ldp.pHead;
	int toaDoY = 21; // Tọa độ của tên KH đầu tiên
	while (toaDoY <= 25 + (soKhachHangDP(ldp) * 4)) {
		int X = 105; // Tọa độ X của khung thông tin cá nhân
		int Y = 21;  // Tọa độ Y của khung thông tin cá nhân
		if (batSuKien(65, toaDoY, 35, 2)) {
			VeHCN(X - 1, Y - 1, 40, 20, 4); // Khung chứa thông tin cá nhân
			gotoXY(X, Y);
			Sleep(100);
			cout << "Ten KH: " << p->data.TenKH;
			gotoXY(X, Y + 1);
			Sleep(100);
			cout << "Ma KH: " << p->data.MaKH;
			gotoXY(X, Y + 2);
			Sleep(100);
			cout << "So DT: " << p->data.SoDT;
			gotoXY(X, Y + 3);
			Sleep(100);
			cout << "CMND: " << p->data.CMND;
			gotoXY(X, Y + 4);
			Sleep(100);
			cout << "Ma phong: " << p->data.MaPhong;
			gotoXY(X, Y + 5);
			Sleep(100);
			cout << "Loai phong: " << p->data.LoaiPhong;
			gotoXY(X, Y + 6);
			Sleep(100);
			cout << "Ngay dang ky: " << p->data.NgayLap;
			gotoXY(X, Y + 7);
			Sleep(100);
			cout << "Ngay di: " << p->data.NgayDi;
			toaDoY += 4;
			p = p->next; // p trỏ đến KH thứ 2
			system("pause");
			//cin.get();
			XoaManHinhTuyChon(X, Y, 39, 9);
			if (batSuKien(110, 49, 20, 2)) { // Bắt sự kiện quay lại
				break;
			}
		}
	}
	//system("pause");
}

void PDK_TimKiem(LISTPDK lpdk)
{
	VeHCN(80, 13, 30, 2, 3); // Vẽ khung Tìm kiếm thông tin
	ToMauHCN(80, 13, 30, 2, 255);
	gotoXY(81, 14);
	textcolor(7);
	cout << "Tim Kiem Thong Tin Khach Hang";
	VeHCN(75, 15, 30, 2, 3);
	gotoXY(76, 16);
	cout << "Nhap Ma KH can tim kiem: |";
	VeHCN(73, 18 + soKhachHangPDK(lpdk) + 11, 10, 2, 3); // Vẽ khung quay lai
	gotoXY(74, 20 + soKhachHangPDK(lpdk) + 10);
	cout << "Quay lai.";
	VeHCN(120, 18 + soKhachHangPDK(lpdk) + 11, 10, 2, 3); // Vẽ khung Tiếp tục
	gotoXY(121, 20 + soKhachHangPDK(lpdk) + 10);
	cout << "Tiep tuc.";
	int x = 100;
	char c[100];
	int y = 10;
	int z = 0;
	int dem = 1;
	int demBreak = 0;
	do
	{
		ShowCur(1);
		do {

			gotoXY(x++, 16);
			c[z] = _getche();// A
			if (c[z] >= 'a' && c[z] <= 'z') {
				c[z] -= 32;
			}
			XoaManHinhTuyChon(84, 18, 39, soKhachHangPDK(lpdk) + 8); //rs khung thông tin
		} while (c[z] == '\r');
		int Y = 18;
		ShowCur(0);
		VeHCN(83, 17, 40, 4 + soKhachHangPDK(lpdk) + 6, 2); // Khung thong tin
		ToMauHCN(83, 17, 40, 12, 244);
		textcolor(7);
		int aa = 1;
		for (NODEPDK* k = lpdk.pHead; k != NULL; k = k->next)
		{
			for (int i = 0; i < k->data.MaKH.length(); i++)
			{
				if (i == z)
				{
					if (z == 0) {
						if (c[z] == k->data.MaKH[i])
						{
							gotoXY(85, Y++);
							cout << k->data.MaKH << "  " << k->data.TenKH << endl;
							gotoXY(85, Y++);
							cout << "-------------------------------------" << endl;
							aa++;
							if (aa > 10) {
								gotoXY(130, 25);
								cout << "Trang sau";
								aa = 1;
								//system("pause");
								while (!batSuKien(116, 30, 20, 2)) {
									cout << "Nhap laai";
									if (batSuKien(116, 30, 20, 2));
								}
								XoaManHinhTuyChon(84, 18, 39, soKhachHangPDK(lpdk) + 8);
								Y = 18;
							}
							demBreak = 0;
							//break;
						}
					}

					else if (z > 0 && z < k->data.MaKH.length() - 1) {
						if (c[z] == k->data.MaKH[i] && c[z - 1] == k->data.MaKH[i - 1])
						{
							gotoXY(85, Y++);
							cout << k->data.MaKH << "  " << k->data.TenKH << endl;
							gotoXY(85, Y++);
							cout << "-------------------------------------" << endl;
							if (aa > 10) {
								gotoXY(130, 25);
								cout << "Trang sau";
								aa = 1;
								//system("pause");
								while (!batSuKien(116, 30, 20, 2)) {
									cout << "Nhap laai";
									if (batSuKien(116, 30, 20, 2));

								}
								XoaManHinhTuyChon(84, 18, 39, soKhachHangPDK(lpdk) + 8);
								Y = 18;
							}
							demBreak = 0;
							//break;

						}
					}
					else if (z == k->data.MaKH.length() - 1) {
						int dem = 0;
						for (int i = 0; i < k->data.MaKH.length(); i++) {
							if (k->data.MaKH[i] == c[i]) {
								dem++;
							}
						}
						if (dem == k->data.MaKH.length()) {
							XoaManHinhTuyChon(84, 18, 39, soKhachHangPDK(lpdk) + 8);
							output1PDK(k->data, 85, 18);
							if (batSuKien(65, 41 + soKhachHangPDK(lpdk), 10, 2)) { // Bắt sự kiện quay lại
								demBreak = 3;
								//break;
							}

							// ==========================Lỗi tiếp tục=========================//
							else if (batSuKien(115, 30 + soKhachHangPDK(lpdk) + 9, 10, 2)) { // Bắt sự kiện tiếp tục
								/*system("cls");
								continue;*/
								//XoaManHinhTuyChon(100, 16, 10, 1);
								//PDK_TimKiem(lpdk);	
								demBreak = 1;
							}
						}
					}

				}

			}
		}
		z++;
	} while (demBreak <= 2);
}

void MenuDP() {
	LISTDP ldp;
	LISTPDK lpdk;
	DATPHONG dp;
	PDK pdk;
	PDK_init(lpdk);
	DP_docFile(ldp);
	PDK_docFile(lpdk);
	do {
		VeHCN(63, 12, 133, 39, 3);
		ToMauHCN(63, 12, 133, 39, 3);
		VeHCN(85, 17, 50, 2, 4);
		gotoXY(86, 18);
		cout << "Dang ky Dat phong." << endl;

		VeHCN(85, 20, 50, 2, 4);
		gotoXY(86, 21);
		cout << "Huy dat phong theo ten khach hang." << endl;

		VeHCN(85, 23, 50, 2, 4);
		gotoXY(86, 24);
		cout << "Thay doi thong tin dat phong." << endl;

		VeHCN(85, 26, 50, 2, 4);
		gotoXY(86, 27);
		cout << "Xem danh sach dat phong." << endl;

		VeHCN(85, 29, 50, 2, 4);
		gotoXY(86, 30);
		cout << "Quay lai trang chu." << endl;


		if (batSuKien(76, 21, 50, 2)) { // Bắt sự kiện nút đăng ký dat phong
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			DP_input(ldp);
		}
		else if (batSuKien(76, 24, 50, 2)) { // Bắt sự kiện nút hủy đặt phòng
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			DP_xoaBatKy(ldp, dp);
			DP_ghiFile(ldp);
		}
		else if (batSuKien(76, 28, 50, 2)) { // Bắt sự kiện thay đổi thông tin phòng
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			DP_change(ldp, dp);
			DP_ghiFile(ldp);
		}
		else if (batSuKien(76, 32, 50, 2)) { // Bắt sự kiện xem dat phong
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			DP_output(ldp);
		}
		//else if (batSuKien(76, 36, 50, 2)) { // Bắt sự kiện xem đặt phòng 
		//	VeHCN(63, 12, 133, 39, 3);
		//	ToMauHCN(63, 12, 133, 39, 3);
		//	PDK_output(lpdk);
		//	//PDK_ghiFile(lpdk);
		//	//PDK_output(lpdk);

		//}

		else if (batSuKien(76, 36, 50, 2))
		{
			break;

		}
		//============================================================

		//if (batSuKien(55, 3, 21, 1)) { // Bắt sự kiện nút đăng ký đặt phòng			
		//	ToMauHCN(55, 3, 21, 1, 255);
		//	gotoXY(56, 4);
		//	textcolor(7);
		//	cout << "1: Dang ky dat phong." << endl;
		//	Sleep(1000);
		//	DP_input(ldp);
		//}
		//else if (batSuKien(55, 4, 40, 1)) { // Bắt sự kiện nút hủy đặt phòng
		//	DP_xoaBatKy(ldp, dp);
		//	DP_ghiFile(ldp);
		//}
		//else if (batSuKien(55, 5, 33, 1)) { // Bắt sự kiện thay đổi thông tin phòng
		//	DP_change(ldp, dp);
		//	DP_ghiFile(ldp);
		//}
		//else if (batSuKien(55, 6, 30, 2)) { // Bắt sự kiện xem thông tin đặt phòng
		//	DP_veKhungTenKHDP(ldp);
		//}
		//else
		//	break;
		//} while (true);

	} while (true);
}

void MenuPDK() {
	LISTPDK lpdk;
	PDK pdk;
	PDK_init(lpdk);
	PDK_docFile(lpdk);
	do {
		VeHCN(63, 12, 133, 39, 3);
		ToMauHCN(63, 12, 133, 39, 3);

		VeHCN(85, 17, 50, 2, 4);
		gotoXY(86, 18);
		cout << "Dang ky Phieu dang ky." << endl;

		VeHCN(85, 20, 50, 2, 4);
		gotoXY(86, 21);
		cout << "Huy phieu dang ky theo ten khach hang." << endl;

		VeHCN(85, 23, 50, 2, 4);
		gotoXY(86, 24);
		cout << "Thay doi thong tin phieu dang ky." << endl;

		VeHCN(85, 26, 50, 2, 4);
		gotoXY(86, 27);
		cout << "Tim kiem PDK theo ma khach hang." << endl;

		VeHCN(85, 29, 50, 2, 4);
		gotoXY(86, 30);
		cout << "Xem danh sach phieu dang ky." << endl;

		VeHCN(85, 32, 50, 2, 4);
		gotoXY(86, 33);
		cout << "Quay lai trang chu." << endl;
		if (batSuKien(76, 21, 50, 2)) { // Bắt sự kiện nút đăng ký phiếu đăng ký	
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			PDK_input(lpdk);
		}
		else if (batSuKien(76, 24, 50, 2)) { // Bắt sự kiện nút hủy đặt phòng
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			PDK_xoaBatKy(lpdk, pdk);
			PDK_ghiFile(lpdk);
		}
		else if (batSuKien(76, 28, 50, 2)) { // Bắt sự kiện thay đổi thông tin phòng
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			PDK_change(lpdk, pdk);
			PDK_ghiFile(lpdk);
		}
		else if (batSuKien(76, 32, 50, 2)) { // Bắt sự kiện tìm kiếm
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			PDK_TimKiem(lpdk);
		}
		else if (batSuKien(76, 36, 50, 2)) { // Bắt sự kiện xem đặt phòng 
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			PDK_output(lpdk);
			//PDK_ghiFile(lpdk);
			//PDK_output(lpdk);

		}
		else
			break;
	} while (true);
}
/////---------------------DICH VU---------------------------//////



struct dichvu
{
	string MaDV;
	string TenDV;
	string GiaDV;

};
typedef struct dichvu DICHVU;
struct nodedv
{
	DICHVU data;
	struct nodedv* pNext;
};
typedef struct nodedv NODEDV;

struct listdv
{
	NODEDV* pHead;
	NODEDV* pTail;
};
typedef struct listdv LISTDV;


void KhoiTaoDanhSachDV(LISTDV& l1)
{
	l1.pHead = NULL;
	l1.pTail = NULL;
}
NODEDV* KhoiTaoNodeDV(DICHVU dv)
{
	NODEDV* p = new NODEDV;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->data = dv;
	p->pNext = NULL;
	return p;
}
void ThemCuoi(LISTDV& l1, NODEDV* p)
{

	if (l1.pHead == NULL)
	{
		l1.pHead = l1.pTail = p;
	}
	else
	{
		l1.pTail->pNext = p;
		l1.pTail = p;
	}
}
void docthongtinmotdichvu(ifstream& filein, DICHVU& dv)
{	//VD: 1. abc, An uong, 100


	getline(filein, dv.MaDV, ',');//dungf ham getline doc hoc ten va dau phay
	//bo qua ki tu khoang trang bang ham seekg()
	filein.seekg(1, 1);
	getline(filein, dv.TenDV, ',');
	filein.seekg(1, 1);
	filein >> dv.GiaDV;
	// tạo biến tạm để đọc cái kí tự xuống dòng ở cuối dòng
	string temp;
	getline(filein, temp);

}

void docthongtindanhsachdichvu(ifstream& filein, LISTDV& l)
{
	filein.open("DICHVU.txt", ios::in);

	while (!filein.eof())
	{

		DICHVU dv;

		docthongtinmotdichvu(filein, dv);

		NODEDV* p = KhoiTaoNodeDV(dv);
		ThemCuoi(l, p);


	}
	filein.close();
}
//kiem tra rong

bool kiemtramaDV(DICHVU dv)
{

	if (dv.MaDV == "")
		return false;
	return true;
}
bool kiemtratenDV(DICHVU dv)
{

	if (dv.TenDV == "")
		return false;
	return true;
}
bool kiemtragiaDV(DICHVU dv)
{

	if (dv.GiaDV == "")
		return false;
	return true;
}
//////kiem tra trung
int kiemtramaDVbitrung(LISTDV& l, DICHVU& dv)
{
	int dem = 0;
	for (NODEDV* h = l.pHead; h != NULL; h = h->pNext)
	{
		if (h->data.MaDV == dv.MaDV)
		{
			dem = dem + 1;
		}
		else
		{
			dem = dem;
		}
	}
	if (dem >= 1)
		return 1;
	else
		return 0;
}

int  kiemtragia(string gia)
{
	DICHVU dv;
	int dem = 0;
	for (int i = 0; i < gia.length(); i++)
	{
		if (gia[i] < '0' && gia[i]>'9' || gia[i] >= 'a' && gia[i] <= 'z' || gia[i] >= 'A' && gia[i] <= 'Z')
		{
			return 0;
			break;
		}
		else if (gia[i] >= '0' && gia[i] <= '9')
			dem++;

	}
	if (dem == gia.length())
	{
		return 1;
	}

}



void Themdichvu(LISTDV& l, DICHVU& dv)
{
	//VeHCN(60, 16, 50, 15, 3);
	fstream f;
	gotoXY(72, 18);
	cout << "Nhap ma dich vu";
	VeHCN(90, 17, 20, 2, 3);
	gotoXY(72, 21);
	cout << "nhap ten dich vu:";
	VeHCN(90, 20, 20, 2, 3);

	VeHCN(90, 23, 20, 2, 3);
	gotoXY(72, 24);
	cout << "nhap gia dich vu: ";


	//VeHCN(73, 28, 8, 2, 3);
	gotoXY(74, 29);
	cout << "Cancel";
	//VeHCN(88, 28, 8, 2, 3);
	gotoXY(90, 29);
	cout << "OK";
	if (batSuKien(65, 35, 8, 2)) // cancel
	{
		ToMauHCN(74, 27, 10, 2, 224);
		//ShowCur(0);
		textcolor(224);
		gotoXY(74, 29);
		cout << "Cancel";
		Sleep(1000);
		textcolor(7);

		//ShowCur(1);
		return;

	}
	do {

		gotoXY(91, 18);
		rewind(stdin);
		getline(cin, dv.MaDV);
		if (kiemtramaDVbitrung(l, dv) == 1 || kiemtramaDV(dv) == false)
		{
			gotoXY(91, 18);
			XoaManHinhTuyChon(91, 18, 19, 1);
			gotoXY(85, 27);
			cout << "Nhap ma bi loi";
			Sleep(1000);
			XoaManHinhTuyChon(85, 27, 16, 1);
		}
	} while (kiemtramaDVbitrung(l, dv) == 1 || kiemtramaDV(dv) == false);

	do {
		gotoXY(91, 21);
		rewind(stdin);
		getline(cin, dv.TenDV);
		if (kiemtratenDV(dv) == false)
		{
			gotoXY(91, 21);
			XoaManHinhTuyChon(91, 21, 19, 1);
			gotoXY(85, 27);
			cout << "Nhap ten bi loi";
			Sleep(1000);
			XoaManHinhTuyChon(85, 27, 18, 1);
		}
	} while (kiemtratenDV(dv) == false);


	do {
		gotoXY(91, 24);
		rewind(stdin);
		getline(cin, dv.GiaDV);
		if (kiemtragiaDV(dv) == false || kiemtragia(dv.GiaDV) == 0)
		{
			gotoXY(91, 24);
			XoaManHinhTuyChon(91, 24, 19, 1);
			gotoXY(85, 27);
			cout << "Nhap gia bi loi";
			Sleep(1000);
			XoaManHinhTuyChon(85, 27, 20, 1);
		}
	} while (kiemtragiaDV(dv) == false || kiemtragia(dv.GiaDV) == 0);

	gotoXY(90, 29);
	//VeHCN(63, 28, 8, 2, 3);


	//VeHCN(78, 28, 8, 2, 3);
	if (batSuKien(79, 35, 8, 2)) // ok
	{
		ToMauHCN(88, 28, 8, 3, 224);
		//ShowCur(0);
		textcolor(224);
		gotoXY(90, 29);
		cout << "OK";
		Sleep(100);
		textcolor(7);
		gotoXY(80, 35);
		cout << "Them Thanh Cong ";
		f.open("DICHVU.txt", ios::out | ios::app);
		f << endl;
		f << dv.MaDV << ", ";
		f << dv.TenDV << ", ";
		f << dv.GiaDV;
		NODEDV* p = KhoiTaoNodeDV(dv);
		ThemCuoi(l, p);
		f.close();
		Sleep(1000);
		return;

		//return;
	}
	

}
void xoadau(LISTDV& l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	NODEDV* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void xoacuoi(LISTDV& l)
{	//ds rong
	if (l.pHead == NULL)
	{
		return;
	}
	//ds co 1 phan tu thi goi lai ham xoa dau
	if (l.pHead->pNext == NULL)
	{
		xoadau(l);
		return;
	}
	//duyet tu dau ds
	for (NODEDV* k = l.pHead; k != NULL; k = k->pNext)
	{
		//tim thay k la phan tu ke phan tu cuoi
		if (k->pNext == l.pTail)
		{
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
			return;
		}

	}
}

void xoanodebatki(LISTDV& l)
{
	DICHVU dv;
	do
	{

		gotoXY(70, 15);
		cout << "nhap vao ma dich vu de xoa:";
		VeHCN(96, 14, 25, 2, 3);
		//VeHCN(73, 18, 8, 2, 3);
		gotoXY(74, 19);
		cout << "Cancel";
		//VeHCN(88, 18, 8, 2, 3);
		gotoXY(90, 19);
		cout << "OK";
		gotoXY(97, 15);
		rewind(stdin);
		getline(cin, dv.MaDV);
		if (kiemtramaDVbitrung(l, dv) == 0)
		{


			gotoXY(70, 15);
			XoaManHinhTuyChon(97, 15, 24, 1);
			gotoXY(78, 24);
			cout << "Nhap ma bi loi";
			Sleep(1000);
			XoaManHinhTuyChon(77, 24, 16, 1);
		}


	} while (kiemtramaDVbitrung(l, dv) == 0);
	gotoXY(90, 19);
	if (batSuKien(68, 23, 8, 2)) // cancel
	{
		ToMauHCN(74, 18, 10, 2, 224);
		ShowCur(0);
		textcolor(224);
		gotoXY(74, 19);
		cout << "Cancel";
		Sleep(200);
		textcolor(7);

		//system("cls");
		return;
	}
	//VeHCN(78, 28, 8, 2, 3);
	else if (batSuKien(80, 23, 8, 2)) // ok
	{
		ToMauHCN(88, 18, 8, 3, 224);
		ShowCur(0);
		textcolor(224);
		gotoXY(90, 19);
		cout << "OK";
		Sleep(100);
		gotoXY(80, 35);
		cout << "Xoa Thanh Cong ";
		Sleep(1000);
		textcolor(7);
		for (NODEDV* h = l.pHead; h != NULL; h = h->pNext)
		{
			if (h->data.MaDV == dv.MaDV)
			{
				if (l.pHead == NULL)
				{
					return;
				}
				if (l.pHead->data.MaDV == dv.MaDV)
				{
					xoadau(l);
					return;
				}
				if (l.pTail->data.MaDV == dv.MaDV)
				{
					xoacuoi(l);
					return;
				}
				NODEDV* g = new NODEDV;
				for (NODEDV* k = l.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.MaDV == dv.MaDV)
					{
						g->pNext = k->pNext;
						delete k;
						return;
					}
					g = k;
				}
			}


		}

		return;
		//return;
	}





}
//xuat du lieu 1 dich vu
void xuatdichvu(DICHVU dv)
{

	ToMauHCN(81, 21, 51, 9, 224);
	textcolor(224);
	int i = 23;
	while (i < 30)
	{
		gotoXY(92, i);
		cout << "|";
		gotoXY(110, i);
		cout << "|";
		i++;

	}
	int j = 83;
	while (j < 130)
	{
		gotoXY(j, 24);
		cout << "_";
		j++;
	}
	gotoXY(84, 23);

	cout << "Ma DV";
	gotoXY(96, 23);
	cout << "Ten DV";
	gotoXY(120, 23);
	cout << "Gia DV";
	gotoXY(86, 26);
	cout << dv.MaDV;
	gotoXY(100, 26);
	cout << dv.TenDV;
	gotoXY(120, 26);
	cout << dv.GiaDV;
	HCNTextDong(81, 21, 51, 9);
	textcolor(7);
}



void xuatdanhsachdichvu(LISTDV l)
{

	DICHVU dv;


	ToMauHCN(82, 20, 50, 28, 224);
	//ShowCur(0);
	textcolor(224);

	int k = 1;
	int a = 1;
	int dem = 1;
	while (a > 0)
	{


		for (NODEDV* k = l.pHead; k != NULL; k = k->pNext)
		{



			gotoXY(86, 25 + a);

			cout << k->data.MaDV;
			gotoXY(100, 25 + a);
			cout << k->data.TenDV;
			gotoXY(120, 25 + a);
			cout << k->data.GiaDV;


			a = a + 2;

		}

		break;
	}
	//XoaManHinhTuyChon(82, 26 + a, 50, 8);
	gotoXY(82, 14);
	cout << "==============Thong tin dich vu =================";

	int j = 83;
	while (j < 130)
	{
		gotoXY(j, 22);
		cout << "_";
		j++;
	}
	gotoXY(84, 21);
	cout << "Ma DV";
	gotoXY(96, 21);
	cout << "Ten DV";
	gotoXY(120, 21);
	cout << "Gia DV";
	XoaManHinhTuyChon(82, 26 + a, 50, 48-26-a);
	HCNTextDong(82, 20, 50, 6 + a);
	int i = 21;


	textcolor(7);

}
int kiemtramaDVtrung(LISTDV& l, string ma)
{
	int dem = 0;
	for (NODEDV* h = l.pHead; h != NULL; h = h->pNext)
	{
		if (h->data.MaDV == ma)
		{
			dem = dem + 1;
		}
		else
		{
			dem = dem;
		}
	}
	if (dem >= 1)
		return 1;
	else
		return 0;
}

void suadichvu(LISTDV& l)
{
	//HCNTextDong(82, 20, 50, 20);
	DICHVU dv;
	fstream f;
	xuatdanhsachdichvu(l);
	do
	{



		gotoXY(74, 18);
		cout << "nhap vao ma dich vu de doi:";
		VeHCN(102, 17, 25, 2, 3);

		//VeHCN(87, 44, 8, 2, 3);
		gotoXY(88, 45);
		cout << "Cancel";
		//VeHCN(105, 44, 8, 2, 3);
		gotoXY(106, 45);
		cout << "OK";
		gotoXY(103, 18);

		rewind(stdin);
		getline(cin, dv.MaDV);

		if (kiemtramaDVbitrung(l, dv) == 0)
		{
			gotoXY(103, 18);
			XoaManHinhTuyChon(103, 18, 24, 1);
			gotoXY(130, 18);
			cout << "Nhap ma bi loi";
			Sleep(1000);
			XoaManHinhTuyChon(130, 18, 19, 1);
			//return;
		}


	} while (kiemtramaDVbitrung(l, dv) == 0);

	string ma, ten;
	string gia;
	//////////////////////////////
	XoaManHinhTuyChon(82, 20, 50, 20);

	gotoXY(76, 24);
	cout << "nhap ma dich vu:";
	VeHCN(94, 23, 25, 2, 3);

	gotoXY(76, 27);
	cout << "nhap ten dich vu:";
	VeHCN(94, 26, 25, 2, 3);

	VeHCN(94, 29, 25, 2, 3);
	gotoXY(76, 30);
	cout << "nhap gia dich vu:";

	
	do
	{
		gotoXY(95, 24);
		rewind(stdin);
		getline(cin, ma);

		if (ma == "" || kiemtramaDVtrung(l, ma) == 1)
		{
			gotoXY(120, 24);
			cout << "Nhap sai:";
			Sleep(1000);
			XoaManHinhTuyChon(120, 23, 12, 2);
			XoaManHinhTuyChon(95, 24, 8, 1);
			gotoXY(95, 24);
		}
	} while (ma == "" || kiemtramaDVtrung(l, ma) == 1);
	do {
		gotoXY(95, 27);
		rewind(stdin);
		getline(cin, ten);
		if (ten == "")
		{
			XoaManHinhTuyChon(95, 27, 8, 1);
			gotoXY(120, 27);
			cout << "Nhap sai:";
			Sleep(1000);
			XoaManHinhTuyChon(120, 26, 12, 2);
			gotoXY(92, 27);

		}

	} while (ten == "");

	do {
		gotoXY(95, 30);
		getline(cin, gia);
		if (gia == "" || kiemtragia(gia) == 0)
		{
			XoaManHinhTuyChon(95, 30, 8, 1);
			gotoXY(120, 30);
			cout << "Nhap sai:";
			Sleep(1000);
			XoaManHinhTuyChon(120, 30, 12, 2);
			gotoXY(95, 30);
		}

	} while (gia == "" || kiemtragia(gia) == 0);




	gotoXY(106, 45);



	if (batSuKien(79, 57, 8, 2)) // cancel
	{

		//system("cls");
		return;

	}

	//VeHCN(78, 28, 8, 2, 3);
	else if (batSuKien(95, 57, 8, 2)) // ok
	{
		ToMauHCN(106, 45, 10, 1, 224);
		textcolor(224);
		gotoXY(106, 45);
		cout << "OK";
		Sleep(1000);
		gotoXY(80, 35);
		cout << "Sua Thanh Cong ";
		Sleep(1000);
		textcolor(7);
		for (NODEDV* k = l.pHead; k != NULL; k = k->pNext)
		{

			if (k->data.MaDV == dv.MaDV)
			{

				k->data.MaDV = ma;
				k->data.TenDV = ten;
				k->data.GiaDV = gia;

			}

		}


	}



}

void Luudichvudasuavaofile(LISTDV& l, DICHVU& dv)
{

	ofstream fileout;
	fileout.open("DICHVU.txt", ios::out);

	suadichvu(l);

	for (NODEDV* k = l.pHead; k != NULL; k = k->pNext)
	{

		fileout << k->data.MaDV << ", ";
		fileout << k->data.TenDV << ", ";
		fileout << k->data.GiaDV;
		if (k->pNext != NULL)
		{
			fileout << endl;
		}
		else
			break;


	}
	fileout.close();

}
void Luudichvudaxoavaofile(LISTDV& l, DICHVU& dv)
{

	ofstream fileout;
	fileout.open("DICHVU.txt", ios::out);

	xoanodebatki(l);

	for (NODEDV* k = l.pHead; k != NULL; k = k->pNext)
	{

		fileout << k->data.MaDV << ", ";
		fileout << k->data.TenDV << ", ";
		fileout << k->data.GiaDV;
		if (k->pNext != NULL)
		{
			fileout << endl;
		}
		else
			break;

	}
	fileout.close();

}


void Timkiemdichvu(LISTDV& l, DICHVU dv)
{
	int x = 104;
	char c[100];
	//int y = 10;
	int z = 0;
	xuatdanhsachdichvu(l);
	while (true)
	{
		/*gotoXY(100, 46);
		cout << "Thoat";
		if (batSuKien(90, 58, 8, 2))
		{
			return;
		}*/

		ShowCur(1);
		do
		{
			gotoXY(70, 17);
			cout << "nhap vao ma dich vu de tim kiem:";
			VeHCN(108, 16, 25, 2, 3);
			gotoXY(x++, 17);
			c[z] = _getche();
		} while (c[z] == '\r');
		XoaManHinhTuyChon(81, 19, 52, 26);
		ToMauHCN(82, 20, 50, 28, 224);

		textcolor(224);
		int a = 1;
		int dem = 1;

		for (NODEDV* k = l.pHead; k != NULL; k = k->pNext)
		{
			for (int i = 0; i < k->data.MaDV.length(); i++)
			{
				if (i == z)
				{
					if (z == 0) {
						if (c[z] == k->data.MaDV[i])
						{
							while (a > 0)
							{
								gotoXY(86, 25 + a);

								cout << k->data.MaDV;
								gotoXY(100, 25 + a);
								cout << k->data.TenDV;
								gotoXY(120, 25 + a);
								cout << k->data.GiaDV;

								a = a + 2;
								break;
							}
						}
					}
					else if (z > 0 && z < k->data.MaDV.length() - 1) {
						if (c[z] == k->data.MaDV[i] && c[z - 1] == k->data.MaDV[i - 1])
						{


							while (a > 0)
							{
								gotoXY(86, 25 + a);

								cout << k->data.MaDV;
								gotoXY(100, 25 + a);
								cout << k->data.TenDV;
								gotoXY(120, 25 + a);
								cout << k->data.GiaDV;

								a = a + 2;
								break;
							}


						}
					}
					else if (z == k->data.MaDV.length() - 1) {
						int dem = 0;
						for (int i = 0; i < k->data.MaDV.length(); i++)
						{
							if (k->data.MaDV[i] == c[i]) {
								dem++;
							}
						}
						if (dem == k->data.MaDV.length()) {
							//xuatdichvu(k->data);
							while (a > 0)
							{
								gotoXY(86, 25 + a);

								cout << k->data.MaDV;
								gotoXY(100, 25 + a);
								cout << k->data.TenDV;
								gotoXY(120, 25 + a);
								cout << k->data.GiaDV;

								a = a + 2;
								break;
							}
						}
					}
				}

			}
		}
		z++;

		//gotoXY(82, 14);
		//cout << "==============Thong tin dich vu =================";

		int j = 83;
		while (j < 130)
		{
			gotoXY(j, 22);
			cout << "_";
			j++;
		}
		gotoXY(84, 21);
		cout << "Ma DV";
		gotoXY(96, 21);
		cout << "Ten DV";
		gotoXY(120, 21);
		cout << "Gia DV";
		XoaManHinhTuyChon(82, 26 + a, 50, 48-26-a);
		HCNTextDong(82, 20, 50, 6 + a);
		textcolor(7);
	}
}




void SapxeptangdantheogiaDV(LISTDV l)
{

	for (NODEDV* k = l.pHead; k != NULL; k = k->pNext)
	{
		for (NODEDV* h = k->pNext; h != NULL; h = h->pNext)
		{
			//int atoi(const char* (k->data.GiaDV));

			if (k->data.GiaDV > h->data.GiaDV)
			{
				swap(k->data, h->data);//hoan vi du lieu
			}
		}
	}
}
void LuuDVdaspaxepvaofile(LISTDV& l, DICHVU& dv)
{

	ofstream fileout;
	fileout.open("DICHVU.txt", ios::out);

	SapxeptangdantheogiaDV(l);
	for (NODEDV* k = l.pHead; k != NULL; k = k->pNext)
	{


		fileout << k->data.MaDV << ", ";
		fileout << k->data.TenDV << ", ";
		fileout << k->data.GiaDV;

		if (k->pNext!=NULL)
		{
			fileout << endl;
		}
		else
			break;
	}
	fileout.close();

}


void giaiphong(LISTDV& l)
{
	NODEDV* p = NULL;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
///////////----------------------------------------------------HOA DON-----------------------------------------------------------////


struct hoadon
{
	string MaHD;
	string MaDV;
	string MaNV;
	//DATE NgayThanhToan;
	string SoTienDatTruoc;
	int TongTien;

};
typedef struct hoadon HOADON;
struct nodehd
{
	HOADON datahd;
	struct nodehd* pNexthd;
};
typedef struct nodehd NODEHD;

struct listhd
{
	NODEHD* pHeadhd;
	NODEHD* pTailhd;
};
typedef struct listhd LISTHD;


void KhoiTaoDanhSachHD(LISTHD& lhd)
{
	lhd.pHeadhd = NULL;
	lhd.pTailhd = NULL;
}
NODEHD* KhoiTaoNodeHD(HOADON hd)
{
	NODEHD* p = new NODEHD;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->datahd = hd;
	p->pNexthd = NULL;
	return p;
}
void ThemCuoiHD(LISTHD& lhd, NODEHD* p)
{

	if (lhd.pHeadhd == NULL)
	{
		lhd.pHeadhd = lhd.pTailhd = p;
	}
	else
	{
		lhd.pTailhd->pNexthd = p;
		lhd.pTailhd = p;
	}
}
bool kiemtraMaDV(HOADON hd)
{
	if (hd.MaDV == "")
		return false;
	return true;
}
bool kiemtraMaNV(HOADON hd)
{
	if (hd.MaNV == "")
		return false;
	return true;
}
bool kiemtraSoTienTraTruoc(HOADON hd)
{
	if (hd.SoTienDatTruoc == "")
		return false;
	return true;
}

int Kiemtramadichvutrung(LISTDV& ldv, HOADON& hd)
{
	ifstream filein;
	docthongtindanhsachdichvu(filein, ldv);
	int dem = 0;
	for (NODEDV* p = ldv.pHead; p != NULL; p = p->pNext)
	{
		if (p->data.MaDV == hd.MaDV)
		{
			dem = dem + 1;
		}
		else
		{
			dem = dem;
		}
	}
	if (dem >= 1)
		return 1;
	else
		return 0;
}
//kiem tra ma hoa don trung
bool kiemtramaHDtrung(NODEHD* pHeadhd, string a)
{
	for (NODEHD* k = pHeadhd; k != NULL; k = k->pNexthd)
	{
		if (k->datahd.MaHD == a)
		{
			return true;
		}
	}
	return false;
}
int  kiemtrasotientratruoc(HOADON& hd)
{
	int dem = 0;
	for (int i = 0; i < hd.SoTienDatTruoc.length(); i++)
	{
		if (hd.SoTienDatTruoc[i] < '0' && hd.SoTienDatTruoc[i]>'9' || hd.SoTienDatTruoc[i] >= 'a' && hd.SoTienDatTruoc[i] <= 'z' || hd.SoTienDatTruoc[i] >= 'A' && hd.SoTienDatTruoc[i] <= 'Z')
		{
			return 0;
			break;
		}
		else if (hd.SoTienDatTruoc[i] >= '0' && hd.SoTienDatTruoc[i] <= '9')
			dem++;

	}
	if (dem == hd.SoTienDatTruoc.length())
	{
		return 1;
	}

}
//tao ngau nhien ma hoa don
string taomahoadon(LISTHD& lhd)
{

	string a = "HD0000";
	do {

		for (int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kiemtramaHDtrung(lhd.pHeadhd, a) == true);

	return a;
}
void docthongtinmothoadon(ifstream& filein, HOADON& hd)
{	//VD:  abc, An uong, 100


	getline(filein, hd.MaHD, ',');
	filein.seekg(1, 1);
	getline(filein, hd.MaDV, ',');
	filein.seekg(1, 1);
	getline(filein, hd.MaNV, ',');
	filein.seekg(1, 1);
	getline(filein, hd.SoTienDatTruoc, ',');
	filein.seekg(1, 1);
	filein >> hd.TongTien;
	// tạo biến tạm để đọc cái kí tự xuống dòng ở cuối dòng
	string temp;
	getline(filein, temp);

}
void docthongtindanhsachhoadon(ifstream& filein, LISTHD& lhd)
{

	filein.open("HOADON.txt", ios::in);

	while (!filein.eof())
	{

		HOADON hd;

		docthongtinmothoadon(filein, hd);


		NODEHD* p = KhoiTaoNodeHD(hd);
		ThemCuoiHD(lhd, p);


	}
	filein.close();
}

void nhapdanhsachHoaDon(LISTHD& lhd, HOADON& hd)
{
	fstream f;
	LISTDV ldv;


	NODEHD* k = new NODEHD;
	srand(time(NULL));
	k->datahd.MaHD = taomahoadon(lhd);
	hd.MaHD = k->datahd.MaHD;
	gotoXY(72, 15);
	cout << "Ma Hoa Don";
	VeHCN(90, 14, 20, 2, 3);
	gotoXY(91, 15);
	cout << hd.MaHD;
	gotoXY(72, 18);
	cout << "Ma dich vu: ";
	VeHCN(90, 17, 20, 2, 3);
	gotoXY(72, 21);
	cout << "Nhap ma nhan vien: ";
	VeHCN(90, 20, 20, 2, 3);

	VeHCN(98, 23, 20, 2, 3);
	gotoXY(72, 24);
	cout << "Nhap so tien tra truoc:";

	gotoXY(72, 28);
	cout << "Tong Tien";
	VeHCN(90, 27, 20, 2, 3);
	gotoXY(91, 28);
	hd.TongTien = 1000;
	cout << hd.TongTien;

	//VeHCN(73, 32, 8, 2, 3);
	gotoXY(74, 33);
	cout << "Cancel";
	//VeHCN(88, 32, 8, 2, 3);
	gotoXY(90, 33);
	cout << "OK";

	

	do {
		gotoXY(91, 18);

		rewind(stdin);

		getline(cin, hd.MaDV);
		if (kiemtraMaDV(hd) == false)//|| Kiemtramadichvutrung(ldv, hd) == 0)
		{
			gotoXY(91, 18);
			XoaManHinhTuyChon(91, 18, 19, 1);
			gotoXY(85, 30);
			cout << "Nhap ma bi loi";
			Sleep(1000);
			XoaManHinhTuyChon(85, 30, 16, 1);
		}

	} while (kiemtraMaDV(hd) == false);// || Kiemtramadichvutrung(ldv, hd) == 0);

	do
	{
		gotoXY(91, 21);
		rewind(stdin);
		getline(cin, hd.MaNV);
		if (kiemtraMaNV(hd) == false)
		{
			gotoXY(91, 18);
			XoaManHinhTuyChon(91, 21, 19, 1);
			gotoXY(85, 30);
			cout << "Nhap ma nhan vien bi loi";
			Sleep(1000);
			XoaManHinhTuyChon(85, 30, 25, 1);
		}
	} while (kiemtraMaNV(hd) == false);

	do {
		gotoXY(99, 24);
		rewind(stdin);
		getline(cin, hd.SoTienDatTruoc);
		if (kiemtraSoTienTraTruoc(hd) == false || kiemtrasotientratruoc(hd) == 0)
		{

			gotoXY(99, 24);
			XoaManHinhTuyChon(99, 24, 19, 1);
			gotoXY(85, 30);
			cout << "Nhap so tien bi loi";
			Sleep(1000);
			XoaManHinhTuyChon(85, 30, 22, 1);
		}
	} while (kiemtraSoTienTraTruoc(hd) == false || kiemtrasotientratruoc(hd) == 0);


	gotoXY(90, 33);
	if (batSuKien(68, 41, 8, 2)) // cancel
	{
		ToMauHCN(74, 33, 8, 2, 224);
		textcolor(224);
		gotoXY(74, 33);
		cout << "Cancel";
		Sleep(1000);
		textcolor(7);
		return;
		//system("cls");
	}
	//VeHCN(78, 28, 8, 2, 3);
	//fstream f;
	if (batSuKien(80, 41, 8, 2)) // ok
	{

		ToMauHCN(90, 33, 10, 1, 224);
		textcolor(224);
		gotoXY(90, 33);
		cout << "OK";
		gotoXY(80, 35);
		cout << "Nhap Thanh cong!!!!";
		Sleep(1000);

		f.open("HOADON.txt", ios::out | ios::app);
		f << endl;
		f << hd.MaHD << ", ";
		f << hd.MaDV << ", ";
		f << hd.MaNV << ", ";
		f << hd.SoTienDatTruoc << ", ";
		f << hd.TongTien;

		NODEHD* p = KhoiTaoNodeHD(hd);
		ThemCuoiHD(lhd, p);
		f.close();
		textcolor(7);
		Sleep(1000);

	}

}
//ham tinh tong tien
//int TinhTongTien(LISTHD& lhd)
//{
//	int tong=(ngay thanh toan-ngay den)*gia phong+giaDV-SoTienTraTruoc
//cout << "\nNgay thanh toan:" << hd.NgayThanhToan.ngay << "/" << hd.NgayThanhToan.thang << "/" << hd.NgayThanhToan.nam;
//}
void Luuhoadonvaofile(LISTHD& lhd, HOADON& hd)
{
	ofstream fileout;
	LISTDV l;

	fileout.open("HOADON.txt", ios::out);

	nhapdanhsachHoaDon(lhd, hd);

	for (NODEHD* k = lhd.pHeadhd; k != NULL; k = k->pNexthd)
	{

		fileout << k->datahd.MaHD << ", ";
		fileout << k->datahd.MaDV << ", ";
		fileout << k->datahd.MaNV << ", ";
		fileout << k->datahd.SoTienDatTruoc << ", ";
		fileout << k->datahd.TongTien;
		if (k->pNexthd != NULL)
		{
			fileout << endl;
		}
		else
			break;
		NODEHD* p = KhoiTaoNodeHD(hd);
		ThemCuoiHD(lhd, p);


	}
	fileout.close();
}
void xuathoadon(HOADON hd)
{
	ToMauHCN(75, 22, 90, 10, 224);
	//ShowCur(0);
	textcolor(224);
	//XoaManHinhTuyChon(60, 2, 50, 15);
	//VeHCN(60, 2, 50, 15, 3);

	LISTHD lhd;
	int a = 23;
	while (a < 31)
	{
		gotoXY(90, a);
		cout << "|";
		gotoXY(106, a);
		cout << "|";
		gotoXY(126, a);
		cout << "|";
		gotoXY(146, a);
		cout << "|";
		a++;

	}
	int j = 80;
	while (j < 164)
	{
		gotoXY(j, 26);
		cout << "_";
		j++;
	}
	gotoXY(79, 24);
	cout << "Ma hoa don";
	gotoXY(92, 24);
	cout << "Ma dich vu";
	gotoXY(108, 24);
	cout << "Ma nhan vien";
	gotoXY(128, 24);
	cout << "So tien tra truoc";
	gotoXY(150, 24);
	cout << "Tong Tien";
	gotoXY(78, 28);
	cout << hd.MaHD;
	gotoXY(92, 28);
	cout << hd.MaDV;
	gotoXY(108, 28);
	cout << hd.MaNV;
	gotoXY(130, 28);
	cout << hd.SoTienDatTruoc;
	//k->datahd.TongTien = 1000;
	gotoXY(150, 28);
	cout << hd.TongTien;
	HCNTextDong(75, 22, 90, 10);
	//Sleep(1000);
	textcolor(7);
}



void xuatdanhsacHoaDon(LISTHD lhd)
{
	int i = 1;
	//ToMauHCN(76, 14, 90, 16, 224);
	ToMauHCN(75, 18, 90, 30, 224);
	ShowCur(0);
	textcolor(224);
	gotoXY(94, 13);
	cout << "==============Thong tin Hoa Don ================";
	//VeHCN(76, 14, 90, 30, 3);
	//HCNTextDong(76, 14, 90, 30);
	HOADON hd;

	int j = 77;
	while (j < 164)
	{
		gotoXY(j, 22);
		cout << "_";
		j++;
	}
	gotoXY(79, 20);
	cout << "Ma hoa don";
	gotoXY(92, 20);
	cout << "Ma dich vu";
	gotoXY(108, 20);
	cout << "Ma nhan vien";
	gotoXY(128, 20);
	cout << "So tien tra truoc";
	gotoXY(150, 20);
	cout << "Tong Tien";

	while (i > 0)
	{
		for (NODEHD* k = lhd.pHeadhd; k != NULL; k = k->pNexthd)
		{


			gotoXY(78, 24 + i);
			cout << k->datahd.MaHD;
			gotoXY(92, 24+ i);
			cout << k->datahd.MaDV;
			gotoXY(110, 24 + i);
			cout << k->datahd.MaNV;
			gotoXY(130, 24 + i);
			cout << k->datahd.SoTienDatTruoc;
			//k->datahd.TongTien = 1000;
			gotoXY(150, 24 + i);
			cout << k->datahd.TongTien;
			i = i + 2;
		}
		break;
	}
	XoaManHinhTuyChon(76, 26 + i, 90, 48-26-i);
	HCNTextDong(75, 18, 90, 8 + i);

	int a = 15;
	
	textcolor(7);
}
void xoadauHD(LISTHD& lhd)
{
	if (lhd.pHeadhd == NULL)
	{
		return;
	}

	NODEHD* p = lhd.pHeadhd;
	lhd.pHeadhd = lhd.pHeadhd->pNexthd;
	delete p;
}
void xoacuoiHD(LISTHD& lhd)
{	//ds rong
	if (lhd.pHeadhd == NULL)
	{
		return;
	}
	//ds co 1 phan tu thi goi lai ham xoa dau
	if (lhd.pHeadhd->pNexthd == NULL)
	{
		xoadauHD(lhd);
		return;
	}
	//duyet tu dau ds
	for (NODEHD* k = lhd.pHeadhd; k != NULL; k = k->pNexthd)
	{
		//tim thay k la phan tu ke phan tu cuoi
		if (k->pNexthd == lhd.pTailhd)
		{
			delete lhd.pTailhd;
			k->pNexthd = NULL;
			lhd.pTailhd = k;
			return;
		}

	}
}
void xoanodebatkiHD(LISTHD& lhd)
{
	HOADON hd;

	do
	{

		gotoXY(75, 15);
		cout << "Nhap vao ma hoa don de xoa:";
		VeHCN(108, 14, 25, 2, 3);

		//VeHCN(76, 23, 8, 2, 3);
		gotoXY(77, 24);
		cout << "Cancel";
		//VeHCN(92, 23, 8, 2, 3);
		gotoXY(93, 24);
		cout << "OK";
		gotoXY(109, 15);
		rewind(stdin);
		getline(cin, hd.MaHD);

		if (kiemtramaHDtrung(lhd.pHeadhd, hd.MaHD) == false)
		{

			gotoXY(75, 15);
			XoaManHinhTuyChon(109, 15, 24, 1);
			gotoXY(82, 20);
			cout << "Nhap ma bi loi";
			Sleep(1000);
			XoaManHinhTuyChon(78, 20, 20, 1);
		}
	} while (kiemtramaHDtrung(lhd.pHeadhd, hd.MaHD) == false);
	gotoXY(93, 24);
	if (batSuKien(70, 29, 8, 3))
	{
		return;
		//Sleep(10000);
	}
	else if (batSuKien(83, 29, 8, 3))
	{
		ToMauHCN(93, 24, 10, 1, 224);
		textcolor(224);
		gotoXY(93, 24);
		cout << "OK";
		Sleep(100);
		gotoXY(80, 36);
		cout << "Xoa thanh cong";
		Sleep(1000);
		textcolor(7);
		for (NODEHD* h = lhd.pHeadhd; h != NULL; h = h->pNexthd)
		{

			if (h->datahd.MaHD == hd.MaHD)
			{
				if (lhd.pHeadhd == NULL)
				{
					return;
				}
				if (lhd.pHeadhd->datahd.MaHD == hd.MaHD)
				{
					xoadauHD(lhd);
					return;
				}
				if (lhd.pTailhd->datahd.MaHD == hd.MaHD)
				{
					xoacuoiHD(lhd);

					return;
				}
				NODEHD* g = new NODEHD;
				for (NODEHD* k = lhd.pHeadhd; k != NULL; k = k->pNexthd)
				{
					if (k->datahd.MaHD == hd.MaHD)
					{
						g->pNexthd = k->pNexthd;
						delete k;
						return;
					}
					g = k;
				}
			}

		}

		return;
	}


}
void Luuhoadondaxoavaofile(LISTHD& lhd, HOADON& hd)
{

	fstream f;
	f.open("HOADON.txt", ios::out);

	xoanodebatkiHD(lhd);

	for (NODEHD* k = lhd.pHeadhd; k != NULL; k = k->pNexthd)
	{


		f << k->datahd.MaHD << ", ";
		f << k->datahd.MaDV << ", ";
		f << k->datahd.MaNV << ", ";
		f << k->datahd.SoTienDatTruoc << ", ";
		f << k->datahd.TongTien;
		f << endl;

	}
	f.close();

}

void Timkiemhoadon(LISTHD& lhd, HOADON hd)
{

	xuatdanhsacHoaDon(lhd);
	int x = 102;
	char c[100];
	//int y = 10;
	int z = 0;
	/*gotoXY(100, 46);
	cout << "Thoat";
	if (batSuKien(90, 58, 8, 2))
	{
		return;
	}*/
	while (true)
	{



		ShowCur(1);

		do
		{
			gotoXY(74, 15);
			cout << "Nhap ma hoa don de tim kiem:";
			VeHCN(102, 14, 25, 2, 3);
			gotoXY(x++, 15);
			c[z] = _getche();
		} while (c[z] == '\r');

		//ToMauHCN(76, 14, 90, 16, 224);
		XoaManHinhTuyChon(75, 18, 96, 24);

		ToMauHCN(76, 18, 90, 30, 224);
		textcolor(224);
		int a = 1;
		int dem = 1;
		for (NODEHD* k = lhd.pHeadhd; k != NULL; k = k->pNexthd)
		{
			for (int i = 0; i < k->datahd.MaHD.length(); i++)
			{
				if (i == z)
				{
					if (z == 0)
					{
						if (c[z] == k->datahd.MaHD[i])
						{
							while (a > 0)
							{
								gotoXY(78, 24 + a);
								cout << k->datahd.MaHD;
								gotoXY(92, 24 + a);
								cout << k->datahd.MaDV;
								gotoXY(110, 24 + a);
								cout << k->datahd.MaNV;
								gotoXY(130, 24 + a);
								cout << k->datahd.SoTienDatTruoc;
								//k->datahd.TongTien = 1000;
								gotoXY(150, 24 + a);
								cout << k->datahd.TongTien;
								a = a + 2;
								break;
							}


						}
					}
					else if (z > 0 && z < k->datahd.MaHD.length() - 1) {
						if (c[z] == k->datahd.MaHD[i] && c[z - 1] == k->datahd.MaHD[i - 1])
						{


							while (a > 0)
							{
								gotoXY(78, 24 + a);
								cout << k->datahd.MaHD;
								gotoXY(92, 24 + a);
								cout << k->datahd.MaDV;
								gotoXY(110, 24 + a);
								cout << k->datahd.MaNV;
								gotoXY(130, 24 + a);
								cout << k->datahd.SoTienDatTruoc;
								//k->datahd.TongTien = 1000;
								gotoXY(150, 24 + a);
								cout << k->datahd.TongTien;
								a = a + 2;
								break;
							}


						}
					}
					else if (z == k->datahd.MaHD.length() - 1) {
						int dem = 0;
						for (int i = 0; i < k->datahd.MaHD.length(); i++)
						{
							if (k->datahd.MaHD[i] == c[i])
							{
								dem++;
							}
						}
						if (dem == k->datahd.MaHD.length())
						{
							while (a > 0)
							{
								gotoXY(78, 24 + a);
								cout << k->datahd.MaHD;
								gotoXY(92, 24 + a);
								cout << k->datahd.MaDV;
								gotoXY(110, 24 + a);
								cout << k->datahd.MaNV;
								gotoXY(130, 24 + a);
								cout << k->datahd.SoTienDatTruoc;
								//k->datahd.TongTien = 1000;
								gotoXY(150, 24 + a);
								cout << k->datahd.TongTien;
								a = a + 2;
								break;
							}
						}
					}
				}


			}
		}
		z++;
		int j = 77;
		while (j < 164)
		{
			gotoXY(j, 22);
			cout << "_";
			j++;
		}
		gotoXY(79, 20);
		cout << "Ma hoa don";
		gotoXY(92, 20);
		cout << "Ma dich vu";
		gotoXY(108, 20);
		cout << "Ma nhan vien";
		gotoXY(128, 20);
		cout << "So tien tra truoc";
		gotoXY(150, 20);
		cout << "Tong Tien";
		XoaManHinhTuyChon(75, 25 + a, 95, 48-25-a);
		HCNTextDong(76, 18, 90, 7 + a);
		textcolor(7);
	}
}


void MENUDV( LISTDV l)
{

	
	ifstream filein;
	docthongtindanhsachdichvu(filein, l);
	while (true)
	{

		
		gotoXY(65, 14);//////////////////////////////////////////
		cout << "1. them dich vu";
		gotoXY(65, 16);
		cout << "2. xuat danh sach dich vu";
		gotoXY(65, 18);
		cout << "3.xoa dich vu";

		gotoXY(65, 20);
		cout << "4.sua Dich vu";
		gotoXY(65, 22);
		cout << "5.Sap xep theo gia";
		gotoXY(65, 24);
		cout << "6.Tim kiem dich vu ";
		gotoXY(65, 27);
		cout << "Thoat";
		///////////////Them dich vu
		if (batSuKien(56, 16, 17, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);

			ToMauHCN(64, 13, 34, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 14);
			cout << "1. them dich vu";
			Sleep(100);
			textcolor(7);
			//XoaManHinhTuyChon(60, 8, 90, 26);
			XoaManHinhTuyChon(64, 13, 90, 26);
			ShowCur(1);
			gotoXY(91, 18);
			DICHVU dv;
			Themdichvu(l, dv);
			XoaManHinhTuyChon(66, 13, 50, 34);
		}

		///////////////Xuat dich vu
		else if (batSuKien(56, 19, 34, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);

			ToMauHCN(64, 15, 34, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 16);
			cout << "2. xuat danh sach dich vu";
			Sleep(100);
			textcolor(7);
			ShowCur(1);
			XoaManHinhTuyChon(64, 13, 90, 26);
			
			xuatdanhsachdichvu(l);
			gotoXY(85, 44);
			system("pause");
			XoaManHinhTuyChon(82, 13, 50, 34);

		}

		/////////////Xoa dich vu
		else if (batSuKien(56, 21, 30, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);

			ToMauHCN(64, 17, 34, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 18);
			cout << "3.xoa dich vu";
			Sleep(1000);
			textcolor(7);

			XoaManHinhTuyChon(64, 13, 90, 26);
			ShowCur(1);
			DICHVU dv;
			Luudichvudaxoavaofile(l, dv);
			XoaManHinhTuyChon(66, 13, 50, 38);

		}
		//////////////Sua thong tin dich vu
		else if (batSuKien(56, 23, 12, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);

			ToMauHCN(64, 19, 34, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 20);
			cout << "4.sua Dich vu";
			Sleep(1000);
			textcolor(7);

			XoaManHinhTuyChon(64, 13, 90, 26);
			ShowCur(1);
			DICHVU dv;
			//suadichvu(l);
			Luudichvudasuavaofile(l, dv);
			XoaManHinhTuyChon(66, 13, 70, 38);
		}
		////sap xep dich vu tang dan theo gia
		else if (batSuKien(56, 25, 15, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			ToMauHCN(64, 21, 34, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 22);
			cout << "5.Sap xep theo gia";
			Sleep(1000);
			textcolor(7);
			XoaManHinhTuyChon(64, 13, 90, 26);
			ShowCur(1);
			DICHVU dv;
			//SapxeptangdantheogiaDV(l);
			LuuDVdaspaxepvaofile(l, dv);
			gotoXY(84, 17);
			cout << "Sap xep tang dan theo gia dich vu ";
			xuatdanhsachdichvu(l);
			gotoXY(85, 44);
			system("pause");
			XoaManHinhTuyChon(66, 13, 70, 38);
		}
		/////////////Tim kiem dich vu
		else if (batSuKien(56, 29, 40, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);

			ToMauHCN(64, 23, 34, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 24);
			cout << "6.Tim kiem dich vu ";
			Sleep(1000);
			textcolor(7);
			XoaManHinhTuyChon(64, 13, 90, 26);
			ShowCur(1);
			DICHVU dv;
			Timkiemdichvu(l, dv);
			XoaManHinhTuyChon(66, 13, 70, 38);
		}
		else if (batSuKien(56, 32, 10, 2))
		{
			ToMauHCN(64, 26, 10, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 27);
			cout << "Thoat ";
			Sleep(1000);
			textcolor(7);
			break;
		}

	}
}
void MENUHD(LISTHD lhd, LISTDV l)
{
	HOADON hd;
	ifstream filein;
	docthongtindanhsachhoadon(filein, lhd);
	while (true)
	{
		
		gotoXY(65, 14);
		cout << "1.Nhap danh sach Hoa Don";
		gotoXY(65, 16);
		cout << "2.Xuat danh sach hoa don ";
		gotoXY(65, 18);
		cout << "3.Tim kiem hoa don dua vao ma hoa don ";
		gotoXY(65, 20);
		cout << "4.Xoa hoa don dua vao ma hoa don ";
		gotoXY(65, 23);
		cout << "Thoat";

		if (batSuKien(60, 15, 17, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);

			ToMauHCN(64, 13, 38, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 14);
			cout << "1.Nhap danh sach Hoa Don";
			Sleep(1000);
			textcolor(7);
			ShowCur(1);
			XoaManHinhTuyChon(64, 13, 90, 26);
			nhapdanhsachHoaDon(lhd, hd);
			//Luuhoadonvaofile(lhd, hd);
			XoaManHinhTuyChon(66, 13, 70, 38);
		}
		else if (batSuKien(60, 19, 34, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);


			ToMauHCN(64, 15, 38, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 16);
			cout << "2.Xuat danh sach hoa don ";
			Sleep(1000);
			textcolor(7);
			XoaManHinhTuyChon(64, 13, 90, 26);
			ShowCur(1);
			HOADON hd;
			xuatdanhsacHoaDon(lhd);
			gotoXY(80, 46);
			system("pause");
			XoaManHinhTuyChon(66, 13, 120, 38);
		}
		else if (batSuKien(60, 21, 30, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);

			ToMauHCN(64, 17, 38, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 18);
			cout << "3.Tim kiem hoa don dua vao ma hoa don ";
			Sleep(1000);
			textcolor(7);
			XoaManHinhTuyChon(64, 13, 90, 26);
			ShowCur(1);
			Timkiemhoadon(lhd, hd);
			XoaManHinhTuyChon(66, 13, 70, 38);

		}
		else if (batSuKien(55, 23, 20, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);

			ToMauHCN(64, 19, 38, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 20);
			cout << "4.Xoa hoa don dua vao ma hoa don ";
			Sleep(1000);
			textcolor(7);
			XoaManHinhTuyChon(64, 13, 90, 26);
			ShowCur(1);
			//xoanodebatkiHD(lhd);
			Luuhoadondaxoavaofile(lhd, hd);
			XoaManHinhTuyChon(66, 13, 70, 38);
			//system("pasue");
		}
		else if (batSuKien(58, 27, 10, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);

			ToMauHCN(64, 22, 10, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(65, 23);
			cout << "Thoat ";
			Sleep(1000);
			textcolor(7);
			break;
		}

	}
}



//==============================================================================================================================================================
//==================================STRUCT NGAY===========================
struct Day
{
    int dd, mm, yy;
};
//==================================STRUCT GIO=============================
struct Time
{
    int hour, min;
};
// ===================== DO DAI KY TU CUA NGAY ============================
int DoDaiNgay(Day a)
{
    int dodai = 0;
    dodai = DoDaiSoDuong(a.dd) + DoDaiSoDuong(a.mm) + DoDaiSoDuong(a.yy) + 2; // 2 dau '/'
    return dodai;
}
// ===================== DO DAI KY TU CUA GIO =======================
int DoDaiGio(Time a)
{
    int dodai = 0;
    if (a.min < 10)
    {
        dodai = DoDaiSoDuong(a.hour) + DoDaiSoDuong(a.min) + 2; // Them so '0' voi ':'
    }
    else
    {
        dodai = DoDaiSoDuong(a.hour) + DoDaiSoDuong(a.min) + 1;
    }
    return dodai;
}
// ============================= IN NGAY ============================
void InNgay(Day a)
{
    cout << a.dd << "/" << a.mm << "/" << a.yy;
}
// =================================== IN GIO ====================
void InGio(Time a)
{
    cout << a.hour << ":";
    if (a.min < 10)
    {
        cout << "0" << a.min;
    }
    else
    {
        cout << a.min;
    }
}

//======================= KIỂM TRA DANH SÁCH NHÂN VIÊN RỖNG ==========================
int DanhSachNhanVien(LIST_NHANVIEN& lnv)
{
    if (lnv.pHead == 0)
        return 1;
    return 0;
}

//==========================Giao dien them nhan vien =========================
void GiaoDienThemNhanVien()
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

	VeHCN(79, 14, 16, 2, 4);
	gotoXY(80, 15);
	cout << "Ma Nhan Vien:";
	VeHCN(96, 14, 50, 2, 4);


	VeHCN(79, 17, 16, 2, 4);
	gotoXY(80, 18);
	cout << "Ten Nhan Vien:";
	VeHCN(96, 17, 50, 2, 4);

	VeHCN(79, 20, 16, 2, 4);
	gotoXY(80, 21);
	cout << "Ma Cong Viec:";
	VeHCN(96, 20, 50, 2, 4);


	VeHCN(79, 23, 16, 2, 4);
	gotoXY(80, 24);
	cout << "So Dien Thoai:";
	VeHCN(96, 23, 50, 2, 4);

	VeHCN(79, 26, 16, 2, 4);
	gotoXY(80, 27);
	cout << "Gioi Tinh:";
	VeHCN(96, 26, 50, 2, 4);

	VeHCN(79, 29, 16, 2, 4);
	gotoXY(80, 30);
	cout << "Dia Chi:";
	VeHCN(96, 29, 50, 2, 4);

	VeHCN(79, 32, 16, 2, 4);
	gotoXY(80, 33);
	cout << "Ngay Sinh:";
	VeHCN(96, 32, 50, 2, 4);

	VeHCN(79, 35, 16, 2, 4);
	gotoXY(80, 36);
	cout << "Ngay Nhan Viec:";
	VeHCN(96, 35, 50, 2, 4);

	VeHCN(79, 38, 16, 2, 4);
	gotoXY(80, 39);
	cout << "Het Han:";
	VeHCN(96, 38, 50, 2, 4);

	VeHCN(79, 41, 16, 2, 4);
	gotoXY(80, 42);
	cout << " Luu Lai ";

	VeHCN(125, 41, 16, 2, 4);
	gotoXY(126, 42);
	cout << " Tro Ve ";

	/*gotoXY(97, 15);
	getline(cin, nv.MaNV);
	gotoXY(97, 18);
	getline(cin, nv.TenNV);*/
	/*VeHCN(79, 23, 16, 2, 4);
	gotoXY(75, 24);
	cout << "Chon Phai:";
	VeHCN(130, 23, 15, 2, 4);
	VeHCN(toadoX, toadoY, 50, 2, 15);
	VeHCN(toadoX, toadoY + 3, 50, 2, 15);
	gotoXY(toadoX + 5, toadoY + 7);
	cout << "Nam";
	gotoXY(toadoX + 20, toadoY + 7);
	cout << "Nu";
	gotoXY(toadoX + 15, toadoY + 10);
	cout << "Dang Ki";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "Cancel";*/
}

//========================== Giao diện chức năng nhỏ nhân viên ===================
void GiaoDienNhoNhanVien()
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

    VeHCN(85, 14, 35, 2, 4);
    gotoXY(86, 15);
    cout << "     Them Nhan Vien";

    VeHCN(85, 17, 35, 2, 4);
    gotoXY(86, 18);
    cout << "     Xoa Nhan Vien";

    VeHCN(85, 20, 35, 2, 4);
    gotoXY(86, 21);
    cout << " Danh Sach Thong Tin Nhan Vien";

	VeHCN(85, 23, 35, 2, 4);
	gotoXY(86, 24);
	cout << " Tao tai Khoan Cho Nhan Vien ";

	VeHCN(85, 26, 35, 2, 4);
	gotoXY(86, 27);
	cout << " Thay Doi Thong Tin Nhan Vien ";

	VeHCN(85, 29, 35, 2, 4);
	gotoXY(86, 30);
	cout << " Thoat ";
}

void GiaoDienSapXepNhanVien()
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

	VeHCN(90, 20, 30, 2, 76);
	gotoXY(91, 21);
	cout << " Sap Xep Theo Ma Nhan Vien";

	VeHCN(90, 23, 30, 2, 76);
	gotoXY(91, 24);
	cout << " Sap Xep Theo Ten Nhan Vien";

	VeHCN(90, 26, 30, 2, 76);
	gotoXY(91, 27);
	cout << " Sap Xep Theo Ma Cong Viec";

	VeHCN(90, 29, 30, 2, 76);
	gotoXY(91, 30);
	cout << "            Thoat";
}

void GiaoDienTaoTaiKhoan()
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

	VeHCN(70, 20, 50, 2, 76);
	gotoXY(71, 21);
	cout << "Nhap ten tai khoan: ";

	VeHCN(70, 26, 50, 2, 76);
	gotoXY(71, 27);
	cout << "\nNhap password: ";
}
//=============================Giao diện nhỏ khách hàng ==========================
void GiaoDienNhoKhacHang()
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

	VeHCN(85, 14, 30, 2, 4);
	gotoXY(86, 15);
	cout << "     Them Khach Hang";

	VeHCN(85, 17, 30, 2, 4);
	gotoXY(86, 18);
	cout << "     Xoa Khach Hang";

	VeHCN(85, 20, 30, 2, 4);
	gotoXY(86, 21);
	cout << "     Sua Khach Hang";

	VeHCN(85, 23, 30, 2, 4);
	gotoXY(86, 24);
	cout << "    Tim Kiem Khach Hang";

	VeHCN(85, 26, 30, 2, 4);
	gotoXY(86, 27);
	cout << "    Danh Sach Khach Hang";

	VeHCN(85, 29, 30, 2, 4);
	gotoXY(86, 30);
	cout << "          Thoat";
}
//========================== Giao dien them khach hang ===========================
void GiaoDienThemkhachhang()
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

    VeHCN(79, 14, 16, 2, 4);
    gotoXY(80, 15);
    cout << "Ma Khach Hang:";
    VeHCN(96, 14, 50, 2, 4);


    VeHCN(79, 17, 16, 2, 4);
    gotoXY(80, 18);
    cout << "Ten Khach Hang:";
    VeHCN(96, 17, 50, 2, 4);

    VeHCN(79, 20, 16, 2, 4);
    gotoXY(80, 21);
    cout << "So Dien Thoai:";
    VeHCN(96, 20, 50, 2, 4);


    VeHCN(79, 23, 16, 2, 4);
    gotoXY(80, 24);
    cout << "Dia Chi:";
    VeHCN(96, 23, 50, 2, 4);

    VeHCN(79, 26, 16, 2, 4);
    gotoXY(80, 27);
    cout << "CMND:";
    VeHCN(96, 26, 50, 2, 4);

    VeHCN(79, 29, 16, 2, 4);
    gotoXY(80, 30);
    cout << "Gioi Tinh:";
    VeHCN(96, 29, 50, 2, 4);

    VeHCN(79, 32, 16, 2, 4);
    gotoXY(80, 33);
    cout << "Quoc Tich:";
    VeHCN(96, 32, 50, 2, 4);

    VeHCN(79, 35, 16, 2, 4);
    gotoXY(80, 36);
    cout << " Luu Lai";

    VeHCN(125, 35, 16, 2, 4);
    gotoXY(126, 36);
    cout << " Tro Ve ";
}

void GiaoDienCapNhatTTKH()
{
	VeHCN(65, 13, 10, 2, 3);
	gotoXY(66, 14);
	cout << "     MaKH";

	VeHCN(76, 13, 32, 2, 3);
	gotoXY(77, 14);
	cout << "        TenKH";

	VeHCN(109, 13, 15, 2, 3);
	gotoXY(110, 14);
	cout << "       CMND";

	VeHCN(125, 13, 15, 2, 3);
	gotoXY(126, 14);
	cout << "      So DT";

	VeHCN(141, 13, 15, 2, 3);
	gotoXY(142, 14);
	cout << "     Dia Chi";

	VeHCN(157, 13, 15, 2, 3);
	gotoXY(158, 14);
	cout << "      Gioi Tinh";

	VeHCN(173, 13, 15, 2, 3);
	gotoXY(174, 14);
	cout << "   Quoc Tich";
}

void GiaoDienSapXepKhachHang()
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

	VeHCN(90, 20, 30,2, 76);
	gotoXY(91, 21);
	cout << " Sap Xep Theo Ma Khach Hang";

	VeHCN(90, 23, 30, 2, 76);
	gotoXY(91, 24);
	cout << " Sap Xep Theo Ten Khach Hang";

	VeHCN(90, 26, 30, 2, 76);
	gotoXY(91, 27);
	cout << "             Thoat";
}

void GiaoDienSapXepPhong()
{
	VeHCN(63, 12, 133, 39, 3);
	ToMauHCN(63, 12, 133, 39, 3);

	VeHCN(90, 20, 30, 2, 76);
	gotoXY(91, 21);
	cout << " Sap Xep Theo Ma Phong";

	VeHCN(90, 23, 30, 2, 76);
	gotoXY(91, 24);
	cout << " Sap Xep Theo Gia Phong";

	VeHCN(90, 26, 30, 2, 76);
	gotoXY(91, 27);
	cout << "             Thoat";
}

void GiaoDienQuyDinhKhachSan()
{
	textcolor(36);
	gotoXY(100, 16);
	cout << "XIN CHAO QUY KHACH DEN VOI KHACH SAN GOLDEN-CACBONHIDRAT";
	gotoXY(80, 21);
	cout << "TRUOC KHI NHAN PHONG O KHACH SAN, QUY KHACH VUI LONG LAM TUNG BUOC DUOC QUY DINH TRONG KHACH SAN";
	gotoXY(80, 23);
	cout << "BUOC 1: CUNG CAP THONG TIN KHACH HANG CHO NHAN VIEN";
	gotoXY(80, 25);
	cout << "BUOC 2: TIEN HANH DANG KI DAT PHONG";
	gotoXY(80, 27);
	cout << "BUOC 3: TIEP THEO DANG KI PHIEU DANG KI DE THANH TOAN TIEN CHO PHONG CUA MINH";
	gotoXY(80, 29);
	cout << "BUOC 4: SAU KHI ROI TIEN HANH LAP HOA DON PHONG CUA MINH";
	gotoXY(65, 35);
	cout << "CHUNG TOI XIN CHAN THANH CAM ON - CHUC QUY KHACH MOT NGAY TOT LANH ---- HAVE NICE A DAY!!! --- BYE BYE SEE YOU AGAIN <3";
	textcolor(7);
}


int MainMenu()
{
	ShowCur(0);
	ChangeColor(11);
	VeHCN(5, 4, 52, 47, 4);//khung Chứa khung chức năng và khung hướng dẫn
	ChangeColor(15);
	VeHCN(6, 5, 50, 15, 3); //Khung hướng dẫn khách sạn
	ChangeColor(15);
	gotoXY(22, 6);
	cout << "     HUONG DAN        ";
	gotoXY(8, 7);
	cout << "TRUOC KHI NHAN PHONG, QUY KHACH VUI LONG NHAP ";
	gotoXY(8, 8);
	cout << "DAY DU THONG TIN CA NHAN,DAT PHONG,LAP PHIEU  ";
	gotoXY(8, 9);
	cout << "DANG KI PHONG, THANH TOAN SO TIEN TRA TRUOC   ";
	gotoXY(8, 10);
	cout << "(NEU CO), VUI LONG CHAP HANH DUNG NOI QUY,    ";
	gotoXY(8, 11);
	cout << "QUY DINH CUA KHACH SAN.                       ";
	gotoXY(8, 12);
	cout << "NEU QUY KHACH CO THAC MAC HAY CAN HO TRO GI   ";
	gotoXY(8, 13);
	cout << "THI XIN LIEN HE DEN DOI CHAM SOC KHACH HANG   ";
	gotoXY(8, 14);
	cout << "THEO DUONG DAY NONG: 0123456789 HOAC QUA      ";
	gotoXY(8, 15);
	cout << "EMAIL: HOTELENTERTAINMENT@GMAIL.COM           ";
	gotoXY(8, 16);
	cout << "CHUNG TOI RAT MONG DUOC PHUC VU QUY KHACH HANG";
	gotoXY(8, 17);
	cout << "~~~~~~~~ WITH US CUSTOMERS ARE GOD ~~~~~~~~   ";
	gotoXY(8, 18);
	cout << "~~~~~~~~~~~~~~~~ XIN CAM ON ~~~~~~~~~~~~~~~~  ";
	gotoXY(6, 23);
	cout << "----------------------------------------------------";
	gotoXY(6, 26);
	cout << "----------------------------------------------------";
	VeHCN(6, 30, 50, 20, 3); // Khung chức năng
	VeHCN(4, 3, 200, 49, 5); // Khung khách sạn
	Menu();
	ChangeColor(15);
	gotoXY(175, 0);
	InThoiGian();
//	Xuly();
	//	 AnConTro();
	cout << endl;

	return 0;
}

//=======================================================XỬ LÝ NHÂN VIÊN - KHÁCH HÀNG ====================================================================
void Xuly()
{
	//============================== XỬ LÍ NHÂN VIÊN = KHÁCH HÀNG ====================================================== 
	//	ShowCur(1);
	MainMenu();
	LIST_NHANVIEN lnv;
	NHANVIEN nv;
	LIST_KHACHHANG lkh;
	KHACHHANG kh;
	LIST_PHONG lp;
	LISTDV ldv;
	LIST_THONGTINPHONG lttp;
	THONGTINPHONG ttp;
	KhoiTaoDanhSachDV(ldv);
	LISTHD lhd;
	KhoiTaoDanhSachHD(lhd);
	PHONG p;
	KhoitaoPhong(lp);
	Docfilephong(lp);
	Khoitaolist(lkh);
	KhoiTaoListNV(lnv);
	KhoitaoThongTinPhong(lttp);

	int b = 1;
	int c = 0;
	DocFileKH(lkh);
	DocFileNV(lnv);


	user d;
	init(d);
	int e = 0;
	//==================================================== XỬ LÍ BẮT SỰ KIỆN NHÂN VIÊN ======================================================
	do
	{
		VeHCN(63, 12, 133, 39, 3);
		ToMauHCN(63, 12, 133, 39, 32);
		GiaoDienQuyDinhKhachSan();
		if (batSuKien(8, 39, 43, 1))//bắt sự kiện vào giao diện tiếp của quản lí nhân viên
		{

			do
			{
				GiaoDienNhoNhanVien();
				//       textcolor(14);
				if (batSuKien(76, 17, 31, 2))//bắt sự kiện vào thêm thông tin nhân viên
				{
					HCNTextDong1(85, 14, 35, 2);
					do
					{
						GiaoDienThemNhanVien();
						if (batSuKien(76, 17, 45, 2))//bắt sự kiện để nhập thêm mã nhân vien
						{
							HCNTextDong1(79, 14, 16, 2);
							createNV(lnv, nv);
							if (batSuKien(71, 53, 13, 3))//bắt sự kiện lưu lại
							{
								HCNTextDong1(79, 41, 16, 2);
								GiaoDienThongBaoThanhCong("Them Thanh Cong!!!");
								break;
							}
						}
						else if (batSuKien(112, 53, 14, 2))//nắt sự kiện thoát
						{
							HCNTextDong1(125, 41, 16, 2);
							break;
						}
						else if (batSuKien(71, 53, 13, 3))
						{
							HCNTextDong1(79, 41, 16, 2);
							GiaoDienThongBaoThatBai("Them That Bai!!!");
						}
					} while (true);
				}
				else if (batSuKien(76, 21, 31, 2))//bắt sự kiện xóa nhân viên
				{
					HCNTextDong1(85, 17, 35, 2);
					XoaBatKiNV(lnv, nv);
					SaveNV(lnv, nv);
				}
				else if (batSuKien(76, 25, 31, 2))//bắt sự kiện show danh sách nhân viên
				{
					HCNTextDong1(85, 20, 35, 2);
					do
					{
						GiaoDienSapXepNhanVien();
						if (batSuKien(80, 25, 27, 2))//sắp xếp nhân viên theo mã
						{
							HCNTextDong1(90, 20, 30, 2);
							SapXeptheoMaNhanVien(lnv, nv);
							SaveNV(lnv, nv);
							xuatdanhsachNhanVien(lnv);
						}
						else if (batSuKien(80, 29, 27, 2))//sắp xếp nhân viên theo tên
						{
							HCNTextDong1(90, 23, 30, 2);
							SapXeptheoTenNhanVien(lnv, nv);
							SaveNV(lnv, nv);
							xuatdanhsachNhanVien(lnv);
						}
						else if (batSuKien(80, 33, 27, 2))//sắp xếp nhân viên theo mã công việc
						{
							HCNTextDong1(90, 26, 30, 2);
							SapXeptheoMaCongViec(lnv, nv);
							SaveNV(lnv, nv);
							xuatdanhsachNhanVien(lnv);
						}
						else if (batSuKien(80, 37, 27, 2))
						{
							HCNTextDong1(90, 29, 30, 2);
							break;
						}
					} while (true);
				}
				else if (batSuKien(76, 29, 31, 2))//bắt sự kiện tạo tài khoản cho nhân viên
				{
					HCNTextDong1(85, 23, 35, 2);
					GiaoDienTaoTaiKhoan();
					d.Create();
					Save(d);
					gotoXY(71, 30);
					cout << "Tai Khoan Duoc Tao Thanh Cong!!!";

				}
				else if (batSuKien(76, 33, 31, 2))//băt sự kiện thay đổi thông tin nhân viên
				{
					HCNTextDong1(85, 26, 35, 2);
					ChangeTenNV(lnv, nv);
					SaveNV(lnv, nv);
				}
				else if (batSuKien(76, 37, 31, 2))
				{
					HCNTextDong1(85, 29, 35, 2);
					e=1;
					break;
				}
			} while (true);

		}
		//============================================= XỬ LÍ BẮT SỰ KIỆN KHÁCH HÀNG ========================================================================
		else if (batSuKien(8, 42, 43, 1))//bắt sự kiện để vào quản lí khách hàng
		{
			do
			{
				GiaoDienNhoKhacHang();
				if (batSuKien(76, 17, 26, 2))//bắt sự kiện để nhập thông tin khách hàng
				{
					HCNTextDong1(85, 14, 30, 2);
					do
					{
						GiaoDienThemkhachhang();
						if (batSuKien(76, 17, 45, 2))//bắt sự kiện bắt đầu nhập từ mã khách hàng
						{

							create(lkh, kh);
							if (batSuKien(71, 45, 13, 3))//bắt sự kiện lưu lại
							{
								GiaoDienThongBaoThanhCong("Them Thanh Cong!!!");
								break;
							}
						}
						else if (batSuKien(112, 45, 14, 2))//nắt sự kiện thoát
						{
							break;
						}
						else if (batSuKien(71, 45, 13, 3))
						{
							GiaoDienThongBaoThatBai("Them That Bai!!!");
						}
					} while (true);
				}
				else if (batSuKien(76, 21, 26, 2))//xóa khách hàng bất kì trong list
				{
					HCNTextDong1(85, 17, 30, 2);
					XoaBatKiKH(lkh, kh);
					SaveKH(lkh, kh);
				}
				else if (batSuKien(76, 25, 27, 2))//giao diện thay đổi thông tin khách hàng
				{
					HCNTextDong1(85, 20, 30, 2);
					ChangeKH(lkh, kh);
					SaveKH(lkh, kh);
				}
				else if (batSuKien(76, 29, 27, 2))//bắt sự kiện tìm kiếm khách hàng
				{
					HCNTextDong1(85, 23, 30, 2);
					TimKiemTTMaKH(lkh);
				}
				else if (batSuKien(76, 33, 27, 2))//xuất danh sách khách hàng
				{
					HCNTextDong1(85, 26, 30, 2);
					do
					{
						GiaoDienSapXepKhachHang();
						if (batSuKien(80, 25, 27, 2))
						{
							HCNTextDong1(90, 20, 30, 2);
							SapXeptheoMaKhachhang(lkh, kh);
							SaveKH(lkh, kh);
							xuatdanhsachKhachHang(lkh);
							if (batSuKien(100, 18, 20, 2))
								break;
						}
						else if (batSuKien(80, 29, 27, 2))
						{
							HCNTextDong1(90, 23, 30, 2);
							SapXeptheoTenKhachhang(lkh, kh);
							SaveKH(lkh, kh);
							xuatdanhsachKhachHang(lkh);
						}
						else if (batSuKien(80, 33, 27, 2))
						{
							HCNTextDong1(90, 26, 30, 2);
							break;
						}
					} while (true);
				}
				else if (batSuKien(76, 37, 27, 2))
				{
					HCNTextDong1(85, 29, 30, 2);
					break;
				}
			} while (true);
		}

		//============================================= XỬ LÍ PHÒNG ======================================================================================
		else if (batSuKien(8, 47, 43, 1))
		{
			do
			{
				VeHCN(63, 12, 133, 39, 3);
				ToMauHCN(63, 12, 133, 39, 3);
				GiaoDienNhoPhong(lp, p);

				if (batSuKien(70, 15, 30, 3))// vào thêm phòng 
				{
					HCNTextDong1(79, 14, 30, 2);
					do
					{
						VeHCN(63, 12, 133, 39, 3);
						ToMauHCN(63, 12, 133, 39, 3);
						XoaManHinhTuyChon(147, 15, 10, 2);
						GiaoDienThemPhong(lp, p);
						XoaManHinhTuyChon(147, 15, 10, 2);

						if (batSuKien(86, 17, 45, 2))
						{
							/*gotoXY(97, 15);
							HienConTro();
							createphong(lp, p);
							AnConTro();*/
							//KhoitaoPhong(lp);
							do
							{
								//KhoitaoPhong(lp);
								gotoXY(97, 15);
								HienConTro();
								createphong(lp, p);
								//XuatPhong(lp);
								//Ghifilephong(lp);
								AnConTro();
								//Ghifilephong(lp);
								if (batSuKien(71, 45, 14, 2))// vao luu
								{
									Ghifilephong(lp);
									GiaoDienThongBaoThanhCong("Them Thanh Cong");
									break;

								}
								else if (batSuKien(112, 45, 14, 2))// tro ve
								{
									break;
								}

							} while (true);
							//system("cls");
							//break;

						}
						if (batSuKien(71, 45, 14, 2))// vao luu
						{

							GiaoDienThongBaoThatBai("Them That Bai");
						}
						if (batSuKien(112, 45, 14, 2))// trở về
						{

							break;
						}
					} while (true);

				}
				else if (batSuKien(70, 21, 27, 2)) // vao tra cuu phong
				{
					HCNTextDong1(79, 17, 30, 2);
					do
					{
						VeHCN(63, 12, 133, 39, 3);
						ToMauHCN(63, 12, 133, 39, 3);
						GiaoDienTraCuuPhong(lp, p);
						if(batSuKien(70,17,27,2))
						{
							HCNTextDong1(79, 14, 30, 2);
							VeHCN(63, 12, 133, 39, 3);
							ToMauHCN(63, 12, 133, 39, 3);
							TimKiemPhong_MP(lp);
							system("pause");
							break;
						}
						else if (batSuKien(70, 20, 27, 3))
						{
							HCNTextDong1(79, 17, 30, 2);
							break;
						}
					} while (true);
				}
				else if (batSuKien(70, 25, 27, 3))// vao thong tin phong
				{
					HCNTextDong1(79, 20, 30, 2);
					do
					{
						VeHCN(63, 12, 133, 39, 3);
						ToMauHCN(63, 12, 133, 39, 3);
						GiaoDienThongTinPhong();
						if (batSuKien(70, 17, 27, 2))
						{

							do
							{
								VeHCN(63, 12, 133, 39, 3);
								ToMauHCN(63, 12, 133, 39, 3);
								GiaoDienThemThongTinPhong();
								if (batSuKien(86, 17, 45, 2))
								{
									do
									{
										gotoXY(97, 15);
										HienConTro();
										createphong(lp, p);
										AnConTro();
										if (batSuKien(71, 45, 14, 2))// vao luu
										{
											Ghifilephong(lp);
											GiaoDienThongBaoThanhCong("Them Thanh Cong");
											break;

										}
										else if (batSuKien(112, 45, 14, 2))// tro ve
										{
											break;
										}

									} while (true);
								}
								if (batSuKien(71, 45, 14, 2))// luu 
								{
									GiaoDienThongBaoThatBai("Them That Bai !!!");			
									break;
								}
								if (batSuKien(112, 45, 14, 2))// trở về
								{

									break;
								}
							} while (true);
						}
						else if (batSuKien(70, 20, 27, 2)) // sua thong tin phong
						{
							break;
						}
						else if (batSuKien(70, 23, 27, 2)) // thoat 
						{
							break;
						}
						system("pause");
						break;
					} while (true);
				}
				else if (batSuKien(70, 29, 27, 2))// vao dat phong
				{
					HCNTextDong1(79, 23, 30, 2);
					do
					{
						MenuDP();
						break;
					} while (true);
				}
				else if (batSuKien(70, 33, 27, 2)) // vao thay doi phong
				{
				    HCNTextDong1(79, 26, 30, 2);
					do
					{
						VeHCN(63, 12, 133, 39, 3);
						ToMauHCN(63, 12, 133, 39, 3);
						GiaoDienThayDoiPhong(lp, p);
						//if (batSuKien(1, 1, 1, 1))
						//{
						//	cout << "aaaa";
						//}
						if (batSuKien(70, 17, 27, 2))
						{
							//cout << "aaaaa";
							//break;
							ThayDoiPhong(lp, p);
							//system("pause");
							break;
						}
						else if (batSuKien(70, 19, 20, 2))
						{
							break;
						}
					} while (true);
				}
				else if (batSuKien(70, 37, 27, 2)) // vao xoa phong
				{
				HCNTextDong1(79, 29, 30, 2);
					do
					{
						VeHCN(63, 12, 133, 39, 3);
						ToMauHCN(63, 12, 133, 39, 3);
						GiaoDienXoaPhong(lp, p);
						if (batSuKien(78, 15, 30, 3))
						{
							XoaBatKiPhong(lp, p);
							Ghifilephong(lp);
							//break;
						}
						else if (batSuKien(78, 19, 30, 3))
						{
							break;
						}
						//if (batSuKien(1, 1, 1, 1))
						//{
						//	cout << "aaaa";
						//}
					} while (true);
				}
				else if (batSuKien(70, 41, 27, 2)) // Danh sach Phong
				{
				HCNTextDong1(79, 32, 30, 2);
					do
					{
						VeHCN(63, 12, 133, 39, 3);
						ToMauHCN(63, 12, 133, 39, 3);
						GiaoDienSapXepPhong();
						if (batSuKien(80, 24, 26, 2))
						{
							HCNTextDong1(90, 20, 30, 2);
							SapXeptheoMaPhong(lp, p);
							xuatdanhsachPhong(lp);
							Ghifilephong(lp);
						}
						else if (batSuKien(80, 27, 26, 2))
						{
							HCNTextDong1(90, 23, 30, 2);
							SapXeptheoGiaPhong(lp, p);
							xuatdanhsachPhong(lp);
							Ghifilephong(lp);
						}
						else if (batSuKien(80, 30, 26, 2))
						{
							HCNTextDong1(90, 26, 30, 2);
							break;
						}
						//xuatdanhsachPhong(lp);
					} while (true);

				}
				else if (batSuKien(70, 45, 27, 3))
				{
				HCNTextDong1(79, 35, 30, 2);
					c = 1;
				    break;
                }

			} while (true);

		}
		//============================================= XỬ LÍ LẬP PHIẾU ĐĂNG KÍ ========================================================================
		else if (batSuKien(8, 50, 43, 1))
		{
			MenuPDK();
		}
		//============================================= XỬ LÍ DICH VU ========================================================================
		else if (batSuKien(8, 52, 40, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			ToMauHCN(9, 40, 44, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(24, 41);
			cout << "Quan li Dich Vu";
			Sleep(1000);
			textcolor(7);
			XoaManHinhTuyChon(10, 41, 44, 1);
			gotoXY(24, 41);
			cout << "Quan li Dich Vu";
			ShowCur(1);
			MENUDV(ldv);

		}
		//============================================= XỬ LÍ HOA DON========================================================================

		else if (batSuKien(8, 55, 40, 2))
		{
			VeHCN(63, 12, 133, 39, 3);
			ToMauHCN(63, 12, 133, 39, 3);
			ToMauHCN(9, 42, 44, 2, 224);
			ShowCur(0);
			textcolor(224);
			gotoXY(24, 43);
			cout << "Quan li Hoa Don";
			Sleep(1000);
			textcolor(7);
			XoaManHinhTuyChon(9, 43, 44, 1);
			gotoXY(24, 43);
			cout << "Quan li Hoa Don";

			ShowCur(1);
			MENUHD(lhd, ldv);
		}
	}while (e == 0);
}

