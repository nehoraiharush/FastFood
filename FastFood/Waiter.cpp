#include"Waiter.h"

int Waiter::id_counter = 0;

void Waiter::start(binary_semaphore& bs) {

	while (timer.isRunning()) {
		this_thread::sleep_for(chrono::milliseconds(rand() % 1000 + 1000));
		bs.acquire();
		if (orderboard.hasUndoneOrders()) {
			Order order = orderboard.preformOrder();
			cout << timer.getTime() << ": Waiter " << id << " preformes order of Customer " << order.getCustomerId() << " (" << order.getAmount() << " " << menu.getMeals()[order.getDishId()].getName() << ")" << endl;
		}
		bs.release();
	}

}