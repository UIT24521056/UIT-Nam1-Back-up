#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
//------------------ClassNguoi--------------------//
class ngSoHuu
{
private:
	string name;
	string birth;
	int id;
	string diaChiThuongTru;
public:
	ngSoHuu(string name, string birth, int id, string diaChiThuongTru){
		this->name = name;
		this->birth = birth;
		this->id = id;
		this->diaChiThuongTru = diaChiThuongTru;
	}
	string getName() {
		return this->name;
	}
	string getBirth() {
		return this->birth;
	}
	int getID() {
		return this->id;
	}
	string getDiaChiThuongTru() {
		return this->diaChiThuongTru;
	}
	virtual ~ngSoHuu() {}
};
//------------------ClassDatO--------------------//
class thongTinDatO : public ngSoHuu
{
private:
	string soGCN;
	int soThua;
	int soMap;
	double dienTich;
	int thueDat;
	string diaChiDat;
	int tongThue;
public:
	thongTinDatO(string name, string birth, int id, string diaChiThuongTru, string soGCN, int soThua, int soMap, double dienTich, int thueDat, string diaChiDat) : ngSoHuu(name, birth, id, diaChiThuongTru) {
		this->soGCN = soGCN;
		this->soThua = soThua;
		this->soMap = soMap;
		this->dienTich = dienTich;
		this->thueDat = thueDat;
		this->diaChiDat = diaChiDat;
		this->tongThue = thueDat * dienTich;
	}
	int getTongThue() {
		return this->tongThue;
	}
	virtual void inThongTin();
	virtual void inTongThue();
	virtual ~thongTinDatO() {}
};
//-hamtt-//
void thongTinDatO::inThongTin() {
	cout << "Ten: " << getName() << " | ";
	cout << "Ngay Sinh: " << getBirth() << " | ";
	cout << "CMND: " << getID() << " | ";
	cout << "Dia Chi Thuong Tru: " << getDiaChiThuongTru() << " | ";
	cout << "So GCN: " << soGCN << " | ";
	cout << "So Thua: " << soThua << " | ";
	cout << "So Ban Do: " << soMap << " | ";
	cout << "Dien Tich: " << dienTich << "m2 | ";
	cout << "Thue Dat: " << thueDat << "dong/m2 | ";
	cout << "Dia Chi Dat: " << diaChiDat;
}

void thongTinDatO::inTongThue() {
	cout << "Tong Thue Dat phai tra: " << tongThue << "dong" << endl;
}
//------------------ClassDatNN--------------------//
class thongTinDatNN : public thongTinDatO
{
private:
	int thoiHanSD;
public:
	thongTinDatNN(string name, string birth, int id, string diaChiThuongTru, string soGCN, int soThua, int soMap, double dienTich, int thueDat, string diaChiDat, int thoiHanSD) : thongTinDatO(name, birth, id, diaChiThuongTru, soGCN, soThua, soMap, dienTich, thueDat, diaChiDat) {
		this->thoiHanSD = thoiHanSD;
	}
	int getThoiHanSD() {
		return this->thoiHanSD;
	}
	void inThongTin() override;
	void inTongThue() override;
	virtual ~thongTinDatNN(){}
};
//-hamtt-//
void thongTinDatNN::inThongTin() {
	thongTinDatO::inThongTin();
	cout << " | Thoi Han Su Dung: den nam " << thoiHanSD;
}
void thongTinDatNN::inTongThue() {
	thongTinDatO::inTongThue();
}
//------------------Hambinhthuong--------------------//
void chucNang(int& n) {
	cout << "vui long chon mot chuc nang:\n";
	cout << "1. Xuat danh sach day chung nhan\n";
	cout << "2. In tien thue nguoi su dung dat phai dong, xuat thong tin manh dat co thue cao nhat\n";
	cout << "3. In thong tin dat nong nghiep da het han su dung\n";
	cout << "0. Thoat\n";
	bool inacp = true;
	do{
	cin >> n;
	if (n<0 || n>3) {
		cout << "Chuc nang khong hop le, vui long chon lai\n";
	}
	else {
		inacp = false;
	}
	} while (inacp);
}
void xuatDanhSach(thongTinDatO* dsTT[], int n) {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". ";
		dsTT[i]->inThongTin();
		cout << endl;
	}
}
void danhSachThue(thongTinDatO* dsTT[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Ten: " << dsTT[i]->getName() << " | ";
		cout << "Tong tien thue phai dong: " << dsTT[i]->getTongThue() << endl;
	}
}

void thueMax(thongTinDatO* dsTT[], int n) {
	int max = dsTT[0]->getTongThue();
	int ttmax = 0;
	for (int i = 1; i < n; i++) {
		if (dsTT[i]->getTongThue() > max) {
			max = dsTT[i]->getTongThue();
			ttmax = i;
		}
	}
	cout << "Thue Dat cao nhat: " << max << " thuoc ve ";
	dsTT[ttmax]->inThongTin();
}

void danhSachHetHan(thongTinDatO* dsTT[], int n, int year) {
	bool hsd = true;
	for (int i = 0; i < n; i++) {
		thongTinDatNN* datNN = dynamic_cast<thongTinDatNN*>(dsTT[i]);
			int k = 1;
			if (datNN->getThoiHanSD() < year) {
				cout << k << ". ";
				datNN->inThongTin();
				cout << endl;
				k++;
				hsd = false;
			}
	}
	if (hsd) {
		cout << "Khong co dat nong nghiep nao da het han su dung\n";
	}
}
//--------------------------------------Main----------------------------------------//
int main(){
	int n;
	thongTinDatO* dsTT[6];
	dsTT[0] = new thongTinDatO("Nguyen Van A", "01/01/1990", 123456789, "Ha Noi", "GCN001", 1, 1, 100.0, 50000, "Ha Noi");
	dsTT[1] = new thongTinDatO("Nguyen Van B", "02/02/1991", 987654321, "Hai Phong", "GCN002", 2, 2, 200.1, 60000, "Hai Phong");
	dsTT[2] = new thongTinDatNN("Nguyen Van C", "03/03/1992", 123456789, "Da Nang", "GCN003", 3, 3, 300.2, 70000, "Da Nang", 2026);
	dsTT[3] = new thongTinDatNN("Nguyen Van D", "04/04/1993", 987654321, "Nha Trang", "GCN004", 4, 4, 400.3, 80000, "Nha Trang", 2015);
	dsTT[4] = new thongTinDatNN("Nguyen Van E", "05/05/1994", 123456789, "Can Tho", "GCN005", 5, 5, 500.4, 90000, "Can Tho", 2024);
	dsTT[5] = new thongTinDatNN("Nguyen Van F", "06/06/1995", 987654321, "Vung Tau", "GCN006", 6, 6, 600.5, 100000, "Vung Tau", 2023);
	chucNang(n);
	switch (n) {
	case 1:
		cout << "Danh sach giay chung nhan:\n";
		xuatDanhSach(dsTT, 6);
		break;
	case 2:
		cout << "Danh sach thue dat phai dong:\n";
		danhSachThue(dsTT, 6);
		thueMax(dsTT, 6);
		break;
	case 3:
		int year;
		cout << "Nam hien tai la:"; cin >> year;
		cout << "Danh sach dat nong nghiep da het han su dung:\n";
		danhSachHetHan(dsTT, 6, year);
		break;
	case 0:
		cout << "Cam on ban da su dung chuong trinh\n";
		break;
	default:
		break;
	}
	for (int i = 0; i < 6; i++) {
		delete dsTT[i];
	}
	return 0;
}
