#pragma once
#include<iostream>

using namespace std;

class OrdersBoard {
private:
	int customerId;
	int itemId;
	int amount;
	bool done;

public:
	OrdersBoard(int customerId, int itemId, int amount):customerId(customerId), itemId(itemId), amount(amount), done(true){}

};