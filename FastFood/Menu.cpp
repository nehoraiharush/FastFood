#include"Menu.h"
#include"Meal.h"

using namespace std;

Meal Menu::allMeals[7] = {
	Meal("Pizza",45),
	Meal("Mac Royale",50),
	Meal("Shawarma",52),
	Meal("Tortia",48),
	Meal("Cookie",20),
	Meal("Coke",10),
	Meal("Stake",80)
};

Menu::Menu(int num_of_meals) {
	if (num_of_meals > 7) {
		cout << "Error: There aren't enough meals only up to 7" << endl;
		exit(EXIT_FAILURE);
	}
	numOfMeals = num_of_meals;
	
	for (int i = 0; i < numOfMeals; i++) {
		requeiredMeals.push_back(allMeals[i]);
	}	
}

void Menu::print() const{
	for (int i = 0; i < numOfMeals; i++) {
		Meal meal(requeiredMeals.at(i));
		cout << "Meal: " << meal.getName() << " | Price: " << meal.getPrice() << " | Total Orders: " << meal.getTotalOrders() << endl;
	}
}