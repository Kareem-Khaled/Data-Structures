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
#include"stack.h"
#include <iostream>
using namespace std;
int main(){
	stack stack;
	try{
		// the stack is empty so the answer is NO.
		cout << (stack.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

		// declare 6 items.
		itemType item1, item2, item3, item4, item5, item6;

		// initialize this items.
		item1.initialize("M");
		item2.initialize("E");
		item3.initialize("E");
		item4.initialize("R");
		item5.initialize("A");
		item6.initialize("K");

		// put this items into the stack 
		stack.push(item1);
		stack.push(item2);
		stack.push(item3);
		stack.push(item4);
		stack.push(item5);
		stack.push(item6);

		// check if it is full now , i hope it is :)
		cout << "after pushing 6 items : ";
		cout << (stack.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

		// show the top of the stack
		cout << "The top of the stack now is : "; stack.top().print(); cout << endl;

		// try to pop the top
		stack.pop();

		// print the top to ensure from poping 
		cout << "The top of the stack now is : "; stack.top().print(); cout << endl;
 
	}
	catch (fullStack exceptionObject){
		cerr << "FullStack exception thrown" << endl;
	}
	catch (emptyStack exceptionObject){
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