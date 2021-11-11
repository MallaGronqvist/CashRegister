// CashRegister.cpp
// Author: Malla Grönqvist
// Date 10.04.2021

#include "CashRegister.h"
#include <iomanip>
#include <iostream>


CashRegister::CashRegister(const char* fileName, int nrOfCategories) {

	// Open file for appending:
	_file.open(fileName, std::ios::app);

	if (_file.is_open()) {
		// print first line to file:
		_file << ">>>>> Register opened." << std::endl;
	}
	else {
		std::cout << "Error: could not open register!";
	}

	// Set data member value.
	_nrOfCategories = nrOfCategories;

	// Dynamically create _categorySums.
	_categorySums = new double[_nrOfCategories];

	// Set values to zero. 
	for (int i = 0; i < _nrOfCategories; ++i) {
		_categorySums[i] = 0;
	}
}

CashRegister::~CashRegister() {

	// Calculate final sales sum.
	double totalSales = 0.0;
	
	for (int i = 0; i < _nrOfCategories; i++) {
		totalSales += _categorySums[i];
	}

	// Write the day's sales per category and total sales in file.

	_file << ">>>>> Register closed." << std::endl << "Category totals for last opening period:"
		<< std::endl << "----------------------------------------" << std::endl;

	int count = 1;
	for (int i = 0; i < _nrOfCategories; i++) {
		_file << std::left << std::setw(10) << "Category" << std::right << std::setw(4) << count
			<< ":" << std::setw(10) << std::fixed << std::setprecision(2) 
			<< _categorySums[i] << std::setw(4) << "Kr." << std::endl;
		count++;
	}

	_file << "Total sales within all categories: " << totalSales << " Kr." 
		<< std::endl << "==========================================================================";

	// Write the end line in the file.
	_file << std::endl;

	// Release dynamic memory:
	delete[] _categorySums; 

	// Close file:
	_file.close();

}

bool CashRegister::registerItem(int category, const char* articleName, double amount) {

	// Write product to the register. Note product category, name and price. 
	// If input data is valid, add price to product category total and to batchTotal (The customer's total).

	if (category < 6 && category > 0 ) {

		_file << std::left << std::setw(10) << "Cat." << std::right << std::setw(4) << category << ":"
			<< std::setw(10) << std::fixed << std::setprecision(2) << amount
			<< std::setw(4) << "Kr." << "[ " << articleName << " ]" << std::endl;

		_categorySums[category - 1] += amount;

		_batchTotal += amount;

		return true; // If registration is succesfull, return true, else return false.
	}
	else {
		return false;
	}
}