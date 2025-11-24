//Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.
#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
};

int UCLN(int a, int b) {
    if (a == 0) {
        return 1;
    }
    else {
        while (a != b) {
            if (b > a) {
                b -= a;
            }
            else {
                a -= b;
            }
        }
        return a;
    }
}

PhanSo rg(PhanSo a) {
    PhanSo temp;
    int ucln = UCLN(a.tu, a.mau);
    temp.tu = a.tu / ucln;
    temp.mau = a.mau / ucln;
    return temp;
}
int main()
{
    PhanSo a;
    cout << "nhap tu so: ";
    cin >> a.tu;
    cout << "nhap mau so: ";
    cin >> a.mau;
    cout << "rut gon:" << rg(a).tu << '/' << rg(a).mau;
}