// Basket.cpp
// Author: Malla Grönqvist
// Date 10.04.2021

#include "Basket.h"
#include <iostream>
#include <iomanip>
#include "Item.h"

#include"CashRegister.h"



Basket::Basket() {
	nrOfItemsInBasket = 0;
}

Basket::~Basket() {

}
void Basket::showBasket() {
	std::cout << std::endl << "ITEMS IN BASKET:" 
		<< std::endl << "---------------------------------------" << std::endl;
	int count = 1;
	for (auto idx : basket) {
		std::cout << count << "." << std::right << std::setw(30) << idx.getItemName() 
			<< std::setw(6) << std::fixed << std::setprecision(2) << idx.getAmount() << std::endl;
		count++;
	}

}

void Basket::addItemToBasket(Item pItem) {
	basket.push_back(pItem);
	nrOfItemsInBasket++;
	std::cout << "Item was added to basket." << std::endl;
}

void Basket::removeItemFromBasket() {
	if (nrOfItemsInBasket == 0) {
		std::cout << "There are no items to remove. Basket is empty." << std::endl
			<< "Choose 1 to add more items from list of items." << std::endl;
	}
	else {
		std::cout << "Enter number of the item you want to remove from basket: " << std::endl;
		int choice;
		std::cin >> choice;

		do {

			if ((std::cin.fail()) || (std::cin.fail() || choice > nrOfItemsInBasket || choice < 0)) {
				// the input couldn't be cast as integer value between 0 and nr of items.
				// clear failure state
				std::cin.clear();
				// discard remaining unprocessed characters in the input stream
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Try again:" << std::endl;   // Advise the user to try again.
				std::cin >> choice;
			}
		} while ((std::cin.fail()) || (std::cin.fail() || choice > nrOfItemsInBasket || choice < 0));

		int index = choice - 1;
		basket.erase(basket.begin() + (index));
		nrOfItemsInBasket--;

		std::cout << "Item was removed from basket." << std::endl;
		std::cin.get();
	}
}

int Basket::getChoiceToProceed() {
	std::cout << std::endl << "1. Choose more items from list." << std::endl
		<< "2. Remove an item from basket." << std::endl
		<< "3. Pay for items in basket." << std::endl;

	std::cout << std::endl << "Choose how to proceed by entering a number (1-3): " << std::endl;
	int choice;
	std::cin >> choice;
	std::cin.get();

	do {

		if ((std::cin.fail()) || (std::cin.fail() || choice > 3 || choice < 0)) {
			// the input couldn't be cast as integer value between 0 and 3.
			// clear failure state
			std::cin.clear();
			// discard remaining unprocessed characters in the input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Try again:" << std::endl;   // Advise the user to try again.
			std::cin >> choice;
		}
	} while ((std::cin.fail()) || (std::cin.fail() || choice > 3 || choice < 0));

	return choice;

}

std::vector<Item> Basket::getBasket() {
	return basket;
}

void Basket::emptyBasket() {
	basket.clear();
}