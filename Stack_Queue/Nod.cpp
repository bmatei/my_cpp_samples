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
}
Nod *adauga(Nod *list, int x)
{
	Nod *p = creaza(x);
	p->next = list; //adaug in fata
		list = p;
	return list;
}
void elimina(Nod *&list, int x)
{
	Nod *p = list;
//	cout<<"PRINT ME!"<<endl;
	if(list){ 
		if(list->data == x){ //daca vreau sa sterg primul element
//			Nod *p = list;
//			cout<<"No way"<<endl;
			list = list->next;
			delete p;
			return ;
		}
	}
//	cout<<"what1"<<endl;
	//Nod *p = list;
	while(p){ //daca vreau sa sterg alt element decat primul
		if(p->next){
			if(p->next->data == x){
				Nod *q = p->next;
				p->next = q->next;
//				cout<<p->next->data<<"<--\n"; //SEG FAULT AICI, CAND ELEMENTUL DE STERS ESTE ULTIMUL DIN LISTA
				delete q;
				return ;
//				cout<<"if in while"<<endl;
			}
		}
		p = p->next;
//		cout<<"whaat"<<endl;
	}
	cerr<<"Elementul nu se gaseste in lista\n";
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