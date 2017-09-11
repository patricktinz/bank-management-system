#include "Menu.h"
#include "Account.h"
#include "PrivateGiroAccount.h"
#include "CompanyGiroAccount.h"
#include <iostream>
#include <string>
using namespace std;

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::main_menu()
{
	while (true)
	{
		unsigned int choice = 5;
		cout << "=== Bank Management ===" << endl;
		cout << "1. List accounts" << endl;
		cout << "2. Create account" << endl;
		cout << "3. Transaction" << endl;
		cout << "4. Search TransactionID" << endl;
		cout << "5. Exit" << endl;

		cout << "Entry > ";
		cin >> choice;
		system("clear");

		switch (choice)
		{
			case 1:
				submenu_list();
				break;
			case 2:
				submenu_create();
				break;
			case 3:
				submenu_transaction();
				break;
			case 4:
				submenu_search_ID();
				break;
			case 5:
				return;
			default:
				cout << "- Wrong Input -" << endl;
		}
	}
}

void Menu::submenu_list()
{
	cout << "=== Submenu List ===" << endl;
	management.list_accounts();
}

void Menu::submenu_create()
{
	while (true)
	{
		Account *newAccount;
		unsigned int choice = 3;
		int accountNumber;

		cout << "=== Submenu Create ===" << endl;
		cout << "1. Private giro account" << endl;
		cout << "2. Company giro account" << endl;
		cout << "3. Back" << endl;
		cout << "Entry > ";
		cin >> choice;

		if (choice == 1 || choice == 2)
		{
			cout << "Account number > ";
			cin >> accountNumber;
		}
		system("clear");

		switch (choice)
		{
		case 1:
			newAccount = new PrivateGiroAccount(accountNumber);
			newAccount->print();
			management.add_account(newAccount);
			break;
		case 2:
			newAccount = new CompanyGiroAccount(accountNumber);
			newAccount->print();
			management.add_account(newAccount);
			break;
		case 3:
			return;
		default:
			cout << "- Wrong input -" << endl;
			break;
		}
	}
}

void Menu::submenu_transaction()
{
	int accountNumber;
	float amount;
	cout << "=== Submenu Transaction ===" << endl;
	cout << "Account number > ";
	cin >> accountNumber;
	cout << "Amount > ";
	cin >> amount;
	system("clear");

	Account* konto = management.getAccount(accountNumber);
	konto->add_transaction(amount);
}

void Menu::submenu_search_ID()
{
	string transactionId;
	cout << "=== Submenu Search TransactionID ===" << endl;
	cout << "Entry > ";
	cin >> transactionId;
	system("clear");

	management.search_ID(transactionId);
}


