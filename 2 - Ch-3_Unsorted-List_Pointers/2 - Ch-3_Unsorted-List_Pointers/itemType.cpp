#include "itemType.h"
itemType::itemType(){
	value = "";
}

void itemType::print(){
	cout << value;
}

void itemType::initialize(string value){
	this->value = value;
}

relation itemType::compareTo(itemType otherItem)const{
	if (this->value < otherItem.value)
		return LESS;
	else if (this->value > otherItem.value)
		return GREATER;
	return EQUAL;
}
