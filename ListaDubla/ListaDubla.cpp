#include "ListaDubla.h"

using namespace std;

#include <cstdio>
#include <cerrno>
#include <cstring>

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define ERROR(M, ...) fprintf(stderr, "[ERROR] %s:%d errno:%s "M"\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__); return

void ListaDubla::adauga(int elem)
{
	if(!cap){
		NEW_NOD(cap);
		cap->elem = elem;
	} else {
		Nod *p = 0;
		NEW_NOD(p);
		p->elem = elem;
		p->next = cap;
		cap->prev = p;
		cap = p;
	}
}

void ListaDubla::adaugaLa(int elem, uint poz)
{
	if(!poz){
		this->adauga(elem);
	} else if(!cap) {ERROR("Lista nu are pozitia %u", poz);}
	else{
		uint k = 0;
		Nod *p = cap;
		poz--;
		while(k < poz){
			p = p->next;
			k++;
			if(!p) {ERROR("Lista nu are pozitia %u", poz+1);}
		}
		Nod *q = 0;
		NEW_NOD(q);
		q->elem = elem;
		q->next = p->next;
		if(p->next) p->next->prev = q;
		q->prev = p;
		p->next = q;
		//01 2
	}
}


//<==>stergeDeLa(0)
void ListaDubla::sterge(int elem)
{
	if(cap){
		Nod *p = cap;
		Nod *q = p;
		while(p -> elem != elem){
			q = p;
			p = p->next;
			if(!p) {ERROR("Elementul %d nu exista", elem);}
		}
		q->next = p->next;
		if(q != p ){if(q->next) q->next->prev = q;}
		else {
			if(q->next) q->next->prev = 0;
			cap = cap->next;
		}
		delete p;
		p = 0;
	} else {ERROR("Lista nu are nici un element");}
}

void ListaDubla::stergeDeLa(uint poz)
{
	if(!poz){
		Nod *p = cap;
		cap = cap->next;
		if(cap) cap->prev = 0;
		delete p;
		p = 0;
	}else if(!cap) {ERROR("Lista nu are pozitia %u", poz);}
	else {
		uint k = 0;
		Nod *q = cap, *p = cap;
		while(k < poz){
			q = p;
			p = p->next;
			k++;
			if(!p) {ERROR("Pozitia %u nu exista", poz);}
		}
		q->next = p->next;
		if(q->next) q->next->prev = q;
		delete p;
	}
}

qword ListaDubla::getIndexOf(int elem)
{
	Nod *p = cap;
	uint rez = 0;
	while(p && p->elem != elem){
		p = p->next;
		rez++;
	}
	if(!p) {ERROR("Elementul %d nu exista. Returnez -1...", elem) -1;}
	return rez;
}

int ListaDubla::getAt(uint poz)
{
	uint k = 0;
	Nod *p = cap;
	while(p && k < poz){
		p = p->next;
		k++;
	}
	if(!p) {ERROR("Pozitia %u nu exista. Returnez 0...", poz) 0;}
	return p->elem;
}

void ListaDubla::setAt(int elem, uint poz)
{
	uint k = 0;
	Nod *p = cap;
	while(p && k < poz){
		p = p->next;
		k++;
	}
	if(!p) {ERROR("Pozitia %u nu exista", poz);}
	p->elem = elem;
}

void ListaDubla::print()
{
	Nod *p = cap;
	cout<<p<<" = (";
	while(p){
		cout<<p->elem<<" ";
		p = p->next;
	}
	cout<<")\n";
}

bool ListaDubla::isEmpty()
{
	return cap ? false : true;
}

ListaDubla::~ListaDubla()
{
	while(!isEmpty()) stergeDeLa(0);
}

#define TEST_LIST_F(L, F, ...) {L.F( __VA_ARGS__ ); L.print();} 

int main()
{
	ListaDubla list;
	TEST_LIST_F(list, adauga, 13);
	TEST_LIST_F(list, adaugaLa, 12, 0);
	TEST_LIST_F(list, adaugaLa, 16, 3); //should be error
	TEST_LIST_F(list, adaugaLa, 15, 2); //should work
	TEST_LIST_F(list, adaugaLa, 14, 2);
	TEST_LIST_F(list, sterge, 12);
	TEST_LIST_F(list, sterge, 14);
	TEST_LIST_F(list, sterge, 15);
	TEST_LIST_F(list, sterge, 20);
	TEST_LIST_F(list, adauga, 11);
	TEST_LIST_F(list, adauga, 10);
	TEST_LIST_F(list, adauga, 9);
	TEST_LIST_F(list, stergeDeLa, 0);
	TEST_LIST_F(list, stergeDeLa, 1);
	TEST_LIST_F(list, stergeDeLa, 1);
	TEST_LIST_F(list, stergeDeLa, 1);
	cout<<"list.getIndexOf(10) = "<<list.getIndexOf(10)<<endl;
	TEST_LIST_F(list, adauga, 9);
	cout<<"list.getIndexOf(10) = "<<list.getIndexOf(10)<<endl;
	cout<<"list.getIndexOf(11) = "<<list.getIndexOf(11)<<endl;
	cout<<"list.getAt(0) = "<<list.getAt(0)<<endl;
	cout<<"list.getAt(1) = "<<list.getAt(1)<<endl;
	cout<<"list.getAt(2) = "<<list.getAt(2)<<endl;
	TEST_LIST_F(list, setAt, 200, 0);
	TEST_LIST_F(list, setAt, 201, 1);
	TEST_LIST_F(list, setAt, 0, 200);

	return 0;
}