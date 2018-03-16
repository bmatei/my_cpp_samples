#include <iostream>
#include <cstdlib>
#include "Nod.h"

using namespace std;

void eroare(const char *msg)
{
	cerr<<"Eroare: "<<msg<<endl;
	exit(EXIT_FAILURE);
}

Nod *creaza(int x)
{
	Nod *p = new Nod;
	if(!p) eroare("Alocare nod");
	p->data = x;
	p->next = 0; //lista cu un singur element;
	return p;
}

void afisare(Nod *list)
{
	cout<<"(";
	while(list){
		cout<<list->data<<" ";
		list = list->next;
	}
	cout<<")\n";
}
