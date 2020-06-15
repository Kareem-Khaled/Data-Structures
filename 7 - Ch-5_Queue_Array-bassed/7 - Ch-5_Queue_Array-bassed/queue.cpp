#include "queue.h"


queue::queue(){
	maxQueue = 6;
	front = 5;
	rear = 5;
	arr = new itemType[maxQueue];
}

queue::queue(int max){
	maxQueue = max + 1;
	front = max;
	rear = max;
	arr = new itemType[maxQueue];
}

bool queue::isEmpty()const{
	return front == rear;
}

bool queue::isFull()const{
	return ((rear + 1) % maxQueue) == front;
}

void queue::makeEmpty(){
	front = maxQueue - 1;
	rear = maxQueue - 1;
}

void queue::enQueue(itemType item){
	if (isFull())
		throw fullQueue();
	rear = (rear + 1) % maxQueue;
	arr[rear] = item;
}

void queue::deQueue(itemType& item){
	if (isEmpty())
		throw emptyQueue();
	front = (front + 1) % maxQueue;
	item = arr[front];
}

queue::~queue(){
	delete[] arr;
}
