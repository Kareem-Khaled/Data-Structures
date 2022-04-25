#include "sorted_listIterator.h"
#include <exception>  // libray for exception handling .. (try & catch)
using namespace std;

template<class T>
class sorted_list{
public:
	sorted_list();
	~sorted_list();
	void makeEmpty();
	bool isFull() const;
	int getLength() const;
	T getItem(T, bool&);
	void putItem(T);
	void deleteItem(T);
	void resrtList();
	sorted_listIterator<T> begin();
	sorted_listIterator<T> end();
private:
	node<T> *listData;
	int length;
};

template<class T>// begin pointing to the first element in the list
sorted_listIterator<T> sorted_list<T>::begin(){
	sorted_listIterator<T> it(listData);
	return it;
}

template<class T> // end pointing to NULL
sorted_listIterator<T> sorted_list<T>::end(){
	sorted_listIterator<T> it(NULL); 
	return it;
}

template<class T> // default constructor
sorted_list<T>::sorted_list(){
	length = 0;
	listData = NULL;
}

template<class T>
bool sorted_list<T>::isFull() const{
	try{
		node* location = new node;
		delete location;
		return false;
	}
	catch (bad_alloc exception){
		return true;
	}
}

template<class T>
int sorted_list<T>::getLength() const{
	return length;
}

template<class T>
void sorted_list<T>::makeEmpty(){
	node<T> *temp;
	while (listData != NULL){
		temp = listData;
		listData = listData->next;
		delete temp;
	}
	length = 0;
}

template<class T>
void sorted_list<T>::putItem(T item){
	node<T> *location, *prelocation, *newNode = new node<T>;
	location = listData;
	prelocation = NULL;
	newNode->value = item;
	while (location != NULL){
		if (item <= location->value)
			break;
		prelocation = location;
		location = location->next;
	}
	if (prelocation == NULL){
		newNode->next = listData;
		listData = newNode;
	}
	else{
		newNode->next = location;
		prelocation->next = newNode;
	}
	length++;
}

template<class T>
T sorted_list<T>::getItem(T item, bool& found){
	node *location = listData;
	while (location != NULL){
		if (item.compareTo(location->value) == EQUAL){
			found = 1;
			break;
		}
		location = location->next;
	}
	return item;
}

template<class T>
void sorted_list<T>::deleteItem(T item){
	node *temp, *location = listData;
	if (item.compareTo(listData->value) == EQUAL){
		listData = listData->next;
		temp = location;
	}
	else{
		while (item.compareTo((location->next)->value) != EQUAL)
			location = location->next;

		temp = location->next;
		location->next = temp->next;
	}
	delete temp;
	length--;
}

template<class T>
sorted_list<T>::~sorted_list(){
				// Destructor : is executed automatically when an object is destroyed
				// and we use it here to set free alocated memory
				//					* important info *
	makeEmpty();// Do you know if you create a pointer and alocated memory
				// this memory still alocated even though the program is terminat
				// so to solve this problem we must delete this pointers 
				// and this the Destructor jop
}