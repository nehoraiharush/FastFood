#pragma once
#include <random>
#include "Menu.h"
#include <iostream>

using namespace std;

class Customer
{
private:
	static int id_counter;
	int id;
	int sleep;
	int readMenu;

public:
	Customer();
	~Customer();
	int getSleep();
};