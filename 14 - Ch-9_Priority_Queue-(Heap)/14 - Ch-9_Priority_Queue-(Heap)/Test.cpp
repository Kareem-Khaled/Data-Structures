/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it 💗
*/
#include"priorityQueue.h"
#include <iostream>
using namespace std;
int main(){
	priorityQueue<int>pq(4);
	// the priority_queue is empty so the answer is NO.
	cout << (pq.IsFull() ? "YES, it is full\n" : "NO, it isn't full\n");

	// put 4 items into the tree 
	pq.Enqueue(3);	
	pq.Enqueue(2);	
	pq.Enqueue(4);	
	pq.Enqueue(1);  

	cout << "--- After insirting 4 items ---\n";
	// the priority_queue is full so the answer is YES, I hope :)
	cout << (pq.IsFull() ? "YES, it is full\n" : "NO, it isn't full\n");

	// dequing all 4 items
	cout << "--- dequing all 4 items ---\n";
	for (int i = 0; i < 4; i++){
		int x; pq.Dequeue(x);
		cout << x << ' ';
	}
	cout << endl;

	// the priority_queue is Empty so the answer is YES.
	cout << (pq.IsEmpty() ? "YES, it is empty\n" : "NO, it isn't empty\n");

	system("pause");
}

/*
		Hi
			Assuming this code is the same as the book, you should optimize it yourself :)
			Please do not be lazy for doing that D=

			If you had any problem with code just ask :)
		Bye
*/