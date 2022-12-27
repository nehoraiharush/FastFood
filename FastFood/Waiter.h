#pragma once
#include<iostream>

class Waiter {
private:
	static int id_counter;
	int id;

public:
	int id_counter = 0;
	Waiter() : id(++id_counter){}
};