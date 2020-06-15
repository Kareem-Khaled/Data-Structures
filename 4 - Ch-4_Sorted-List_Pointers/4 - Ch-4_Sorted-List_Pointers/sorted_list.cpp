#include "sorted_list.h"

struct node{
	itemType value;
	node* next;
};

sorted_list::sorted_list(){
	length = 0;
	listData = NULL;
}

bool sorted_list::isFull() const{
	try{
		node* location = new node;
		delete location;
		return false;
	}
	catch (bad_alloc exception){
		return true;
	}
}

int sorted_list::getLength() const{
	return length;
}

void sorted_list::makeEmpty(){
	node *temp;
	while (listData != NULL){
		temp = listData;
		listData = listData->next;
		delete temp;
	}
	length = 0;
}

void sorted_list::putItem(itemType item){
	node *location, *prelocation, *newNode = new node;
	location = listData;
	prelocation = NULL;
	newNode->value = item;
	while (location != NULL){
		if (item.compareTo(location->value) == LESS || item.compareTo(location->value) == EQUAL)
			break;
		prelocation = location;
		location = location->next;
	}
	if (prelocation == NULL){
		newNode->next = listData;
		listData = newNode;
	}
	else{
		newNode->next = location;
		prelocation->next = newNode;
	}
	length++;
}

itemType sorted_list::getItem(itemType item, bool& found){
	node *location = listData;
	while (location != NULL){
		if (item.compareTo(location->value) == EQUAL){
			found = 1;
			break;
		}
		location = location->next;
	}
	return item;
}

void sorted_list::deleteItem(itemType item){
	node *temp, *location = listData;
	if (item.compareTo(listData->value) == EQUAL){
		listData = listData->next;
		temp = location;
	}
	else{
		while (item.compareTo((location->next)->value) != EQUAL)
			location = location->next;

		temp = location->next;
		location->next = temp->next;
	}
	delete temp;
	length--;
}

void sorted_list::resrtList(){
	currentPos = NULL;
}

itemType sorted_list::getNextItem(){
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->value;
}

sorted_list::~sorted_list(){
									// Destructor : is executed automatically when an object is destroyed
									// and we use it here to set free alocated memory
									//					* important info *
		makeEmpty();				// Do you know if you create a pointer and alocated memory
									// this memory still alocated even though the program is terminat
									// so to solve this problem we must delete this pointers 
									// and this the Destructor jop
}