#include "Orderboard.h"

Orderboard::Orderboard(Menu& menu) : menu(menu), itemCount(0), totalPrice(0) { }

bool Orderboard::canOrder(int customerId) {
	for (Order order : orders) {
		if (customerId == order.getCustomerId() && !order.isFinished())
			return false;
	}
	return true;
}

void Orderboard::orderDish(int customerId, int dishId, int amount) {
	if (canOrder(customerId) && dishId < menu.getNumOfMeals() && amount > 0) {
		Order newOrder(customerId, dishId, amount);
		orders.push_back(newOrder);
	}
}

bool Orderboard::hasUndoneOrders() {
	for (Order order : orders) {
		if (!order.isFinished())
			return true;
	}
	return false;
}

Order Orderboard::preformOrder() {
	for (Order& order : orders) {
		if (!order.isFinished()) {
			order.finish();
			menu.getMeals()[order.getDishId()].addOrders(order.getAmount());
			Order orderCopy(order);
			itemCount += order.getAmount();
			totalPrice += order.getAmount() * menu.getMeals()[order.getDishId()].getPrice();
			orders.remove(order);
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