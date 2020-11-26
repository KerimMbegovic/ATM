#pragma once
class Korisnik
{
private:
	char ime[20], prezime[30], adresa[50], grad[30];
public:
	void setime();
	void setprezime();
	void setadresa();
	void setgrad();
	char* getime();
	char* getprezime();
	char* getadresa();
	char* getgrad();
	void postaviKorisnik();

	Korisnik();
	~Korisnik();

};

