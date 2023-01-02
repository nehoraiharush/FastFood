#include"Customer.h"
#include<iostream>
#include<semaphore>
#include<thread>

using namespace std;

void main() {
	Menu menu(5);
	menu.print();
	Timer timer(5);
	Orderboard orderboard(menu);
	binary_semaphore b(1);
	thread a([&b]() {
		b.acquire();
		cout << "H" << endl;
		b.release();
		});
	Customer c(b,timer,orderboard,menu);
	cout << c.getSleep();
	
	a.join();
	
}