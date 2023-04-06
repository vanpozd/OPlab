#include <iostream>
#include <fstream>
#include <string>
#include "train.h"

int train_count()
{
	int trains_count;
	std::cout << "Введіть кількість потягів: ";
	std::cin >> trains_count;
	return trains_count;
}
train fill_train_data()
{
	std::string dest,number;
	std::cout << "Введіть дані потяга:\nМісце призначення: ";
	std::cin >> dest;
	std::cout << "Номер потяга: ";
	std::cin >> number;
	int hours, minutes;
	std::cout << "Введіть час відправлення потяга:\nГодина: ";
	std::cin >> hours;
	std::cout << "Хвилини: ";
	std::cin >> minutes;
	train new_train(hours,minutes,number,dest);
	return new_train;
}
int	time_point(int hours,int minutes = 0)
{
	int sum;
	sum = ((hours * 60) + minutes);
	return sum;
}
int time_filler()
{
	int hour;
	std::cin >> hour;
	return time_point(hour);
}
std::string time_stringer(int time)
{
	std::string result;
	switch (time)
	{
	case 0:
		result = "00";
		break;
	case 1:
		result = "01";
		break;
	case 2:
		result = "02";
		break;
	case 3:
		result = "03";
		break;
	case 4:
		result = "04";
		break;
	case 5:
		result = "05";
		break;
	case 6:
		result = "06";
		break;
	case 7:
		result = "07";
		break;
	case 8:
		result = "08";
		break;
	case 9:
		result = "09";
		break;
	default:
		result = std::to_string(time);
		break;
	}
	return result;
}

int main()
{
	int trains_count = train_count();
	train trains[trains_count];
	for(int i = 0; i < trains_count; i++)
	{
		trains[i] = fill_train_data();
	}
	std::cout << "Від якої години починається діапазон: ";
	int ftime = time_filler();
	std::cout << "До якої години діапазон діє: ";
	int ltime = time_filler();
	std::cout << "Потяги, які відправляються у зазначеному діапазоні:" << std::endl;
	std::cout << "\n========================\n" << std::endl;
	for(int i = 0; i < trains_count; i++)
	{
		int time = time_point(trains[i].get_hours(),trains[i].get_minutes());
		if((ftime < time) && (time < ltime))
		{
			std::cout << "Номер потяга: " << trains[i].get_number() << std::endl;
			std::cout << "Місце призначення: " << trains[i].get_dest() << std::endl;
			std::cout << "Час відправлення: " << time_stringer(trains[i].get_hours()) << ":" << time_stringer(trains[i].get_minutes()) << std::endl;
			std::cout << "\n========================\n" << std::endl;
		}
	}
}