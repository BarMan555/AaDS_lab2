#include "list.cpp"
#include <iostream>
int main(){
	LinkedList<int> list;
	list.push_head(55);
	list.push_head(3);
	list.push_head(2);
	list.push_head(12);

	LinkedList<int> list2(list);

	list += list2;
	std::cout << list << std::endl;
	LinkedList<int> list3(list + list2);
	std::cout << list3;
	return 0;
}