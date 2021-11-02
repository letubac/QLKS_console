#pragma once
#include<string>
#include<fstream>
#include<iostream>

using namespace std;


class user {

	struct node {
		string ten, mk;
		int rights = 0;
		node* next;
	};

private:
	node* head;
public:
	user()
	{
		head = NULL;
	}
	node* getNewNode(string ten, string mk, int quyen)//hàm khởi tạo node
	{
		node* newNode = new node();
		newNode->ten = ten;
		newNode->mk = mk;
		newNode->rights = quyen;
		newNode->next = NULL;
		return newNode;
	}

	void addHead(string ten, string mk, int quyen);
	void print();
	bool checkUserName(string t)//hàm kiểm tra username có tồn tại trong danh sách
	{
		int dem = 0;
		node* p = head;
		while (p != NULL)  //th == th,vb,abc
		{
			if (p->ten == t) return true;
			p = p->next;
		}
		return false;
	}
	void Create()//hàm tạo tài khoản để lưu vào file
	{
		string a, b;

		while (true)
		{
			cout << "Nhap ten tai khoan: ";
			//gotoXY(90, 21);
			getline(cin, a);
			//XoaManHinhTuyChon(70, 24, 35, 1);
			if (checkUserName(a) == false)
			{
				/*XoaManHinhTuyChon(90, 21, 30, 1);
				gotoXY(70, 24);*/
				//cout << "=>Tai khoan bi trung, Nhap lai!!!";
				break;
			}
		}
		cout << "\nNhap password: ";
		//gotoXY(90, 27);
		getline(cin, b);

		addHead(a, b, 1);
	}
	bool checkPsswd(string t) //hàm kiểm tra mật khẩu có tồn tại trong list
	{
		int dem = 0;
		node* p = head;
		while (p != NULL)
		{
			if (p->mk == t) return true;
			p = p->next;
		}
		return false;
	}
	node* getPoiter(string t) //hàm trả về con trỏ node tại username
	{
		node* p = head;
		while (p != NULL)
		{
			if (p->ten == t) return p;
			p = p->next;
		}
		return NULL;
	}
	node* Trave()
	{
		return head;
	}
};

void init(user& list);
void Save(user t);