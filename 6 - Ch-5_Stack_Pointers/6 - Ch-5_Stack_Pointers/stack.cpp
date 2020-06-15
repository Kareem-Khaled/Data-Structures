#include "stack.h"
struct node{
	itemType value;
	node* next;
};

stack::stack(){
	topPtr = NULL;
}

bool stack::isEmpty()const{
	return topPtr == NULL;
}

bool stack::isFull() const{
	try{
		node* location = new node;
		delete location;
		return false;
	}
	catch (bad_alloc exception){
		return true;
	}
}

void stack::push(itemType item){
	if (isFull())
		throw fullStack();
	node*location = new node;
	location->value = item;
	location->next = topPtr;
	topPtr = location;
}

void stack::pop(){
	if (isEmpty())
		throw emptyStack();
	node* temp = topPtr;
	topPtr = topPtr->next;
	delete temp;
}

itemType stack::top(){
	if (isEmpty())
		throw emptyStack();
	return topPtr->value;
}

stack::~stack(){
	node *temp;
	while (topPtr!= NULL){
		temp = topPtr;
		topPtr = topPtr->next;
		delete temp;
	}
}
