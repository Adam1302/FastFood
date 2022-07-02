#ifndef __ITEM_H__
#define __ITEM_H__

#include <iostream>
#include <iomanip>
#include <map>

enum class Category { MAINS, SIDES, DRINKS };

extern std::map<Category, std::string> categoryNames;

class Item {
	std::string name;
	Category category;
	double price;
	bool vegan;
 public:
	Item(std::string name, Category category, float price, bool vegan);
	std::string getName();
	float getPrice();
	bool isVegan();
	Category getCategory();
	
	friend std::ostream& operator<<(std::ostream& out, Item& item);
};

#endif
