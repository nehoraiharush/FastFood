#pragma once
#include<iostream>
#include <thread>
#include <semaphore>

#include "Timer.h"
#include "Orderboard.h"
#include "Menu.h"

using namespace std;

class Waiter {
private:
	static int id_counter;
	int id;
	thread th;
	Timer& timer;
	Orderboard& orderboard;
	Menu& menu;

public:
	Waiter(binary_semaphore& bs,Orderboard ordB, Timer& tm, Menu& menu) : th([&]() {start(bs); }), timer(tm), menu(menu), id(id_counter++), orderboard(ordB){}
	void start(binary_semaphore&);

};