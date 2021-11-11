// CashRegister.h
// Author: Malla Grönqvist (partly)
// Date 10.04.2021
// Description: Class CashRegister opens a register file when program starts, 
//				registers each sold item and daily sales per item category
//				in the register and closes file when program ends.

#pragma once
#include <fstream>

class CashRegister {
public:
	CashRegister(const char* fileName, int nrOfCategories); // constructor
	~CashRegister(); // destructor
	bool registerItem(int category, const char* articleName, double amount);
	double batchTotal() { // Used when customer pays.
		double total = _batchTotal;
		_batchTotal = 0; // batchTotal() is expected to reset _batchTotal;
		return total;
	}
private:
	std::ofstream _file; // Here will registered items be saved
	int _nrOfCategories; // Products are organized in categories
	double* _categorySums; // The vector will contain respective sum of each
	// category sold during the day
	double _batchTotal; // Sold since the last summation
};

