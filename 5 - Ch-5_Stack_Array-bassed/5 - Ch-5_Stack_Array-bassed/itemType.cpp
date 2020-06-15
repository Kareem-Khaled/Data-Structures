#include "itemType.h"
#include <iostream>
using namespace std;
itemType::itemType(){
	value = 0;
}

void itemType::print(){
	cout << value;
}

void itemType::initialize(int value){
	this->value = value;
}
 