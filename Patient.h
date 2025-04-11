#pragma once
#include "Date.h"
#include <iostream>

class Patient
{
public:
	//G4
	Patient();
	Patient(const char* name, unsigned int d, unsigned int m, unsigned int y, unsigned int visits = 0);
	Patient(const Patient& other);
	Patient& operator=(const Patient& other);
	~Patient() noexcept;

	inline const char* getName()const noexcept{
		return this->name;
	}

	inline Date getDate()const noexcept {
		return this->dateOfBirth; // rvo
	}

	inline unsigned int getVisits()const noexcept {
		return this->visits;
	}

	bool setName(const char* name)noexcept;
	bool setDate(unsigned int d, unsigned int m, unsigned int y);
	bool setVisits(unsigned int v);
	void print()const;
private:
	char* name;
	Date dateOfBirth;
	unsigned int visits;

};
