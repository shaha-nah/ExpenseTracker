#pragma once
#include "Customer.h"
class Bill:public Customer
{
protected:
	ofstream bo;
	ifstream bi;
	string billingDate;
	int month;
	int billNumber;
	int serialNumber;
	double surcharge;
public:
	Bill();
	Bill(int ac, string n, string e, string add, int num, string bd, int mon, int bn, int sn, double sc);
	string getBillingDate();
	void setBillingDate(string bd);
	int getMonth();
	void setMonth(int mon);
	int getBillNumber();
	void setBillNumber(int bn);
	int getSerialNumber();
	void setSerialNumber(int sn);
	double getSurcharge();
	void setSurcharge(double sc);
	virtual double calculateAmountDue(double x,double y,double z) = 0;
	~Bill();
};