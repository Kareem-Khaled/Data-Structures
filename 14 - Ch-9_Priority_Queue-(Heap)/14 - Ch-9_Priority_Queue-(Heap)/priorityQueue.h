#include"Heap.h"
using namespace std;

class FullPQ{};
class EmptyPQ{};

template<class T>
class priorityQueue{
	public :
		priorityQueue(int);
		~priorityQueue();
		void MakeEmpty();
		bool IsEmpty() const;
		bool IsFull() const;
		void Enqueue(T newItem);
		void Dequeue(T& item);
private:
	Heap<T> items;
	int length, maxItems;
};

template<class T>// constructor
priorityQueue<T>::priorityQueue(int max){
	maxItems = max;
	items.elements = new T[max];
	length = 0;
} 

template<class T>
void priorityQueue<T>::MakeEmpty(){
	length = 0;
} 

template<class T> // removing the element with highest priority 
void priorityQueue<T>::Dequeue(T& item){
	if (length == 0)
		throw EmptyPQ();
	else{
		item = items.elements[0];
		items.elements[0] = items.elements[--length]; // putting the last item value in the first
		items.ReheapDown(0, length - 1); // then get the heap default shape
	}
}

template<class T> // inserting new element
void priorityQueue<T>::Enqueue(T newItem){
	if (length == maxItems)
		throw FullPQ();
	else{
		items.elements[length++] = newItem; // putting new item in the last place
		items.ReheapUp(0, length - 1); // then get the heap default shape
	}
}
template<class T>// Returns true if the queue is full and false otherwise.
bool priorityQueue<T>::IsFull() const{
	return length == maxItems;
}

template<class T> // Returns true if the queue is empty and false otherwise.
bool priorityQueue<T>::IsEmpty() const{
	return length == 0;
}

template<class T>// Deconstructor
priorityQueue<T>::~priorityQueue(){
	delete[] items.elements;
}
