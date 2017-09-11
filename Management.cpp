#include "Management.h"
#include "PrivateGiroAccount.h"
#include "CompanyGiroAccount.h"
#include <iostream>
#include <fstream>
using namespace std;

Management::Management()
{
	ifstream accountRead;
	accountRead.open("accounts.txt", ios::in);

	if (accountRead)
	{
		while (!accountRead.eof())
		{
			string value, accountType;
			int accountNumber;
			float accountBalance;

			getline(accountRead, value, ';');
			accountType = value;

			getline(accountRead, value, ';');
			accountNumber = stoi(value);

			getline(accountRead, value, '\n');
			accountBalance = stof(value);

			if (accountType == "private")
				accounts.push_back(new PrivateGiroAccount(accountNumber, accountBalance));
			if (accountType == "company")
				accounts.push_back(new CompanyGiroAccount(accountNumber, accountBalance));
			if(accountRead.peek() == '\n')
				break;
		}
	}
	else
		cout << "Reading (accounts.txt) is not possible! " << endl;
	accountRead.close();
	
	ifstream transactionRead;
	transactionRead.open("transactions.txt", ios::in);

	if (transactionRead)
	{
		while (!transactionRead.eof())
		{
			string value, time, transactionId;
			int accountNumber;
			float amount, charge;

			getline(transactionRead, value, ';');
			accountNumber = stoi(value);

			getline(transactionRead, value, ';');
			transactionId = value;

			getline(transactionRead, value, ';');
			amount = stof(value);

			Account *account = getAccount(accountNumber);
			if (account->getAccountType() == "company")
			{
				getline(transactionRead, value, ';');
				charge = stof(value);
			}
			getline(transactionRead, value, '\n');
			time = value;

			Transaction* transaction;
			if(account->getAccountType() == "company")
				transaction = new Transaction(time, amount, charge, transactionId);
			else
				transaction = new Transaction(time, amount, transactionId);
			account->execute_transaction(transaction);

			if (transactionRead.peek() == '\n')
				break;
		}
	}
	else
		cout << "Reading (transactions.txt) is not possible! " << endl;
	transactionRead.close();
}

Management::~Management()
{
	ofstream accountWrite;
	accountWrite.open("accounts.txt", ios::out);

	ofstream transactionWrite;
	transactionWrite.open("transactions.txt", ios::out);

	for (unsigned int i = 0; i < accounts.size(); i++)
	{
		accountWrite << accounts.at(i)->getAccountType() << ";";
		accountWrite << accounts.at(i)->getAccountNumber() << ";";
		accountWrite << accounts.at(i)->getAccountBalance() << '\n';

		for (unsigned int j = 0; j < accounts.at(i)->getTransactions().size(); j++)
		{
			transactionWrite << accounts.at(i)->getAccountNumber() << ";";
			transactionWrite << accounts.at(i)->getTransactions().at(j)->getTransactionId() << ";";
			transactionWrite <<  accounts.at(i)->getTransactions().at(j)->getAmount() << ";";

			if (accounts.at(i)->getAccountType() == "company")
				transactionWrite << accounts.at(i)->getTransactions().at(j)->getCharge() << ";";

			transactionWrite << accounts.at(i)->getTransactions().at(j)->getTime() << '\n';
			delete accounts.at(i)->getTransactions().at(j);
		}
		delete accounts.at(i);
	}
	accountWrite.close();
	transactionWrite.close();
}

Management& Management::getInstance()   // singleton
{
	static Management instance;
	return instance;
}

void Management::add_account(Account* newAccount)
{
	accounts.push_back(newAccount);
}

void Management::list_accounts()
{
	for (unsigned int i = 0; i < accounts.size(); i++)
		accounts.at(i)->print();
}

void Management::search_ID(string transactionId)
{
	unsigned int counter = 0;
	for (int i = 0; i < accounts.size(); i++)
	{
		for (int j = 0; j < accounts.at(i)->getTransactions().size(); j++)
		{
			if (accounts.at(i)->getTransactions().at(j)->getTransactionId() == transactionId) 
			{
				cout << "Account number (" << accounts[i]->getAccountType() << "): " << accounts[i]->getAccountNumber() << endl;
				string konto_typ = accounts.at(i)->getAccountType();
				accounts.at(i)->getTransactions().at(j)->print_transaction(konto_typ);
				counter++;
			}
		}
	}
	if (counter == 0)
		cout << "- Wrong TransaktionsID -" << endl;
}

Account* Management::getAccount(int number)
{
	for (unsigned int i = 0; i < accounts.size(); i++)
	{
		if (accounts.at(i)->getAccountNumber() == number)
			return accounts.at(i);
	}
	return NULL;
}

vector<Account*> Management::getAccounts() const
{
	return this->accounts;
}
