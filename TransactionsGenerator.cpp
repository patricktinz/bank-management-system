#include "Management.h"
#include "Account.h"
#include "TransactionsGenerator.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

TransactionsGenerator::TransactionsGenerator()
{
}


TransactionsGenerator::~TransactionsGenerator()
{
}

string TransactionsGenerator::generateID()
{
	srand((unsigned)time(0));

	string key = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	int length = key.length();
	int value;
	string transactionId;

	for (int i = 0; i < 4; i++)
	{
		value = (rand() % length+1);
		transactionId.append(key.substr(value, 1));
	}

	while (exists(transactionId))
	{
		for (int i = 0; i < 4; i++)
		{
			value = (rand() % length+1);
			transactionId.append(key.substr(value, 1));
		}
	}
	return transactionId;
}

bool TransactionsGenerator::exists(string transactionId)
{
	Management& management = Management::getInstance();
	for (int i = 0; i < management.getAccounts().size(); i++)
	{
		for (int j = 0; j < management.getAccounts().at(i)->getTransactions().size(); j++) 
		{
			if (transactionId == management.getAccounts().at(i)->getTransactions().at(j)->getTransactionId())   
				return true;
		}
	}
	return false;  
}
