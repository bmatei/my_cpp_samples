#include <iostream>
#include "Stiva.h"

#define HACK_STACK(S) { cout<<#S<<" = "; afisare(*((Nod **)&S));}

using namespace std;

void move(Stiva *ti, Stiva *tf)
{
	if(!ti->isEmpty())
		tf->push(ti->pop());
}

Stiva 	*TI = 0,
		*TAUX = 0,
		*TF = 0; //pointeri globali pentru o afisare mai ordonata

void printStackTrace(int n)
{
	HACK_STACK((*TI));
	HACK_STACK((*TF));
	HACK_STACK((*TAUX));
	cout<<"n = "<<n<<endl;
}

void Hanoi(int n, Stiva *ti, Stiva *tf, Stiva *tm) 
{ 
	printStackTrace(n);
	if(n == 1) {
		move (ti, tf); //deplaseaza discul superior 
		//printStackTrace(n);
	}
	else {
		Hanoi(n-1, ti, tm, tf);
		move(ti, tf);
		//printStackTrace(n);
		Hanoi(n-1, tm, tf, ti) ;
	}
	
	
}

int main()
{
	
	Stiva ti, tf, taux; //turn initial, turn final, turn auxiliar
	TI = &ti;
	TF = &tf;
	TAUX = &taux; //initializari pointeri globali necesari pentru afisari
	int n;
	cout<<"n = ";cin>>n;
	int i;
	for(i = n; i>0; --i)
		ti.push(i);
	//am populat stiva initiala cu valori
	cout<<"Fara macro: ";
	afisare(*((Nod**)&ti)); //mic hack pentru afisare stiva
	//integrez sintaxa de mai sus intr-un macro, pentru simplitate in exprimare
	cout<<"Cu macro: ";
	HACK_STACK(ti); //aici folosesc macro pentru exact aceeasi treaba ca mai sus
	cout<<"Incep procesarea...\n";
	Hanoi(n, &ti, &tf, &taux);
	HACK_STACK(tf);

	return 0;
}