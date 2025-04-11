#include <iostream>
#include "Doctor.h"
#include "Patient.h"
#include "Date.h"

int main()
{
    try
    {
        Patient first;
        Patient second("Antonio", 17, 1, 2003,4);
        Patient third("Marina", 24, 10, 2004,4);
        second.setVisits(3); // samo tova trqbva da se printne
        Doctor doc("Dr.Kojuxarova");
        doc.registerPatient(first);
        doc.registerPatient(second);
        doc.registerPatient(third);

        doc.printUpper(1);

        Doctor copy(doc);
        std::cout << copy.average() << "\n";
        
    }
    catch (const std::exception& e)
    { 
        std::cerr << e.what() << "\n";
    }
}
