#ifndef _NOD_H
#define _NOD_H

struct Nod{
	int data; //tipul poate fi orice
	Nod *next;
};

void eroare(char *msg);
Nod *creaza(int x);
Nod *adauga(Nod *list, int x);
void elimina(Nod *&list, int x);
void afisare(Nod *list);

#endif
//_NOD_H