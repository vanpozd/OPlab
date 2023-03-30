#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string today;
int days_in_date(std::string date)
{
	std::stringstream ss(date);
	std::string token;

	int day, month, year;
	std::getline(ss, token, '.');
	day = std::stoi(token);
	std::getline(ss, token, '.');
	month = std::stoi(token);
	std::getline(ss, token, '.');
	year = std::stoi(token);
	int sum = day + (month * 30.425) + ((year * 12)*30.425);
	return sum;
}
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
int read_or_write()
{
	int a;
	std::cout << "Оберіть дію:\n1)Записати у файл.\n2)Зчитати з файлу." << std::endl;
	std::cin >> a;
	return a;
}
std::string infilename()
{
	std::string infilename;
	std::cout << "Введіть назфу файлу: " << std::endl;
	std::cin >> infilename;
	return infilename;
}
void today_date()
{
	std::cout << "Введіть сьогоднішню дату та місяць(dd.mm.yyyy)" << std::endl;
	std::cin >> today;
}

int main()
{
	today_date();
	std::string filename = infilename();
	int a = read_or_write();
	std::string compline;
	if(a == 1)	 //write in file
	{
		std::ofstream file(filename, std::ios::binary);
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
		std::cout << "\n====== Всі автівки салону ======\n" << std::endl;
		while (!file.eof()) //read file
		{
            car c;
            file.read((char*)&c, sizeof(car));
            if (file.gcount() == sizeof(car)) 
			{
				std::cout << "\n========================\n" << std::endl;
				std::cout << "Назва: " << c.get_name() << std::endl;
				std::cout << "Дата випуску: " << c.get_date_of_manufacture() << std::endl;
				std::cout << "Дата продажу: " << c.get_sell_date() << std::endl;
				if(c.get_used_flg() == true)
				{
					std::cout << "Вживаний: так" << std::endl;
				}
				else
				{
					std::cout << "Вживаний: ні" << std::endl;
				}
			}
        }
		file.close();
		std::ifstream filer(filename, std::ios::binary);	//reopen file to read one more time
		std::cout << "\n====== Автівки які надійшли останього місяця ======\n" << std::endl;
		while (!filer.eof()) //read file
		{
            car c;
            filer.read((char*)&c, sizeof(car));
            if (filer.gcount() == sizeof(car) && c.get_month_income() == true)
			{
				std::cout << "Назва: " << c.get_name() << std::endl;
				std::cout << "Дата випуску: " << c.get_date_of_manufacture() << std::endl;
				std::cout << "Дата продажу: " << c.get_sell_date() << std::endl;
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
		filer.close();
	}
}