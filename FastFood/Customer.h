#pragma once
#include<random>
#include"Menu.h"
#include<iostream>

using namespace std;

class Customer {
private:
	int sleep;
	int readMenu;

public:
	Customer() {

		srand(time(0));
		sleep = rand() % 3 + 4;
		readMenu = 1;
	}
	~Customer() { cout << "\nDtor"; }
	int getSleep() { return sleep; }
};