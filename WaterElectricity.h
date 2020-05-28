#pragma once
#include "Bill.h"
class WaterElectricity:public Bill{
	int meter;
	double currentMeter;
	double previousMeter;
public:
	WaterElectricity();
	WaterElectricity(int ac, string n, string e, string add, int num, string bd, int mon, int bn, int sn, double sc, int me, double cme, double pme);
	int getMeter();
	void setMeter(int me);
	double getCurrentMeter();
	void setCurrentMeter(double cme);
	double getPreviousMeter();
	void setPreviousMeter(double pme);
	double usage(double cme, double pme);
	double calculateAmountDue(double cme, double pme,double rate);
	void inputwe(string filename, int ac, string bd, int mon, int bn, int sn, double sc, int me, double cme, double pme, double usage, double amountDue);
	~WaterElectricity();
};