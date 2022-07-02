#ifndef __MENUVIEWER_H__
#define __MENUVIEWER_H__

#include <vector>
#include <memory>
#include <iostream>
#include "item.h"


class Item;

class MenuViewer {
  public:
	void print(std::vector< std::unique_ptr<Item> >&, std::ostream& out);
	void print(std::vector< std::unique_ptr<Item> >&, std::ostream& out, std::vector<int>);
	void printVegan(std::vector< std::unique_ptr<Item> >&, std::ostream& out);
};

#endif
