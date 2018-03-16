#include <iostream>
#include <cstdlib>
#include "ListaSimpluInlantuita.h"

using namespace std;

#define creeazaNod(DATA) ({Nod *p = new Nod; \
						if(!p){ \
							cerr<<"Eroare alocare\n"; \
							exit(1);} \
						p->data = DATA; \
						p->next = 0; \
						p; \
					})

static double comparaCrescator(double a, double b)
{
	return a-b;
}

static double comparaDescrescator(double a, double b)
{
	return b-a;
}

ListaSimpluInlantuita::ListaSimpluInlantuita()
{
	head = 0;
}

ListaSimpluInlantuita::ListaSimpluInlantuita(double *vect, int size)
{
	head = 0;
	ListaSimpluInlantuita aux;

	for(int i = 0; i < size; ++i)
		aux.adauga(vect[i]);
	while(!aux.isEmpty()){
		adauga(aux.get());
		aux.sterge();
	}
}

ListaSimpluInlantuita::ListaSimpluInlantuita(double elem)
{
	head = 0;
	this->adauga(elem);
}

ListaSimpluInlantuita::ListaSimpluInlantuita(const ListaSimpluInlantuita &src)
{
	Nod *p = src.head;
	head = 0;
	ListaSimpluInlantuita aux;
	while(p){
		aux.adauga(p->data);
		p = p->next;
	}
	while(!aux.isEmpty()){
		adauga(aux.get());
		aux.sterge();
	}
}

ListaSimpluInlantuita::~ListaSimpluInlantuita()
{
	while(head){
		this->sterge();
	}
}

void ListaSimpluInlantuita::adauga(double elem)
{
	Nod *p = creeazaNod(elem);
	p->next = head;
	head = p;
}

void ListaSimpluInlantuita::adaugaLa(double elem, int poz) //0 primul element
{
	if(poz == 0){
		adauga(elem);
	} else if(poz >= 0){
		int k = 0;
		Nod *p = head;
		while(p->next && k != poz-1){
			p = p->next;
			k++;
		}
		if(k == poz-1){
			Nod *q = creeazaNod(elem);
			q->next = p->next;
			p->next = q;
		} else {
			cerr<<"Pozitie prea mare.\n";
		}
	} else {
		cerr<<"Pozitie prea mica.\n";
	}
}

void ListaSimpluInlantuita::sterge()
{
	if(!isEmpty()){
		Nod *p = head;
		head = head->next;
		delete p;
		p = 0;
	} else {
		cerr<<"Lista este deja goala. Nu pot sterge.\n";
	}
}

void ListaSimpluInlantuita::stergeLa(int poz) //0 primul element
{
	if(poz == 0){
		this->sterge();
	} else if (poz > 0){
		int k = 0;
		Nod *p = head;
		while(p && k != poz-1){
			p = p->next;
			k++;
		}
		if(p){
			if(p->next){
				Nod *q = p->next;
				p->next = q->next;
				delete q;
				q = 0;
			} else {
				cerr<<"Pozitie prea mare.\n";
			}
		} else {
			cerr<<"Pozitie prea mare.\n";
		}
	} else
		cerr<<"Pozitie prea mica.\n";
}

void ListaSimpluInlantuita::sort(bool crescator) //modified bubble
{
	if(!head) return;
	else
		if(!head->next)
			return;
	double (*comp)(double, double) = crescator ? comparaCrescator : comparaDescrescator;
	bool schimbat = true;
	while(schimbat){
		schimbat = false;
		Nod *p;
		for(p = head; p->next; p = p->next){
			if(comp(p->data, p->next->data) > 0){
				double aux = p->data;
				p->data = p->next->data;
				p->next->data = aux;
				schimbat = true;
			}
		}
	}
}

bool ListaSimpluInlantuita::isEmpty()
{
	return (bool)(head == 0);
}

double ListaSimpluInlantuita::get()
{
	return this->head->data;
}

double ListaSimpluInlantuita::getAt(unsigned int poz)
{
	Nod *p = head;
	int k = 0;
	while(p && k != poz){
		p = p->next;
		k++;
	}
	if(p) return p->data;
	return 0; //error
}

void ListaSimpluInlantuita::print()
{
	cout<<"(";
	Nod *p = head;
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<")\n";
}
