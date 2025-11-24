/**Viết chương trình cho phép người dùng nhập vào danh sách học sinh(thông tin mỗi học sinh giống bài 5).
Tìm và xuất thông tin học sinh có điểm trung bình cao nhất, thấp nhất ra màn hình.**/
#include <iostream>
#include <string>
using namespace std;
#define MAX 100

struct hocSinh
{
	string hoTen;
	float diemToan = 0.0;
	float diemVan = 0.0;
	float diemAnh = 0.0;
	float trungBinh = 0.0;
};

struct minmax
{
	int ptmax, ptmin;
};

void nhapHS(hocSinh mangHS[],int &soHocSinh)
{
	int i = 0;
	while (true) 
	{
		cout<<"nhap ten hoc sinh(neu khong co gi nhan enter): ";
		if (cin.peek() == '\n')
		{
			break;
			cin.ignore();
		}
		getline(cin, mangHS[i].hoTen);
		cout << "Nhap diem Toan: ";
		cin >> mangHS[i].diemToan;

		cout << "Nhap diem Van: ";
		cin >> mangHS[i].diemVan;

		cout << "Nhap diem Anh: ";
		cin >> mangHS[i].diemAnh;
		mangHS[i].trungBinh = (mangHS[i].diemVan + mangHS[i].diemToan + mangHS[i].diemAnh) / 3;
		i++;
		cin.ignore();
		if (i == MAX)
		{
			break;
		}
	}
	soHocSinh = i;
}
minmax sapXepMinMax(hocSinh mangHS[], int &soHocSinh)
{
	minmax mm;
	float tbmax = 0, tbmin = 10;
	mm.ptmax = 0, mm.ptmin = 0;
	for (int i = 0; i < soHocSinh; i++)
	{
		if (mangHS[i].trungBinh > tbmax) 
		{
			tbmax = mangHS[i].trungBinh;
			mm.ptmax = i;
		}
		else if(mangHS[i].trungBinh < tbmin)
		{
			tbmin = mangHS[i].trungBinh;
			mm.ptmin = i;
		}
	}
	return mm;
}
int main()
{
	int soHocSinh = 0;
	hocSinh mangHS[MAX];
	nhapHS(mangHS, soHocSinh);
	int ptmax = sapXepMinMax(mangHS, soHocSinh).ptmax;
	int ptmin = sapXepMinMax(mangHS, soHocSinh).ptmin;
	cout << "Ten HS co diem TB cao nhat la: " << mangHS[ptmax].hoTen << '\n';
	cout << "Ten HS co diem TB thap nhat la: " << mangHS[ptmin].hoTen << '\n';
}