#include"Customer.h"
#include<iostream>
#include<semaphore>
#include<thread>

using namespace std;

void main() {
	Customer c;
	cout << c.getSleep();
	binary_semaphore b(1);
	thread a([&b]() {
		b.acquire();
		cout << "H" << endl;
		b.release();
	});
	a.join();
}