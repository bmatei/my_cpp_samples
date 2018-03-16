#include <iostream>
#include <cstdlib>
#include "ListaCirculara.h"

#define creeazaNod(DATA) ({Nod *TEMPp = new Nod; \
						if(!TEMPp){ \
							std::cerr<<"Eroare alocare\n"; \
							exit(1);} \
						TEMPp->data = DATA; \
						TEMPp->next = TEMPp; \
						TEMPp; \
					})


ListaCirculara::ListaCirculara()
{
	cursor = 0;
}

ListaCirculara::ListaCirculara(double elem)
{
	cursor = 0;
	adauga(elem);
}

ListaCirculara::ListaCirculara(double *vect, int size)
{
	int i;
	cursor = 0;
	for(i = 0; i < size; ++i)
		adauga(vect[i]);
}

ListaCirculara::ListaCirculara(const ListaCirculara &src)
{
	cursor = 0;
	Nod *p = src.cursor;
	adauga(p->data);
	p = p->next;
	while(p != src.cursor)
	{
		adauga(p->data);
		p = p->next;
	}
}

ListaCirculara::~ListaCirculara()
{
	while(!isEmpty())
		sterge();
}

void ListaCirculara::adauga(double elem)
{
	Nod *p = creeazaNod(elem);
	if(cursor){
		p->next = cursor->next;
		cursor->next = p;
		double aux = p->data;
		p->data = cursor->data;
		cursor->data = aux;
		cursor = p;
	} else {
		cursor = p;
	}
}

void ListaCirculara::sterge()
{
	if(cursor){
		if(cursor->next != cursor){
			Nod *p = cursor->next;
			double aux = p->data;
			p->data = cursor->data;
			cursor->data = aux;
			cursor->next = p->next;
			delete p;
			p = 0;
		} else {
			delete cursor;
			cursor = 0;
		}
	}
}

void ListaCirculara::sterge(double elem)
{
	if(cursor){
		Nod *p = cursor;
		while(p->data != elem){
			p = p->next;
			if(p == cursor) break;
		}
		if(p->data == elem)
			if(cursor->next == cursor)
				sterge();
			else{
				Nod *q = cursor;
				cursor = p;
				sterge();
				cursor = q;
			}
	}
}

void ListaCirculara::print()
{
	using namespace std;
	cout<<"(";
	if(cursor){
		Nod *p = cursor;
		do{
			cout<<p->data<<" ";
			p = p->next;
		} while(p != cursor);
	}
	cout<<")\n";
}

double ListaCirculara::getCurrentElement()
{
	if(cursor) return cursor->data;
	else return 0;
}

void ListaCirculara::moveCursor()
{
	if(cursor) cursor = cursor->next;
}

void ListaCirculara::moveCursor(int poz)
{
	if(poz > 0 && cursor){
		int k = 0;
		while (k < poz){
			cursor = cursor->next;
			k++;
		}
	}
}

bool ListaCirculara::isEmpty()
{
	return (cursor == 0);
}