#include"itemType.h"
class unsorted_list
{
public:
	unsorted_list(); // Constructor
	void makeEmpty();
	bool isFull() const;
	int getLength() const;
	itemType getItem(itemType, bool&);
	void putItem(itemType);
	void deleteItem(itemType);
	void resrtList();
	itemType getNextItem();
private:
	int length, currentPos;
	itemType arr[maxItem];
};

