#include <iostream>
#include "Stiva.h"

using namespace std;

Stiva::Stiva()
{
	this->vf = 0;
}
void Stiva::push(int x)
{
	Nod *p = creaza(x);
	p->next = this->vf;
	this->vf = p;
}
int Stiva::top()
{
	if(!this->isEmpty())
		return this->vf->data;
	return 0;
}
int Stiva::pop()
{
	int data = this->top();
	if(!this->isEmpty()){
		Nod *p = this->vf;
		this->vf = p->next;
		delete p;
	}
	return data;
}
bool Stiva::isEmpty()
{
	if(this->vf) return false;
	return true;
}
void Stiva::afisareSiGolire()
{
	cout<<"(";
	while(!this->isEmpty())
	{
		cout<<this->pop()<<" ";
	}
	cout<<")\n";
}