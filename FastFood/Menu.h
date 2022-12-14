#pragma once
#include"Meal.h"
#include <vector>

class Menu {
private:
	static Meal allMeals[7];
	vector<Meal> requeiredMeals;
	int numOfMeals;

public:
	Menu(int);
	~Menu() { delete[] allMeals; requeiredMeals.clear(); }
	void print()const;
	int getNumOfMeals() const { return numOfMeals; }
	vector<Meal> getMeals() { return requeiredMeals; }
};