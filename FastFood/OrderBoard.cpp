#include "Orderboard.h"

Orderboard::Orderboard(Menu& menu) : menu(menu), itemCount(0), totalPrice(0) { }

bool Orderboard::canOrder(int customerId) {
	for (Order order : orders) {
		if (customerId == order.getCustomerId() && !order.isFinished())
			return false;
	}
	return true;
}

void Orderboard::orderMeal(int customerId, int mealId, int amount) {
	if (canOrder(customerId) && mealId < menu.getNumOfMeals() && amount > 0) {
		Order newOrder(customerId, mealId, amount);
		orders.push_back(newOrder);
	}
}

bool Orderboard::hasUnFinishedOrders() {
	cout << orders.size() << endl;
	for (Order order : orders) {
		if (!order.isFinished())
			return true;
	}
	return false;
}

Order Orderboard::excuteOrder() {
	for (Order& order : orders) {
		if (!order.isFinished()) {
			order.finish();
			menu.getMeals()[order.getMealId()].addOrders(order.getAmount());
			Order orderCopy(order);
			itemCount += order.getAmount();
			totalPrice += order.getAmount() * menu.getMeals()[order.getMealId()].getPrice();
			return orderCopy;
		}
	}
}

double Orderboard::getTotalPrice() {
	return totalPrice;
}

int Orderboard::getAmount() {
	return itemCount;
}