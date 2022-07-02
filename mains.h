#ifndef __MAINS_H__
#define __MAINS_H__

#include "item.h"

class Mains : public Item {
  public:
    Mains(std::string name, Category category, float price, bool vegan); 
};

#endif
