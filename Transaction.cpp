#include "Transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(string time, float amount, string transactionId)
{
	this->time = time;
	this->amount = amount;
	this->transactionId = transactionId;
}

Transaction::Transaction(string time, float amount, float charge, string transactionId)
{
	this->time = time;
	this->amount = amount;
	this->charge = charge;
	this->transactionId = transactionId;
}

Transaction::~Transaction()
{
}

void Transaction::print_transaction(string accountType)
{
	cout << "ID: " << transactionId << endl;
	if(accountType == "company")
		cout << "Charge: " << charge << endl;
	cout << "Amount: " << amount << endl;
	cout << "Time: " << time << endl;

}

string Transaction::getTime() const
{
	return this->time;
}

float Transaction::getAmount() const
{
	return this->amount;
}

float Transaction::getCharge() const
{
	return this->charge;
}

string Transaction::getTransactionId() const
{
	return this->transactionId;
}
