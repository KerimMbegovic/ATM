#include <iostream>
#include <iomanip>
#include "Racun.h"
using std::cin;
using std::cout;
int main() {
	std::shared_ptr<Racun> racun(new Racun());
	int izbor;

	do {
		do {
			racun->meni();
			cin >> izbor;
			if (izbor == 1) {
				system("cls");
				racun->otvaranjeRacuna();
			}
			if (izbor == 2) {
				system("cls");
				racun->uplata();
			}
			if (izbor == 3) {
				system("cls");
				racun->isplata();
			}
			if (izbor == 4) {
				system("cls");
				racun->ispisTransakcija();
			}
			if (izbor == 5) {
				system("cls");
				racun->informacije();
			}
			if (izbor == 6) {
				system("cls");
				cout << "Hvala i dovidjenja!\n";
			}
			if (izbor < 1 || izbor > 6) system("cls");
		} while (izbor < 1 || izbor > 6);
	} while (izbor != 6);
	

	return 0;
}