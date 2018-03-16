#include	 <stdio.h>
#include	 <stdlib.h>

#define MAX		 100


struct Heap_nod
{
	char data;
	unsigned int frecventa;
	struct Heap_nod *stanga, *dreapta;		
};


// Structura heap-ului
struct Heap
{
	unsigned int dim;
	unsigned int n;
	struct Heap_nod **vector;
};



//aloca un nod din heap
struct Heap_nod* alocare(char data, unsigned int frecventa)
{
	struct Heap_nod* nou = (struct Heap_nod *)malloc(sizeof(struct Heap_nod));
	if(nou == 0)
	{
		fprintf(stderr, "[ERROR]: malloc() \n");
		exit(EXIT_FAILURE);
	}

	nou->stanga = 0;
	nou->dreapta = 0;
	nou->data = data;
	nou->frecventa = frecventa;

	return nou;
}


//aloca heap-ul ( vectorul )
struct Heap* alocareHeap(unsigned int n)
{
	struct Heap *heap = 0;
	heap = (struct Heap *)malloc(sizeof(struct Heap));
	heap->dim = 0;
	heap->n = n;
	heap->vector = (struct Heap_nod **)malloc(heap->n * sizeof(struct Heap_nod *));
	return heap;	
}


//interschimba doua noduri din heap
void swap(struct Heap_nod **a, struct Heap_nod **b)
{
	struct Heap_nod *t = *a;
	*a = *b;
	*b = t;
}


//Functie auxiliara pentru crearea heap-ului, realizeaza min(tata, fiu stang, fiu drept),
//acesta va fi "urcat" in heap
void shift(struct Heap *heap, int index)
{
	int tata = index;
	int stanga = 2 * index + 1;		// pentru fiu stang tata se gaseste la indexul 2 * index + 1, 
						// indexarea in heap facandu-se de la 0 
	int dreapta = 2 * index + 2;

	if((stanga < heap->dim) && (heap->vector[stanga]->frecventa < heap->vector[tata]->frecventa))
	{
		tata = stanga;
	}

	if(dreapta < heap->dim && heap->vector[dreapta]->frecventa < heap->vector[tata]->frecventa)
	{
		tata = dreapta;
	}

	if(tata != index)
	{
		swap(&heap->vector[tata], &heap->vector[index]);
		shift(heap, tata);
	}
}


//extrage minimul din heap, adica primul element din vector.
struct Heap_nod* extractMin(struct Heap * heap)
{
	struct Heap_nod* aux = heap->vector[0];
	heap->vector[0] = heap->vector[heap->dim - 1];
	--heap->dim;
	shift(heap, 0);
	return aux;
}


//insereaza un nod in heap
void insertHeap(struct Heap * heap, struct Heap_nod *nod)
{
	++heap->dim;
	int i = heap->dim - 1;
	while((i != 0) && (nod->frecventa < heap->vector[(i - 1) / 2]->frecventa))
	{
		heap->vector[i] = heap->vector[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	heap->vector[i] = nod;
}


//creeaza heap-ul, se incepe de la (n - 1) / 2, pentru ca frunzele se considera a fi aranjate corect in heap 
void creareHeap(struct Heap * heap)
{
	int n = heap->dim - 1;
	int i;
	for(i = (n - 1) / 2; i >= 0; --i)
	{
		shift(heap, i);
	}
}

void afisareVector(int vector[], int n)
{
	int i;
	for(i = 0; i < n ; ++i)
	{
		printf("%d", vector[i]);
	}
	printf("\n");
}

int esteFrunza(struct Heap_nod * nod)
{
	return !(nod->stanga) && !(nod->dreapta);
}


//populeaza heap-ul cu informatii
struct Heap *construireHeap(char data[], int frecventa[], int dim)
{
	struct Heap * heap = alocareHeap(dim);
	int i;
	for(i = 0; i < dim; ++i)
	{
		heap->vector[i] = alocare(data[i], frecventa[i]);
	}
	heap->dim = dim;
	creareHeap(heap);
	return heap;
}

//implementeaza algoritmul de creare a arborelui Huffman
struct Heap_nod * creareHuffman(char data[], int frecventa[], int dim)
{
	struct Heap_nod * stanga, *dreapta, *nou;

	struct Heap * heap = construireHeap(data, frecventa, dim);

	while(heap->dim != 1)
	{
		stanga = extractMin(heap);
		dreapta = extractMin(heap);

		nou = alocare('~', stanga->frecventa + dreapta->frecventa);
		nou->stanga = stanga;
		nou->dreapta = dreapta;
		insertHeap(heap, nou);	
	}

	return extractMin(heap);
}

//afiseaza codurile rezultate
void aficareCoduri(struct Heap_nod* radacina, int vector[], int index)
{
	if(radacina->stanga)
	{
		vector[index] = 0;
		aficareCoduri(radacina->stanga, vector, index + 1);
	}

	if(radacina->dreapta)
	{
		vector[index] = 1;
		aficareCoduri(radacina->dreapta, vector, index + 1);
	}

	if(esteFrunza(radacina))
	{
		printf("%c : ", radacina->data);
		afisareVector(vector, index);
	}
}

//creaza arborele si afiseaza codurile
void coduriHuffman(char data[], int frecventa[], int dim)
{
	struct Heap_nod * radacina = creareHuffman(data, frecventa, dim);

	int vector[MAX], tata = 0;
	aficareCoduri(radacina, vector, tata);
}

int main()
{
	/* Exemplul ales pentru a exemplifica corectitudinea programului este HARABABURA
		f(H) = 1
		f(A) = 4
		f(R) = 2
		f(B) = 2
		f(U) = 1
	*/

	char vector[] =   { 'H', 'A', 'R', 'B', 'U' };
	int frecventa[] = { 1, 4, 2, 2, 1 };
	int dim = sizeof(vector) / sizeof(vector[0]);
	coduriHuffman(vector, frecventa, dim);

	return 0;
}
