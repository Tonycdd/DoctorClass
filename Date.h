#pragma once

const int MAX_SIZE_LENGTH_NAME = 30;

class Date
{
public:
	Date();
	Date(unsigned int d, unsigned int m, unsigned int y);
	Date(const Date& other) = default;
	Date& operator=(const Date& other) = default;
	~Date() = default;
	
	inline unsigned int getDay() const noexcept{
		return this->day;
	}
	inline unsigned int intGetMonth()const noexcept{
		return this->month;
	}
	inline unsigned int getYear()const noexcept {
		return this->year;
	}

	bool setDay(unsigned int day) noexcept;
	bool setMonth(unsigned int month) noexcept;
	bool setYear(unsigned int year)noexcept;

	void print()const noexcept;

private:
	
	static bool validDayAndMonth(unsigned int day,unsigned int month)noexcept;
	static bool validYear(unsigned int year)noexcept;

	unsigned int day;
	unsigned int month;
	unsigned int year;
};