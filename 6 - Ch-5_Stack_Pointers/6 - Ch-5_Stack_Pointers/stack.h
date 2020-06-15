#include"itemType.h"
#include <exception>  // libray for exception handling .. (try & catch)
#include <cstddef>	 // library for using NULL with pointers
#include<string>
using namespace std;
struct node;
class fullStack{
};


class emptyStack{

};

class stack
{
public:
	stack();
	~stack();
	bool isFull() const;
	bool isEmpty() const;
	void push(itemType);
	void pop();
	itemType top();
private:
	node *topPtr;
};
