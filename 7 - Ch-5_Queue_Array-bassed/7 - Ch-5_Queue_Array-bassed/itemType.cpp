#include "itemType.h"
#include <iostream>
using namespace std;
itemType::itemType(){
	value = NULL;
}

void itemType::print(){
	cout << value;
}

void itemType::initialize(int value){
	this->value = value;
}
 