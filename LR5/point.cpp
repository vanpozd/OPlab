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