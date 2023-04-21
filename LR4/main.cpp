#include "point.h"
#include <iostream>
#include <sstream>
#include <string>

point doter();

int main()
{
	std::cout << "Введіть координати першої точки(X Y): " << std::endl;
	point point1 = doter();
	std::cout << "Введіть координати другої точки(X Y): " << std::endl;
	point point2 = doter();
	std::cout << "Введіть координати третьої точки(X Y): " << std::endl;
	point point3 = doter();
	++point1;
	point2++;
	double distance = point1 - point2;
	int quad = point3.qudrant();
	std::cout << "Т1 (" << point1.get_axisX() << "," << point1.get_axisY() << ")" << std::endl;
	std::cout << "Т2 (" << point2.get_axisX() << "," << point2.get_axisY() << ")" << std::endl;
	std::cout << "Т3 (" << point3.get_axisX() << "," << point3.get_axisY() << ")" << std::endl;
	std::cout << "Відстань між Т1 та Т2: " << distance << std::endl;
	std::cout << "Квадрант Т3: " << quad << std::endl;
}

point doter()
{
	int x = 0;
	int y = 0;
	std::string input;
	getline(std::cin, input);
	std::stringstream ss(input);
	ss >> x >> y;
	point dot(x,y);
	return dot;
	/*
	if(x == 0)
	{
		point dot;
		return dot;
	}
	else if (x != 0 && y == 0)
	{
		point dot(x);
		return dot;
	}
	else
	{
		point dot(x,y);
		return dot;
	}
	*/
}