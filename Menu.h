#include "Management.h"
using namespace std;

#pragma once
class Menu
{
public:
	Menu();
	~Menu();

	void main_menu();
	void submenu_list();
	void submenu_create();
	void submenu_transaction();
	void submenu_search_ID();
private:
	Management& management = Management::getInstance();
};

