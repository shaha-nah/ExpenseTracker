#pragma once
#include "Customer.h"
#include "WaterElectricity.h"
#include "Telephone.h"
#include "Entertainment.h"
#include <iostream>
class filemanip
{
public:
	filemanip();
	void CreateCustomerFile();
	void CreateWaterFile();
	void CreateElectricityFile();
	void CreateTelephoneFile();
	void CreateEntertainmentFile();
	void CreateLoginFile();
	bool check(int acn);
	bool checkpw(int acn, string pwd);
	void SignUp();
	void Login();
	void Menu(int acn);
	void OutputOneCustomer(int acn);
	void ModifyPassword(int acn);
	void ModifyPhoneNumber(int acn);
	void ModifyAddress(int acn);
	void ModifyName(int acn);
	void ModifyEmail(int acn);
	void ModifyCustomer(int acn);
	void DeleteFromLoginFile(int acn);
	void DeleteFromCustomerFile(int acn);
	void DeleteFromWaterFile(int acn);
	void DeleteFromElectricityFile(int acn);
	void DeleteFromTelephoneFile(int acn);
	void DeleteFromEntertainmentFile(int acn);
	void DeleteCustomer(int acn);
	int ChooseBill();
	void InputBillDetails(int ac);
	void InputWaterElectricityBillDetails(string filename, int ac, string bd, int mon, int bn, int sn, double sc, double rate);
	void InputTelephoneDetails(int ac, string bd, int mon, int bn, int sn, double sc);
	void InputEntertainmentDetails(int ac, string bd, int mon, int bn, int sn, double sc);
	void OutputCustomerDetailsInBills(int acn);
	void OutputOneBill(int ac, int mth);
	void OutputAllBills(int ac);
	void OutputOneWaterElectricityBill(string filename, int acn, int mth);
	void OutputOneTelephoneBill(int acn, int mth);
	void OutputOneEntertainmentBill(int acn, int mth);
	double GetWaterElectricityExpense(string filename, int acn, int mth);
	double GetTelephoneEntertainmentExpense(string filename, int acn, int mth);
	void TotalMonthlyExpense(int acn);
	void CalculateTotal(int acn);
	~filemanip();
};