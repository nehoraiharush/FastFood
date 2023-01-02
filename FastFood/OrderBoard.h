#pragma once

#include "Menu.h"
#include "Order.h"
#include <list>
class Orderboard
{
private:
	Menu& menu;
	int itemCount;
	double totalPrice;
	list<Order> orders;

public:
	Orderboard(Menu&);
	bool canOrder(int);
	void orderMeal(int, int, int);
	bool hasUnFinishedOrders();
	Order excuteOrder();
	double getTotalPrice();
	int getAmount();
	list<Order> getOrders() { return orders; }
};

