#include <iostream>
#include "Nod.h"
#include "Coada.h"

using namespace std;

Coada::Coada()
{
	this->enter = 0;
	this->exitN = 0;
}
void Coada::put(int x)
{
	Nod *p = creaza(x);
	p->next = enter;
	enter = p;
	if(!this->exitN){
		this->exitN = p;
	}
//	cout<<x<<"<>"<<this->exitN<<endl;
}
int Coada::get()
{
//	cout<<"get->"<<exitN<<endl;
	if(this->exitN){
//		cout<<"if(this->exitN)"<<endl;
		int data = this->exitN->data;
		Nod *p = this->enter;
		if(p->next){
//			cout<<"if(p->next)"<<endl;
			while(p->next->next){
//				cout<<"while(p->next->next)";
				p = p->next;
			}
		}
		else {
//			cout<<"if(!p->next)"<<endl;
			delete this->exitN;
			this->exitN = 0;
			this->enter = 0;
			return data;
		}
//		cout<<"enter:"<<enter<<" <> "<<p<<endl;
		this->exitN = p;
		p = p->next;
		this->exitN->next = 0;
		delete p;
		p = 0;
		return data;
	}

	return -1;
	
}
bool Coada::isEmpty()
{
	if (this->enter && this->exitN) return false;
	return true;
}
void Coada::afisareSiGolire()
{
	while(!isEmpty()){
		cout<<get()<<" ";
	}
	cout<<endl;
}