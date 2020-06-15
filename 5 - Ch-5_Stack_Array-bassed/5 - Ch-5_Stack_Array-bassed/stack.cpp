#include "stack.h"


stack::stack(){
	Top = -1;
}

bool stack::isEmpty()const{
	return Top == -1;
}

bool stack::isFull()const{
	return Top == maxItem - 1;
}

void stack::push(itemType item){
	if (isFull())
		throw fullStack();
	arr[++Top] = item;
}

void stack::pop(){
	if (isEmpty())
		throw emptyStack();
	Top--;
}

itemType stack::top()const{
	if (isEmpty())
		throw emptyStack();
	return arr[Top];
}

int stack::size()const{
	return Top + 1;
}

