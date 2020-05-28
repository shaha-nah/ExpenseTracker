#include "WaterElectricity.h"
WaterElectricity::WaterElectricity(){
}
WaterElectricity::WaterElectricity(int ac, string n, string e, string add, int num, string bd, int mon, int bn, int sn, double sc, int me, double cme, double pme) {
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
	meter = me;
	currentMeter = cme;
	previousMeter = pme;
}
int WaterElectricity::getMeter(){
	return meter;
}
void WaterElectricity::setMeter(int me) {
	meter = me;
}
double WaterElectricity::getCurrentMeter(){
	return currentMeter;
}
void WaterElectricity::setCurrentMeter(double cme) {
	currentMeter = cme;
}
double WaterElectricity::getPreviousMeter(){
	return previousMeter;
}
void WaterElectricity::setPreviousMeter(double pme) {
	previousMeter = pme;
}
double WaterElectricity::usage(double cme, double pme) {
	return cme - pme;
}
double WaterElectricity::calculateAmountDue(double cme, double pme,double rate) {
	return rate * (cme - pme);
}
void WaterElectricity::inputwe(string filename, int ac, string bd, int mon, int bn, int sn, double sc, int me, double cme, double pme, double usage, double amountDue) {
	ofstream fo;
	fo.open(filename,ios::app);
	fo << ac << "\t"  << bd << "\t" << mon << "\t" << bn << "\t" << sn << "\t" << sc << "\t" << me << "\t" << cme << "\t" << pme << "\t" << usage << "\t" << amountDue << "\n";
	fo.close();
}
WaterElectricity::~WaterElectricity(){
}