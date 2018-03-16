#ifndef _STIVA_H
#define _STIVA_H

#include "Nod.h"

class Stiva{
	Nod *vf;
public:
	void printDebug();
	Stiva();
	void push(int x);
	int top();
	int pop();
	bool isEmpty();
	void afisareSiGolire();
};

#endif
//_STIVA_H