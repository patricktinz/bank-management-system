#include <string>
using namespace std;

#pragma once
class Transaction
{
public:
	Transaction(string, float, string);
	Transaction(string, float, float, string);
	~Transaction();

	void print_transaction(string);

	string getTime() const;
	float getAmount() const;
	float getCharge() const;
	string getTransactionId() const;

private:
	string time;
	float amount;
	float charge;
	string transactionId; 
};