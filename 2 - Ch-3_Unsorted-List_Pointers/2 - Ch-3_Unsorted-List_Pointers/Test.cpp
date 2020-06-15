/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
				Believe in yourself ,( try and try and then try ), You can do it 💗
*/
#include"itemType.h"
#include"unsorted_list.h"
#include <iostream>
using namespace std;
int main(){
	unsorted_list list;

	// the list is empty so the answer is NO.
	cout << (list.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

	// declare 6 items.
	itemType item1, item2, item3, item4, item5, item6;

	// initialize this items.
	item1.initialize("M");
	item2.initialize("E");
	item3.initialize("E");
	item4.initialize("R");
	item5.initialize("A");
	item6.initialize("K");

	// put this items into the list 
	list.putItem(item1);
	list.putItem(item2);
	list.putItem(item3);
	list.putItem(item4);
	list.putItem(item5);
	list.putItem(item6);

	// check if it is full now ,absolutely the answer is NO, Because we don't know when the memory will be full :)
	// we deall here with linked-list (Pointers)
	cout << "after adding 6 items : ";
	cout << (list.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

	// get length of the list
	cout << "Length now is : " << list.getLength() << endl;


	// iterate overall items and print them

	cout << "Items are : ";
	for (int i = 0; i < list.getLength(); i++){
		list.getNextItem().print();
		cout << " \n"[i + 1 == list.getLength()];
	}

	// try to remove item from the list
	itemType item;
	item.initialize("E");
	list.deleteItem(item);

	/*
		see if the length is redused & print the items to ensure from deleting
		but don't forget to call resetList function to show all elements from the beginig
	*/
	list.resrtList();
	cout << "after removing E from the list Length now is : " << list.getLength() << endl;
	cout << "Items are : ";
	for (int i = 0; i < list.getLength(); i++){
		list.getNextItem().print();
		cout << " \n"[i + 1 == list.getLength()];
	}


	/*
		check if item is exist or not.
		first we create new item with the value we want to search
		second create boolean found to know if the item is exist or not
	*/
	item.initialize("R");
	bool found = false;
	cout << "check if the item "; item.print(); cout << " are exist or not : ";
	list.getItem(item, found);
	cout << (found ? "YES, it is exist\n" : "NO, it isn't exist\n");


	// try to make the list empty 
	list.makeEmpty();
	list.resrtList();
	cout << "after making the list empty Length now is : " << list.getLength() << endl;
	cout << "Items are : ";
	for (int i = 0; i < list.getLength(); i++){
		list.getNextItem().print();
		cout << " \n"[i + 1 == list.getLength()];
	}
	cout << endl;

	// comparing two items
	item1.initialize("N");
	item2.initialize("K");
	item1.print();
	switch (item1.compareTo(item2)){
	case GREATER:
		cout << " is gretaer than ";
		break;
	case LESS:
		cout << " is smaller than ";
		break;
	default:
		cout << " is equal to ";
	}
	item2.print();
	cout << endl;
	system("pause");
}

/*
				Hi
					The assumption is :
 					 - you shouldn't put item if the list is full
					 - you shouldn't delete item isn't exist
					 - you should call resetList() before showing all items in the list
					 - I hope I haven't forgotten anything, but if the program crashes on your face, forgive me :)
					   and if you had any problem with code just Ask :)
				Bye

*/