#include"Customer.h"
#include <random>

using namespace std;
using namespace chrono;
using namespace this_thread;

int Customer::id_counter = 0;

Customer::Customer(binary_semaphore& orderSemaphore, Timer& timer, Orderboard& orderboard, Menu& menu) : id(id_counter++), th([&]() {start(orderSemaphore); }), timer(timer), orderboard(orderboard), menu(menu)
{
	if (id == 10) {
		cout << "Error: Number of customers can only be up to 10" << endl;
		exit(EXIT_FAILURE);
	}
}

Customer::~Customer() {}

void Customer::start(binary_semaphore& sp) {
	while (timer.isRunning()) {
		sp.acquire();
		if (orderboard.canOrder(id))
			tryOrder();
		sp.release();
		sleep_for(milliseconds(rand() % 3000 + 3000));
	}
}

void Customer::tryOrder() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> randBool(0, 1), randMeal(0, menu.getNumOfMeals() - 1), randAmount(1, 4);
	int mealId = randMeal(mt);
	int amount = randAmount(mt);
	bool wantToOrder(randBool(mt));
	cout << timer.getTime() << ": Customer " << id << " reads a menu about " << menu.getMeals()[mealId].getName();
	if (wantToOrder) {
		orderboard.orderMeal(id, mealId, amount);
		cout << " (ordered, amount " << amount << ")" << endl;
	}
	else {
		cout << " (doesn\'t want to order)" << endl;
	}
}