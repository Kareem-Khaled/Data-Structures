#include <iostream> 
#include <exception>  // libray for exception handling .. (try & catch)

enum Order { PRE_ORDER, IN_ORDER, POST_ORDER }; // to traverse the tree as we want

template<class T>
struct node{
	T info;
	node* left;
	node* right;
};

template<class T>
class Tree{
	public :
	Tree(); // Constructor.
	~Tree(); // Destructor.
	Tree(const Tree& originalTree); // Copy constructor.
	void operator=(const Tree& originalTree);
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int GetLength() const;
	T GetItem(T item, bool& found) const;
	void PutItem(T item);
	void DeleteItem(T item);
	void Print(Order order)const;
private:
	node<T>* root;
};

template<class T> // Default constructor
Tree<T>::Tree(){ 
	root = NULL;
}

template<class T> // Returns true if the memory has free space for another node and false otherwise.
bool Tree<T>::IsFull() const{ 
	node<T>* location;
	try{
		location = new node<T>;
		delete location;
		return false;
	}
	catch(std::bad_alloc exception){
		return true;
	}
} 

template<class T> // Returns true if the tree is empty and false otherwise. 
bool Tree<T>::IsEmpty() const{ 
	return root == NULL;
}

template<class T> // Calls the (recursive function) 'CountNodes' to count the nodes in the tree.
int Tree<T>::GetLength() const {
	return CountNodes(root);
}

template<class T> // Returns the number of nodes in the tree.
int CountNodes(node<T>* tree){ 
	if (tree == NULL)
		return 0;
	else
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template<class T> // Calls the (recursive function) 'Retrieve' to search the tree for item.
T Tree<T>::GetItem(T item, bool& found) const{ 
	Retrieve(root, item, found);
	return item;
}

template<class T> // Recursively searches tree for item, and returns found is (true, false).
void Retrieve(node<T>* tree, T& item, bool& found){ 
	if (tree == NULL)
		found = false; // item is not found.
	else if (item < tree->info)
		Retrieve(tree->left, item, found); // Search left subtree.
	else if (item > tree->info)
		Retrieve(tree->right, item, found); // Search right subtree.
	else{
		item = tree->info; // item is found.
		found = true;
	}
}

template<class T> // Calls the (recursive function) 'Insert' to insert item into tree.
void Tree<T>::PutItem(T item){
	Insert(root, item);
}

template<class T> // Inserts item into tree.
void Insert(node<T>*& tree, T item){ 
	if (tree == NULL) {// Tree is Empty.
		tree = new node<T>;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	} 
	else if (item < tree->info)
		Insert(tree->left, item); // Insert in left subtree.
	else
		Insert(tree->right, item); // Insert in right subtree.
}

template<class T> // Calls the (recursive function) Delete to delete item from tree.
void Tree<T>::DeleteItem(T item){
	Delete(root, item);
}

template<class T> // Deletes item from tree. (the item should be in the tree)
void Delete(node<T>*& tree, T item){
	if (item < tree->info)
		Delete(tree->left, item); // Look in left subtree.
	else if (item > tree->info)
		Delete(tree->right, item); // Look in right subtree 
	else
		DeleteNode(tree); // Node found; call DeleteNode.
}

template<class T> // Deleting the node 'tree' if it is a leaf or has only one non-NULL child.
void DeleteNode(node<T>*& tree){ // otherwise, the 'tree' data is replaced by its logical predecessor and the predecessor's node is deleted.					
	T data;	// Logical predecessor: it is the first item smaller than 'tree' (right-most node in the left subtree). 
	node<T>* tempPtr = tree;
	if (tree->left == NULL) {
		tree = tree->right; delete tempPtr;
	}
	else if (tree->right == NULL){
		tree = tree->left; delete tempPtr;
	}
	else{
		GetPredecessor(tree->left, data);
		tree->info = data; // Putting predecessor value in the 'tree' node.
		Delete(tree->left, data); // Deleting predecessor node.
	}
}

template<class T> // get the rightmost node in this sub-tree.
void GetPredecessor(node<T>* tree, T& data){
	while (tree->right != NULL)
		tree = tree->right;
	data = tree->info;
}

template<class T> // Calls recursive functions to print the tree in a specific order.
void Tree<T>::Print(Order order) const{
	switch (order) {
	case PRE_ORDER:
		PreOrder(root); // (root, left, right)
		break;
	case IN_ORDER:
		InOrder(root);  // (left, root, right)
		break;
	case POST_ORDER:
		PostOrder(root); // (left, right, root)
		break;
	}
	cout << endl;
}

template<class T> // (root, left, right)
void PreOrder(node<T> *tree) { 
	if (tree != NULL){
		std::cout << tree->info << ' ';
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}

template<class T> // (left, root, right)
void InOrder(node<T> *tree){ 
	if (tree != NULL){
		InOrder(tree->left);
		cout << tree->info << ' ';
		InOrder(tree->right);
	}
}

template<class T> // (left, right, root)
void PostOrder(node<T> *tree){
	if (tree != NULL){
		PostOrder(tree->left);
		PostOrder(tree->right);
		cout << tree->info << ' ';
	}
}

template<class T> // Constructor calls the (recursive function) 'CopyTree' to copy originalTree into root.
Tree<T>::Tree(const Tree<T>& originalTree) {
	CopyTree(root, originalTree.root);
} 

template<class T> // Calls the (recursive function) 'CopyTree' to copy originalTree into root.
void Tree<T>::operator= (const Tree<T>& originalTree){
	if (&originalTree == this)
		return; // Ignore assigning self to self.
	Destroy(root); // Deallocate existing tree nodes.
	CopyTree(root, originalTree.root);
}

template<class T> // 'copy' is the root of a tree that is a duplicate of originalTree.
void CopyTree(node<T>*& copy, const node<T>* originalTree){ 
	if (originalTree == NULL)
		copy = NULL;
	else{
		copy = new node<T>;
		copy->info = originalTree->info;
		CopyTree(copy->left, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}
}

template<class T>// Calls (recursive function) Destroy to destroy the tree.
Tree<T>::~Tree(){
	Destroy(root);
}

template<class T> // nodes have been deallocated.
void Destroy(node<T>*& tree){
	if (tree != NULL){
		Destroy(tree->left); Destroy(tree->right); delete tree;
	}
}
