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

	// the list is empty so the answer is NO.								// it is the same as :
																			// if (list.isFull() == true)
	cout << (list.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");	//		cout<<"YES, it is full\n";
																			// else
																			//		cout<<"NO, it isn't full\n";
	// declare 5 items.
	itemType item1, item2, item3, item4, item5;

	// initialize this items.
	item1.initialize(13);
	item2.initialize(8);
	item3.initialize(2000);
	item4.initialize(0);
	item5.initialize(1);

	// put this items into the list 
	list.putItem(item1);
	list.putItem(item2);
	list.putItem(item3);
	list.putItem(item4);
	list.putItem(item5);

	// check if it is full now , i hope it is :)
	cout << "after adding 5 items : ";
	cout << (list.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

	// get length of the list
	cout << "Length now is : " << list.getLength() << endl;

	/*
		iterate overall items and print them
		but first we need to call resetList to
		initialize the currentPos by -1  :}
	*/
	list.resrtList();
	cout << "Items are : ";
	for (int i = 0; i < list.getLength(); i++){
														// it is the same as :
		list.getNextItem().print();						// if (i + 1 == list.getLength())
														//		cout<<" \n";
		cout << " \n"[i + 1 == list.getLength()];		//	else 
														//		cout<<" ";
	}
	// try to remove item 0 from the list
	itemType item;
	item.initialize(0);
	list.deleteItem(item);

	// see if the length is redused & print the items to ensure from deleting 
	list.resrtList();
	cout << "after removing 0 from the list Length now is : " << list.getLength() << endl;
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
	item.initialize(8);
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
	item1.initialize(10);
	item2.initialize(20);
	item1.print();
	switch (item1.compareTo(item2)){
	case GREATER:
		cout << " gretaer than ";
		break;
	case LESS:
		cout << " smaller than ";
		break;
	default:
		cout << " equal to ";
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