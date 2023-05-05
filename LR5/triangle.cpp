#include "triangle.h"
#include "point.h"

int randint()
{
	srand(time(0)); 
	int randomnum = rand() % 100 + 1; 
}

double TTriangle::distance(point vertex1, point vertex2) 
{
	double dx = vertex1.get_axisX() - vertex2.get_axisX();
	double dy = vertex1.get_axisY() - vertex2.get_axisY();
	return std::sqrt(dx*dx + dy*dy);
}

TTriangle::TTriangle() : vertex1(randint(), randint()), vertex2(randint(), randint()), vertex3(randint(), randint()) {}
TRtriangle::TRtriangle() : TTriangle() {}
TEtriangle::TEtriangle() : TTriangle() {}
TItriangle::TItriangle() : TTriangle() {}
