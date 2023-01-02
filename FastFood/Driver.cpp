#include <vector>
#include "Customer.h"
#include "Waiter.h"
#include "Timer.h"
#include "Orderboard.h"

int main() {
    Timer timer(30);
    binary_semaphore bs(1);
    Menu menu(5);
    menu.print();
    Orderboard orderboard(menu);
    Customer** vec_c = new Customer*[6];
    Waiter** vec_w = new Waiter*[2];
    for (int i = 0; i < 6; i++) 
        vec_c[i] = new Customer(bs, timer, orderboard, menu);
    
    for (int i = 0; i < 2; i++) 
        vec_w[i] = new Waiter(bs, orderboard, timer, menu);
    
    cout << timer.getTime() << ": End" << endl;
    menu.print();
    cout << "Total price: " << orderboard.getTotalPrice() << "$." << endl;
    cout << "Total amount: " << orderboard.getAmount() << " orders." << endl;

    for (int i = 0; i < 6; i++)
        delete vec_c[i];
    delete[] vec_c;
    for (int i = 0; i < 2; i++) 
        delete vec_w[i];
    delete[] vec_w;
    

}