#include"itemType.h"
class sorted_list
{
public:
	sorted_list();
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
	int binary_search(itemType);
};

