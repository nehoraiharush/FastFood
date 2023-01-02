#pragma once
#include<iostream>

using namespace std;
class Meal {
private:
	static int id_counter;
	int id;
	string name;
	double price;
	int totalOrders;

public:
	Meal(string inp_name, double price): id(id_counter++), name(inp_name), price(price), totalOrders(0){}
	Meal(const Meal& obj) : name(obj.name), price(obj.price), totalOrders(obj.totalOrders) {}
	~Meal() { cout << "Dtor" << endl; }
	string getName() const { return name; }
	double getPrice() const { return price; }
	void setTotalOrders(int numOfOrders) { totalOrders = numOfOrders; }
	int getTotalOrders() const { return totalOrders; }
	void addOrders(int orders) { totalOrders += orders; }

};