#include "Korisnik.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;

Korisnik::Korisnik()
{
	strcpy_s(this->ime, "Niko");
	strcpy_s(this->prezime, "Nikic");
	strcpy_s(this->adresa, "Tu i tamo");
	strcpy_s(this->grad, "Ovamo");
}

Korisnik::~Korisnik()
{

}

void Korisnik::setime()
{
	cin.ignore();
	cout << "Unesite ime korisnika: ";
	cin.getline(this->ime, 20);
}

void Korisnik::setprezime()
{
	cout << "Unesite prezime korisnika: ";
	cin.getline(this->prezime, 30);

}

void Korisnik::setadresa()
{
	cout << "Unesite adresu korisnika: ";
	cin.getline(adresa, 50);
}

void Korisnik::setgrad()
{
	cout << "Unesite grad korisnika: ";
	cin.getline(this->grad, 30);
}

char* Korisnik::getime()
{
	return this->ime;
}

char* Korisnik::getprezime()
{
	return this->prezime;
}

char* Korisnik::getadresa()
{
	return this->adresa;
}

char* Korisnik::getgrad()
{
	return this->grad;
}

void Korisnik::postaviKorisnik()
{
	this->setime();
	this->setprezime();
	this->setadresa();
	this->setgrad();
}
