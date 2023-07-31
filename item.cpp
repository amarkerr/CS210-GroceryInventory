#include "item.h"

void Item::SetName(string itemName) {
	this->itemName = itemName;
}

string Item::GetName() {
	return itemName;
}

void Item::SetCount(int itemCount) {
	this->itemCount = itemCount;
}

int Item::GetCount() {
	return itemCount;
}

void Item::PrintItem() {
	cout << "- " << this->itemName << ": " << this->itemCount << endl;
}

void Item::PrintHistogram() {
	cout << "- " << this->itemName << ": ";
	for (int i = 0; i < this->GetCount(); ++i) { cout << "*"; }
	cout << endl;
}


