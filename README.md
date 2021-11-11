# CashRegister

This is a C++ console application that simulates a pay desk. 
Through the user interface the user can add items to a shopping basket 
from a list of items and pay for the items. 

The program registers all the items bought by customers
within the day and prints a register to file when the pay desk is closed
at the end of the day. The register contains all items with their prices
and categories, sales per item category and total sales for the day.

Example output to file:
>>>>> Register opened.
Cat.         1:     76.00 Kr.[ Laxbiffar ]
Cat.         4:     30.50 Kr.[ Kaffe ]
Cat.         2:     13.50 Kr.[ Kexchoklad ]
>>>>> Register closed.
Category totals for last opening period:
----------------------------------------
Category     1:     76.00 Kr.
Category     2:     13.50 Kr.
Category     3:      0.00 Kr.
Category     4:     30.50 Kr.
Category     5:      0.00 Kr.
Total sales within all categories: 120.00 Kr.
==========================================================================

## Technical description

The program consist of following interacting classes:
<li> Basket
<li> Item
<li> ItemList
<li> CashRegister

Objects of type Item contain the various product information. Items are stored in the ItemList, 
which is used to view the available products and to retrieve the items that the customer picks.
The Basket object is used to temporarily group together the items that the customer selects.
CashRegister instead enables storing the information from all Basket objects throughout the day.
