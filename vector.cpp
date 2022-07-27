/*У контейнері типу vector зберігається набір цілих чисел. Створіть функтори для вирішення наступних завдань:
■ Пошук мінімального значення;                             ■ Пошук максимального значення;
■ Сортування даних за спаданням;                           ■ Сортування даних за зростанням;
■ Збільшення значень в контейнері на задану константу;     ■ Зменшення значень в контейнері на задану константу;
■ Видалення елементів з контейнера які рівні шуканому значенню.
Не забувайте використовувати алгоритми там, де це необхідно.*/
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;
void print(vector<int>V);


class MinMax {
public:

	void operator()(vector<int>V) {
		print(V); cout << endl;
		auto min = min_element(V.begin(), V.end());//Пошук мінімального значення;    
		cout << "Min element=" << *min << endl;
		auto max = max_element(V.begin(), V.end());//Пошук максимального значення;
		cout << "Max element=" << *max << endl;

	}


	void operator()(vector<int>V, int a) {
		cout << "Add number to all collection" << endl;
		transform(V.begin(), V.end(), V.begin(), [&a](int& x) {return x + a; });//Збільшення значень в контейнері на задану константу;
		print(V); cout << endl;
	}
};


class Sort {
public:
	void operator()(vector<int>V) {
		cout << "Sorting data in ascending order" << endl;
		sort(V.begin(), V.end(), [](int a, int b) {return a < b; });//Сортування даних за зростанням;
		print(V); cout << endl;

		cout << "Sorting data in descending order" << endl;
		sort(V.begin(), V.end(), [](int a, int b) {return a > b; });//Сортування даних за спаданням;  
		print(V); cout << endl;
	}


	void operator()(int a, vector<int>V) {
		cout << "Subtract number from all collection" << endl;
		transform(V.begin(), V.end(), V.begin(), [&a](int& x) {return x - a; });//Зменшення значень в контейнері на задану константу;
		print(V); cout << endl;
	}
};

class FindRemove {
public:
	void operator()(vector<int>V) {
		int k = 0;
		cout << "Enter element from collection and we find and remove it" << endl;
		cin >> k;
		auto result = find(V.begin(), V.end(), k);//пошук елемента
		if (result == V.end())cout << "Wi didn't find element" << endl;
		else {
			cout << "We removed your element:" << endl;
			auto answ = remove(V.begin(), V.end(), k);
			V.erase(answ, V.end());//Видалення елементів з контейнера які рівні шуканому значенню.
			print(V); cout << endl;
		}
	}
};


int main()
{
	srand(time(NULL));
	vector<int>V(10);
	const int a = 5;
	for (int i = 0; i < V.size(); i++)
	{
		V[i] = rand() % 20 - 5;
	}
	MinMax minMax;
	FindRemove Remove;
	Sort Sort_V;
	minMax(V);
	Sort_V(V);
	minMax(V, a);
	Sort_V(a, V);
	Remove(V);
}

void print(vector<int>V) {
	for (auto i : V) {
		cout << i << '\t';
	}
}