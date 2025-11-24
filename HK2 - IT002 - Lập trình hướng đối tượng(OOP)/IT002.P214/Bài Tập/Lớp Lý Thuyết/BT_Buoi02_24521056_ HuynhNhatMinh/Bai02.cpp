/**Cài đặt lớp biểu diễn khái niệm điểm trong mặt phẳng với hai thành phần dữ liệu hoành độ và tung độ với các phương 
thức thiết lập, các hàm thành phần cho phép thay đổi nội dung của điểm, lấy hoành độ, tung độ, thay đổi hoành độ, tung 
độ, tịnh tiến, nhập, xuất một điểm.**/

#include <iostream>
using namespace std;

class toaDoDiem
{ 
private:
    double hoanhDo, tungDo ;
public:
    toaDoDiem(double x = 0, double y = 0)
    {
        hoanhDo = x;
        tungDo = y;
    }
    void Nhap();
    void Xuat();
	toaDoDiem tinhTien(double x, double y);
};
void toaDoDiem::Nhap()
{
	cout << "Nhap hoanh do: ";
	cin >> hoanhDo;
	cout << "Nhap tung do: ";
	cin >> tungDo;
}
toaDoDiem toaDoDiem::tinhTien(double x, double y)
{
	toaDoDiem temp(hoanhDo , tungDo);
	temp.hoanhDo += x;
	temp.tungDo += y;
	return temp;
}
void toaDoDiem::Xuat()
{
	cout << "Toa do diem sau khi tinh tien la: (" << hoanhDo << ", " << tungDo << ")" << endl;
}
int main()
{
	toaDoDiem diemBanDau;
	diemBanDau.Nhap();
	double ttx, tty;
	cout << "Nhap tien do tinh tien theo hoanh do: ";
	cin >> ttx;
	cout << "Nhap tien do tinh tien theo tung do: ";
	cin >> tty;
	toaDoDiem diemLucSau = diemBanDau.tinhTien(ttx , tty);
	diemLucSau.Xuat();
	return 0;
}

