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

		// declare 5 items.
		itemType item1, item2, item3, item4, item5;

		// initialize this items.
		item1.initialize(13);
		item2.initialize(8);
		item3.initialize(2000);
		item4.initialize(0);
		item5.initialize(1);

		// put this items into the stack 
		stack.push(item1);
		stack.push(item2);
		stack.push(item3);
		stack.push(item4);
		stack.push(item5);

		// check if it is full now , i hope it is :)
		cout << "after pushing 5 items : ";
		cout << (stack.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

		// get size of the stack now
		cout << "size now is : " << stack.size() << endl;

		// show the top of the stack
		cout << "The top of the stack now is : "; stack.top().print(); cout << endl;

		// try to pop the top
		stack.pop();

		// see if the size is redused & print the top to ensure from poping 

		cout << "after pop the top the size now is : " << stack.size() << endl;

		// show the top of the stack
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
				Assuming this code is as the same as the book, and you should optimize it yourself :)
				Please do not be lazy for doing that D=

				The assumption is :
				- you shouldn't put item if the stack is full
				- you shouldn't delete item isn't exist
 				- I hope I haven't forgotten anything, but if the program crashes on your face, forgive me :)
				and if you had any problem with code just Ask :)
			Bye

*/