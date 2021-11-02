#pragma once
#include"user.h"
#include"DoHoa.h"
using namespace std;

void loading() {

	system("cls");
	AnConTro();
	textcolor(5);
	for (int i = 1; i <= 50; i++)
	{
		system("cls");
		cout << "\n\n\n\n\t\t\t\t   Loading " << '\n' << '\t' << '\t';
		for (int j = 1; j <= i; j++)
			cout << "²";
		//cout << "|";
		cout << "\n\n\t " << 2 * i << "%";

		if (i > 1 && i <= 20)
			cout << "\n\n\tDang khoi tao chuong trinh";
		else if (i > 20 && i <= 40)
			cout << "\n\n\tVui long doi";
		else if (i > 40 && i <= 48)
			cout << "\n\n\tCho them xiu nua, dung bo cuoc";
		else cout << "\n\n\tSuccess...Cong suc cua ban duoc den dap.";
		Sleep(150 - i * 3); // Dang giam dan tgian cho
	}
	textcolor(7);
}

int  windowsSignIn(user t)//cửa sổ đăng nhập
{
	string id;
	while (id == "")
	{
		string a;
		if (t.checkUserName(a)) {
			id = a;
		}
	}

	while (true)
	{
		string b;
		if (t.checkPsswd(b)) {
			auto p = t.getPoiter(id);
		}
	}
}