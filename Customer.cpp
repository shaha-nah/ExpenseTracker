#include "Customer.h"
Customer::Customer(){
}
Customer::Customer(int ac, string n, string e, string add, int num) {
	accNumber = ac;
	name = n;
	email = e;
	address = add;
	phoneNumber = num;
}
int Customer::getAccNumber() {
	return accNumber;
}
void Customer::setAccNumber(int ac) {
	accNumber = ac;
}
string Customer::getName() {
	return name;
}
void Customer::setName(string n) {
	name = n;
}
string Customer::getEmail() {
	return email;
}
void Customer::setEmail(string e) {
	email = e;
}
string Customer::getAddress() {
	return address;
}
void Customer::setAddress(string add) {
	address = add;
}
int Customer::getPhoneNumber() {
	return phoneNumber;
}
void Customer::setPhoneNumber(int num) {
	phoneNumber = num;
}
void Customer::inputc(int ac, string n, string e, string add, int num) {
	ofstream fo;
	fo.open("Customer.txt", ios::app);
	fo << ac << "\t" << "\t" << n << "\t" << e << "\t" << add << "\t" << num << "\n";
	fo.close();
}
Customer::~Customer(){
}