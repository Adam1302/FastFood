#include "item.h"

using namespace std;

std::map<Category, std::string> categoryNames = {
	{Category::MAINS, "Mains"},
	{Category::SIDES, "Sides"},
	{Category::DRINKS, "Drinks"}
};

Item::Item(string name, Category category, float price, bool vegan):
	name{name}, category{category}, price{price}, vegan{vegan} {}

string Item::getName() { return name; }
float Item::getPrice() { return price; }
bool Item::isVegan() { return vegan; }
Category Item::getCategory() { return category; }

ostream& operator<<(ostream& out, Item& item) {
        out << left << setw(30) << item.getName() << right << setw(6) << item.getPrice();
        if (item.isVegan()) {
                out << "    V";
        } else {
                out << "     ";
        }
        out << endl;
	
	return out;
}
