#pragma once
#include "itemType.h"

class fullStack{
};


class emptyStack{

};


class stack{
public:
	stack();
	bool isEmpty()const;
	bool isFull()const;
	void push(itemType);
	itemType top()const;
	int size()const;
	void pop();
private:
	int Top;
	itemType arr[maxItem];
 };

