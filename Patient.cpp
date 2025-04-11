#include "Patient.h"
#include <cstring>
#include <new>
#include <stdexcept>
#include <string>//swap
#define _CRT_SECURE_NO_WARNINGS

Patient::Patient() : name(nullptr), dateOfBirth(), visits(0)
{
	if (!setName("N/A")) {
		throw std::invalid_argument("problem with name");
	}

}


Patient::Patient(const char* name, unsigned int d, unsigned int m, unsigned int y, unsigned int visits)
	:visits(visits)
{
	if (!setName(name) || !setDate(d, m, y)) {
		throw std::invalid_argument("problem occured!");
	}
	// moje da ima proerka za visits, no da kajem che e fine
}

Patient::Patient(const Patient& other)
{
	//other e validen
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	// ako grumne e fine
	this->dateOfBirth = other.dateOfBirth;
	this->visits = other.visits;
}

Patient& Patient::operator=(const Patient& other)
{
	if (this != &other) {
		//copy-swap tui kato obektite ne sa tejki
		Patient temp(other);

		std::swap(this->name, temp.name);
		std::swap(this->dateOfBirth, temp.dateOfBirth);
		this->visits = temp.visits;
	}
	return *this;
}

Patient::~Patient() noexcept
{
	delete[]this->name;
}

bool Patient::setName(const char* name) noexcept
{
	if (name == nullptr || name[0] == '\0') {
		return false;
	}
	//sranqvame adresite
	else if (this->name == name) {
		return false;
	}
	if (strlen(name) > MAX_SIZE_LENGTH_NAME) {
		return false;
	}
	char* newName = new(std::nothrow)  char[strlen(name) + 1];
	// ne iskame da gurmi tui kato vrushtame samo true or false

	if (newName == nullptr) {
		return false;
	}
	//inache e ok newName
	strcpy_s(newName,strlen(name) + 1, name);
	delete[]this->name;
	this->name = newName;
	return true;
}

bool Patient::setDate(unsigned int d, unsigned int m, unsigned int y) 
{
	try
	{
		this->dateOfBirth = Date(d, m, y); // operator=
		//moje samo ctora da ne uspee s args;
	}
	catch (const std::exception& e)
	{
		return false;
	}
	return true;
}

bool Patient::setVisits(unsigned int v)
{
	// ne pravim validaciq
	this->visits = v;
	return true;
}

void Patient::print() const
{
	std::cout << "Name= " << name << ", Date= ";
	dateOfBirth.print();
	std::cout << "Visits= " << visits << "\n";

}
