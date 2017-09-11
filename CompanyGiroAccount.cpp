#include "CompanyGiroAccount.h"
#include "TransactionsGenerator.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

CompanyGiroAccount::CompanyGiroAccount(int kontonumber)
{
	accountType = "company";
	this->accountNumber = kontonumber;
}

CompanyGiroAccount::CompanyGiroAccount(int kontonumber, float kontobalance)
{
	accountType = "company";
	this->accountNumber = kontonumber;
	this->accountBalance = kontobalance;
}

CompanyGiroAccount::~CompanyGiroAccount()
{
}

void CompanyGiroAccount::add_transaction(float amount)
{
	time_t rawtime;
	time(&rawtime);
	string time = ctime(&rawtime);
	time = time.substr(0, 24);
	float charge;
	charge = amount * 0.002;
	if (charge < 0.1)
		charge = 0.1;
	amount -= charge;
	accountBalance += amount;

	string transaktion_id = TransactionsGenerator::generateID();

	Transaction* new_transaktion = new Transaction(time, amount, charge, transaktion_id);
	execute_transaction(new_transaktion);
}

void CompanyGiroAccount::print()
{
	cout << "Giro account: " << accountType << endl;
	cout << "Account number: " << accountNumber << endl;
	cout << "Account balance: " << accountBalance << endl;
}