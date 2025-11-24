//Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.
#include <iostream>
using namespace std;
struct Date
{
	int day;
	int month;
	int year;
};
bool checkLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	return false;
}
int main()
{
	Date date;
	cout << "Nhap ngay: ";
	cin >> date.day;
	cout << "Nhap thang: ";
	cin >> date.month;
	cout << "Nhap nam: ";
	cin >> date.year;
	if (date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12)
	{
		cout << "Ngay thang khong hop le!";
		return 0;
	}
	if (date.month == 2)
	{
		if (checkLeapYear(date.year))
		{
			if (date.day > 29)
			{
				cout << "Ngay thang khong hop le!";
				return 0;
			}
			else {
				if (date.day == 29)
				{
					date.day = 1;
					date.month++;
				}
				else
				{
					date.day++;
				}
			}
		}
		else
		{
			if (date.day > 28)
			{
				cout << "Ngay thang khong hop le!";
				return 0;
			}
			else {
				if (date.day == 28)
				{
					date.day = 1;
					date.month++;
				}
				else
				{
					date.day++;
				}
			}
		}
	}
	else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
	{
		if (date.day > 30)
		{
			cout << "Ngay thang khong hop le!";
			return 0;
		}
		else {
			if (date.day == 30)
			{
				date.day = 1;
				date.month++;
			}
			else
			{
				date.day++;
			}
		}
	}
	else
	{
		if (date.day > 31)
		{
			cout << "Ngay thang khong hop le!";
			return 0;
		}
		else {
			if (date.day == 31)
			{
				date.day = 1;
				date.month++;
			}
			else
			{
				date.day++;
			}
		}
	}
	cout << "Ngay tiep theo la: " << date.day << "/" << date.month << "/" << date.year;
	return 0;
}
