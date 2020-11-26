#pragma once
#include "Korisnik.h"
#include "Datum.h"
class Racun
{
private:
	int brRacuna;
	Korisnik korisnik;
	Datum * datumTransakcije;
	float* iznosTransakcije;
	float* stanjeRacuna;
	float limit;
	int brTransakcija;
	bool otvoren;

public:
	Racun();
	void setbrRacuna();
	void setlimit();
	int getbrRacuna();
	float getlimit();
	int getbrTransakcija();
	bool getotvoren();
	void uplata();
	void isplata();
	float getStanje();	
	void otvaranjeRacuna();
	void meni();
	void ispisTransakcija();
	void informacije();

	~Racun();
};

