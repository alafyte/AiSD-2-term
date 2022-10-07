#include "Hash_Twin_Chain.h"
#include <iostream>
#include <Windows.h>

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
	ELEM()
	{
		tel_number = 0;
		fio = nullptr;
	}
};
//-------------------------------
int hf(void* d)
{
	ELEM* f = (ELEM*)d;
	return f->tel_number;
}
//-------------------------------
void ELEM_print(listx::Element* e)
{
	cout << ((ELEM*)e->data)->fio;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int current_size = 0;
	cout << "Введите размер хеш-таблицы" << endl;
	for (;;)
	{
		cin >> current_size;
		if (cin.get() != (int)'\n')
		{
			cout << ">>>>>>>>>>> Введены неверные данные, попробуйте ещё раз <<<<<<<<<<<" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int number;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "Сделайте выбор" << endl;
		cin >> choice;
		if (cin.get() != (int)'\n')
		{
			cout << ">>>>>>>>>>> Введены неверные данные, попробуйте ещё раз <<<<<<<<<<<" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}

		switch (choice)
		{
			case 0:  
				exit(0);
			case 1: 
				H.Scan();
				break;
			case 2:
			{	
				ELEM* a = new ELEM;
				char* str = new char[100];
				cout << ">>>>>>>>>>> Введите номер телефона (7 цифр) <<<<<<<<<<<" << endl;
				cin >> number;
				cin.ignore(32767, '\n');
				a->tel_number = number;
				cout << ">>>>>>>>>>> Введите ФИО <<<<<<<<<<<" << endl;
				cin.getline(str, 100);
				a->fio = str;
				H.insert(a);
			}
				  break;
			case 3: 
			{	
				ELEM* b = new ELEM;
				cout << ">>>>>>>>>>> Введите номер телефона <<<<<<<<<<<" << endl;
				cin >> number;
				b->tel_number = number;
				H.deleteByData(b);
			}
			break;

			case 4: 
			{
				ELEM* c = new ELEM;
				cout << ">>>>>>>>>>> Введите номер телефона <<<<<<<<<<<" << endl;
				cin >> number;
				c->tel_number = number;
				if (H.search(c) == NULL)
					cout << ">>>>>>>>>>> Элемент не найден <<<<<<<<<<<" << endl;
				else
				{
					cout << "Владелец: " << endl;
					ELEM_print(H.search(c));
					cout << endl;
				}
			}
				break;
			default: 
				cout << ">>>>>>>>>>> Введены неверные данные, попробуйте ещё раз <<<<<<<<<<<" << endl;
		}

	}
	return 0;
}
