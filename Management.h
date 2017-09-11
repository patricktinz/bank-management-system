#include "Account.h"
#include <vector>
#include <string>
using namespace std;

#pragma once
class Management
{
public:
	~Management();

	static Management& getInstance();    // singleton

	void add_account(Account*);
	void list_accounts();
	void search_ID(string);
	Account* getAccount(int);

	vector<Account*> getAccounts() const;
private:
	Management();
	vector<Account*> accounts;
};