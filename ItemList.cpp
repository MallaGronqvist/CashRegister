// ItemList.cpp
// Author: Malla Grönqvist
// Date 10.04.2021

#include "ItemList.h"
#include <iostream>
#include <iomanip>



void ItemList::addItem(int pCategory, const char *pArticleName, double pAmount) {
	Item tmpItem;
	tmpItem.setCategory(pCategory);
	tmpItem.setName(pArticleName);
	tmpItem.setAmount(pAmount);

	itemList.push_back(tmpItem);
	nrOfItems++;
}

void ItemList::printItemList() {
	std::cout << std::endl << "LIST OF ITEMS:" << std::endl << "---------------------------------------"
		<< std::endl;
	int count = 1;
	for (auto idx: itemList) {
		std::cout << count << "." << std::right << std::setw(30) << idx.getItemName() 
			<<std::setw(6) << std::fixed << std::setprecision(2) << idx.getAmount() << std::endl;
		count++;
	}
}

int ItemList::getItemChoice() {
	std::cout << std::endl << "Choose item from the list by entering respective number: ";
	int choice;
	std::cin >> choice;

	// Check whether input is valid or not.
	do {
		if ((std::cin.fail()) || (std::cin.fail() || choice > nrOfItems || choice < 0)) {
			// the input couldn't be cast as integer value between 0 and nr of items.
			// clear failure state
			std::cin.clear();
			// discard remaining unprocessed characters in the input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Try again:" << std::endl;   // Advise the user to try again.
			std::cin >> choice;
		}
	} while ((std::cin.fail()) || (std::cin.fail() || choice > nrOfItems || choice < 0));

	return choice;
}

Item ItemList::getItem(int pChoice) {
	return itemList[pChoice];
}

ItemList::ItemList() {
	nrOfItems = 0;
}

ItemList::~ItemList() {

}