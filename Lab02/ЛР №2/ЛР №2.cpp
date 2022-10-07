#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	int n, count = 1;
	cout << "Введите диапазон поиска" << endl;
	cin >> n;
	int upper = n, lower = 1;
	int result = n / 2;
	cout << result << endl;
	while (true)
	{
		int variant;
		cout << "Выберите вариант" << endl;
		cout << "1 - Много" << endl;
		cout << "2 - Мало" << endl;
		cout << "3 - Угадал" << endl;
		cin >> variant;
		cout << endl;
		switch (variant)
		{
		case 1:
			upper = result;
			result = (upper + lower) / 2;
			cout << result << endl;
			break;
		case 2:
			lower = result;
			result = (upper + result) / 2;
			cout << result << endl;
			break;
		case 3:
			cout << "Число шагов: " << count << endl;
			exit(0);
			break;
		default:
			exit(0);
			break;
		}
		count++;
	}
}