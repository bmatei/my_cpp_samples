#include "Nod.h"
#include "Stiva.h"
#include "Coada.h"

void testStivaStatica()
{

}

void testStivaDinamica()
{

}


int main()
{
	//Lista liniara simplu inlantuita
	/*Nod *list = 0;
	list = creaza(5);
	list = adauga(list, 10);
	afisare(list);
	list = adauga(list, 15);
	afisare(list);
	list = adauga(list, 20);
	list = adauga(list, 25);
	afisare(list);
	elimina(list, 10);
	afisare(list);
	elimina(list, 25);
	afisare(list);
	elimina(list, 5);
	afisare(list);*/

	//Stiva implementata dinamic (cu liste)
	/*Stiva s;
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	s.push(25);
	s.afisareSiGolire();*/

	//Coada implementata simplu dinamic (cu liste simplu inlantuite)
	Coada c;
	c.put(5);
	c.put(10);
	c.put(15);
	c.put(20);
	c.put(25);
	c.afisareSiGolire();


	return 0;
}