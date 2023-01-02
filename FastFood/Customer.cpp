#include"Customer.h"
#include <random>

using namespace std;

int Customer::id_counter = 0;

Customer::Customer(binary_semaphore& orderSemaphore, Timer& timer, Orderboard& orderboard, Menu& menu) : id(id_counter++), th([&]() {start(orderSemaphore); }), timer(timer), orderboard(orderboard), menu(menu)
{
	cout << "Default ctor" << endl;
	srand(time(0));
	sleep = rand() % 3000 + 3000;
	readMenu = 1;
}

Customer::~Customer() { cout << "\nDtor"; }
int Customer::getSleep() { return sleep; }

void Customer::start(binary_semaphore& sp) {
	while (timer.isRunning()) {
		sp.acquire();
		if (orderboard.canOrder(id))
			tryOrder();
		sp.release();
		this_thread::sleep_for(chrono::milliseconds(rand() % 3000 + 3000));
	}
}

void Customer::tryOrder() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> randBool(0, 1), randDish(0, menu.getNumOfMeals() - 1), randAmount(1, 4);
	int dishId = randDish(mt);
	int amount = randAmount(mt);
	bool wantToOrder(randBool(mt)); // 50% chance
	cout << timer.getTime() << ": Customer " << id << " reads a menu about " << menu.getMeals()[dishId].getName();
	if (wantToOrder) {
		orderboard.orderDish(id, dishId, amount);
		cout << " (ordered, amount " << amount << ")" << endl;
	}
	else {
		cout << " (doesn\'t want to order)" << endl;
	}
}