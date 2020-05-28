#include "Entertainment.h"
Entertainment::Entertainment(){
}
Entertainment::Entertainment(int ac, string n, string e, string add, int num, string bd, int mon, int bn, int sn, double sc, double in, double cab, double wir) {
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
	internet = in;
	cableTv = cab;
	wireless = wir;
}
double Entertainment::getInternet(){
	return internet;
}
void Entertainment::setInternet(double in){
	internet = in;
}
double Entertainment::getCableTv(){
	return cableTv;
}
void Entertainment::setCableTv(double cab){
	cableTv = cab;
}
double Entertainment::getWireless(){
	return wireless;
}
void Entertainment::setWireless(double wir){
	wireless = wir;
}
double Entertainment::calculateAmountDue(double in, double cab, double wir) {
	return in + cab + wir;
}
void Entertainment::inpute(int ac, string bd, int mon, int bn, int sn, double sc, double in, double cab, double wir, double amtdue) {
	ofstream fo;
	fo.open("Entertainment.txt", ios::app);
	fo << ac << "\t" << bd << "\t" << mon << "\t" << bn << "\t" << sn << "\t\t" << sc << "\t" << in << "\t" << cab << "\t" << wir << "\t" << amtdue << "\n";
	fo.close();
}
Entertainment::~Entertainment(){
}