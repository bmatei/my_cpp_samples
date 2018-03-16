#include "ListaCirculara.h"

int main()
{
	ListaCirculara l1(0);
	l1.adauga(1);
	l1.adauga(3);
	l1.adauga(2);
	l1.print();
	l1.sterge(3);
	l1.print();
	l1.adauga(3);
	l1.adauga(4);
	l1.moveCursor();
	l1.print();
	l1.moveCursor(3);
	l1.print();
	double vect[5] = {1, 2, 3, 4, 6};
	ListaCirculara l2(vect, 5);
	l2.print();
	l2.adauga(100);
	ListaCirculara l3(l2);
	l3.print();
	return 0;
}