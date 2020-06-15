#include"itemType.h"
#include <exception>  // libray for exception handling .. (try & catch)
#include <cstddef>	 // library for using NULL with pointers
#include<string>
using namespace std;
struct node;
class sorted_list
{
public:
	sorted_list();
	~sorted_list();
	void makeEmpty();
	bool isFull() const;
	int getLength() const;
	itemType getItem(itemType, bool&);
	void putItem(itemType);
	void deleteItem(itemType);
	void resrtList();
	itemType getNextItem();
private:
	node *currentPos, *listData;
	int length;
};
