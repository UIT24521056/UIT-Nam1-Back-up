//Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính điểm trung bình và xuất kết quả.
#include <iostream>
#include <string>
using namespace std;
struct ttcn {
	string hoTen;
	double toan, van;
};
double diemTrungBinh(ttcn hs) {
	return (hs.toan + hs.van) / 2.0;
}
int main()
{
	ttcn hocSinhA;
	cout << "nhap ho ten: ";
	getline(cin, hocSinhA.hoTen);
	cout << "nhap diem toan: ";
	cin >> hocSinhA.toan;
	cout << "nhap diem van: ";
	cin >> hocSinhA.van;
	if (hocSinhA.toan < 0 || hocSinhA.toan > 10 || hocSinhA.van < 0 || hocSinhA.van > 10) {
		cout << "Diem khong hop le(0 <= diem <= 10)";
	}
	else {
		cout << "Diem trung binh cua hoc sinh " << hocSinhA.hoTen << " la " << diemTrungBinh(hocSinhA);
	}
}
