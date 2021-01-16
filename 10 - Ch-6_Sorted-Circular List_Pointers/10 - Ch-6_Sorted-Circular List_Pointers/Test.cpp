/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
				Believe in yourself ,( try and try and then try ), You can do it 💗
*/
#include"sorted_Circular_list.h"
#include <iostream>
#include<string>
using namespace std;
int main(){
	sorted_Circular_list<string> list;

	// the list is empty so the answer is NO.
	cout << (list.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

	// put 5 items into the list 
	list.putItem("Z");
	list.putItem("K");
	list.putItem("N");
	list.putItem("A");
	list.putItem("E");

	// make sure form Cycle
	cout << "Begin Cycle from A : "; list.moveFrom("A");
	cout << "Begin Cycle from B : "; list.moveFrom("B");
	cout << "Begin Cycle from Z : "; list.moveFrom("Z");
	cout << "Begin Cycle from K : "; list.moveFrom("K");
	cout << "Begin Cycle from C : "; list.moveFrom("C");
	cout << "Begin Cycle from D : "; list.moveFrom("D");
	cout << "Begin Cycle from N : "; list.moveFrom("N");


	// check if it is full now ,absolutely the answer is NO, Because we don't know when the memory will be full :)
	cout << "after adding 5 items : ";
	cout << (list.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

	// get length of the list
	cout << "Length now is : " << list.getLength() << endl;

	/*
		iterate overall items and print them
		but first we need to call resetList to
		initialize the currentPos by -1
	*/
	list.resrtList();
	cout << "Items are : ";
	for (int i = 0; i < list.getLength(); i++){
		cout << list.getNextItem() << " \n"[i + 1 == list.getLength()];
	}

	// try to remove item from the list
	list.deleteItem("E");

	// see if the length is redused & print the items to ensure from deleting 
	list.resrtList();
	cout << "after removing E from the list Length now is : " << list.getLength() << endl;
	cout << "Items are : ";
	for (int i = 0; i < list.getLength(); i++){
		cout << list.getNextItem() << " \n"[i + 1 == list.getLength()];
	}

	/*
		check if item K is exist or not.
		first we create new item with the value we want to search
		second create boolean found to know if the item is exist or not
	*/
	bool found = false;
	cout << "check if the item K are exist or not : ";
	list.getItem("K", found);
	cout << (found ? "YES, it is exist\n" : "NO, it isn't exist\n");


	found = false;
	cout << "check if the item S are exist or not : ";
	list.getItem("S", found);
	cout << (found ? "YES, it is exist\n" : "NO, it isn't exist\n");

	// try to make the list empty 
	list.makeEmpty();
	list.resrtList();
	cout << "after making the list empty Length now is : " << list.getLength() << endl;
	cout << "Items are : ";
	for (int i = 0; i < list.getLength(); i++){
		cout << list.getNextItem() << " \n"[i + 1 == list.getLength()];
	}
	cout << endl;
	system("pause");
}

/*
		Hi
			Assuming this code is as the same as the book, and you should optimize it yourself :)
			Please do not be lazy for doing that D=

			The assumption is :
			- you shouldn't put item if the list is full
			- you shouldn't delete item isn't exist
			- you should call resetList() before showing all items in the list
			- I hope I haven't forgotten anything, but if the program crashes on your face, forgive me :)
			and if you had any problem with code just Ask :)
		Bye
*/