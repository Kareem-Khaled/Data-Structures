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
#include"queue.h"
#include <iostream>
using namespace std;
int main(){
	queue queue;
	try{
		// the queue is empty so the answer is NO.
		cout << (queue.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

		// declare 6 items.
		itemType item1, item2, item3, item4, item5, item6;

		// initialize this items.
		item1.initialize('K');
		item2.initialize('A');
		item3.initialize('R');
		item4.initialize('E');
		item5.initialize('E');
		item5.initialize('M');

		// put this items into the queue 
		queue.enQueue(item1);
		queue.enQueue(item2);
		queue.enQueue(item3);
		queue.enQueue(item4);
		queue.enQueue(item5);
		queue.enQueue(item6);


		// check if it is full now , i hope it is :)
		cout << "after pushing 6 items : ";
		cout << (queue.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

		// deque the front of queue & show the top of the it
		cout << "The front of the Queue now is : "; queue.deQueue(item1); item1.print(); cout << endl;

		// show the top of the queue
		cout << "The top of the Queue now is : "; queue.deQueue(item1); item1.print(); cout << endl;

	 
	}
	catch (fullQueue exceptionObject){
		cerr << "FullStack exception thrown" << endl;
	}
	catch (emptyQueue exceptionObject){
		cerr << "EmptyStack exception thrown" << endl;
	}
	system("pause");
}


/*
			Hi 
			The assumption is :
				- you shouldn't put item if the list is full
				- you shouldn't delete item isn't exist
 				- I hope I haven't forgotten anything, but if the program crashes on your face, forgive me :)
				and if you had any problem with code just Ask :)
			Bye

*/