#include "sorted_list.h"

sorted_list::sorted_list(){
	length = 0;
}

void sorted_list::makeEmpty(){
	length = 0;
}

void sorted_list::resrtList(){
	currentPos = -1;
}

bool sorted_list::isFull() const{
	return(length == maxItem);
}

int sorted_list::getLength() const{
	return length;
}

int sorted_list::binary_search(itemType value){ // if you don't know Binary_Search please search about it :)
	int left = 0, right = length;
	while (left <= right){						// if you don't know what is this operator ( >> ) it's called (right shift) search about it 
		int mid = (left + right) >> 1;			// but to know quickly it is the same as dividing by 2 
		if (value.compareTo(arr[mid]) == EQUAL) // but also you need searching about it to know more :>	
			return mid;								
		if (value.compareTo(arr[mid]) == LESS)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return length;
}

itemType sorted_list::getItem(itemType item, bool& found) {
	int location = binary_search(item);
	if (location != length)
		found = 1;
	return item;
}

void sorted_list::putItem(itemType item){
	if (length == 0)
		arr[length++] = item;
	else{
		int location = length - 1;
		for (location; location >= 0; location--){
			if (item.compareTo(arr[location]) == EQUAL || item.compareTo(arr[location]) == GREATER)
				break;
		}
		location++;
		for (int i = length - 1; i >= location; i--){
			arr[i + 1] = arr[i];
		}
		arr[location] = item;
		length++;
	}
}

void sorted_list::deleteItem(itemType item){
	int location = binary_search(item);			// you must be careful, this implementation isn't valid in one case
	for (int i = location; i < length; i++){	// do you know what is it D=
		arr[i] = arr[i + 1];
	}
	length--;
}


itemType sorted_list::getNextItem(){
	return arr[++currentPos];
}