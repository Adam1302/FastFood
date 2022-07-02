#include <iostream>

#include "controller.h"

using namespace std;

Controller::Controller(istream& in, ostream& out):
	in{in}, out{out}, menu{} {
	
}

void Controller::run() {
	out << "Hi, welcome to Fred's! Here is our menu:" << endl;
	
	menu.print(out);

	std::vector< int > order;
	getOrder(order);
	
	payment(order);

	out << "\nHope you enjoy! Have a nice day." << endl;
}

void Controller::getOrder(std::vector< int >& order) {
	int itemNum;
	int quantity;

	out << endl;
	out << "What can I get for you today?" << endl;
	out << "\tInstructions:" << endl;
	out << "\t  - Enter the corresponding number to select an item" << endl;
	out << "\t  - Enter '0' was you are done" << endl;

	while (true) {
		in >> itemNum;

		if (itemNum == 0) break;

		out << "Quantity: ";
		in >> quantity;

		for (int i = 0; i < quantity; ++i)
			order.emplace_back(itemNum);

		out << quantity << " " << menu.getName(itemNum);
		out << ((quantity == 1)? " has" : " have") << " been added to your order." << endl;
		out << "Anything else?" << endl;
	}
}

void Controller::payment(std::vector< int >& order) {
	float curPrice = 0.0;
	float tipPercentage;
	
	for (auto i : order) {
		curPrice += menu.getPrice(i);
	}

	out << endl << "Your order is:" << endl;
	menu.print(out, order);
	out << setw(21) << "Total: $" << fixed << setprecision(2) << curPrice << endl;

	out << endl << "Ontario Tax Rate is 13%: $" << fixed << setprecision(2) << curPrice*0.13 << endl;
	curPrice *= 1.13;

	out << "Total Price: $" << fixed << setprecision(2) << curPrice << endl << endl;

	out << "Enter your tip percentage: ";
	in >> tipPercentage;

	out << "Tip is " << tipPercentage << "%: $" << curPrice*tipPercentage/100 << endl;

	curPrice *= (1 + tipPercentage/100);

	out << "Total Price: $" << fixed << setprecision(2) << curPrice << endl;

	if (tipPercentage > 0) { out << "Thank you for the tip!" << endl; }
}

/*
void displayOrder(vector<Item*> order) {
	for (auto i : order) {
		out << i;
	}
}
*/