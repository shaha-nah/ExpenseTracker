#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Customer
{
protected:
	int accNumber;
	string name;
	string email;
	string address;
	int phoneNumber;
public:
	Customer();
	Customer(int ac, string n, string e, string add, int num);
	int getAccNumber();
	void setAccNumber(int ac);
	string getName();
	void setName(string n);
	string getEmail();
	void setEmail(string e);
	string getAddress();
	void setAddress(string add);
	int getPhoneNumber();
	void setPhoneNumber(int num);
	void inputc(int ac, string n, string e, string add, int num);
	~Customer();
};