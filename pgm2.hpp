/*
//Author : Andrew Son
//Student ID : Y738V433
//Program Number : 2

Description : A modification of program 1 to convert the structure into
using classes.

Psuedo Code

Class Name : Item

Data:
	int itemNum - an integer that holds the location of the item in list is derived, not written
	string itemName - the name of the item
	int itemQuant - the amount of the item on hand
	float itemCost - the cost of the item
	float itemGross - the Gross cost of all of this item. Is derived, not written

mutators:
	set_num - sets itemNum
	set_name - sets itemName
	set_quant - sets itemQuant
	set_cost - sets itemCost
	 
	* OR
	
	setItem(itemNum, itemName, itemQuant, itemCost)

accesors:
	get_num - returns itemNum
	get_name - returns itemName
	get_quant - returns itemQuant
	get_cost - returns itemCost
	get_gross - returns itemGross
	
functions:
	calcGross - uses the itemQuant and itemCost to calculate the total gross cost (itemGross)
	must be called from outside class
	
	Input:None
	Output:None
	 
	itemGross = itemQuant * itemCost

*/
