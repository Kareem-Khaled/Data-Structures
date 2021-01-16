/*
	we can't separate this file into .h and .cpp
	Because The compiler cannot instantiate afunction template 
	Unless it knows the actual parameter to the template
	And this actual parameter appears in the client code (Test.cpp).
*/

class fullStack{
};


class emptyStack{

};

const int maxItem = 5;

template<class T>
class stack{
public:
	stack();
	bool isEmpty()const;
	bool isFull()const;
	void push(T);
	T top()const;
	int size()const;
	void pop();
private:
	int Top;
	T arr[maxItem];
};


template<class T>
stack<T>::stack(){
	Top = -1;
}

template<class T>
bool stack<T>::isEmpty()const{
	return Top == -1;
}

template<class T>
bool stack<T>::isFull()const{
	return Top == maxItem - 1;
}

template<class T>
void stack<T>::push(T item){
	if (isFull())
		throw fullStack();
	arr[++Top] = item;
}

template<class T>
void stack<T>::pop(){
	if (isEmpty())
		throw emptyStack();
	Top--;
}

template<class T>
T stack<T>::top()const{
	if (isEmpty())
		throw emptyStack();
	return arr[Top];
}

template<class T>
int stack<T>::size()const{
	return Top + 1;
}