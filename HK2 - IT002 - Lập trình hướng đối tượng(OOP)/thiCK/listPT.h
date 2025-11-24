#pragma once
#include "Taxi.h"
#include "Train.h"
#include "Bus.h"

class lisPT {
private:
	vector<Taxi> taxiList;
	vector<Train> trainList;
	vector<Bus> busList;
public:
	int a;
	string b;
	cout << "nhap so luong xe:"; cin << a;
	for (int i = 0; i < a; i++) {
		getline(cin, b);
		cin.ignore();
		if (b == "Bus") {
			Bus bus;
			bus.nhapBus();
			busList.push_back(bus);
		}
		else if (b == "Train") {
			Train train;
			train.nhapTrain();
			trainList.push_back(train);
		}
		else if (b == "Taxi") {
			Taxi taxi;
			taxi.nhapTaxi();
			taxiList.push_back(taxi);
		}
	}
};