#pragma once

#include <iostream>
#include <string>


class Date {
public:
	Date(int month = 1, int day = 1, int year = 1);
	int month();
	int day();
	int year();
	void updateMonth(int month);
	void updateDay(int day);
	void next();
	void back();
private:
	int _month;
	int _day;
	int _year;
};

bool isDate(int month, int day);
int getDaysInMonth(int month);
int dayOfYear(Date d);
std::string toString(Date d);
