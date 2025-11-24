/**Xây dựng lớp biểu diễn khái niệm số phức với hai thành phần dữ liệu thực, ảo
và các hàm thành phần xuất, nhập, định giá trị cho số phức, cộng, trừ, nhân,
chia hai số phức.Viết chương trình cho phép nhập vào hai số phức, in ra kết quả
các phép toán cộng, trừ, nhân, chia hai số phức kể trên.**/

#include <iostream>
using namespace std;

class Sophuc
{
private:
	float thuc, ao;
public:
	Sophuc()
	{
		thuc = 0;
		ao = 0;
	}
	void Nhapso();
	void Xuatso();
	Sophuc Cong(Sophuc);
	Sophuc Tru(Sophuc);
	Sophuc Nhan(Sophuc);
	Sophuc Chia(Sophuc);
};
void Sophuc::Nhapso()
{
	cout << "Nhap phan thuc: ";
	cin >> thuc;
	cout << "Nhap phan ao: ";
	cin >> ao;
}
void Sophuc::Xuatso()
{
	cout << thuc << " + " << ao << "i";
}
Sophuc Sophuc::Cong(Sophuc b)
{
	Sophuc tong;
	tong.thuc = thuc + b.thuc;
	tong.ao = ao + b.ao;
	return tong;
}
Sophuc Sophuc::Tru(Sophuc b)
{
	Sophuc hieu;
	hieu.thuc = thuc - b.thuc;
	hieu.ao = ao - b.ao;
	return hieu;
}
Sophuc Sophuc::Nhan(Sophuc b)
{
	Sophuc tich;
	tich.thuc = thuc * b.thuc - ao * b.ao;
	tich.ao = thuc * b.ao + ao * b.thuc;
	return tich;
}
Sophuc Sophuc::Chia(Sophuc b)
{
	Sophuc thuong;
	thuong.thuc = (thuc * b.thuc + ao * b.ao) / (b.thuc * b.thuc + b.ao * b.ao);
	thuong.ao = (ao * b.thuc - thuc * b.ao) / (b.thuc * b.thuc + b.ao * b.ao);
	return thuong;
}
int main()
{
	Sophuc a, b;
	a.Nhapso();
	b.Nhapso();
	cout << "a+b= ";
	a.Cong(b).Xuatso();
	cout << endl;
	cout << "a-b= ";
	a.Tru(b).Xuatso();
	cout << endl;
	cout << "a*b= ";
	a.Nhan(b).Xuatso();
	cout << endl;
	cout << "a/b= ";
	a.Chia(b).Xuatso();
	cout << endl;
	return 0;
}