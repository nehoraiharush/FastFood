#pragma once
#include <random>
#include<iostream>
#include <thread>
#include <semaphore>

#include "Timer.h"
#include "Orderboard.h"
#include "Menu.h"

using namespace std;

class Customer
{
private:
	static int id_counter;
	int id;
	thread th;
	Timer& timer;
	Orderboard& orderboard;
	Menu& menu;
	void tryOrder();

public:
	Customer(binary_semaphore&, Timer&, Orderboard&, Menu&);
	~Customer();
	int getSleep();
	void start(binary_semaphore&);
};