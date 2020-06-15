#include "itemType.h"
itemType::itemType(){
	value = NULL;
}

void itemType::print(){
	cout << value;
}

void itemType::initialize(char value){
	this->value = value;
}
 