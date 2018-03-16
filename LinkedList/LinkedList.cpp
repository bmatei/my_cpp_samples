#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

#define creeazaNod(DATA) ({LinkedListN::Nod *p = new Nod; \
						if(!p){ \
							std::cerr<<"Eroare alocare nod.\n"; \
							exit(1);} \
						p->data = DATA; \
						p->next = 0; \
						p->prev = 0; \
						p; \
					})


using namespace LinkedListN;

static double comparaCrescator(double a, double b){
	return a-b;
}
static double comparaDescrescator(double a, double b){
	return b-a;
}

LinkedList::LinkedList()
{
	head = 0;
	tail = 0;
}

LinkedList::LinkedList(double elem)
{
	head = 0;
	tail = 0;
	pushFront(elem);
}

LinkedList::LinkedList(double *vect, int size)
{
	head = 0;
	tail = 0;
	for(int i = 0; i < size; ++i)
		pushBack(vect[i]);
}

LinkedList::LinkedList(const LinkedList &src)
{
	Nod *p = src.head;
	head = 0;
	tail = 0;
	while(p){
		pushBack(p->data);
		p = p->next;
	}
}

LinkedList::~LinkedList()
{
	while(!isEmpty()){
		popBack();
	}
}

double LinkedList::getFront()
{
	if(!isEmpty())
		return head->data;
	return -1;
}

double LinkedList::getBack()
{
	if(!isEmpty())
		return tail->data;
	return -1;
}

double LinkedList::getAt(int index)
{
	Nod *p = head;
	int k = 0;
	while(p && k != index){
		p = p->next;
		k++;
	}
	if(k == index){
		if(p) return p->data;
		else return -1;
	} else return -1;
}

void LinkedList::pushFront(double elem)
{
	Nod *p = creeazaNod(elem);
	p->next = head;
	if(head) head->prev = p;
	head = p;
	if(!tail) tail = p;
}

void LinkedList::pushBack(double elem)
{
	Nod *p = creeazaNod(elem);
	p->prev = tail;
	if(tail) tail->next = p;
	if(!head) head = p;
	tail = p;
}

double LinkedList::popFront()
{
	if(!isEmpty()){
		Nod *p = head;
		double rez = p->data;
		head = p->next;
		if(head) head->prev = 0;
		else tail = 0;
		delete p;
		return rez;
	}
	return -1;
}

double LinkedList::popBack()
{
	if(!isEmpty()){
		Nod *p = tail;
		double rez = p->data;
		tail = p->prev;
		if(tail) tail->next = 0;
		else head = 0;
		delete p;
		return rez;
	}
}

void LinkedList::pushAt(double elem, int index)
{
	Nod *p = head;
	int k = 0;
	while(p && k != index){
		p = p->next;
		k++;
	}
	if(k == index){
		if(p){
			Nod *q = creeazaNod(elem);
			q->next = p;
			q->prev = p->prev;
			if(p->prev) p->prev->next = q;
			else head = q;
			p->prev = q;
		} else{
			pushBack(elem);
		}
	}
}

double LinkedList::popAt(int index){
	if(!isEmpty()){
		if(index == 0) return popFront();

		Nod *p = head;
		int k = 0;
		while(p && k != index){
			p = p->next;
			k++;
		}
		if(k == index){
			if(p){
				if(p->next){
					p->prev->next = p->next;
					p->next->prev = p->prev;
					double rez = p->data;
					delete p;
					p = 0;
					return rez;
				}
				else return popBack();
			}
		}
	}
	return -1;
}

void LinkedList::erase(double elem)
{
	if(!isEmpty()){
		Nod *p = head;
		while(p){
			if(p->data == elem) break;
			p = p->next;
		}
		if(p){
			if(p->prev) p->prev->next = p->next;
			else head = head->next;
			if(p->next) p->next->prev = p->prev;
			else tail = tail->prev;
			delete p;
		}
	}
}

bool LinkedList::isEmpty()
{
	return (head == 0) && (tail == 0);
}
void LinkedList::print()
{
	using namespace std;
	cout<<"(";
	Nod *p = head;
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<")\n";
}

void LinkedList::sort(bool crescator)
{
	if(!isEmpty()){
		double (*comp)(double, double) = crescator ? comparaCrescator : comparaDescrescator;

		bool schimbat = true;
		while(schimbat){
			schimbat = false;
			for(Nod *p = head; p->next; p = p->next){
				if(comp(p->data, p->next->data) > 0){
					double aux = p->data;
					p->data = p->next->data;
					p->next->data = aux;
					schimbat = true;
				}
			}
		}
	}
}

bool LinkedList::contains(double elem)
{
	if(!isEmpty()){
		Nod *p = head;
		while(p){
			if(p->data == elem) return true;
			p = p->next;
		}
	}
	return false;
}

int LinkedList::containsAt(double elem){
	int i = -1;
	if(!isEmpty()){
		Nod *p = head;
		while(p){
			++i;
			if(p->data == elem) return i;
			p = p->next;
		}
		i = -1;
	}
	return i;
}

int LinkedList::size(){
	int i = 0;
	Nod *p = head;
	while(p){
		p = p->next;
		i++;
	}
	return i;
}