// main.cpp
// Author: Malla Grönqvist
// Date 10.04.2021

#include "Item.h"
#include "ItemList.h"
#include "CashRegister.h"
#include "Basket.h"
#include <iostream>

class App {
public:
	int run();
};

int App::run() {

	CashRegister cashRegister("Register.txt", 5);

	ItemList itemList;
	itemList.addItem(1, "Kalles Kaviar", 15.00);
	itemList.addItem(2, "Goda kakor", 25.00);
	itemList.addItem(4, "Kaffe", 30.50);
	itemList.addItem(1, "Laxbiffar", 76.00);
	itemList.addItem(2, "Kexchoklad", 13.50);
	itemList.addItem(5, "Tandborste", 10.00);
	itemList.addItem(3, "Bananer", 12.00);
	itemList.addItem(3, "Ost", 65.50);

	Basket basket;

	// Run program until user chooses to exit.
	bool again = true;
	do {
		std::cout << std::endl << std::endl << "WELCOME TO PAY DESK" << std::endl
			<< "-----------------------------------------------" << std::endl;

		std::cout << "1. New customer." << std::endl << "2. Close pay desk for the day." << std::endl
			<< std::endl << "Enter your choice:";
		int choice;
		std::cin >> choice;

		// Check whether input is valid or not.
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

		if (choice == 2) {
			std::cout << std::endl << "Closing Pay Desk." << std::endl << std::endl;
			again = false;
			return 0;
		}
			
			// Do until customer pays.
			bool showItemList = true;
			do {
				// Print item list and read item choice.
				itemList.printItemList();
				int itemChoice;
				itemChoice = itemList.getItemChoice();
				
				Item tmpItem;
				tmpItem = itemList.getItem(itemChoice - 1);
				// Add item of choice to basket.
				basket.addItemToBasket(tmpItem);

				bool showBasket = true;
				do {
					basket.showBasket();
					switch (basket.getChoiceToProceed()) {
					case 1: showBasket = false;
						break;
					case 2: basket.removeItemFromBasket();
						break;
					case 3:
						// Register items in basket.
						std::vector<Item>tmpVector;
						tmpVector = basket.getBasket();
						int tmpCategory;
						const char *tmpArticleName;
						double tmpAmount;

						for (auto idx : tmpVector) {
							tmpCategory = idx.getCategory();
							tmpArticleName = idx.getItemName();
							tmpAmount = idx.getAmount();
							cashRegister.registerItem(tmpCategory, tmpArticleName, tmpAmount);
						}

						std::cout << std::endl << "Total for this basket was: " << cashRegister.batchTotal()
							<< " Kr. Payment was made." << std::endl
							<< "Press ENTER to go back to start menu.";
						std::cin.get();

						basket.emptyBasket();

						showBasket = false;
						showItemList = false;
					}
				} while (showBasket);

			} while (showItemList);

	} while (again);
	
}

int main() {
	
	App payDesk;
	return payDesk.run();
	
}


