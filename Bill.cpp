#include "Bill.h"
Bill::Bill(){
}
Bill::Bill(int ac, string n, string e, string add, int num, string bd, int mon, int bn, int sn, double sc) {
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
}
string Bill::getBillingDate() {
	return billingDate;
}
void Bill::setBillingDate(string bd) {
	billingDate = bd;
}
int Bill::getMonth() {
	return month;
}
void Bill::setMonth(int mon) {
	month = mon;
}
int Bill::getBillNumber() {
	return billNumber;
}
void Bill::setBillNumber(int bn) {
	billNumber = bn;
}
int Bill::getSerialNumber() {
	return serialNumber;
}
void Bill::setSerialNumber(int sn) {
	serialNumber = sn;
}
double Bill::getSurcharge() {
	return surcharge;
}
void Bill::setSurcharge(double sc) {
	surcharge = sc;
}
Bill::~Bill(){
}