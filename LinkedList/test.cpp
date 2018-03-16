#include "LinkedList.h"

int main()
{
	LinkedList l1(123);
	l1.pushFront(10);
	l1.pushBack(9);
	l1.print();
	l1.pushAt(7, 0);
	l1.pushAt(11, 3);
	l1.pushAt(8, 1);
	l1.print();
	l1.pushAt(-1, -1);
	l1.pushAt(123, 15);
	l1.print();
	l1.erase(7);
	l1.erase(123);
	l1.pushFront(l1.popBack());
	l1.print();
	l1.pushFront(l1.popAt(3));
	l1.pushFront(l1.getFront());
	l1.pushFront(l1.getBack());
	l1.pushFront(l1.getAt(1));
	l1.pushFront(l1.getAt(0));
	l1.pushFront(l1.getAt(7));
	if(l1.contains(-2)) l1.pushFront(l1.getAt(-2));
	if(l1.containsAt(-2) != -1) l1.pushFront(l1.getAt(100));
	if(l1.contains(8)) l1.sort();
	l1.print();
	LinkedList l2(l1);
	while(l1.contains(-1))
		l1.erase(-1);
	if(l2.containsAt(9)>0)l2.sort(false);
	l2.print();
	return 0;
}