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
	int id_counter = 0;
	Meal(string inp_name, double price): id(++id_counter), name(inp_name), price(price), totalOrders(0){}


};