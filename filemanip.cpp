#include "filemanip.h"
#include <iostream>
//#include "Graph.h"
//Graph g;
ifstream fi,f;
ofstream fo;
filemanip::filemanip() {
}
void filemanip::CreateCustomerFile() {
	fo.open("Customer.txt");
	fo.close();
}
void filemanip::CreateWaterFile() {
	fo.open("Water.txt");
	fo.close();
}
void filemanip::CreateElectricityFile() {
	fo.open("Electricity.txt");
	fo.close();
}
void filemanip::CreateTelephoneFile() {
	fo.open("Telephone.txt");
	fo.close();
}
void filemanip::CreateEntertainmentFile() {
	fo.open("Entertainment.txt");
	fo.close();
}
void filemanip::CreateLoginFile() {
	fo.open("LoginFile.txt");
	fo.close();
}
bool filemanip::check(int acn) {
	int ac;
	string pw;
	bool exist;
	exist = false;
	fi.open("LoginFile.txt");
	while (fi >> ac >> pw) {
		if (acn == ac) {
			exist = true;
			break;
		}
	}
	fi.close();
	return exist;
}
bool filemanip::checkpw(int acn, string pwd) {
	int ac;
	string pw;
	bool correct;
	correct = false;
	fi.open("LoginFile.txt");
	while (fi >> ac >> pw) {
		if (ac == acn) {
			break;
		}
	}
	fi.close();
	if (pwd == pw) {
		correct = true;
	}
	return correct;
}
void filemanip::SignUp() {
	system("cls");
	Customer c;
	int ac, num;
	string pw, n, e, add;
	cout << "Enter an account number: ";
	cin >> ac;
	cin.ignore();
	if (!check(ac)) {
		cout << "Enter a password: ";
		getline(cin, pw);
		fo.open("LoginFile.txt", ios::app);
		fo << ac << "\t" << pw << "\n";
		fo.close();
		cout << "Enter name: ";
		getline(cin, n);
		c.setName(n);
		cout << "Enter email: ";
		getline(cin, e);
		c.setEmail(e);
		cout << "Enter town: ";
		getline(cin, add);
		c.setAddress(add);
		cout << "Enter phone number: ";
		cin >> num;
		cin.ignore();
		c.setPhoneNumber(num);
		c.inputc(ac, n, e, add, num);
	}
	else {
		cout << "Account number already exists.";
	}
}
void filemanip::Login() {
	system("cls");
	int ac, acf;
	string pw, pwf;
	bool success;
	success = false;
	cout << "Enter account number: ";
	cin >> ac;
	if (check(ac)) {
		cout << "Enter password: ";
		cin >> pw;
		if (checkpw(ac, pw)) {
			success = true;
		}
		if (success == true) {
			cout << "Login successful.";
			cin.get();

			Menu(ac);
		}
		else {
			cout << "Wrong Login.";
			cin.get();
		}
	}
	else {
		cout << "Account does not exist.";
		cin.get();
	}
}
void filemanip::Menu(int acn) {
	int choice, mth;
	do {
		system("cls");
		cout << "1. Display your details" << endl;
		cout << "2. Modify details" << endl;
		cout << "3. Delete account" << endl;
		cout << "4. Enter your bill details" << endl;
		cout << "5. Display a utility's bill for a month" << endl;
		cout << "6. Display all bills for a utility" << endl;
		cout << "7. Display total monthly expense" << endl;
		cout << "8. Generate a graph" << endl;
		cout << "9. Logout" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: OutputOneCustomer(acn);
			break;
		case 2: ModifyCustomer(acn);
			break;
		case 3: DeleteCustomer(acn);
			break;
		case 4: InputBillDetails(acn);
			break;
		case 5: cout << "Enter a month: ";
			cin >> mth;
			OutputOneBill(acn, mth);
			break;
		case 6: OutputAllBills(acn);
			break;
		case 7: TotalMonthlyExpense(acn);
			break;
		case 8: 
			break;
		case 9: break;
		}
		cin.get();
	} while (choice != 9);
}
void filemanip::OutputOneCustomer(int acn) {
	system("cls");
	int ac, num;
	string fn, ln, e, add;
	fi.open("Customer.txt");
	while (fi >> ac >> fn >> ln >> e >> add >> num) {
		if (acn == ac) {
			cout << "Account Number: " << ac << endl;
			cout << "Name: " << fn + " " + ln << endl;
			cout << "Email: " << e << endl;
			cout << "Town: " << add << endl;
			cout << "Phone number: " << num << endl;
			break;
		}
	}
	fi.close();
}
void filemanip::ModifyPassword(int acn) {
	string pw, opw, npw;
	cout << "Enter old password: ";
	cin >> opw;
	if (checkpw(acn,opw)) {
		cout << "Enter new password: ";
		cin >> npw;
		DeleteFromLoginFile(acn);
		fo.open("LoginFile.txt", ios::app);
		fo << acn << "\t" << npw << "\n";
		fo.close();
	}
	else {
		cout << "Incorect password";
	}
}
void filemanip::ModifyPhoneNumber(int acn) {
	int ac, num, nnum;
	string pw, fn, ln, e, add;
	cout << "Enter new phone number: ";
	cin >> nnum;
	cout << "Enter password: ";
	cin >> pw;
	fi.open("Customer.txt");
	while (fi >> ac >> fn >> ln >> e >> add >> num) {
		if (ac == acn) {
			break;
		}
	}
	fi.close();
	if (checkpw(ac, pw)) {
		DeleteFromCustomerFile(acn);
		fo.open("Customer.txt");
		fo << ac << "\t" << fn + " " + ln << "\t" << e << "\t" << add << "\t" << nnum << "\n";
		fo.close();
	}
}
void filemanip::ModifyAddress(int acn) {
	int ac, num;
	string nadd, pw, fn, ln, e, add;
	cout << "Enter new town: ";
	cin >> nadd;
	cout << "Enter password: ";
	cin >> pw;
	fi.open("Customer.txt");
	while (fi >> ac >> fn >> ln >> e >> add >> num) {
		if (ac == acn) {
			break;
		}
	}
	fi.close();
	if (checkpw(ac, pw)) {
		DeleteFromCustomerFile(acn);
		fo.open("Customer.txt");
		fo << ac << "\t" << fn + " " + ln << "\t" << e << "\t" << nadd << "\t" << num << "\n";
		fo.close();
	}
}
void filemanip::ModifyEmail(int acn) {
	int ac, num;
	string ne, pw, fn, ln, e, add;
	cout << "Enter new email: ";
	cin >> ne;
	cout << "Enter password: ";
	cin >> pw;
	fi.open("Customer.txt");
	while (fi >> ac >> fn >> ln >> e >> add >> num) {
		if (ac == acn) {
			break;
		}
	}
	fi.close();
	if (checkpw(ac, pw)) {
		DeleteFromCustomerFile(acn);
		fo.open("Customer.txt");
		fo << ac << "\t" << fn + " " + ln << "\t" << ne << "\t" << add << "\t" << num << "\n";
		fo.close();
	}
}
void filemanip::ModifyName(int acn) {
	int ac, num;
	string nfn, nln, pw, fn, ln, e, add;
	cout << "Enter new name: ";
	cin >> nfn;
	cin >> nln;
	cout << "Enter password: ";
	cin >> pw;
	fi.open("Customer.txt");
	while (fi >> ac >> fn >> ln >> e >> add >> num) {
		if (ac == acn) {
			break;
		}
	}
	fi.close();
	if (checkpw(ac, pw)) {
		DeleteFromCustomerFile(acn);
		fo.open("Customer.txt");
		fo << ac << "\t" << nfn + " " + nln << "\t" << e << "\t" << add << "\t" << num << "\n";
		fo.close();
	}
}
void filemanip::ModifyCustomer(int acn) {
	int choice, num;
	string n, e, ad;
	do {
		system("cls");
		cout << "1. Password" << endl;
		cout << "2. Name" << endl;
		cout << "3. Email" << endl;
		cout << "4. Town" << endl;
		cout << "5. Phone Number" << endl;
		cout << "6. Save changes" << endl;
		cout << endl;
		cout << "Enter choice: ";
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1:ModifyPassword(acn);
			break;
		case 2:ModifyName(acn);
			break;
		case 3: ModifyEmail(acn);
			break;
		case 4: ModifyAddress(acn);
			break;
		case 5: ModifyPhoneNumber(acn);
			break;
		case 6:
			break;
		}
	} while (choice != 6);
}
void filemanip::DeleteFromLoginFile(int acn) {
	int ac;
	string pw;
	fi.open("LoginFile.txt");
	fo.open("temp.txt");
	while (fi >> ac >> pw) {
		if (ac != acn) {
			fo << ac << "\t" << pw << "\n";
		}
	}
	fo.close();
	fi.close();
	remove("LoginFile.txt");
	rename("temp.txt", "LoginFile.txt");
}
void filemanip::DeleteFromCustomerFile(int acn) {
	int ac, num;
	string fn, ln, e, add;
	fi.open("Customer.txt");
	fo.open("temp.txt");
	while (fi >> ac >> fn >> ln >> e >> add >> num) {
		if (ac != acn) {
			fo << ac << "\t" << fn + " " + ln << "\t" << e << "\t" << add << "\t" << num << "\n";
		}
	}
	fo.close();
	fi.close();
	remove("Customer.txt");
	rename("temp.txt", "Customer.txt");
}
void filemanip::DeleteFromWaterFile(int acn) {
	int ac, num, mon, bn, sn, sc, me;
	string fn, ln, add, bd;
	double cme, pme, us, amtdue;
	fi.open("Water.txt");
	fo.open("temp.txt");
	while (fi >> ac >> fn >> ln >> add >> bd >> mon >> bn >> sn >> sc >> me >> cme >> pme >> us >> amtdue) {
		if (ac != acn) {
			fo << ac << "\t" << fn + " " + ln << "\t" << add << "\t" << bd << "\t" << mon << "\t" << bn << "\t" << sn << "\t" << sc << "\t" << me << "\t" << cme << "\t" << pme << "\t" << us << "\t" << amtdue << "\n";
		}
	}
	fo.close();
	fi.close();
	remove("Water.txt");
	rename("temp.txt", "Water.txt");
}
void filemanip::DeleteFromElectricityFile(int acn) {
	int ac, num, mon, bn, sn, sc, me;
	string fn, ln, add, bd;
	double cme, pme, us, amtdue;
	fi.open("Electricity.txt");
	fo.open("temp.txt");
	while (fi >> ac >> fn >> ln >> add >> bd >> mon >> bn >> sn >> sc >> me >> cme >> pme >> us >> amtdue) {
		if (ac != acn) {
			fo << ac << "\t" << fn + " " + ln << "\t" << add << "\t" << bd << "\t" << mon << "\t" << bn << "\t" << sn << "\t" << sc << "\t" << me << "\t" << cme << "\t" << pme << "\t" << us << "\t" << amtdue << "\n";
		}
	}
	fo.close();
	fi.close();
	remove("Electricity.txt");
	rename("temp.txt", "Electricity.txt");
}
void filemanip::DeleteFromTelephoneFile(int acn) {
	int ac, mon, bn, sn;
	double sc, sch, lc, ldc, amtdue;
	string fn, ln, add, bd;
	fi.open("Telephone.txt");
	fo.open("temp.txt");
	while (fi >> ac >> fn >> ln >> add >> bd >> mon >> bn >> sn >> sc >> sch >> lc >> ldc >> amtdue) {
		if (ac != acn) {
			fo << ac << "\t" << fn + " " + ln << "\t" << add << "\t" << bd << "\t" << mon << "\t" << bn << "\t" << sn << "\t" << sc << "\t" << sch << "\t" << lc << "\t" << ldc << "\t" << amtdue << "\n";
		}
	}
	fo.close();
	fi.close();
	remove("Telephone.txt");
	rename("temp.txt", "Telephone.txt");
}
void filemanip::DeleteFromEntertainmentFile(int acn) {
	int ac, mon, bn, sn;
	double sc, in, cab, wir, amtdue;
	string fn, ln, add, bd;
	fi.open("Entertainment.txt");
	fo.open("temp.txt");
	while (fi >> ac >> fn >> ln >> add >> bd >> mon >> bn >> sn >> sc >> in >> cab >> wir >> amtdue) {
		if (ac != acn) {
			fo << ac << "\t" << fn + " " + ln << "\t" << add << "\t" << bd << "\t" << mon << "\t" << bn << "\t" << sn << "\t" << sc << "\t" << in << "\t" << cab << "\t" << wir << "\t" << amtdue << "\n";
		}
	}
	fo.close();
	fi.close();
	remove("Entertainment.txt");
	rename("temp.txt", "Entertainment.txt");
}
void filemanip::DeleteCustomer(int acn) {
	string c;
	cout << "Do you want to delete your account?y/n" << endl;
	cin >> c;
	if (c == "y") {
		DeleteFromLoginFile(acn);
		DeleteFromCustomerFile(acn);
		DeleteFromWaterFile(acn);
		DeleteFromElectricityFile(acn);
		DeleteFromTelephoneFile(acn);
		DeleteFromEntertainmentFile(acn);
	}
}
int filemanip::ChooseBill() {
	int choice;
	cout << "Choose a bill" << endl;
	cout << "1. Water" << endl;
	cout << "2 .Electricity" << endl;
	cout << "3. Telephone " << endl;
	cout << "4. Entertainment" << endl;
	cout << "Enter choice: ";
	cin >> choice;
	return choice;
}
void filemanip::InputBillDetails(int ac) {
	int choice, num, acn, bn, sn, mon;
	string buffer, fn, ln, e, add, name, address, bd;
	double sc, rate;
	system("cls");
	cout << "Enter billing date: ";
	cin >> bd;
	cin.ignore();
	cout << "Enter month: ";
	cin >> mon;
	cin.ignore();
	cout << "Enter bill number: ";
	cin >> bn;
	cin.ignore();
	cout << "Enter serial number: ";
	cin >> sn;
	cin.ignore();
	cout << "Enter surcharge: ";
	cin >> sc;
	cin.ignore();
	choice = ChooseBill();
	switch (choice) {
	case 1: rate = 3;
		InputWaterElectricityBillDetails("Water.txt", ac, bd, mon, bn, sn, sc, rate);
		break;
	case 2: rate = 3.5;
		InputWaterElectricityBillDetails("Electricity.txt", ac, bd, mon, bn, sn, sc, rate);
		break;
	case 3: InputTelephoneDetails(ac, bd, mon, bn, sn, sc);
		break;
	case 4: InputEntertainmentDetails(ac, bd, mon, bn, sn, sc);
		break;
	case 5: break;
	}
}
void filemanip::InputWaterElectricityBillDetails(string filename, int ac, string bd, int mon, int bn, int sn, double sc, double rate) {
	int me;
	double cme, pme, us, amtdue;
	WaterElectricity we;
	we.setAccNumber(ac);
	we.setBillingDate(bd);
	we.setMonth(mon);
	we.setBillNumber(bn);
	we.setSerialNumber(sn);
	we.setSurcharge(sc);
	cout << "Enter meter serial number: ";
	cin >> me;
	cin.ignore();
	we.setMeter(me);
	cout << "Enter current meter read: ";
	cin >> cme;
	cin.ignore();
	we.setCurrentMeter(cme);
	cout << "Enter previous meter read: ";
	cin >> pme;
	cin.ignore();
	we.setPreviousMeter(pme);
	us = we.usage(cme, pme);
	amtdue = we.calculateAmountDue(cme, pme, rate);
	we.inputwe(filename, ac, bd, mon, bn, sn, sc, me, cme, pme, us, amtdue);
}
void filemanip::InputTelephoneDetails(int ac, string bd, int mon, int bn, int sn, double sc) {
	double sch, lc, ldc, amtdue;
	Telephone t;
	t.setAccNumber(ac);
	t.setBillingDate(bd);
	t.setMonth(mon);
	t.setBillNumber(bn);
	t.setSerialNumber(sn);
	t.setSurcharge(sc);
	cout << "Enter regular service charge: ";
	cin >> sch;
	cin.ignore();
	t.setServiceCharge(sch);
	cout << "Enter local call charge: ";
	cin >> lc;
	cin.ignore();
	t.setLocalCalls(lc);
	cout << "Enter long distance call charge: ";
	cin >> ldc;
	cin.ignore();
	t.setLongDistanceCalls(ldc);
	amtdue = t.calculateAmountDue(sch, lc, ldc);
	t.inputt(ac, bd, mon, bn, sn, sc, sch, lc, ldc, amtdue);
}
void filemanip::InputEntertainmentDetails(int ac, string bd, int mon, int bn, int sn, double sc) {
	double in, cab, wir, amtdue;
	Entertainment e;
	e.setAccNumber(ac);
	e.setBillingDate(bd);
	e.setMonth(mon);
	e.setBillNumber(bn);
	e.setSerialNumber(sn);
	e.setSurcharge(sc);
	cout << "Enter internet charge: ";
	cin >> in;
	cin.ignore();
	e.setInternet(in);
	cout << "Enter cable tv charge: ";
	cin >> cab;
	cin.ignore();
	e.setCableTv(cab);
	cout << "Enter wireless: ";
	cin >> wir;
	cin.ignore();
	e.setWireless(wir);
	amtdue = e.calculateAmountDue(in, cab, wir);
	e.inpute(ac, bd, mon, bn, sn, sc, in, cab, wir, amtdue);
}
void filemanip::OutputCustomerDetailsInBills(int acn){
	int ac, num, accnum;
	string fn, ln, e, add,name, email, address;
	f.open("Customer.txt");
	while (!f.eof()) {
		f >> ac >> fn >> ln >> e >> add >> num;
		if (ac == acn) {
			cout << "Account Number: " << ac << endl;
			cout << "Name: " << fn + " " + ln << endl;
			cout << "Address: " << add << endl;
			break;
		}
	}
	f.close();
}
void filemanip::OutputOneWaterElectricityBill(string filename, int acn, int mth) {
	int ac, mon, bn, sn, me;
	double sc, cme, pme, us, amtdue;
	string fn, ln, add, bd;
	fi.open(filename);
	while (fi >> ac >> bd >> mon >> bn >> sn >> sc >> me >> cme >> pme >> us >> amtdue) {
		if ((ac == acn) && (mon == mth)) {
			OutputCustomerDetailsInBills(acn);
			cout << "Billing Number: " << bd << endl;
			cout << "Service Number: " << sn << endl;
			cout << "Billing date: " << bd << endl;
			cout << "Month: " << mon << endl;
			cout << "Meter Number: " << me << endl;
			cout << "Previous Meter Reading: " << pme << endl;
			cout << "Current Meter Reading: " << cme << endl;
			cout << "Current Meter Reading: " << cme << endl;
			cout << "Usage: " << us << endl;
			cout << "Amount Due: " << amtdue << endl;
			cout << "Surcharge(if applicable): " << sc << endl;
			cout << endl;
			break;
		}
	}
	fi.close();
}
void filemanip::OutputOneTelephoneBill(int acn, int mth) {
	int ac, mon, bn, sn;
	double sc, sch, lc, ldc, amtdue;
	string fn, ln, add, bd;
	fi.open("Telephone.txt");
	while (fi >> ac >> bd >> mon >> bn >> sn >> sc >> sch >> lc >> ldc >> amtdue) {
		if ((acn == ac) && (mon == mth)) {
			OutputCustomerDetailsInBills(acn);
			cout << "Billing Number: " << bd << endl;
			cout << "Service Number: " << sn << endl;
			cout << "Billing date: " << bd << endl;
			cout << "Month: " << mon << endl;
			cout << "Regular Service Charge: " << sch << endl;
			cout << "Local Call Charge : " << lc << endl;
			cout << "Long Distance Call Charge: " << ldc << endl;
			cout << "Amount Due: " << amtdue << endl;
			cout << "Surcharge(if applicable): " << sc << endl;
			cout << endl;
			break;
		}
	}
	fi.close();
}
void filemanip::OutputOneEntertainmentBill(int acn, int mth) {
	int ac, mon, bn, sn;
	double sc, in, cab, wir, amtdue;
	string fn, ln, add, bd;
	fi.open("Entertainment.txt");
	while (fi >> ac >> bd >> mon >> bn >> sn >> sc >> in >> cab >> wir >> amtdue) {
		if ((acn == ac) && (mon == mth)) {
			OutputCustomerDetailsInBills(acn);
			cout << "Billing Number: " << bd << endl;
			cout << "Service Number: " << sn << endl;
			cout << "Billing date: " << bd << endl;
			cout << "Month: " << mon << endl;
			cout << "Internet Charge: " << in << endl;
			cout << "Cable TV Charge: " << cab << endl;
			cout << "Wireless Charge: " << wir << endl;
			cout << "Amount Due: " << amtdue << endl;
			cout << "Surcharge(if applicable): " << sc << endl;
			cout << endl;
			break;
		}
	}
	fi.close();
}
void filemanip::OutputOneBill(int ac, int mth) {
	int choice;
	string filename;
	system("cls");
	choice = ChooseBill();
	system("cls");
	switch (choice) {
	case 1: OutputOneWaterElectricityBill("Water.txt", ac, mth);
		break;
	case 2: OutputOneWaterElectricityBill("Electricity.txt", ac, mth);
		break;
	case 3: OutputOneTelephoneBill(ac, mth);
		break;
	case 4: OutputOneEntertainmentBill(ac, mth);
		break;
	}
}
void filemanip::OutputAllBills(int ac) {
	int choice;
	string filename;
	system("cls");
	choice = ChooseBill();
	system("cls");
	switch (choice) {
	case 1: for (int i = 1; i < 13; i++) {
		OutputOneWaterElectricityBill("Water.txt", ac, i);
	}
			break;
	case 2: for (int i = 1; i < 13; i++) {
		OutputOneWaterElectricityBill("Electricity.txt", ac, i);
	}
			break;
	case 3: for (int i = 1; i < 13; i++) {
		OutputOneTelephoneBill(ac, i);
	}
			break;
	case 4: for (int i = 1; i < 13; i++) {
		OutputOneEntertainmentBill(ac, i);
	}
			break;
	}
}
double filemanip::GetWaterElectricityExpense(string filename, int acn, int mth) {
	int ac, mon, bn, sn, me;
	double sc, cme, pme, us, amtdue;
	amtdue = 0;
	string bd;
	cout << "boo";
	fi.open(filename);
	while (fi >> ac >> bd >> mon >> bn >> sn >> sc >> me >> cme >> pme >> us >> amtdue) {
		if ((ac == acn) && (mon == mth)) {
			break;
		}
	}
	fi.close();
	return amtdue;
}
double filemanip::GetTelephoneEntertainmentExpense(string filename, int acn, int mth) {
	int ac, mon, bn, sn;
	double sc, x, y, z, amtdue;
	amtdue = 0;
	string bd;
	cout << "boo";
	fi.open(filename);
	while (fi >> ac >> bd >> mon >> bn >> sn >> sc >> x >> y >> z >> amtdue) {
		if ((acn == ac) && (mon == mth)) {
			break;
		}
	}
	fi.close();
	return amtdue;
}
void filemanip::TotalMonthlyExpense(int acn) {
	int mth;
	double wat, elec, tel, ent, total;
	total = 0;
	system("cls");
	cout << "Enter a month: ";
	cin >> mth;
	wat = GetWaterElectricityExpense("Water.txt", acn, mth);
	elec = GetWaterElectricityExpense("Electricity.txt", acn, mth);
	tel = GetTelephoneEntertainmentExpense("Telephone.txt", acn, mth);
	ent = GetTelephoneEntertainmentExpense("Entertainment.txt", acn, mth);
	total = wat + elec + tel + ent;
	system("cls");
	cout << "Water Expense :" << wat << endl;
	cout << "Electricity Expense: " << elec << endl;
	cout << "Telephone Expense: " << tel << endl;
	cout << "Entertainment Expense: " << ent << endl;
	cout << "Total Expense for month " << mth << " is: " << total << endl;
	cin.get();
}
void filemanip::CalculateTotal(int acn) {
	int mth;
	double wat, elec, tel, ent, total;
	for (mth = 1; mth < 13; mth++) {
		total = 0;
		wat = GetWaterElectricityExpense("Water.txt", acn, mth);
		elec = GetWaterElectricityExpense("Electricity.txt", acn, mth);
		tel = GetTelephoneEntertainmentExpense("Telephone.txt", acn, mth);
		ent = GetTelephoneEntertainmentExpense("Entertainment.txt", acn, mth);
		total = wat + elec + tel + ent;
		cout << "Total" << total << endl;
	}
	cin.get();
}
filemanip::~filemanip() {
}