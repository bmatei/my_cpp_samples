#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

namespace LinkedListN{

	struct Nod{
		double data;
		Nod *next, *prev;
	};

}

/*
 * BUGURI:
 *	Functiile popAt si getAt nu ar trebui
 *	folosite fara a utiliza un index valid
 *	index trebuie sa se afle in intervalul
 *	intreg [0, this->size()]
 *	Functiile getBack(), getFront(), popBack(),
 *	popFront() nu ar trebui utilizate pe liste
 *	vide. Folositi isEmpty() pentru a verifica
 *	acest lucru in prealabil!
 */
class LinkedList{
public:
	//constructor implicit
	LinkedList();
	//construieste cu un element
	LinkedList(double elem);
	//construieste dintr-un vector
	LinkedList(double *vect, int size);
	//constructor de copiere
	LinkedList(const LinkedList &src);
	//destructor
	~LinkedList();
	//intoarce elementul de la final sau -1 pentru lista vida
	double getBack();
	//intoarce elementul de la inceput sau -1 pentru lista vida
	double getFront();
	//intoarce elementul [index] sau -1 daca index este prea mare sau prea mic
	double getAt(int index);
	//adauga argumentul elem la sfarsit
	void pushBack(double elem);
	//adauga argumentul elem la inceput
	void pushFront(double elem);
	//intoarce si sterge ultimul element sau intoarce -1 pentru lista vida
	double popBack();
	//intoarce si sterge primul element sau intoarce -1 pentru lista vida
	double popFront();
	//adauga argumentul elem pe pozitia [index] <<incepand cu 0
	void pushAt(double elem, int index);
	//elimina si intoarce elementul [index] sau -1 daca index este prea mare sau prea mic
	double popAt(int index);
	//sterge primul element cu valoarea elem
	void erase(double elem);
	//intoarce true daca e lista vida false in caz contrar
	bool isEmpty();
	//afiseaza pe ecran continutul listei
	void print();
	//sorteaza crescator sau descrescator
	void sort(bool crescator = true);
	//intoarce true daca argumentul elem se gaseste printre elementele listei sau fals in caz contrar
	bool contains(double elem);
	//intoarce index-ul la care se gaseste argumentul elem in lista sau -1 in caz contrar
	int containsAt(double elem);
	//intoarce numarul de elemente din lista
	int size();
private:
	LinkedListN::Nod *head, *tail;
};

#endif