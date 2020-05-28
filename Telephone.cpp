#include "Telephone.h"
Telephone::Telephone() {
}
Telephone::Telephone(int ac, string n, string e, string add, int num, string bd, int mon, int bn, int sn, double sc, double sch, double lc, double ldc) {
	accNumber = ac;
	name = n;
	email = e;
	address = add;
	phoneNumber = num;
	billingDate = bd;
	month = mon;
	billNumber = bn;
	serialNumber = sn;
	surcharge = sc;
	serviceCharge = sch;
	localCalls = lc;
	longDistanceCalls = ldc;
}
double Telephone::getServiceCharge() {
	return serviceCharge;
}
void Telephone::setServiceCharge(double sch) {
	serviceCharge = sch;
}
double Telephone::getLocalCalls() {
	return localCalls;
}
void Telephone::setLocalCalls(double lc) {
	localCalls = lc;
}
double Telephone::getLongDistanceCalls() {
	return longDistanceCalls;
}
void Telephone::setLongDistanceCalls(double ldc) {
	longDistanceCalls = ldc;
}
double Telephone::calculateAmountDue(double sch, double lc, double ldc) {
	return sch + lc + ldc;
}
void Telephone::inputt(int ac, string bd, int mon, int bn, int sn, double sc, double sch, double lc, double ldc, double amtdue) {
	ofstream fo;
	fo.open("Telephone.txt", ios::app);
	fo << ac << "\t" << bd << "\t" << mon << "\t" << bn << "\t" << sn << "\t" << sc << "\t" << sch << "\t" << lc << "\t" << ldc << "\t" << amtdue << "\n";
	fo.close();
}
Telephone::~Telephone(){
}