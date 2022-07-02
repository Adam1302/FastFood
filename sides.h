#ifndef __SIDES_H__
#define __SIDES_H__

#include "item.h"

class Sides : public Item {
  public:
	Sides(std::string name, Category category, float price, bool vegan); 
};

#endif
