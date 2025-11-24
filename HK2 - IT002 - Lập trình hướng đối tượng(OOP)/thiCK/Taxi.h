#pragma once
#include "phuongtien.h"

class Taxi : public PhuongTien {
private:
	bool coDongHoTinhTien;
public:
	Taxi(bool a = false) {
		coDongHoTinhTien = a;
	}
	double taxiPriority();
	void nhapTaxi();
	~Taxi(){}
};

double Taxi::taxiPriority() {
	if (coDongHoTinhTien) {
		return (getSoHanhKhach() * 2);
	}
	else {
		return (getSoHanhKhach() * 1.2);
	}
}
void Taxi::nhapTaxi() {
	PhuongTien::nhapPT();
	int kt;
	cout << "neu co dong ho tinh tien, an phim 1, neu khong, an phim bat ky.";
	cin << kt;
	if (kt == 1) {
		this->coDongHoTinhTien = true;
	}
}