#pragma once
#include<iostream>

using namespace std;

class Order {
private:
	int customerId;
	int itemId;
	int amount;
	bool done;

public:
	Order(int customerId, int itemId, int amount):customerId(customerId), itemId(itemId), amount(amount), done(true){}
	int getCustomerId() {
		return customerId;
	}

	int getDishId() { return itemId; }

	int getAmount() { return amount; }

	int isDone() { return done; }

	void finish() { done = true; }
};