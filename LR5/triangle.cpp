#include "triangle.h"

int randint()
{
	int randomnum = rand() % 100 + 1; 
	return randomnum;
}

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

int TTriangle::get_1axisX()
{
	return vertex1.get_axisX();
}
int TTriangle::get_2axisX()
{
	return vertex2.get_axisX();
}
int TTriangle::get_3axisX()
{
	return vertex3.get_axisX();
}
int TTriangle::get_1axisY()
{
	return vertex1.get_axisY();
}
int TTriangle::get_2axisY()
{
	return vertex2.get_axisY();
}
int TTriangle::get_3axisY()
{
	return vertex3.get_axisY();
}
double TTriangle::distance(point vert1, point vert2) 
{
	double side = sqrt(pow((vert2.get_axisX() - vert1.get_axisX()), 2) + pow((vert2.get_axisY() - vert1.get_axisY()), 2));
	return side;
}
double TTriangle::square()
{
	double a = distance(vertex1, vertex2);
	double b = distance(vertex2, vertex3);
	double c = distance(vertex1, vertex3);
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
double TItriangle::square()
{
	return 1.5;
}
TTriangle::TTriangle() : vertex1(randint(), randint()), vertex2(randint(), randint()), vertex3(randint(), randint()) {}
TRtriangle::TRtriangle() : TTriangle() 
{
	vertex2.set_axisY(vertex1.get_axisY());
	vertex3.set_axisX(vertex1.get_axisX()); 
}
TItriangle::TItriangle() : TTriangle() 
{
	int ab = randint();
	int ac = ab;
	int bc = sqrt(2.0) * ab;
	vertex2.set_axisX(vertex1.get_axisX() + ab / 2.0);
	vertex2.set_axisY(vertex1.get_axisY() + bc / 2.0);
	vertex3.set_axisX(vertex1.get_axisX() - ab / 2.0);
	vertex3.set_axisY(vertex1.get_axisY() + bc / 2.0);
}
double TItriangle::perimeter()
{
	double a = distance(vertex1, vertex2);
	double b = distance(vertex2, vertex3);
	double c = distance(vertex1, vertex3);
	double sum = a + b + c;
	return sum;
}
TEtriangle::TEtriangle() : TTriangle() 
{
	double side = randint() % 50 + 1;
	double height = (sqrt(3) / 2) * side;
	vertex2.set_axisX(vertex1.get_axisX() + side / 2);
	vertex2.set_axisY(vertex1.get_axisY() + height);
	vertex3.set_axisX(vertex1.get_axisX() - side / 2);
	vertex3.set_axisY(vertex1.get_axisY() + height);
}