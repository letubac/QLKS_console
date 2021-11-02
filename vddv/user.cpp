#include"user.h"


void user::addHead(string ten, string mk, int quyen)
{
	node* p = getNewNode(ten, mk, quyen);
	if (head == NULL)
	{
		head = p;
	}
	else {
		p->next = head;
		head = p;
	}

}


void user::print() //hàm xuất tài khoản
{
	node* p = head;
	while (p != NULL)
	{
		cout << "\nTen: " << p->ten << "\tMat khau: " << p->mk << "\tQuyen: " << (p->rights == 1 ? "Admin" : "Khach Hang");
		p = p->next;
	}
}

void init(user& list)//hàm đọc file tài khoản
{
	ifstream f("dataUser.txt");
	while (!f.eof())
	{
		string a, b; int c;

		getline(f, a); if (a == "") return;
		getline(f, b);
		f >> c;
		f.ignore(1);
		list.addHead(a, b, c);
	}
}
void Save(user t) //hàm lưu tài khoản vào danh sách tài khoản
{
	ofstream f("dataUser.txt");
	for (auto p = t.Trave(); p != NULL; p = p->next)
	{
		f << p->ten << endl;
		f << p->mk << endl;
		f << p->rights << endl;

	}

	f.close();
}