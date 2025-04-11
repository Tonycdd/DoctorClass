#pragma once
#include "Patient.h"
#include "Date.h"
#include <stdexcept>


class Doctor
{
public:
	static const unsigned int PATIENTS = 100;
	Doctor() = delete; // nqma da pravim masivi ot tqx, a i zasega ne ni trqbva defaulten
	Doctor(const char* name);
	Doctor(const Doctor& other);
	Doctor& operator=(const Doctor& other);
	~Doctor();

	inline const char* getName()const noexcept {
		return this->name;
	}
	static unsigned int getRegistered()noexcept {
		return Doctor::registered;
	}
	inline unsigned int getPatientRegistered()const noexcept {
		return this->patientRegistered;
	}
	const Patient* getPatientList()const noexcept {
		return this->patientList;
	}

	static bool canRegister() {
		// nqmame poveche ot PATIENT pacienti
		if (Doctor::registered  + 1 > Doctor::PATIENTS) {
			return false;
		}
		return true;
	}

	bool setName(const char* name);
	
	//methods
	void registerPatient(const Patient& patient);
	double average()const;
	void printUpper(int visits)const;

private:
	char* name;
	Patient* patientList;
	unsigned int patientRegistered; // vischki registrirani
	static unsigned int registered; // za indeksirane v masiva
};

