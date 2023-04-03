#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "addition.cpp"
//#include "addition.h"

std::string today;
class car
{
	private:
	std::string name;
	std::string date_of_manufacture;
	std::string sell_date;
	bool used_flg;
	bool month_income;
	
	public:
	std::string get_name() const
	{
		return name;
	}
	void set_name(std::string usr_name)
	{
		name = usr_name;
	}
	bool get_used_flg()
	{
		return used_flg;
	}
	std::string get_date_of_manufacture() const
	{
		return date_of_manufacture;
	}
	void set_date_of_manufacture(std::string date)
	{
		date_of_manufacture = date;
	}
	std::string get_sell_date() const
	{
		return sell_date;
	}
	void set_sell_date(std::string date)
	{
		sell_date = date;
	}
	void set_used_flg()
	{
		if(days_in_date(sell_date) - days_in_date(date_of_manufacture) > 365)
		{
			used_flg = true;
		}
		else
		{
			used_flg = false;
		}
	}
	void set_month_income()
	{
		if(days_in_date(today) - days_in_date(sell_date) < 30)
		{
			month_income = true;
		}
		else
		{
			month_income = false;
		}
	}
	bool get_month_income()
	{
		return month_income;
	}
};
car fill_car_data()
{
	car car1;
	std::string token;
	std::cout << "Введіть дані автівки:\nНазва: ";
	std::cin >> token;
	car1.set_name(token);
	std::cout << "Дата випуску: ";
	std::cin >> token;
	car1.set_date_of_manufacture(token);
	std::cout << "Дата надходження у продаж: ";
	std::cin >> token;
	car1.set_sell_date(token);
	car1.set_used_flg();
	car1.set_month_income();
	return car1;
}
std::string infilename()
{
	std::string infilename;
	std::cout << "Введіть назву файлу: " << std::endl;
	std::cin >> infilename;
	return infilename;
}
void today_date()
{
	std::cout << "Введіть сьогоднішню дату(dd.mm.yyyy)" << std::endl;
	std::cin >> today;
}
bool file_exist(std::string filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		return 0;
	}
	else
	{
		std::cout << "Такий файл існує.\n====== Всі автівки салону ======\n" << std::endl;
		while (!file.eof()) //read file
		{
			car c;
			file.read((char*)&c, sizeof(car));
			if (file.gcount() == sizeof(car)) 
			{
				std::cout << "Назва: " << c.get_name() << std::endl;
				std::cout << "Дата випуску: " << c.get_date_of_manufacture() << std::endl;
				std::cout << "Дата надходження: " << c.get_sell_date() << std::endl;
				if(c.get_used_flg() == true)
				{
					std::cout << "Вживаний: так" << std::endl;
				}
				else
				{
					std::cout << "Вживаний: ні" << std::endl;
				}
				std::cout << "\n========================\n" << std::endl;
			}
		}
		file.close();
		return 1;
	}
}

int main()
{
	std::string filename = infilename();
	int a = read_or_write(file_exist(filename));
	std::string compline;
	if(a == 1)	 //append in file
	{
		today_date();
		std::ofstream file(filename, std::ios_base::app | std::ios_base::binary);
		do
		{
			car main_car;
			main_car = fill_car_data();
			file.write((char*)&main_car, sizeof(main_car));
			std::cout << "Чи хочете ви додати ще одну автівку у список?(+/-)" << std::endl;
			std::cin >> compline;
		}while(compline.compare("+") == 0);
		file.close();
	}
	else if (a == 2)	//read from file
	{
		std::ifstream file(filename, std::ios::binary);
		std::cout << "\n====== Автівки які надійшли останього місяця ======\n" << std::endl;
		while (!file.eof()) //read file
		{
            car c;
            file.read((char*)&c, sizeof(car));
            if (file.gcount() == sizeof(car) && c.get_month_income() == true)
			{
				std::cout << "Назва: " << c.get_name() << std::endl;
				std::cout << "Дата випуску: " << c.get_date_of_manufacture() << std::endl;
				std::cout << "Дата надходження: " << c.get_sell_date() << std::endl;
				if(c.get_used_flg() == true)
				{
					std::cout << "Вживаний: так" << std::endl;
				}
				else
				{
					std::cout << "Вживаний: ні" << std::endl;
				}
				std::cout << "\n========================\n" << std::endl;
			}
        }
		file.close();
	}
	else if(a == 3)	 //new file fill
	{
		today_date();
		std::ofstream file(filename,std::ios_base::binary);
		do
		{
			car main_car;
			main_car = fill_car_data();
			file.write((char*)&main_car, sizeof(main_car));
			std::cout << "Чи хочете ви додати ще одну автівку у список?(+/-)" << std::endl;
			std::cin >> compline;
		}while(compline.compare("+") == 0);
		file.close();
	}
}