#include "point.h"

point::point() : axisX(0), axisY(0) {} 
point::point(int x) : axisX(x), axisY(0) {}
point::point(int x, int y) : axisX(x), axisY(y) {}

int point::get_axisX()
{
	return axisX;
}
int point::get_axisY()
{
	return axisY;
}
void point::set_axisX(int x)
{
	axisX = x;
}
void point::set_axisY(int y)
{
	axisY = y;
}
int point::qudrant()
{
	if(axisX > 0 && axisY > 0)
	{
		return 1;
	}
	else if(axisX < 0 && axisY > 0)
	{
		return 2;
	}
	else if(axisX < 0 && axisY < 0)
	{
		return 3;
	}
	else
	{
		return 4;
	}
}
point point::operator++ () 
{
	axisX++;
	return *this;
}
point point::operator++ (int) 
{
	point temp = *this;
	axisY++;
	return temp;
}
double point::operator-(const point& other) 
{
	double dx = axisX - other.axisX;
	double dy = axisY - other.axisY;
	return std::sqrt(dx*dx + dy*dy);
}