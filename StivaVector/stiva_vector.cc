#include	<iostream>
#include	<cstring>

#define		ST_INIT	0x0F

template <class T>
class Stiva {
private:
	unsigned int len;
	unsigned int size;
	T *elems;

	int alloc()
	{
		std::cout<<"debug alloc\n";
		if(elems && size) {
			unsigned int tmp_sz = (size << 1) + 1;
			T *tmp = new T[(tmp_sz) + 1];
			if(!tmp)
				return 0;
			delete[] elems;
			elems = tmp;
			memcpy(elems, tmp, size);
			std::cout<<"debug "<<size<<"\n";
			memset(elems + size, 0, tmp_sz - size);
			size = tmp_sz;
		} else {
			elems = new T[ST_INIT];
			if(!elems)
				return 0;
			size = ST_INIT;
			memset(elems, 0, size);
		}
		return size;
	}

public:
	Stiva()
	{
		len = 0;
		size = 0;
		elems = 0;
	}

	int add(T elem)
	{
		if(len == size) {
			if(!alloc()) {
				return -1;
			}
		}
		elems[len++] = elem;
		std::cout<<"debug "<<size<<"<>"<<len<<"<>"<<elems[len-1]<<"\n";
		return 0;
	}

	void print()
	{
		for(int i = 0; i < len; ++i) {
			std::cout<<"Elem["<<i<<"] = "<<elems[i]<<"\n";
		}
	}


	~Stiva()
	{
		if(elems && size)
			delete[] elems;
	}
};

int main()
{
//	Stiva<int> s = new Stiva<int>();
	Stiva<int> s;
	for(int i = 0; i < 32; ++i) {
		if(s.add(i)) {
			std::cerr<<"add fail\n";
			return 1;
		}
	}

	s.print();
	return 0;
}
