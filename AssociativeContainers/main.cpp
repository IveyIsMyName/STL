#include<iostream>
#include<map>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------\n"

#define STL_MAP

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_MAP
	//map - это контейнер, каждый элемент которого хранит пару 
	//"ключ - значение" (pair<key, value>). Ключ и значение могут быть
	//любых типов, как одинаковых, так и разных.

	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		{4, "Thursday"},
		{5, "Friday"},
		{5, "Friday"},
		{5, "Friday"},
		{5, "Friday"},
		{5, "Friday"},
		{6, "Saturday"},
		{7, "Saturday"}
	};

	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}

#endif // STL_MAP

}