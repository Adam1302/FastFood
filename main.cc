#include <iostream>
#include "controller.h"

int main() {
	Controller c{std::cin, std::cout};
	c.run();
}
