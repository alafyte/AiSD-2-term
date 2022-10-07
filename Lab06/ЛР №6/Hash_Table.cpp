#include "Hash_Twin_Chain.h"
#include "Lists.h"
#include <iostream>

using namespace std;

struct ELEM
{
	unsigned int tel_number;
	char* fio;

	ELEM(int k, char* z)
	{
		tel_number = k;
		fio = z;
	}
};
namespace hashTC
{
	Object create(int size, int(*f)(void*))
	{
		return *(new Object(size, f));
	}

	int Object::hashFunction(void* data)
	{
		return (FunKey(data) % size);
	};

	bool Object::insert(void* data)
	{
		return (Hash[hashFunction(data)].insert(data));
	};

	bool Object::deleteByData(void* data)
	{
		return (Hash[hashFunction(data)].deleteByData(data));
	};

	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};

	void Object::Scan()
	{
		for (int i = 0; i < size; i++)
		{
			Hash[i].scan();
			cout << '\n';
		}
	};
}
