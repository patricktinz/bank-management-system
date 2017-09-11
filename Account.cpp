#include "Account.h"
#include <iostream>
using namespace std;

Account::Account()
{
	this->accountBalance = 0;
}

Account::~Account()
{
}

void Account::execute_transaction(Transaction* new_transaktion)
{
	transactions.push_back(new_transaktion);
}

int Account::getAccountNumber() const
{
	return accountNumber;
}

float Account::getAccountBalance() const
{
	return accountBalance;
}

string Account::getAccountType() const
{
	return accountType;
}

vector<Transaction*> Account::getTransactions() const
{
	return this->transactions;
}
