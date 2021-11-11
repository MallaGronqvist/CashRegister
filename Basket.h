// Basket.h
// Author: Malla Grönqvist
// Date 10.04.2021
// Description: Class Basket stores the items a customer chooses. Provides functions for adding
//				and removing items as well as emptying the basket when the customer has paid.
//				Includes also a function for printing a sub menu and getting the user's choice.

#pragma once
#include "Item.h"
#include<vector>


class Basket
{
private:
	std::vector<Item>basket;
	int nrOfItemsInBasket;
public:
	Basket();
	~Basket();
	void showBasket();
	void addItemToBasket(Item pItem);
	void removeItemFromBasket();
	void emptyBasket();
	int getChoiceToProceed();
	std::vector<Item> getBasket();
};

