#include "Date.h"
#include <stdexcept>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

Date::Date():day(1),month(1),year(1900){}


Date::Date(unsigned int d, unsigned int m, unsigned int y)
	:Date()
{
	if (!setDay(d) || !setMonth(m) || !setYear(y)) {
		throw std::invalid_argument("Invalid arguments!");
	}
	// inache sme gi setnali
}


bool Date::setDay(unsigned int day)noexcept
{
    if (!Date::validDayAndMonth(day, this->month)) {
        return false;
    }
    //inache denqt e validen toest e mejdu 1.....31
    this->day = day;
    return true;
}

bool Date::setMonth(unsigned int month) noexcept
{
    if (!Date::validDayAndMonth(this->day,month))
    {
        return false;
    }
    this->month = month;
    return true;
}

bool Date::setYear(unsigned int year)noexcept
{
    if (!Date::validYear(year)){
        return false;
    }
    this->year = year;
    return true;
}

void Date::print() const noexcept
{
    std::cout << (this->day < 10 ? "0" : "")<< this->day << "/" << (this->month < 10 ? "0" : "") << this->month << "/" << this->year << std::endl; 
}

bool Date::validDayAndMonth(unsigned int day, unsigned int month) noexcept
{
	switch (month)
	{
	case 1:
		return day <= 31;
	case 2:
		return day <= 28;
	case 3:
		return day <= 31;
	case 4:
		return day <= 30;
	case 5:
		return day <= 31;
	case 6:
		return day <= 30;
	case 7:
		return day <= 31;
	case 8:
		return day <= 31;
	case 9:
		return day <= 30;
	case 10:
		return day <= 31;
	case 11:
		return day <= 30;
	case 12:
		return day <= 31;
	default:
		return false;
	}
}

bool Date::validYear(unsigned int year) noexcept
{

	return year > 1899 && year < 2026; // pravim go za tekushtata godina. ne gledame budeshteto
}
