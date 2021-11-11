// Item.cpp
// Author: Malla Grönqvist
// Date 10.04.2021

#include "Item.h"


void Item::setCategory(int pCategory) {
	category = pCategory;
}

void Item::setName(const char *pArticleName) {
	articleName = pArticleName;
}

void Item::setAmount(double pAmount) {
	amount = pAmount;
}

const char* Item::getItemName() {
	return articleName;
}

int Item::getCategory() {
	return category;
}

double Item::getAmount() {
	return amount;
}