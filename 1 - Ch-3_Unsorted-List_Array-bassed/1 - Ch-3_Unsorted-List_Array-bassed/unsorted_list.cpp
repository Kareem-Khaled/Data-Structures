#include "unsorted_list.h"

unsorted_list::unsorted_list(){
	length = 0;
}

void unsorted_list::makeEmpty(){
	length = 0;
}

void unsorted_list::resrtList(){
	currentPos = -1;			// Do you know why we initialize it by -1  D=
}

bool unsorted_list::isFull() const{

								
								//		It is the same as :
								//			if(length == maxItem)
	return(length == maxItem);	//				return true;
								//			else
								//				return false;
								//	
}

int unsorted_list::getLength() const{
	return length;
}

itemType unsorted_list::getItem(itemType item, bool& found) {
	int location = -1;
	while (++location < length){
		relation relt = (item.compareTo(arr[location]));
		if (relt == EQUAL){
			found = true;
			break;
		}
	}
	return item;
}

void unsorted_list::putItem(itemType item){
										//  It is the same as :
		arr[length++] = item;			// arr[length] = item;
										//  length++;
}										

void unsorted_list::deleteItem(itemType item){
	int location = -1;
	while (++location < length){
		relation relt = (item.compareTo(arr[location]));
		if (relt == EQUAL)
			break;
	}									//  It is the same as :
	arr[location] = arr[--length];		//	arr[location] = arr[length - 1];
}										//   length--;


itemType unsorted_list::getNextItem(){
										//  It is the same as :
										// currentPos++;
	 return arr[++currentPos];			// return arr[currentPos];
										// Do you know now why we initialize it by -1  :)
}