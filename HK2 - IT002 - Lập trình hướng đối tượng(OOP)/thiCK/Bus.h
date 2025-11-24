#pragma once
#include "phuongtien.h"

class Bus : public PhuongTien {
private:
	int soTuyenPhu;
public:
	Bus(int a=0){
		soTuyenPhu = a;
	}
	int busPriority();
	void nhapBus();
	~Bus()
};

int Bus::busPriority() {
	if (soTuyenPhu >= 2) {
		return (getSoHanhKhach() + soTuyenPhu * 10);
	}else{
		return (getSoHanhKhach() + soTuyenPhu * 5);
	}
}
void Bus::nhapBus() {
	PhuongTien::nhapPT();
	cout << "nhap so tuyen phu:"; cin << this->soTuyenPhu;
}
