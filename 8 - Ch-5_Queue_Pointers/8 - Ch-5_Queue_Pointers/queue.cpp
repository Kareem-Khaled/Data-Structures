#include "queue.h"
struct node{
	itemType value;
	node* next;
};

queue::queue(){
	front = NULL;
	rear = NULL;
}

bool queue::isEmpty()const{
	return front == NULL;
}

bool queue::isFull() const{
	try{
		node* location = new node;
		delete location;
		return false;
	}
	catch (bad_alloc exception){
		return true;
	}
}

void queue::enQueue(itemType item){
	if (isFull())
		throw fullQueue();
	node*location = new node;
	location->value = item;
	location->next = NULL;
	if (rear == NULL)
		front = location;
	else
		rear->next = location;
	rear = location;
}

void queue::deQueue(itemType &item){
	if (isEmpty())
		throw emptyQueue();
	node* temp = front;
	item = front->value;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	delete temp;
}

void queue::makeEmpty(){
	node *temp;
	while (front != NULL){
		temp = front;
		front = front->next;
		delete temp;
	}
}

queue::~queue(){
	makeEmpty();
}
