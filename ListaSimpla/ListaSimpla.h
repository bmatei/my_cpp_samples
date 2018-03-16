#ifndef _lista_simpla_h_
#define _lista_simpla_h_

//insert_first
//insert_middle
//insert_end
//remove_first
//remove_middle
//remove_end
//print
struct ListaSimpla{
	int elem;
	ListaSimpla *next;
	ListaSimpla(){elem = 0; next = 0;}
};

typedef unsigned int uint;
void insert_first(int elem, ListaSimpla *&p);
void insert_middle(int elem, uint poz, ListaSimpla *&p);
void insert_end(int elem, ListaSimpla *&p);
void remove_first(ListaSimpla *&p);
void remove_last(ListaSimpla *&p);
void remove_middle(int elem, ListaSimpla *&p);
void remove_middle(uint poz, ListaSimpla *&p);
void print(ListaSimpla *p);

#endif