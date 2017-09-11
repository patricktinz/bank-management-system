#include "Transaction.h"
#include <vector>
#include <string>
using namespace std;

#pragma once
class Account
{
public:
	Account();
	virtual ~Account();

	virtual void print() = 0;
	virtual void add_transaction(float) = 0;
	void execute_transaction(Transaction*);

	int getAccountNumber() const;
	float getAccountBalance() const;
	string getAccountType() const;
	vector<Transaction*> getTransactions() const;
protected:
	int accountNumber;
	float accountBalance;
	string accountType;
	vector<Transaction*> transactions;
};