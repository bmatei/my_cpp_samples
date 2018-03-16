#include <iostream>
#include <cstdlib>
#include "ListaSimpla.h"

using namespace std;

void error(const char *msg)
{
	cerr<<msg<<endl;
	exit(EXIT_FAILURE);
}

void insert_first(int elem, ListaSimpla* &p)
{
	ListaSimpla *added = 0;
	added = new ListaSimpla;
	if(!added) error("Memory error");
	if(!p) {
		p = added;
		p->elem = elem;
	}
	else {
		added->next = p;
		added->elem = elem;
		p = added;
	}
}

void insert_middle(int elem, uint poz, ListaSimpla *&p)
{
	if(!poz){
		insert_first(elem, p);
		return;
	}
	uint k = 0;
	ListaSimpla *q = p;
	while(q){
		if(k == poz-1){
			ListaSimpla *added = new ListaSimpla;
			if(!added) error("Memory error");
			added->elem = elem;
			added->next = q->next;
			q->next = added;
			break;
		}
		k++;
		q = q->next;
	}
	if(k != poz-1) cerr<<"Insert_middle error. Check the pozition argument\n";
}

void insert_end(int elem, ListaSimpla *&p)
{
	ListaSimpla *q = p;
	if(!p) insert_first(elem, p);
	else {
		while(q->next){
			q = q->next;
		}
		ListaSimpla *added = new ListaSimpla;
		if(!added) error("Memory error");
		added->elem = elem;
		q->next = added;
	}
}

void remove_first(ListaSimpla *&p)
{
	if(p){
		ListaSimpla *q = p;
		p = p->next;
		delete q;
		q = 0;
//		if(!p->next) p = 0;
	}
}

void remove_last(ListaSimpla *&p)
{
	if(p){
		ListaSimpla *q = p;
		ListaSimpla *r = p;
		while(r->next){
			q = r;
			r = r -> next;
		}
		q->next = 0;
		delete r;
		r = 0;
	}
}

void remove_middle(int elem, ListaSimpla *&p)
{
	if(p){
		if(p->elem == elem){
			remove_first(p);
			return;
		}
		ListaSimpla *q = p;
		ListaSimpla *r = p;
		while(r->elem != elem){
			q = r;
			r = r->next;
			if(!r){
				cerr<<elem<<" not found in the list, so it couldn't be deleted\n";
				return;
			}
		}
		q->next = r->next;
		delete r;
		r = 0;
	}
}

void remove_middle(uint poz, ListaSimpla *&p)
{
	if(p){
		if(!poz) {
			remove_first(p);
			return;
		}
		ListaSimpla *q = p;
		ListaSimpla *r = p;
		uint k = 0;
		while(k != poz){
			q = r;
			r = r->next;
			k++;
			if(!r){
				cerr<<"Illegal position: "<<poz<<"\n";
				return;
			}
		}
		q->next = r->next;
		delete r;
		r = 0;
	}
}

void print(ListaSimpla *p)
{
	cout<<p<<" = (";
	while(p){
		cout<<p->elem<<" ";
		p = p->next;
	}
	cout<<")\n";
}

int main()
{
	ListaSimpla *list = 0;
	for(uint i = 0; i < 10; ++i)
		insert_first((int)i, list);
	print(list);
	for(uint i = 0; i < 10; ++i)
		remove_first(list);
	print(list);
	for(uint i = 0; i < 10; ++i)
		insert_middle(i, i, list);
	print(list);
	for(uint i = 11; i; --i)
		remove_middle(i-1, list);
	print(list);
	for(uint i = 0; i < 10; ++i)
		insert_end(i, list);
	print(list);
	for(uint i = 0; i < 10; ++i)
		remove_middle((int)i, list);
	print(list);
	return 0;
}