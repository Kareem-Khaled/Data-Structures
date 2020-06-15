#pragma once
#include<iostream>
#include<string>
using namespace std;
enum relation{ LESS, EQUAL, GREATER };
class itemType
{
public:
	itemType();
	relation compareTo(itemType)const;
	void initialize(string);
	void print();
private:
	string value;
};

