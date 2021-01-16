/*
	we can't separate this file into .h and .cpp
	Because The compiler cannot instantiate afunction template
	Unless it knows the actual parameter to the template
	And this actual parameter appears in the client code (Test.cpp).
*/

#include <cstddef>	 // library for using NULL with pointers
template<class T>
struct node{
	T value;
	node<T>* next, *back;
};

template<class T>
class Sorted_Doubly_List
{
public:
	Sorted_Doubly_List();
	~Sorted_Doubly_List();
	void makeEmpty();
	bool isFull() const;
	int getLength() const;
	void putItem(T);
	void deleteItem(T);
	void resrtList();
	void moveForwardFrom(T);
	void moveBackwardFrom(T);
	T getItem(T, bool&);
	T getNextItem();
private:
	node<T>* getLoc(T);
	node<T> *currentPos, *listData;
	int length;
};

template<class T>
Sorted_Doubly_List<T>::Sorted_Doubly_List(){
	length = 0;
	listData = NULL;
}

template<class T>
node<T>* Sorted_Doubly_List<T>::getLoc(T item){
	if (listData == NULL) // List is Empty
		return NULL;
	if (listData->value == item)  // The item we want is the first
		return listData;
	node<T> *location = listData->next;
	while (location != NULL && item != location->value) 
		location = location->next;
	return ((location != NULL && location->value == item) ? location : NULL); // return NULL if we don't find the item
}

template<class T>
void Sorted_Doubly_List<T>::moveForwardFrom(T item){
	node<T>*temp = getLoc(item);
	if (temp == NULL){
		cout << "Can't find this item\n";
		return;
	}
	cout << temp->value << ' ';
	node<T>* location = temp->next;
	while (location != NULL){// reach to last item
		cout << location->value << ' ';
		location = location->next;
	}
	cout << endl;
}

template<class T>
void Sorted_Doubly_List<T>::moveBackwardFrom(T item){
	node<T>*temp = getLoc(item);
	if (temp == NULL){
		cout << "Can't find this item\n";
		return;
	}
	cout << temp->value << ' ';
	node<T>* location = temp->back;
	while (location != NULL){// reach to first item 
		cout << location->value << ' ';
		location = location->back;
	}
	cout << endl;
}

template<class T>
bool Sorted_Doubly_List<T>::isFull() const{
	try{
		node<T>* location = new node<T>;
		delete location;
		return false;
	}
	catch (bad_alloc exception){
		return true;
	}
}

template<class T>
int Sorted_Doubly_List<T>::getLength() const{
	return length;
}

template<class T>
void Sorted_Doubly_List<T>::makeEmpty(){
	if (listData == NULL) // List is Empty
		return;
	node<T> *temp, *location = listData->next;
	while (location != NULL){
		temp = location;
		location = location->next;
		delete temp;
	}
	listData = NULL;
	length = 0;
}

template<class T>
void Sorted_Doubly_List<T>::putItem(T item){
	node<T> *location = listData, *newNode = new node<T>;
	newNode->value = item;
	if (listData == NULL){//newNode is the first element  
		newNode->next = NULL;
		newNode->back = NULL;
		listData = newNode;
	}
	else if (location->value >= newNode->value){// newNode is the smallest element (first)
		newNode->back = NULL;
		newNode->next = listData;
		location->back = newNode;
		listData = newNode;
	}
	else{// otherwise newNode is in the middle or back
		while (location->next != NULL && (location->next)->value < newNode->value)
			location = location->next;
		if (location->next == NULL){ // bigest element - put in back
			newNode->back = location;
			newNode->next = NULL;
			location->next = newNode;
		}
		else{ // middle elememt
			newNode->back = location;
			newNode->next = location->next;
			(location->next)->back = newNode;
			location->next = newNode;
		}
	}
	length++;
}

template<class T>
T Sorted_Doubly_List<T>::getItem(T item, bool& found){
	node<T> *location = getLoc(item);
	if (location == NULL) //we can't find the item
		return item;
	if (location->value == item)
		found = 1;
	return item;
}

template<class T>
void Sorted_Doubly_List<T>::deleteItem(T item){
	node<T>*location = getLoc(item);
	if (location == NULL)
		return;
	if (location->back == NULL){ // first element
		(location->next)->back = NULL;
		listData = listData->next;
	}
	else if (location->next == NULL) // last element
		(location->back)->next = NULL;
	else{ // middle element
		(location->back)->next = location->next;
		(location->next)->back = location->back;
	}
	delete location; length--;
}

template<class T>
void Sorted_Doubly_List<T>::resrtList(){
	currentPos = NULL;
}

template<class T>
T Sorted_Doubly_List<T>::getNextItem(){
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->value;
}

template<class T>
Sorted_Doubly_List<T>::~Sorted_Doubly_List(){
				// Destructor : is executed automatically when an object is destroyed
				// and we use it here to set free alocated memory
				//					* important info *
	makeEmpty();// Do you know if you create a pointer and alocated memory
				// this memory still alocated even though the program is terminat
				// so to solve this problem we must delete this pointers 
				// and this the Destructor jop
}