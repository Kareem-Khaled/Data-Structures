#pragma once
enum relation{ LESS, EQUAL, GREATER };
const int maxItem = 5;
class itemType
{
public:
	itemType();
	relation compareTo(itemType)const;
	void initialize(int);
	void print();
private:
	int value;
};

