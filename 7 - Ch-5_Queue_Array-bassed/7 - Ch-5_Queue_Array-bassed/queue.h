#pragma once
#include "itemType.h"

class fullQueue{
};


class emptyQueue{

};


class queue{
public:
	queue();
	queue(int);
	bool isEmpty()const;
	bool isFull()const;
	void makeEmpty();
	void enQueue(itemType);
	void deQueue(itemType&);
 	~queue();
private:
	int front, rear, maxQueue;
	itemType* arr;
};

