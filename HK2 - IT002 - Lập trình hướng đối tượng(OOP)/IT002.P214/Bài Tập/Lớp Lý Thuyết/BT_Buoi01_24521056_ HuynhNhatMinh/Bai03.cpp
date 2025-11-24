//Viết chương trình nhập vào hai phân số.
// Tính tổng, hiệu, tích, thương giữa chúng
//và xuất kết quả.
#include <iostream>
using namespace std;

struct PhanSo {
    int tuSo, mauSo;
};

PhanSo operator +(PhanSo a, PhanSo b) {
    PhanSo temp;
    temp.tuSo = a.tuSo * b.mauSo + a.mauSo * b.tuSo;
    temp.mauSo = a.mauSo * b.mauSo;
    return temp;
}
PhanSo operator -(PhanSo a, PhanSo b) {
    PhanSo temp;
    temp.tuSo = a.tuSo * b.mauSo - a.mauSo * b.tuSo;
    temp.mauSo = a.mauSo * b.mauSo;
    return temp;
}
PhanSo operator *(PhanSo a, PhanSo b) {
    PhanSo temp;
    temp.tuSo = a.tuSo * b.tuSo;
    temp.mauSo = a.mauSo * b.mauSo;
    return temp;
}
PhanSo operator /(PhanSo a, PhanSo b) {
    PhanSo temp;
    temp.tuSo = a.tuSo * b.mauSo;
    temp.mauSo = a.mauSo * b.tuSo;
    return temp;
}
int main() {
    PhanSo p1, p2, p3;
    cout << "Nhap tu so p1: "; cin >> p1.tuSo;
    cout << "Nhap mau so p1: "; cin >> p1.mauSo;
    cout << "Nhap tu so p2: "; cin >> p2.tuSo;
    cout << "Nhap mau so p2: "; cin >> p2.mauSo;
    p3 = p1 + p2;
    cout << "tong: " << p3.tuSo << "/" << p3.mauSo << endl;
    p3 = p1 - p2;
    cout << "hieu: " << p3.tuSo << "/" << p3.mauSo << endl;
    p3 = p1 * p2;
    cout << "tich: " << p3.tuSo << "/" << p3.mauSo << endl;
    p3 = p1 / p2;
    cout << "thuong: " << p3.tuSo << "/" << p3.mauSo << endl;
}