#include "menu.h"

#include "mains.h"
#include "sides.h"
#include "drinks.h"

using namespace std;

Menu::Menu(): view{new MenuViewer()}, menu{} {
	addItem("Grilled Chicken Sandwich", Category::MAINS, 6.99, false);
	addItem("Classic Hamburger", Category::MAINS, 6.99, false);
	addItem("Tuna and Egg Wrap", Category::MAINS, 7.49, false);
	addItem("Fish and Chips", Category::MAINS, 7.99, false);
	addItem("Tofu Platter", Category::MAINS, 10.99, true);

	addItem("Fried Calimari", Category::SIDES, 4.49, false);
	addItem("Chicken Nuggets", Category::SIDES, 3.99, false);
	addItem("Caesar Salad", Category::SIDES, 3.99, true);
	addItem("Garden Salad", Category::SIDES, 3.49, true);
	addItem("French Fries", Category::SIDES, 2.99, true);
	addItem("Sweet Potato Fries", Category::SIDES, 3.99, true);
	addItem("Popcorn Shrimp", Category::SIDES, 4.49, false);
	addItem("Beans and Rice", Category::SIDES, 3.99, true);
	addItem("Chips & Salsa", Category::SIDES, 3.79, true);
	addItem("Sweet Potato Fries", Category::SIDES, 3.99, true);

	addItem("Water", Category::DRINKS, 2.29, true);
	addItem("Soda", Category::DRINKS, 1.99, true);
	addItem("Hot Chocolate", Category::DRINKS, 2.49, true);
	addItem("Coffee", Category::DRINKS, 2.09, true);
	addItem("Iced Coffee", Category::DRINKS, 2.09, true);
	addItem("Orange Juice", Category::DRINKS, 2.39, true);
	addItem("Chocolate Milkshake", Category::DRINKS, 3.09, false);
	addItem("Strawberry-Banana Smoothie", Category::DRINKS, 3.49, false);
}

void Menu::print(ostream& out) {
	view->print(menu, out);
}

void Menu::print(ostream& out, vector<int> order) {
	view->print(menu, out, order);
}

void Menu::addItem(string name, Category category, float price, bool vegan) {
	if (category == Category::MAINS) {
		menu.emplace_back(make_unique<Mains>(name, category, price, vegan));
	} else if (category == Category::SIDES) {
		menu.emplace_back(make_unique<Sides>(name, category, price, vegan));
	} else {
		menu.emplace_back(make_unique<Drinks>(name, category, price, vegan));
	}
}

string Menu::getName(int i) {
	return menu.at(i - 1)->getName();
}

double Menu::getPrice(int i) {
	return menu.at(i - 1)->getPrice();
}

int Menu::getMenuSize() {
	return menu.size();
}