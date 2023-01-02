#pragma once
#include<iostream>

using namespace std;

class Order {
private:
	int customerId;
	int itemId;
	int amount;
	bool finished;

public:
	Order(int customerId, int itemId, int amount):customerId(customerId), itemId(itemId), amount(amount), finished(true){}
	int getCustomerId() {
		return customerId;
	}

	int getDishId() { return itemId; }

	int getAmount() { return amount; }

	int isFinished() { return finished; }

	void finish() { finished = true; }
	bool operator == (const Order& other) const {
		return customerId == other.customerId && itemId == other.itemId && amount == other.amount && finished == other.finished;
	}
};