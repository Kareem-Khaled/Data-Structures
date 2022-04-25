template<class T>
struct Heap{ // we implemented it as struct bcs we didn't use it alone but will use it in the priority queue class
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	T* elements; // Array to be allocated dynamically
	int numElements;
};

template<class T>// Restores the order property of heaps to the tree between root and bottom.
void Heap<T>::ReheapDown(int root, int bottom){
	int maxChild, leftChild = root * 2 + 1, rightChild = root * 2 + 2;
	if (leftChild > bottom) return; // we are outside the heap
	if (leftChild == bottom)
		maxChild = leftChild;
	else{
		if (elements[leftChild] <= elements[rightChild])
			maxChild = rightChild;
		else
			maxChild = leftChild;
	}
	if (elements[root] < elements[maxChild]){
		swap(elements[root], elements[maxChild]);
		ReheapDown(maxChild, bottom);
	}
}

template<class T>// Restores the order property to the heap between root and bottom.
void Heap<T>::ReheapUp(int root, int bottom){
	if (bottom <= root) return; // we are outside the heap
	int parent = (bottom - 1) / 2;
	if (elements[parent] < elements[bottom]){
		swap(elements[parent], elements[bottom]);
		ReheapUp(root, parent);
	}
}