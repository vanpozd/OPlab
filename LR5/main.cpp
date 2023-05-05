#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "point.h"
#include "triangle.h"

TRtriangle fill_datar();

int main()
{
	int i, n, a, b, c;
	std::cout << "Введіть n: " << std::endl;
	std::cin >> n;
    a = n / 3;
    b = a;
    c = n - (a + b);
	TRtriangle rtriangle[a];
	TItriangle itriangle[b];
	TEtriangle etriangle[c];
	for(i = 0; i < n; i++)
	{
		if(i <= a)
		{
			rtriangle[i] = fill_datar();
		}
		else if(i <= b)
		{
			
		}
		else
		{

		}
	}
}

TRtriangle fill_datar()
{
	TRtriangle figure;
	return figure;
}