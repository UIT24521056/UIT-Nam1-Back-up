#pragma once
#include "phuongtien.h"

class Train : public PhuongTien{
private:
	bool coNhaVeSinh;
public:
	Train(bool a = false) {
		coNhaVeSinh = a;
	}
	double trainPriority();
	void nhapTrain();
	~Train(){}
};
double Train::trainPriority() {
	if (coNhaVeSinh) {
		return (getSoHanhKhach() + getThoiGianHoatDong() / 2);
	}
	else {
		return(getSoHanhKhach() + getThoiGianHoatDong() / 4);
	}
}
void Train::nhapTrain() {
	PhuongTien::nhapPT();
	int kt;
	cout << "neu co nha ve sinh, an phim 1, neu khong, an phim bat ky.";
	cin << kt;
	if (kt == 1) {
		this->coNhaVeSinh = true;
	}
}