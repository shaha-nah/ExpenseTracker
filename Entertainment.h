#pragma once
#include "Bill.h"
class Entertainment:public Bill
{
	double internet;
	double cableTv;
	double wireless;
public:
	Entertainment();
	Entertainment(int ac, string n, string e, string add, int num, string bd, int mon, int bn, int sn, double sc, double in, double cab, double wir);
	double getInternet();
	void setInternet(double in);
	double getCableTv();
	void setCableTv(double cab);
	double getWireless();
	void setWireless(double wir);
	double calculateAmountDue(double in, double cab, double wir);
	void inpute(int ac, string bd, int mon, int bn, int sn, double sc, double in, double cab, double wir, double amtdue);
	~Entertainment();
};