#include"Customer.h"
#include <random>

using namespace std;

int id_counter = 0;

Customer::Customer():id(++id_counter)
{
	cout << "Default ctor" << endl;
	srand(time(0));
	sleep = rand() % 3000 + 3000;
	readMenu = 1;
}

Customer::~Customer() { cout << "\nDtor"; }
int Customer::getSleep() { return sleep; }