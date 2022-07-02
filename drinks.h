#ifndef __DRINKS_H__
#define __DRINKS_H__

#include "item.h"

class Drinks : public Item {
  public:
	Drinks(std::string name, Category category, float price, bool vegan); 
};

#endif
