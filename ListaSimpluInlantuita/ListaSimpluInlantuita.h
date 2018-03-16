#ifndef _LISTA_SIMPLU_INLANTUITA_H
#define _LISTA_SIMPLU_INLANTUITA_H

struct Nod{
	double data;
	Nod *next;
};

class ListaSimpluInlantuita{
public:
	ListaSimpluInlantuita();
	ListaSimpluInlantuita(double *vect, int size);
	ListaSimpluInlantuita(double elem);
	ListaSimpluInlantuita(const ListaSimpluInlantuita &src);
	~ListaSimpluInlantuita();
	void adauga(double elem);
	void adaugaLa(double elem, int poz); //0 primul element
	void sterge();
	void stergeLa(int poz); //0 primul element
	void sort(bool crescator = true); //modified bubble
	bool isEmpty();
	void print();
	double get();
	double getAt(unsigned int poz);
private:
	Nod *head;
};

#endif