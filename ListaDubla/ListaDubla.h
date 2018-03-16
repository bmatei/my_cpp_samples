#ifndef __lista_dubla_h_
#define __lista_dubla_h_

struct Nod{
	int elem;
	Nod *next, *prev;
};

#include <iostream>
#include <cstdlib>

#define NEW_NOD(P) {P = new Nod; 												\
					if(!P){std::cerr<<"Memory error\n"; exit(EXIT_FAILURE);}	\
					P->elem = 0; P->next = 0; P->prev = 0;}

typedef unsigned int uint;
typedef long long int qword;

class ListaDubla{
	Nod *cap;
public:
	ListaDubla(){cap = 0;}
	ListaDubla(int elem){NEW_NOD(cap); cap->elem = elem;}
	void adauga(int elem);
	void adaugaLa(int elem, uint poz);
	void sterge(int elem);
	void stergeDeLa(uint poz);
	qword getIndexOf(int elem);
	int getAt(uint poz);
	void setAt(int elem, uint poz);
	void print();
	bool isEmpty();
	~ListaDubla();

};

#endif