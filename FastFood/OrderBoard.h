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
	void orderDish(int, int, int);
	bool hasUndoneOrders();
	Order preformOrder();
	double getTotalPrice();
	int getAmount();
};

