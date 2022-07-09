#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
#include "menuViewer.h"
#include "item.h"
#include "mains.h"
#include "sides.h"
#include "drinks.h"
*/
#include "menuViewer.h"
#include "item.h"

class Menu {
	std::unique_ptr<MenuViewer> view;
	std::vector< std::unique_ptr<Item> > menu;
  public:
	Menu();
	void print(std::ostream& out);
	void print(std::ostream& out, std::vector<int> order);
	void addItem(std::string, Category category, float price, bool vegan);
	
	std::string getName(int i);
	double getPrice(int i);
	int getMenuSize();
};

#endif
