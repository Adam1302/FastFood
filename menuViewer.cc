#include "menuViewer.h"

using namespace std;

void MenuViewer::print(vector< unique_ptr<Item> >& menu, ostream& out) {
	// string currentCategory = "";
	int i = 0;
	Category currentCategory = Category::DRINKS; // Won't begin at DRINKS, just a random starting value

	out << endl;
	for (auto& item : menu) {
		++i;
		if (currentCategory != item->getCategory()) {
			out << categoryNames[item->getCategory()] << endl;
			currentCategory = item->getCategory();
		}
		out << "(" << right << setw(2) << i << ") " << *item;
	}
}

void MenuViewer::print(vector< unique_ptr<Item> >& menu, ostream& out, vector<int> order) {
	out << endl;
	for (auto i : order) {
        out << *menu.at(i-1);
    }
	out << endl;
}

void MenuViewer::printVegan(vector< unique_ptr<Item> >& menu, ostream& out) {
	int i = 0;
	Category currentCategory = Category::DRINKS; // Won't begin at DRINKS, just a random starting value

	out << endl;
	for (auto& item : menu) {
		++i;
		if (currentCategory != item->getCategory()) {
			out << categoryNames[item->getCategory()] << endl;
			currentCategory = item->getCategory();
		}
		if (item->isVegan()) out << "(" << right << setw(2) << i << ") " << *item;
	}
}