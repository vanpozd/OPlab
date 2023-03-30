#include <iostream>
#include <fstream>
#include <sstream>

int days_in_date(std::string date)
{
	std::stringstream ss(date);
	std::string token;

	int day, month, year;
	std::getline(ss, token, '.');
	day = std::stoi(token);
	std::getline(ss, token, '.');
	month = std::stoi(token);
	std::getline(ss, token, '.');
	year = std::stoi(token);
	int sum = day + (month * 30.425) + ((year * 12)*30.425);
	return sum;
}
int read_or_write(bool check)
{
	int a;
	if(check == true)
	{
		std::cout << "Оберіть дію:\n1)Дописати нові автівки у файл.\n2)Автомобілі, які надійшли останнього місяця." << std::endl;
		std::cin >> a;
	}
	else
	{
		std::cout << "Такого файлу ще не існує." << std::endl;
		a = 3;
	}
	return a;
}