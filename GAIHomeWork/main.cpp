#include<iostream>
#include<fstream>
#include<map>
#include<vector>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------\n"

class ViolationDatabase
{
	std::map<std::string, std::vector<std::string>> violationsMap;
public:
	void addViolation(const std::string& carNumber, const std::string& violation)
	{
		violationsMap[carNumber].push_back(violation);
	}
	void printDatabase()const
	{
		cout << "База данных штрафных квитанций: " << endl;
		for (const auto& entry : violationsMap)
		{
			cout << "Номер машины: " << entry.first << endl;
			cout << "Правонарушения: " << endl;
			for (const auto& violation : entry.second)
			{
				cout << " - " << violation << endl;
			}
		}
		cout << delimiter << endl;
	}
	void printForCar(const std::string& carNumber)const
	{
		cout << "Данные по заданному номеру машины: " << endl;
		auto it = violationsMap.find(carNumber);
		if (it != violationsMap.end())
		{
			cout << "Номер машины: " << carNumber << endl;
			cout << "Правонарушения: " << endl;
			for (const auto& violation : it->second)
			{
				cout << " - " << violation << endl;
			}
		}
		else
		{
			cout << "Нет данных о правонарушениях для машины с номером " << carNumber << endl;
		}
		cout << delimiter << endl;
	}
	void printInRange(const std::string& first, const std::string& last)const
	{
		cout << "Данные по диапазону номеров машин: " << endl;
		auto itFirst = violationsMap.lower_bound(first);
		auto itLast = violationsMap.upper_bound(last);
		for (auto it = itFirst; it != itLast; ++it)
		{
			cout << "Номер машины: " << it->first << endl;
			cout << "Правонарушения: " << endl;
			for (const auto& violation : it->second)
			{
				cout << " - " << violation << endl;
			}
		}
		cout << delimiter << endl;
	}
	void save(const std::string& file)
	{
		std::ofstream fout(file);
		for (const auto& entry: violationsMap)
		{
			fout << entry.first << tab;
			for (const auto& violation : entry.second)
			{
				fout << " - " << violation << endl;
			}
			fout << endl;
		}
		fout.close();
		std::string command = "notepad ";
		command += file;
		system(command.c_str());
	}
	void load(const std::string& file)
	{
		std::ifstream fin(file);
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				const int SIZE = 1024;
				char buffer[SIZE]{};
				fin.getline(buffer, SIZE);
				cout << buffer << endl;
			}
			fin.close();
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");

	ViolationDatabase database;

	database.addViolation("К245ОР", "Выезд на встречную полосу");
	database.addViolation("В456НУ", "Проезд на красный свет светофора");
	database.addViolation("В456НУ", "Парковка в неположенном месте");
	database.addViolation("П873ЗЖ", "Превышение скорости");
	database.addViolation("О394ГИ", "Вождение без прав");
	
	//database.printDatabase();
	//database.printForCar("В456НУ");
	//database.printInRange("В456НУ", "П873ЗЖ");
	//database.save("base.txt");
	database.load("base.txt");
}