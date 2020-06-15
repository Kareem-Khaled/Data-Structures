#pragma once
#include "queue.h"
class countedQueue:public queue
{
public:
	countedQueue();
	countedQueue(int);
	void enQueue(itemType);
	void deQueue(itemType&);
	int getLength()const;
private:
	int length;
};

