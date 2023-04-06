#include <string>
#include "train.h"

int train::get_hours()
{
	return hours;
}
int train::get_minutes()
{
	return minutes;
}
std::string train::get_number()
{
	return number;
}
std::string train::get_dest()
{
	return dest;
}
void train::set_hours(int x)
{
	hours = x;
}
void train::set_minutes(int x)
{
	minutes = x;
}
void train::set_number(std::string x)
{
	number = x;
}
void train::set_dest(std::string x)
{
	dest = x;
}