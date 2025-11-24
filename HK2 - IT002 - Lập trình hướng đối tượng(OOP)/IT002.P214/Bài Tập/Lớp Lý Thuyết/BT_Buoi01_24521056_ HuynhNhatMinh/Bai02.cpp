/**Cài đặt lớp biểu diễn khái niệm số phức với hai thành phần dữ liệu thực, ảo và các hàm thành phần xuất, nhập, định giá trị cho số phức, cộng, trừ, nhân, chia hai số phức.
Viết chương trình cho phép nhập vào hai số phức, in ra kết quả các phép toán cộng, trừ, nhân, chia hai số phức kể trên.**/
#include <iostream>
using namespace std;

class SoPhuc
{
private:
	float thuc, ao;	
public:
	SoPhuc(float a=0, float b=0) 
	{
		thuc = a;
		ao = b;
	}
	void Nhap();
	void Xuat();
	SoPhuc Cong(SoPhuc);
	SoPhuc Tru(SoPhuc);
	SoPhuc Nhan(SoPhuc);
	SoPhuc Chia(SoPhuc);
};
void SoPhuc::Nhap()
{
	cout << "Nhap phan thuc: ";
	cin >> thuc;
	cout << "Nhap phan ao: ";
	cin >> ao;
}
void SoPhuc::Xuat()
{
	cout << thuc << " + " << ao << "i" << endl;
}
SoPhuc SoPhuc::Cong(SoPhuc sp)
{
	SoPhuc kq;
	kq.thuc = thuc + sp.thuc;
	kq.ao = ao + sp.ao;
	return kq;
}
SoPhuc SoPhuc::Tru(SoPhuc sp)
{
	SoPhuc kq;
	kq.thuc = thuc - sp.thuc;
	kq.ao = ao - sp.ao;
	return kq;
}
SoPhuc SoPhuc::Nhan(SoPhuc sp)
{
	SoPhuc kq;
	kq.thuc = thuc * sp.thuc - ao * sp.ao;
	kq.ao = thuc * sp.ao + ao * sp.thuc;
	return kq;
}
SoPhuc SoPhuc::Chia(SoPhuc sp)
{
	SoPhuc kq;
	kq.thuc = (thuc * sp.thuc + ao * sp.ao) / (sp.thuc * sp.thuc + sp.ao * sp.ao);
	kq.ao = (ao * sp.thuc - thuc * sp.ao) / (sp.thuc * sp.thuc + sp.ao * sp.ao);
	return kq;
}
int main()
{
	SoPhuc sp1, sp2;
	cout << "Nhap so phuc thu nhat: " << endl;
	sp1.Nhap();
	cout << "Nhap so phuc thu hai: " << endl;
	sp2.Nhap();
	cout << "Tong hai so phuc: ";
	sp1.Cong(sp2).Xuat();
	cout << "Hieu hai so phuc: ";
	sp1.Tru(sp2).Xuat();
	cout << "Tich hai so phuc: ";
	sp1.Nhan(sp2).Xuat();
	cout << "Thuong hai so phuc: ";
	sp1.Chia(sp2).Xuat();
	return 0;
}