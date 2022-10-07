#pragma once              
#include "Lists.h"
namespace hashTC
{
	struct Object
	{
		int size;
		int(*FunKey)(void*);
		listx::Object* Hash;

		Object(int size, int(*f)(void*))
		{
			this->size = size;
			this->FunKey = f;
			this->Hash = new listx::Object[size];
		};

		int hashFunction(void* data);
		bool insert(void* data);
		listx::Element* search(void* data);
		bool deleteByData(void* data);
		void Scan();
	};
	Object create(int size, int(*f)(void*));
}
