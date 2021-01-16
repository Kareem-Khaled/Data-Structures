/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
				Believe in yourself ,( try and try and then try ), You can do it 💗
*/
#include"stack.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
	stack<int>Stack; stack<char>Stack2; 
	stack<string>Stack3; stack<bool>Stack4; 
	stack<float>Stack5; stack<double>Stack6;
	try{
		// the stack is empty so the answer is NO.
		cout << (Stack.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

		// put 5 items into the stack 
		Stack.push(1);
		Stack.push(2);
		Stack.push(3);
		Stack.push(4);
		Stack.push(5);

		// check if it is full now , i hope it is :)
		cout << "after pushing 5 items : ";
		cout << (Stack.isFull() ? "YES, it is full\n" : "NO, it isn't full\n");

		// get size of the stack now
		cout << "size now is : " << Stack.size() << endl;

		// show the top of the stack
		cout << "The top of the stack now is : " << Stack.top() << endl;

		// try to pop the top
		Stack.pop();

		// see if the size is redused & print the top to ensure from poping 
		cout << "after pop the top the size now is : " << Stack.size() << endl;

		// show the top of the stack
		cout << "The top of the stack now is : " << Stack.top() << endl;

		// put string in stack of strings (stack3)
		Stack3.push("Kemo");

	    // show the top of the stack3
		cout << Stack3.top() << endl;
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