#include <iostream>
#include "ListaSimpluInlantuita.h"
using namespace std;

int main()
{
	ListaSimpluInlantuita s1;
	s1.adauga(22.5);
	s1.adauga(23.5);
	s1.print();
	s1.sterge();
	s1.print();
	s1.adaugaLa(15, 1);
	s1.adaugaLa(16, 2);
	s1.adaugaLa(17, 3);
	s1.adaugaLa(16.5, 3);
	s1.adaugaLa(19, 6);
	s1.adaugaLa(1, 0);
	s1.print();
	s1.stergeLa(100);
	s1.stergeLa(-1);
	s1.stergeLa(3);
	s1.print();
	ListaSimpluInlantuita s2(s1);
	s2.sort();
	s2.print();
	double vect[200];
	double val;
	int i = 0;
	for(val = 22.5; val > -6; val-=0.5){
		vect[i] = val;
		i++;
		if(i == 200) break;
	}
	ListaSimpluInlantuita s3(vect, i);
	s3.print();
	s3.sort();
	s3.print();

	return 0;
}