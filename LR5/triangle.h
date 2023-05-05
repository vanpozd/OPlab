#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

int randint();

class point
{
	private:
	int axisX, axisY;

	public:
	point();
	point(int x);
    point(int x, int y);
	int get_axisX();
	int get_axisY();
	void set_axisX(int);
	void set_axisY(int);
};

class TTriangle
{
	protected:

	point vertex1;
	point vertex2;
	point vertex3;
	double distance(point, point);
	TTriangle();

	public:

	int get_1axisX();
	int get_2axisX();
	int get_3axisX();
	int get_1axisY();
	int get_2axisY();
	int get_3axisY();
	double square();
};
class TRtriangle : public TTriangle //прямокутний
{
	public:

	TRtriangle();
};
class TItriangle : public TTriangle //рівнобедренний
{
	public:

	TItriangle();
	double perimeter();
};
class TEtriangle : public TTriangle //рівносторонній
{
	public:

	TEtriangle();
};

#endif