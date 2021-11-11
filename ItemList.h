// ItemList.h
// Author: Malla Grönqvist
// Date 10.04.2021
// Description: Class ItemList stores all items and the total number of items.
//				Provides functions for adding items to the list, printing the list,
//				getting an item from the list and a function for user interaction.

#pragma once

#include "Item.h"
#include <vector>

class ItemList
{
private:
	std::vector<Item>itemList;
	int nrOfItems;
public:
	ItemList();
	~ItemList();
	void addItem(int pCategory, const char *pArticleName, double pAmount);
	void printItemList();
	int getItemChoice();
	Item getItem(int pChoice);
};

