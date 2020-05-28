#pragma once
#include "Bill.h"
class Telephone:public Bill
{
	double serviceCharge;
	double localCalls;
	double longDistanceCalls;
public:
	Telephone();
	Telephone(int ac, string n, string e, string add, int num, string bd, int mon, int bn, int sn, double sc, double sch, double lc, double ldc);
	double getServiceCharge();
	void setServiceCharge(double sch);
	double getLocalCalls();
	void setLocalCalls(double lc);
	double getLongDistanceCalls();
	void setLongDistanceCalls(double ldc);
	double calculateAmountDue(double sch, double lc, double ldc);
	void inputt(int ac, string bd, int mon, int bn, int sn, double sc, double sch, double lc, double ldc, double amtdue);
	~Telephone();
};