#include <iostream>
#include "header.h"

using namespace std;

int main(void)
{
	Stiva s;
	s.push(4);
	s.push(3);
	cout << s.top() << endl;
	s.push(9);
	cout << s.pop() << endl;
	s.push(2);
	cout << "s afisare finala: ";
	s.afisare();
	//cout<<"<>"<<&s<<endl;
	Stiva s1(s);
	cout << endl << "s1 afisare finala: ";
	s1.afisare();

	return 0;
}
