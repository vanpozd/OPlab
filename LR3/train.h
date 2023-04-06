#ifndef TRAIN_H
#define TRAIN_H
#include <string>

class train
{
	private:
	int hours, minutes;
	std::string number, dest;

	public:
	train() : hours(0), minutes(0), number("00000"), dest("") {}
    train(int h, int m, std::string num, std::string destination) : hours(h), minutes(m), number(num), dest(destination) {}
	int get_hours();
	int get_minutes();
	std::string get_number();
	std::string get_dest();
	void set_hours(int);
	void set_minutes(int);
	void set_number(std::string);
	void set_dest(std::string);
};

#endif