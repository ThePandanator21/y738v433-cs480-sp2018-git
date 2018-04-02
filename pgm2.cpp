//Author : Andrew Son
//Student ID : Y738V433
//Program Number : 2

//This Program is to keep track of inventory amount 
//while writing to a file inventory.txt
//This program was updated to use classes

/*
 *
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


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item
{
	int itemNum;
	string itemName;
	int itemQuant;
	float itemCost;
	float itemGross;
	
	public:
	
	//function to set values
	void setItem(int, string, int, float);
		
	//function to reveal values, it makes some logic easier down the road
	int getNum();
	string getName();
	int getQuant();
	float getCost();
	float getGross();	
};

void Item::setItem (int num, string name, int quant, float cost)
{
	itemNum = num;
	itemName = name;
	itemQuant = quant;
	itemCost = cost;
	
	//Instead of having a dedicated function for this 
	//it makes more sense to do it here
	itemGross = itemQuant * itemCost;
}

int Item::getNum()
{
	return itemNum;
}

string Item::getName()
{
	return itemName;
}

int Item::getQuant()
{
	return itemQuant;
}

float Item::getCost()
{
	return itemCost;
}

float Item::getGross()
{
	return itemGross;
}

int main()
{
	
	//This is used to generate item array
	//item invitem[101]; Andrew Son
	Item invItem[101];
	
	//Opens File For use
	ifstream invfilein;
	invfilein.open("inventory.txt");

	if(!invfilein.good())
	{
		cout << "File does not exist! Generating blank inventory..." << endl;
		
		//Nullifies entire array for use when no file
		for (int x = 1; x <= 100; x++)
		{		
			invItem[x].setItem(x, "null", 0, 0.00);
		}
	}
	else if (invfilein.good())
	{
		int filequant;
		float filecost;
		string filepart;
		
		bool endoffile = false;
		
		for (int x = 1; x <= 100; x++)
		{
			invfilein >> filequant >> filecost;
			invfilein.ignore();
			getline(invfilein, filepart);
			
			//Reads into array, checks for nulls to not repeat
			if ((invItem[x-1].getName() != filepart) && (endoffile == false))
			{
		
				invItem[x].setItem( x, filepart, filequant, filecost);
				
			}
			else
			{		
				invItem[x].setItem(x, "null", 0, 0.00);
				
				endoffile = true;
			}
		}	
	}
	
	invfilein.close();

	//This is used to hold the value for menu navigation
	int menu_userinput =0 ;

	while (menu_userinput != 5)
	{
		cout << "What would you like to do?" << endl;
		cout << "1: Print Inventory" << endl;
		cout << "2: Enter a new Part" << endl;
		cout << "3: Modify a Part" << endl;
		cout << "4: Print Total Inventory Cost" << endl;
		cout << "5: Exit" << endl;

		cin >> menu_userinput;
		cin.ignore();

		switch (menu_userinput)
		{
		case 1:
		{
			//Running throug entire array to print list
			for (int x = 1; x <= 100; x++)
			{
				//checks for nulls to print only what exists
				if (invItem[x].getName() != "null")
				{
					
					cout << invItem[x].getNum() << " ";
					cout << invItem[x].getName() << " ";
					cout << invItem[x].getQuant() << " $";
					cout << invItem[x].getCost() << " $";
					cout << invItem[x].getGross() << endl;
					
				}
			}

			break;
		}

		case 2:
		{
			//Run through list to find a spot that is null
			//then stops to edit said location Andrew Son

			//this bool is the flag out
			bool escape = false;

			//this x is to run through array
			int x = 0;

			while (escape != true)
			{
				x++;

				//This will run through the array looking for the null flag name
				//then it will use x's place in the array to edit that location
				//finally it will set escape to true to "break" out of the loop Andrew Son
				if (invItem[x].getName() == "null")
				{
				
					//holds the inputs so it can write to array at the end
					string tempName;
					int tempQuant;
					float tempCost;
					
					cout << "Enter Item Name:" << endl;
					getline(cin, tempName);
					
					cout << "Enter Quantity:" << endl;
					cin >> tempQuant;
					cin.ignore();
					
					cout << "Enter Item Cost (Do not use $):" << endl;
					cin >> tempCost;
					cin.ignore();
					
					invItem[x].setItem( x, tempName, tempQuant, tempCost);

					escape = true;
				}
			}
			break;
		}
		case 3:
		{
			//asks user for part location
			cout << "Enter Part to be Edited:" << endl;
			//integer to see which part to edit
			int toedit;

			cin >> toedit;
			cin.ignore();

			//veryifiys that the location is real

			if ((toedit >= 1) && (toedit <= 100))
			{

				//prints out line to be edited
				cout << endl;
				cout << invItem[toedit].getNum() << " ";
				cout << invItem[toedit].getName() << " ";
				cout << invItem[toedit].getQuant() << " $";
				cout << invItem[toedit].getCost() << " $";
				cout << invItem[toedit].getGross() << endl;
				
				//Edits Part			
				//Variable holders so we can write to array at the end	
				string tempName;
				int tempQuant;
				float tempCost;
					
				cout << "Enter Item Name:" << endl;
				getline(cin, tempName);
									
				cout << "Enter Quantity:" << endl;
				cin >> tempQuant;
				cin.ignore();
					
				cout << "Enter Item Cost (Do not use $):" << endl;
				cin >> tempCost;
				cin.ignore();
					
				invItem[toedit].setItem( toedit, tempName, tempQuant, tempCost);

			}

			break;
		}
		case 4:
		{
			//creates a total by running through invitem.itotalcost

			float totalcost = 0;

			for (int x = 1; x <= 100; x++)
			{
				totalcost = totalcost + invItem[x].getGross();
			}

			cout << "Total Cost of Inventory: $" << totalcost << endl;

			break;
		}
		case 5:
		{
			//writes to file including null
			ofstream invfileout;
			invfileout.open("inventory.txt");
			
			for (int x = 1; x <= 100; x++)
			{
				invfileout << invItem[x].getQuant() << " ";
				invfileout << invItem[x].getCost() << " ";
				invfileout << invItem[x].getName() << endl;
				
			}
			
			invfileout.close();
			break;
		}
		}
	}

}
