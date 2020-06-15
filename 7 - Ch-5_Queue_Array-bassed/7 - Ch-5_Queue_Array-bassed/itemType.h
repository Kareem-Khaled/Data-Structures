#pragma once
const int maxItem = 5;
class itemType
{
public:
	itemType();
	relation compareTo(itemType)const;
	void initialize(int);
	void print();
private:
	char value;
};

