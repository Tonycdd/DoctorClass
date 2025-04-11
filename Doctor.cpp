#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <cstring>
#include <stdexcept>
unsigned int Doctor::registered = 0;


Doctor::Doctor(const char* name)
    :name(nullptr),patientList(nullptr),patientRegistered(0)
{
    if (!setName(name)) {
        throw std::runtime_error("Invalid name!");
    }
    patientList = new Patient[Doctor::PATIENTS];
    //registered si e 0 -> tova e indeksa

}

Doctor::Doctor(const Doctor& other)
    :name(nullptr), patientList(nullptr), patientRegistered(other.patientRegistered)
{
    //other e validen obekt
    // kopirame mu imeto
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->patientList = new(std::nothrow) Patient[other.patientRegistered];
    //ako ne uspee
    if (patientList == nullptr) {
        delete[]this->name;
        throw std::bad_alloc();
    }

    // trqbva da mu prisvoim pacientite
    for (size_t i = 0; i < other.patientRegistered; i++)
    {
        try
        {
            //operator= na pacientite moje da xvurli greshka
            this->patientList[i] = other.patientList[i];
        }
        catch (const std::exception& e)
        {
            delete[] this->name;
            delete[]this->patientList;
            throw e;
        }
    }

    this->registered = other.registered;

}

Doctor& Doctor::operator=(const Doctor& other)
{
    if (this == &other) {
        return *this;
    }
    //dva validni obekta
    Patient* newList = new Patient[other.patientRegistered];
    // ako xvurli greshka - e ok - nqmame leak i ne sme promenili nashiqt obekt
    // inache e uspqlo zadelqneto
    for (size_t i = 0; i < other.patientRegistered; i++)
    {
        try
        {
            newList[i] = other.patientList[i];

        }
        catch (...)
        {
            delete[] newList;
            throw;
        }
    }
    //inache sme go kopirali ok

    // sega iskame da  se probvame da setnem purvo imeto
    if (!setName(other.name)) {
        delete[] newList;
    // other ne e nullptr, ne e i prazen niz, taka che setName shte napravi dve izlishni proverki no ne e problem
        throw std::bad_alloc();
    }

    //inache i to e uspqlo
    delete[]this->patientList;
    this->patientList = newList;
    this->registered = other.registered;
    this->patientRegistered = other.patientRegistered;
    return *this;
}

Doctor::~Doctor()
{
    delete[]this->name;
    delete[] patientList;
}

bool Doctor::setName(const char* name)
{
    if (name == nullptr || name[0] == '\n') {
        return false;
    }
    else if (this->name == name) {
        return false;
    }
    char* newName = new(std::nothrow) char[strlen(name) + 1];
    if (newName == nullptr) {
        return false;
    }
    strcpy(newName, name);
    delete[]this->name;
    this->name = newName;
    return true;
}

void Doctor::registerPatient(const Patient& patient)
{
    //imame nashiq obekt
    if (!(Doctor::canRegister())) {
        throw std::invalid_argument("Too many patients!");
    }
    //inache go dobavqme
    this->patientList[registered++] = patient;
    this->patientRegistered++;
}

double Doctor::average() const
{
    if (patientRegistered == 0) {
        return 0.0;
    }
    //inache imame registrirani
    int totalVisits = 0;
    for (size_t i = 0; i < patientRegistered; i++)
    {
        totalVisits += patientList[i].getVisits();
    }
    return static_cast<double>(totalVisits / patientRegistered);
}

void Doctor::printUpper(int visits) const
{
    if (visits < 0) {
        throw std::invalid_argument("Visits cannot be negative!");
    }
    for (size_t i = 0; i < patientRegistered; i++)
    {
        if (patientList[i].getVisits() > visits) {
            patientList[i].print();
        }
    }
}
