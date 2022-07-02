#include "drinks.h"

using namespace std;

Drinks::Drinks(string name, Category category, float price, bool vegan):
	Item{name, category, price, vegan} {}
