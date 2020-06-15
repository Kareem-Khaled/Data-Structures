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
 