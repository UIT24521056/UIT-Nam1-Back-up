#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PhuongTien {
private:
	string tuyen;
	int thoigianHoatDong;
	int soHanhKhach;
	int phanLoai;
public:
	PhuongTien(string a = '', int b = 0, int c = 0) {
		tuyen = a;
		thoigianHoatDong = b;
		soHanhKhach = c;
	}
	int getSoHanhKhach();
	int getThoiGianHoatDong();
	int phanLoai();
	void nhapPT();
	void xuatPT();
	~PhuongTien(){}
};

int PhuongTien::getSoHanhKhach() {
	return this->soHanhKhach;
}
int PhuongTien::getThoiGianHoatDong() {
	return this->thoigianHoatDong;
}
int PhuongTien::phanLoai() {
	if (this->thoigianHoatDong < 180) {
		return 1;
	}
	else if (this->thoigianHoatDong >= 360) {
		return 3;
	}
	else {
		return 2;
	}
}
void PhuongTien::nhapPT() {
	cout << "nhap ten tuyen:";
	getline(cin, tuyen);
	cin.ignore();
	cout << "nhap thoi gian hoat dong:"; cin << this->thoigianHoatDong;
	cout << "nhap so hanh khach:"; cin << this->soHanhKhach;
}
void PhuongTien::xuatPT() {
	cout << "Ten tuyen :" << tuyen << '|';
	cout << "Thoi gian hoat dong :" << thoigianHoatDong << '|';
	cout << "So hanh khach :" << soHanhKhach << '|';
}