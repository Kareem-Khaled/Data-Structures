#include <cstddef>	 // library for using NULL with pointers
/*
		An Iterator object is an instance of a class that
		`knows` how to iterate over a particular ADT and is
		required to overload three operators: 
		- the dereference operator (*) => to get pointer value
		- increment operator (++) => to go to the next item
		- not equals operator (!=) => to compare between items
*/

template<class T>
struct node{
	T value;
	node* next;
};

template<class T>
class sorted_listIterator{
public:
	sorted_listIterator(node<T>* start);
	T& operator*();
	sorted_listIterator<T>& operator++();
	bool operator!=(const sorted_listIterator<T>& it) const;
private:
	node<T>* item;
};

template<class T>
sorted_listIterator<T>::sorted_listIterator(node<T> *start){
	this->item = start;
}

template<class T>
T& sorted_listIterator<T>::operator*(){
	return item->value;
}

template<class T>
sorted_listIterator<T>& sorted_listIterator<T>::operator++(){
	if (item == NULL || item->next == NULL)
		item = NULL;
	else
		item = item->next;
	return *this;
}

template<class T>
bool sorted_listIterator<T>::operator!=(const sorted_listIterator<T> &it) const{
	return item != it.item;
}