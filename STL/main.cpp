#include<iostream>
#include<array>
#include<vector>
#include<list>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------------------\n"

template<typename T>void vector_info(const std::vector<T>& vec);

//#define STL_ARRAY
//#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	const int N = 5;
	std::array<int, N> arr = { 3, 5, 8, 13, 21};
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };

	for (int i = 0; i < vec.size(); i++)
	{ 
		cout << vec[i] << tab;
	}
	cout << endl;
	vector_info(vec);
	vec.push_back(55);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << tab;
	}
	cout << endl;
	vector_info(vec);

	vec.reserve(15);
	vector_info(vec);

	vec.shrink_to_fit();
	vector_info(vec);

	vec.resize(8);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	vector_info(vec);

	vec.resize(14);
	for (int i : vec)cout << i << tab; cout << endl;
	vector_info(vec);

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;

	if (index >= 0 && index <= vec.size())vec.insert(vec.begin() + index, value);
	else cout << "Индекс вне диапазона!" << endl;
	for (int i : vec)cout << i << tab; cout << endl;

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	if (index >= 0 && index <= vec.size())vec.erase(vec.begin() + index);
	else cout << "Индекс вне диапазона!" << endl;
	for (int i : vec)cout << i << tab; cout << endl;
	
#endif // STL_VECTOR	
	std::list<int> list = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	for (int i : list)cout << i << tab; cout << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;

	if (index >= 0 && index <= list.size())
	{
		std::list<int>::iterator it = list.begin(); //инициализируем итератор
		std::advance(it, index); //Перемещаем итератор на нужный индекс
		list.insert(it, value);
	}
	else
	{
		cout << "Индекс вне диапазона!" << endl;
	}
	for (int i : list)cout << i << tab; cout << endl;

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	if (index >= 0 && index <= list.size())
	{
		std::list<int>::iterator it = list.begin();
		std::advance(it, index); //Перемещаем итератор на нужный индекс
		list.erase(it);
	}
	else
	{
		cout << "Индекс вне диапазона!" << endl;
	}
	for (int i : list)cout << i << tab; cout << endl;
}
template<typename T>void vector_info(const std::vector<T>& vec)
{
	cout << "Size:    " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
}