// Item.h
// Author: Malla Grönqvist
// Date 10.04.2021
// Description: Class item stores item data and provides set and get functions.

#pragma once



class Item
{ 
private:
	int category;
	const char *articleName;
	double amount;
public:
	void setCategory(int pCategory);
	void setName(const char *pArticleName);
	void setAmount(double pAmount);
	const char* getItemName();
	int getCategory();
	double getAmount();
};

