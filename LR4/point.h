#ifndef POINT_H
#define POINT_H
#include <string>

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
	int qudrant();
	point operator++ ();
	point operator++ (int);
	double operator-(const point& other);
};

#endif