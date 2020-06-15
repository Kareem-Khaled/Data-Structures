#include "countedQueue.h"


countedQueue::countedQueue(){
 	length = 0;
}

countedQueue::countedQueue(int max) :queue(max){
	length = 0;
}

void countedQueue::enQueue(itemType item){
	try{
		queue::enQueue(item);
		length++;
	}
	catch (fullQueue){
		throw fullQueue();
	}
}

void countedQueue::deQueue(itemType& item){
	try{
		queue::deQueue(item);
		length--;
	}
	catch (emptyQueue){
		throw emptyQueue();
	}
}

int countedQueue::getLength()const{
	return length;
}



