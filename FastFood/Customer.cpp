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
	srand(time(NULL));
}

Customer::~Customer() {}

void Customer::start(binary_semaphore& sp) {
	while (timer.isRunning()) {
		//cout << "Customer: " << id << endl;
		sp.acquire();
		if (orderboard.canOrder(id)) {
			tryOrder();
		}
		sp.release();
		sleep_for(milliseconds(rand() % 4000 + 3000));
	}
}

void Customer::tryOrder() {
	
	cout << "HHH" << endl;
	int mealId = rand() % menu.getNumOfMeals();
	int amount = rand() % 4 + 1;
	bool wantToOrder = rand() % 2;
	cout << menu.getNumOfMeals() << rand() % menu.getNumOfMeals() << " " << rand() % 4 + 1 << " " << rand() % 2 << endl;
	cout << timer.getTime() << ": Customer " << id << " reads a menu about " << menu.getMeals()[mealId].getName();
	if (wantToOrder) {
		orderboard.orderMeal(id, mealId, amount);
		cout << " (ordered, amount " << amount << ")" << endl;
	}
	else {
		cout << " (doesn\'t want to order)" << endl;
	}
}