#pragma once

typedef int Atom;

struct Nod {
	Atom data;
	Nod *succ;
};

class Stiva {
	Nod *vf;
public:
	Stiva();
	Stiva(const Stiva &s);
	~Stiva();
	void push(Atom a);
	Atom pop(void);
	Atom top(void);
	void afisare();
	bool isEmpty();
};
