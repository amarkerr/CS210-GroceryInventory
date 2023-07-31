#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	Item() : itemName("None"), itemCount(0) {}

	void SetName(string itemName);
	string GetName();

	void SetCount(int itemCount);
	int GetCount();

	void PrintItem();
	void PrintHistogram();

private:
	string itemName;
	int itemCount;
};


#endif

