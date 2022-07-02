#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <iostream>

#include "menu.h"

class Item;

class Controller {
	std::istream& in;
	std::ostream& out;
	Menu menu;
  public:
	Controller(std::istream& in, std::ostream& out);
	void run();
	void getOrder(std::vector< int >&);
	void payment(std::vector< int >&);
};

#endif
