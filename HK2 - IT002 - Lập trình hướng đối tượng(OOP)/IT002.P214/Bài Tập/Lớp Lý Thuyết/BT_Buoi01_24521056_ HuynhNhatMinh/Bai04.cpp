/**Viết chương trình cho phép người dùng nhập vào một dãy gồm n phân số.
Tìm và xuất ra màn hình phân số lớn nhất. Sắp xếp dãy phân số tăng dần/giảm dần.**/

#include <iostream>
using namespace std;
#define MAX 100

struct PhanSo
{
	int tu;
	int mau;
};

void NhapPhanSo(PhanSo a[], int &triSoPhanTuCuoi)
{
	int i = 0;
	do 
	{
		cout << "Nhap tu so (neu khong co gi, nhan enter): ";
		if (cin.peek() == '\n') 
		{
			break;
		}
		cin >> a[i].tu;
		cout << "Nhap mau so: ";
		cin >> a[i].mau;
		i++;
		if (i == MAX) 
		{
			break;
		}
		cin.ignore();
	}while (true);
	triSoPhanTuCuoi = i;
}

void XuatPhanSoTang(PhanSo a[], int triSoPhanTuCuoi)
{
	for (int i = 0; i < triSoPhanTuCuoi; i++)
	{
		cout << a[i].tu << "/" << a[i].mau << "; ";
	}
}
void XuatPhanSoGiam(PhanSo a[], int triSoPhanTuCuoi)
{
	for (int i = triSoPhanTuCuoi - 1; i >= 0; i--)
	{
		cout << a[i].tu << "/" << a[i].mau << "; ";
	}
}

void sapXep(PhanSo a[], int triSoPhanTuCuoi)
{
	for (int i = 0; i < triSoPhanTuCuoi - 1; i++)
	{
		for (int j = i + 1; j < triSoPhanTuCuoi; j++)
		{
			if (a[i].tu * a[i].mau > a[j].tu * a[j].mau)
			{
				PhanSo soTruoc = a[i];
				a[i] = a[j];
				a[j] = soTruoc;
			}
		}
	}
}

int main()
{
	PhanSo a[MAX];
	int triSoPhanTuCuoi;
	cout << "Nhap toi da "<< MAX<<" phan so" << endl;
	NhapPhanSo(a, triSoPhanTuCuoi);
	sapXep(a, triSoPhanTuCuoi);
	cout << "Phan so lon nhat la: " << a[triSoPhanTuCuoi-1].tu << "/" << a[triSoPhanTuCuoi-1].mau << endl;
	cout << "Day phan so tang dan: ";
	XuatPhanSoTang(a, triSoPhanTuCuoi);
	cout << endl;
	cout << "Day phan so giam dan: ";
	XuatPhanSoGiam(a, triSoPhanTuCuoi);
	return 0;
}