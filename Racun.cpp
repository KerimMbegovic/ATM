#include "Racun.h"
#include <iostream>
#include <iomanip>
#include <memory>
using std::cin;
using std::cout;

Racun::Racun()
{
	this->datumTransakcije = new Datum[50];
	this->iznosTransakcije = new float[50];
	this->stanjeRacuna = new float[50];
	this->brTransakcija = 0;
	this->otvoren = 0;
}

Racun::~Racun()
{
	delete[] this->datumTransakcije;
	delete[] this->iznosTransakcije;
	delete[] this->stanjeRacuna;
}

void Racun::setbrRacuna()
{
	cout << "Unesite broj racuna: ";
	cin >> this->brRacuna;
	cin.ignore();

}

void Racun::setlimit()
{
	cout << "Unesite iznos limita: ";
	cin >> this->limit;
	cin.ignore();
}

int Racun::getbrRacuna()
{
	return this->brRacuna;
}

float Racun::getlimit()
{
	return this->limit;
}

int Racun::getbrTransakcija()
{
	return this->brTransakcija;
}

bool Racun::getotvoren()
{
	return this->otvoren;
}

void Racun::otvaranjeRacuna()
{
	if (this->getotvoren()) {
		cout << "Racun je vec otvoren!\n";
	}
	else {
		this->korisnik.postaviKorisnik();
		this->setbrRacuna();
		cout << "\n\tDatum otvoranja racuna\n\n";
		this->datumTransakcije[this->brTransakcija].setdatum();
		cout << "Unesite iznos prvobitne uplate: ";
		cin >> this->iznosTransakcije[this->brTransakcija];
		cin.ignore();
		this->stanjeRacuna[this->brTransakcija] = this->iznosTransakcije[this->brTransakcija];
		this->setlimit();
		this->brTransakcija++;
		this->otvoren = true;
		cout << "\n\tUspjesno ste kreirali vas racun!\n\n";
		system("pause");
	}
}

void Racun::meni()
{
	system("cls");
	cout << "\t1.Kreiranje racuna\n\t2.Uplata\n\t3.Isplata\n\t4.Izvod\n\t5.Informacije\n\t6.Kraj\n";
	cout << "\nIzbor: ";
}

void Racun::uplata()
{
	if (this->getotvoren() == true) {
		cout << "Unesite iznos za uplatu: ";
		cin >> this->iznosTransakcije[this->brTransakcija];
		this->stanjeRacuna[this->brTransakcija] = this->stanjeRacuna[this->brTransakcija - 1] + this->iznosTransakcije[this->brTransakcija];
		cin.ignore();
		this->datumTransakcije[this->brTransakcija].setdatum();
		this->brTransakcija++;
	}
	else {
		cout << "Nemate otvoren racun!\n\n";
		system("pause");
	}
}

void Racun::isplata()
{
	if (this->getotvoren() == true) {
		unos:
		float x;
		cout << "Unesite iznos za isplatu: ";
		cin >> x;
		if (stanjeRacuna[this->brTransakcija - 1]+this->getlimit() >= x) {
			this->iznosTransakcije[this->brTransakcija] = x;
			this->stanjeRacuna[this->brTransakcija] = this->stanjeRacuna[this->brTransakcija - 1] - x;
			cin.ignore();
			this->datumTransakcije[this->brTransakcija].setdatum();
			this->brTransakcija++;
		}
		else{
			cout << "Nije moguce podignuti toliki iznos!\n";
			goto unos;
		}
	}
	else {
		cout << "Nemate otvoren racun!\n\n";
		system("pause");
	}

}

float Racun::getStanje()
{
	return this->stanjeRacuna[this->brTransakcija-1];
}

void Racun::ispisTransakcija()
{
	system("cls");
	cout << "*****************************************************************************\n";
	cout << "Broj racuna: " << this->getbrRacuna();
	cout << "\nKorisnik: " << this->korisnik.getime() << " " << this->korisnik.getprezime();
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(6); cout << "R. br.";
	cout.width(20); cout << "Datum transakcije";
	cout.width(23); cout << "Iznos transakcije";
	cout.width(24); cout << "Stanje racuna";
	cout << "\n----------------------------------------------------------------------------\n";
	for (int i = 0; i < this->brTransakcija; i++) {
		cout.width(6);	cout << i + 1;	
		cout.width(20);	cout << this->datumTransakcije[i].getdatum();
		cout.width(20); cout << std::right << std::setprecision(2) << std::fixed << this->iznosTransakcije[i] << " KM";
		cout.width(20); cout << std::right << std::setprecision(2) << std::fixed << this->stanjeRacuna[i] << " KM\n";
	}
	cout << "\n****************************************************************************\n";
	system("pause");

}

void Racun::informacije()
{
	if (getotvoren() == true) {
		cout << "\n****************************************************************************\n";
		cout << "Korisnik: " << this->korisnik.getime() << " " << this->korisnik.getprezime();
		cout << "\n\nAdresa: " << this->korisnik.getadresa() << "," << this->korisnik.getgrad();
		cout << "\n\nBroj racun: " << this->getbrRacuna();
		cout << "\n\nStanje racuna: " << this->stanjeRacuna[brTransakcija - 1];
		cout << "\n\nPostavljeni limit: " << this->getlimit();
		cout << "\n****************************************************************************\n\n";
		system("pause");
	}
	else {
		cout << "Racun nije otvoren!\n\n";
		system("pause");
	}
}
