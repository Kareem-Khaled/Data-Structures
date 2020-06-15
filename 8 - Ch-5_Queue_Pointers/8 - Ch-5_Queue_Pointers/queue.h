#include"itemType.h"
#include <exception>  // libray for exception handling .. (try & catch)
#include <cstddef>	 // library for using NULL with pointers
#include<string>
using namespace std;
struct node;
class fullQueue{
};


class emptyQueue{

};

class queue{
public:
	queue();
 	bool isEmpty()const;
	bool isFull()const;
	void makeEmpty();
	void enQueue(itemType);
	void deQueue(itemType&);
	~queue();
private:
	node *front, *rear;
};
