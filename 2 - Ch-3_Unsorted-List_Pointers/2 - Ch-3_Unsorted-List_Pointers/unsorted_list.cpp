#include "unsorted_list.h"

struct node{
	itemType value;
	node* next;
};

unsorted_list::unsorted_list(){
	length = 0;
	listData = NULL;
}

bool unsorted_list::isFull() const{
	try{
		node* location = new node;
		delete location;
		return false;
	}
	catch (bad_alloc exception){
		return true;
	}
}

int unsorted_list::getLength() const{
	return length;
}

void unsorted_list::makeEmpty(){
	node *temp;
	while (listData != NULL){
		temp = listData;
		listData = listData->next;
		delete temp;
	}
	length = 0;
}

void unsorted_list::putItem(itemType item){
	node *location = new node;
	location->value = item;
	location->next = listData;
	listData = location;
	length++;
}

itemType unsorted_list::getItem(itemType item, bool& found){
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

void unsorted_list::deleteItem(itemType item){
	node *temp, *location = listData;
	if (item.compareTo(listData->value) == EQUAL){	// if the item we search about it in the top
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

void unsorted_list::resrtList(){
	currentPos = NULL;
}

itemType unsorted_list::getNextItem(){
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->value;
}

unsorted_list::~unsorted_list(){
										// Destructor : is executed automatically when an object is destroyed
										// and we use it here to set free alocated memory
										//					* important info *
	makeEmpty();						// Do you know if you create a pointer and alocated memory
										// this memory still alocated even though the program is terminat
										// so to solve this problem we must delete this pointers 
										// and this the Destructor jop
}