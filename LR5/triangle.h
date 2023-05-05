#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "point.h"

int randint();

class TTriangle
{
	protected:

	point vertex1, vertex2, vertex3;
	double distance(point, point);
	TTriangle();
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
};
class TEtriangle : public TTriangle //рівносторонній
{
	public:

	TEtriangle();
};

#endif