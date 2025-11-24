/**Thiết lập lớp PhanSo để biểu diễn khái niệm phân số với hai thành phần dữ liệu 
tử số, mẫu số và các hàm thành phần cộng, trừ, nhân, chia hai phân số, các 
hàm thành phần xuất, nhập, định giá trị cho phân số. Viết chương trình cho 
phép nhập vào hai phân số, in ra kết quả các phép toán cộng, trừ, nhân, chia hai 
phân số kể trên. **/

#include <iostream>
using namespace std;
class PhanSo
{
private:
	int tuSo, mauSo;

public:
	PhanSo(int a = 0, int b = 1)
	{
		tuSo = a;
		mauSo = b;
	}
	void nhap();
	void xuat();
	PhanSo cong(PhanSo);
	PhanSo tru(PhanSo);
	PhanSo nhan(PhanSo);
	PhanSo chia(PhanSo);
};
void PhanSo::nhap()
{
	cout << "Nhap tu so: ";
	cin >> tuSo;
	cout << "Nhap mau so: ";
	cin >> mauSo;
}
void PhanSo::xuat()
{
	cout << tuSo << "/" << mauSo;
}
PhanSo PhanSo::cong(PhanSo b)
{
	PhanSo tong;
	tong.tuSo = tuSo * b.mauSo + mauSo * b.tuSo;
	tong.mauSo = mauSo * b.mauSo;
	return tong;
}
PhanSo PhanSo::tru(PhanSo b)
{
	PhanSo hieu;
	hieu.tuSo = tuSo * b.mauSo - mauSo * b.tuSo;
	hieu.mauSo = mauSo * b.mauSo;
	return hieu;
}
PhanSo PhanSo::nhan(PhanSo b)
{
	PhanSo tich;
	tich.tuSo = tuSo * b.tuSo;
	tich.mauSo = mauSo * b.mauSo;
	return tich;
}
PhanSo PhanSo::chia(PhanSo b)
{
	PhanSo thuong;
	thuong.tuSo = tuSo * b.mauSo;
	thuong.mauSo = mauSo * b.tuSo;
	return thuong;
}
int main()
{
	PhanSo a(4,5), b;
	a.nhap();
	b.nhap();
	a.cong(b).xuat();
	cout << endl;
	a.tru(b).xuat();
	cout << endl;
	a.nhan(b).xuat();
	cout << endl;
	a.chia(b).xuat();
	cout << endl;
	return 0;
}