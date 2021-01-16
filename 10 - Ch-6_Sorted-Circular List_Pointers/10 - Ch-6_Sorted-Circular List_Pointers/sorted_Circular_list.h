/*
	we can't separate this file into .h and .cpp
	Because The compiler cannot instantiate afunction template
	Unless it knows the actual parameter to the template
	And this actual parameter appears in the client code (Test.cpp).
*/

#include <exception>  // libray for exception handling .. (try & catch)
#include <cstddef>	 // library for using NULL with pointers
#include<string>
using namespace std;

template<class T>
struct node{
	T value;
	node<T>* next;
};

template<class T>
class sorted_Circular_list
{
public:
	sorted_Circular_list();
	~sorted_Circular_list();
	void makeEmpty();
	bool isFull() const;
	int getLength() const;
	void putItem(T);
	void deleteItem(T);
	void resrtList();
	void moveFrom(T);
	T getItem(T, bool&);
	T getNextItem();
private:
	node<T>* getLoc(T);
	node<T> *currentPos, *listData;
	int length;
};

template<class T>
sorted_Circular_list<T>::sorted_Circular_list(){
	length = 0;
	listData = NULL;
}

template<class T>
node<T>* sorted_Circular_list<T>::getLoc(T item){
	if (listData == NULL) // list is Empty
		return NULL;
	if (listData->value == item) // The item we want is the first
		return listData;
	node<T> *location = listData->next;
	while (location != listData && item != location->value)
		location = location->next;
	return (location->value == item ? location : NULL);// return NULL if we don't find the item
}

template<class T>
void sorted_Circular_list<T>::moveFrom(T item){
	node<T>*temp = getLoc(item);
	if (temp == NULL){
		cout << "Can't find this item\n";
		return;
	}
	cout << temp->value << ' ';
	node<T>* location = temp->next;
	while (location != temp){
		cout << location->value << ' ';
		location = location->next;
	}
	cout << endl;
}

template<class T>
bool sorted_Circular_list<T>::isFull() const{
	try{ // try to allocate new node
		node<T>* location = new node<T>;
		delete location;
		return false;
	}
	catch (bad_alloc exception){
		return true;
	}
}

template<class T>
int sorted_Circular_list<T>::getLength() const{
	return length;
}

template<class T>
void sorted_Circular_list<T>::makeEmpty(){
	if (listData == NULL) // list is Empty
		return;
	node<T> *temp, *location = listData->next;
	while (location != listData){ // if we reach to listDate, then we are done one Cycle
		temp = location;
		location = location->next;
		delete temp;
	}
	listData = NULL;
	length = 0;
}

template<class T>
void sorted_Circular_list<T>::putItem(T item){
	node<T> *location = listData, *newNode = new node<T>;
	newNode->value = item;
	if (listData == NULL){//newNode is the first element 
		newNode->next = newNode;
		listData = newNode;
	}
	else if (location->value >= newNode->value){// newNode is the smallest element (first)
		while (location->next != listData)// get last element and make cycle with newNode
			location = location->next;
		location->next = newNode;
		newNode->next = listData;
		listData = newNode;
	}
	else{// otherwise newNode is in the middle or back
		while (location->next != listData && (location->next)->value < newNode->value)
			location = location->next;
		newNode->next = location->next;
		location->next = newNode;
	}
	length++;
}

template<class T>
T sorted_Circular_list<T>::getItem(T item, bool& found){
	node<T> *location = getLoc(item);
	if (location == NULL)//we can't find the item
		return item;
	if (location->value == item)
		found = 1;
	return item;
}

template<class T>
void sorted_Circular_list<T>::deleteItem(T item){
	node<T> *temp, *location = listData;
	if (item == listData->value) {
		listData = listData->next;
		delete location; length--;
		return;
	}
	while (location->next != listData && item != (location->next)->value)
		location = location->next;
	if ((location->next)->value == item){
		temp = location->next;
		location->next = temp->next;
		delete temp; length--;
	}
}

template<class T>
void sorted_Circular_list<T>::resrtList(){
	currentPos = NULL;
}

template<class T>
T sorted_Circular_list<T>::getNextItem(){
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->value;
}

template<class T>
sorted_Circular_list<T>::~sorted_Circular_list(){
				// Destructor : is executed automatically when an object is destroyed
				// and we use it here to set free alocated memory
				//					* important info *
	makeEmpty();// Do you know if you create a pointer and alocated memory
				// this memory still alocated even though the program is terminat
				// so to solve this problem we must delete this pointers 
				// and this the Destructor jop
}