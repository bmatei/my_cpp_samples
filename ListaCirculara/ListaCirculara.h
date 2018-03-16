#ifndef _LISTA_CIRCULARA_H
#define _LISTA_CIRCULARA_H

struct Nod{
	double data;
	Nod *next;
};

class ListaCirculara{
public:
	ListaCirculara();
	ListaCirculara(double elem);
	ListaCirculara(double *vect, int size);
	ListaCirculara(const ListaCirculara &src);
	~ListaCirculara();
	void adauga(double elem);
	void sterge();
	void sterge(double elem);
	void print();
	double getCurrentElement();
	void moveCursor();
	void moveCursor(int poz);
	bool isEmpty();
private:
	Nod *cursor;
};

#endif