#include <iostream>
#include "header.h"

using namespace std;

Stiva::Stiva()
{
	vf = NULL;
}



Stiva::~Stiva()
{
	while(!isEmpty())
	{
		pop();
	}
}



void Stiva::push(Atom a)
{
//	cout<<"push\n";
	Nod *p;
	p = new Nod;
	p->data = a;
	p->succ = vf;
	vf = p;
}

Stiva::Stiva(const Stiva &s)
{
	Nod *p = s.vf;
	vf = 0;
	//cout<<"copy1<>"<<p<<"<>"<<s.vf<<"<>"<<&s<<endl;
	while(p){
	//	cout<<"copy\n";
	//	cout<<"merge\n";
		push(p->data);
		p = p->succ;
	}
}


Atom Stiva::pop(void)
{
	if(isEmpty())
	{
		cerr << "Eroare: Stiva goala!" << endl;
		return 0;
	}
	else
	{
		Nod *p = vf;
		vf = vf->succ;
		Atom a = p->data;
		delete p;
		return a;
	}
}


Atom Stiva::top(void)
{
	//Nod *p = vf;
	Atom a = vf->data;
	return a;
}



bool Stiva::isEmpty()
{
	if(vf==0)
		return true;
	return false;
}


void Stiva::afisare()
{
	Nod *p = this->vf;
	while(p)
	{
		cout << p->data << " ";
		p = p->succ;
	}
	cout << endl;
}
