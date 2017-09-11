#include "PrivateGiroAccount.h"
#include "TransactionsGenerator.h"
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

PrivateGiroAccount::PrivateGiroAccount(int accountNumber)
{
	accountType = "private";
	this->accountNumber = accountNumber;
}

PrivateGiroAccount::PrivateGiroAccount(int accountNumber, float accountBalance)
{
	accountType = "private";
	this->accountNumber = accountNumber;
	this->accountBalance = accountBalance;
}

PrivateGiroAccount::~PrivateGiroAccount()
{
}

void PrivateGiroAccount::add_transaction(float amount)
{
	time_t rawtime;
	time(&rawtime);
	string time = ctime(&rawtime);
	time = time.substr(0, 24);

	accountBalance += amount;

	string transactionId = TransactionsGenerator::generateID();

	Transaction* newTransaction = new Transaction(time, amount, transactionId);
	execute_transaction(newTransaction);
}

void PrivateGiroAccount::print()
{
	cout << "Giro account: " << accountType << endl;
	cout << "Account number: " << accountNumber << endl;
	cout << "Account balance: " << accountBalance << endl;
}