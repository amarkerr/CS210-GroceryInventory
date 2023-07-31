#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>


#include "item.h"

using namespace std;

//This method greets user
void Welcome() {
	for (int i = 0; i < 30; ++i) {
		cout << "*";
	}
	cout <<"\n*";
	for (int i = 0; i < 28; ++i) {
		cout << " ";
	}
	cout << "*" << endl;
	cout << "*  Welcome to Corner Grocer  *" << endl;
	cout << "*";
	for (int i = 0; i < 28; ++i) {
		cout << " ";
	}
	cout << "*" << endl;
	for (int i = 0; i < 30; ++i) {
		cout << "*";
	}
	cout << endl;
}

//This method displays the menu
void Menu() {
	cout << endl;
	for (int i = 0; i < 30; ++i) {
		cout << "*";
	}
	cout << "\n*";
	for (int i = 0; i < 28; ++i) {
		cout << " ";
	}
	cout << "*" << endl;
	cout << "*     Select an option:      *" << endl;
	cout << "*";
	for (int i = 0; i < 28; ++i) {
		cout << " ";
	}
	cout << "*" << endl;
	cout << "* [1] - Item Lookup          *" << endl;
	cout << "* [2] - Display Inventory    *" << endl;
	cout << "* [3] - Inventory Histogram  *" << endl;
	cout << "* [4] - Quit                 *" << endl;
	cout << "*";
	for (int i = 0; i < 28; ++i) {
		cout << " ";
	}
	cout << "*" << endl;
	for (int i = 0; i < 30; ++i) {
		cout << "*";
	}
	cout << endl;
}

//this method allows for clearing the input to assist with input validation
void InputClear() {
	cin.clear();
	cin.ignore(1000, '\n');  //This ignores up to 1000 extra characters or newlines
}


int main()
{
	ifstream inFS("CS210_Project_Three_Input_File.txt");
	ofstream outFS;

	map<string,int> itemMap;
	vector<Item> itemList;

	Item currItem;
	string currText;
	int currCount;
	char menuChoice = 0;
	bool run = true;

	//Validate opening file
	if (!inFS.is_open()) {
		cout << "Failed to open inventory file.\nEnding program." << endl;
		exit(0);
	}

	//Read data from file and create map
	while (inFS.good()) {
		getline(inFS, currText);

		if (!itemMap.count(currText)) {
			itemMap.emplace(currText, 1);
		}
		else {
			itemMap.at(currText) = itemMap.at(currText) + 1;
			
		}
	}


	//Output mapped data to file and create vector item list
	outFS.open("frequency.dat");
	map<string, int>::iterator it = itemMap.begin();
	while (it != itemMap.end()) {
		string word = it->first;
		int count = it->second;
		outFS << word << " " << count << endl;
		currItem.SetName(word);
		currItem.SetCount(count);
		itemList.push_back(currItem);
		it++;
	}

	//Close files
	inFS.close();
	outFS.close();


	Welcome();

	//Running loop
	while (run) {

		Menu();

		cin >> menuChoice;

		//Menu option 1 - Search quantity (uses map)
		if (menuChoice == '1') {
			InputClear();
			cout << endl;

			cout << "What item are you looking for? ";
			getline(cin, currText);

			if (itemMap.count(currText) == 1){
				cout << "There are: " << itemMap.at(currText) << " " << currText << " available." << endl;
			}

			else {
				cout << "There are currently no " << currText << " available." << endl;
			}

			cout << endl;
			continue;
		}

		//Menu option 2 - Printed inventory list with numerical representation
		else if (menuChoice == '2') {

			//formatting for display purposes
			cout << endl;
			for (int i = 0; i < 30; ++i) {cout << "*";}
			cout << "\n*";
			for (int i = 0; i < 28; ++i) {cout << " ";}
			cout << "*" << endl;
			cout << "*     Current Inventory      *" << endl;
			cout << "*";
			for (int i = 0; i < 28; ++i) {cout << " ";}
			cout << "*" << endl;
			for (int i = 0; i < 30; ++i) {cout << "*";}
			cout << endl;
			cout << endl;

			//Call print method for Item class in loop
			for (int i = 0; i < itemList.size(); ++i) {itemList[i].PrintItem();}
			cout << endl;
		}

		//Menu option 3 - Printed inventory histogram
		else if (menuChoice == '3') {

			//formatting for display purposes
			cout << endl;
			for (int i = 0; i < 30; ++i) {cout << "*";}
			cout << "\n*";
			for (int i = 0; i < 28; ++i) {cout << " ";}
			cout << "*" << endl;
			cout << "*     Current Inventory      *" << endl;
			cout << "*";
			for (int i = 0; i < 28; ++i) {cout << " ";}
			cout << "*" << endl;
			for (int i = 0; i < 30; ++i) {cout << "*";}
			cout << endl;
			cout << endl;

			//Call print histogram method for Item class in loop
			for (int i = 0; i < itemList.size(); ++i) {itemList[i].PrintHistogram();}
			cout << endl;
		}

		//Menu option 4 - End program
		else if (menuChoice == '4') {  //Leaves loop, resulting in program end
			cout << endl;
			cout << "Thank you for shopping with Corner Grocer.\nGoodbye." << endl;
			return 0;
		}

		//Menu option invalid - Outputs notice, loops back to menu and choice
		else {
			cout << "Invalid menu choice.\nPlease re-enter your menu choice." << endl;
		}


		InputClear();
	}

	return 0;
}