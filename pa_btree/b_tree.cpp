#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#define ORDIN 2

struct BNod {
	int tipNod; /*0 --> frunza*/
	int nrChei;
	int cheie[(int)(2 * ORDIN - 1)];
	BNod* fiu[(int)(2 * ORDIN)];
};

typedef BNod* PBNod;

// VERIFICAT

void afisare(PBNod v, int index);

PBNod creareBNod() {

	PBNod t = new BNod;

	if(!t) {
		fprintf(stderr, "Memorie insuficienta !\n");
		exit(EXIT_FAILURE);
	}
	memset(t, 0, sizeof(*t));

	return t;

}

PBNod cautareBarbore(PBNod v, int k) {

	PBNod t = v;
	int i = 0;

	while((i < t->nrChei) && (k > t->cheie[i])) i++;
	if((i < t->nrChei) && (k == t->cheie[i])) return t;
	if(t->tipNod == 0) return 0;
	else return cautareBarbore(t->fiu[i], k);

}

// VERIFICAT

void spargeBNod(PBNod u, int i, PBNod v) {

	PBNod w = creareBNod();
	int j;

	w->tipNod = v->tipNod;
	w->nrChei = ORDIN - 1;
	for(j = 0; j < ORDIN - 1; ++j) {
		w->cheie[j] = v->cheie[j + ORDIN];
	}
	if(v->tipNod == 1) {
		for(j = 0; j < ORDIN; ++j) {
			w->fiu[j] = v->fiu[j + ORDIN];
		}
	}	
	v->nrChei = ORDIN - 1;
	for(j = u->nrChei; j > i; --j){
		u->fiu[j + 1] = u->fiu[j];
	}
	u->fiu[i + 1] = w;
	for(j = u->nrChei - 1; j >= i; --j) {
		u->cheie[j + 1] = u->cheie[j];
	}
	u->cheie[i] = v->cheie[ORDIN - 1];
	u->nrChei = u->nrChei + 1;
}

void insereazaInNodIncomplet(PBNod v, int k) {

	int i = v->nrChei - 1;

	if(v->tipNod == 0) {
		while((i >= 0) && (k < v->cheie[i])) {
			v->cheie[i + 1] = v->cheie[i];
			i = i - 1;
		}
		printf("DEBUG:special<%d->%d>\n", k, i);
		v->cheie[i + 1] = k;
		v->nrChei = v->nrChei + 1;
	}
	else {
		while((i >= 0) && (k < v->cheie[i])) {
			--i;
		} 
		++i;
		if(v->fiu[i]->nrChei == 2 * ORDIN - 1) {
			spargeBNod(v, i, v->fiu[i]);
			if(k > v->cheie[i]) {
				++i;
			}
		}
		insereazaInNodIncomplet(v->fiu[i], k);
	}
}

void insereazaBarbore(PBNod &n, int k) {
	PBNod t = n;

	if(t->nrChei == 2 * ORDIN - 1) {
		printf("DEBUG:break\n");
		afisare(n, 0);
		printf("DEBUG:break<\n");
		PBNod p = creareBNod();
		n = p;
		p->tipNod = 1;
		p->nrChei = 0;
		p->fiu[0] = t;
		spargeBNod(p, 0, t);
		insereazaInNodIncomplet(p, k);
	}
	else {
		printf("DEBUG:regular\n");
		afisare(n, 0);
		printf("DEBUG:regular<\n");
		insereazaInNodIncomplet(t, k);
	}
}

void afisareBarbore(PBNod v) {

	int i;

	if(v != 0) {
		for(i = 0; i < v->nrChei; i++) {
			printf("%d.", v->cheie[i]);
		}
		printf("   ");
		for(i = 0; i <= v->nrChei; i++) {
			afisareBarbore(v->fiu[i]);
		}
	} 

}

void afisare(PBNod v, int index) { 
int i;
	if(v) {
		for(int j = 0; j < index; j++) {
			cout << "\t"; 
		}
		for(i = 0; i < v->nrChei; i++) { 
		cout << v->cheie[i] << " ";
	} 
	if(i == v->nrChei)
	  cout << endl;
	   for (i = 0; i <= v->nrChei; i++) {
		if(v->fiu[i])
			afisare(v->fiu[i], index + 1); 
		}
	}
}


void dealocaBarbore(PBNod &t) {

	int i;

	if(t->tipNod == 1) {
		for(i = 0; i <= t->nrChei; i++) {
			dealocaBarbore(t->fiu[i]);
			delete t->fiu[i];
		}
	}

}

int main() {

	PBNod r = creareBNod(); /*face nod gol*/
	int info = 0; /*info tmp*/

	do {
	//	printf("Citeste informatia: ");
		scanf("%d", &info);
		if(info != 0) insereazaBarbore(r,(char)info); /*asta-i insertu'*/
	}while(info != 0);

	afisare(r, 0);	/*afisare indentata*/
	//afisareBarbore(r); 
	printf("\n");

	printf("Se cauta elementul 10 in B-Tree ! \n");
	PBNod deCautat = cautareBarbore(r, 10); /*cautarea (NULL sau adresa)*/
	if(deCautat == 0)
		printf("Elementul nu a fost gasit !\n");
	else 
		printf("Elementul a fost gasit ! \n");

	dealocaBarbore(r); /*elib mem*/
	delete r;

	return 0;
}