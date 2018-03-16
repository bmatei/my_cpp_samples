#ifndef _COADA_H
#define _COADA_H

class Coada{
	Nod *enter, *exitN; //intrare si iesire in coada;
public:
	Coada();
	void put(int x);
	int get();
	bool isEmpty();
	void afisareSiGolire();
};

#endif
//_COADA_H