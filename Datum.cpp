#include "Datum.h"
#include <string>
#include <iostream>


void Datum::setdatum()
{
	std::cout << "Unesite datum: ";
	std::cin.getline(this -> datum, 11);
}

char* Datum::getdatum()
{
	return this->datum;
}

Datum::Datum()
{
	strcpy_s(this->datum,"1.1.1900");
}

Datum::~Datum()
{
}
