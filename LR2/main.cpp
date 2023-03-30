#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
			if(days_in_date(date_of_manufacture) - days_in_date(sell_date) > 365)
			{
				used_flg = true;
			}
			else
			{
				used_flg = false;
			}
		}
};
car fill_car_data()
{
	car car1;
	std::string token;
	std::cout << "Введіть дані автівки:\nНазва: ";
	getline(std::cin, token);
	car1.set_name(token);
	std::cout << "\nДата випуску: ";
	getline(std::cin, token);
	car1.set_date_of_manufacture(token);
	std::cout << "\nДата купівлі: ";
	getline(std::cin, token);
	car1.set_sell_date(token);
	car1.set_used_flg();
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
	std::getline(std::cin, infilename);
	return infilename;
}

int main()
{
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
			std::cout << "Чи хочете ви додати ще одну автівку у список?(+/-)" << std::endl;
			std::cin >> compline;
			file.write((char*)&main_car, sizeof(main_car));
			
		}while(compline.compare("+") == 0);
		file.close();
	}
	else if (a == 2)	//read from file
	{

	}
}