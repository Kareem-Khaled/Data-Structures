/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it 💗
*/
#include"Tree.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
	Tree<string>tree;
	// the tree is empty so the answer is NO.
	cout << (tree.IsFull() ? "YES, it is full\n" : "NO, it isn't full\n");
	
	// put 4 items into the tree 
	tree.PutItem("c");	//		c
	tree.PutItem("a");	//	  a   d
	tree.PutItem("b");	//		b
	tree.PutItem("d");  // this is how the tree looks like.

	// get Length of the tree now
	cout << "Length now is : " << tree.GetLength() << endl;

	// check if "a" exist or not
	bool found = 0;
	tree.GetItem("a", found);
	cout << (found ? "YES, 'a' is in the tree\n" : "No, 'a' isn't in the tree\n");

	// printing in the 3 orders
	cout << "PRE  :"; tree.Print(PRE_ORDER);
	cout << "IN   :"; tree.Print(IN_ORDER);
	cout << "POST :"; tree.Print(POST_ORDER);

	// delete the root c
	cout << "--- deleting c ---\n";
	tree.DeleteItem("c");

	// printing in the 3 orders after deletion
	cout << "PRE  :"; tree.Print(PRE_ORDER);
	cout << "IN   :"; tree.Print(IN_ORDER);
	cout << "POST :"; tree.Print(POST_ORDER);

	// check if "c" exist or not
	found = 0;
	tree.GetItem("c", found);
	cout << (found ? "YES, 'c' is in the tree\n" : "No, 'c' isn't in the tree\n");

	// try '=' operator or (we can use copy constructor).
	Tree<string> tree2 = tree;
	cout << "--- in copied tree2 ---\n";

	// printing in the 3 orders in the copied tree
	cout << "PRE  :"; tree2.Print(PRE_ORDER);
	cout << "IN   :"; tree2.Print(IN_ORDER);
	cout << "POST :"; tree2.Print(POST_ORDER);

	system("pause");
}

/*
		Hi
			Assuming this code is the same as the book, you should optimize it yourself :)
			Please do not be lazy for doing that D=

			If you had any problem with code just ask :)
		Bye
*/