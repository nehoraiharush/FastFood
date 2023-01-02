#include"Waiter.h"

using namespace chrono;
using namespace this_thread;

int Waiter::id_counter = 0;

void Waiter::start(binary_semaphore& bs) {

	while (timer.isRunning()) {
		sleep_for(milliseconds(rand() % 1000 + 1000));
		bs.acquire();
		if (orderboard.hasUnFinishedOrders()) {
			Order order = orderboard.excuteOrder();
			cout << timer.getTime() << ": Waiter " << id << " preformes order of Customer " << order.getCustomerId() << " (" << order.getAmount() << " " << menu.getMeals()[order.getMealId()].getName() << ")" << endl;
		}
		bs.release();
	}

}