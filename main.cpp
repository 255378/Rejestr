#include <iostream>
#include <string>
#include "Car.h"
#include "Register.h"
using namespace std;
int main() {
    Register reg;
    int choice;

    do {
        cout << "\n -----MENU REJESTRU SAMOCHODOWEGO -----\n";
        cout << "1. Dodaj samochod\n";
        cout << "2. Usun samochod po rejestracji\n";
        cout << "3. Wyswietl wszystkie\n";
        cout << "4. Szukaj po marce\n";
        cout << "5. Szukaj po kolorze\n";
        cout << "6. Szukaj powyzej przebiegu\n";
        cout << "7. Szukaj ponizej przebiegu\n";
        cout << "8. Zapisz do pliku\n";
        cout << "9. Wczytaj z pliku\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";
        cin >> choice;
        cin.ignore();


        switch (choice) {
            case 1: {
                reg.addCar();
                break;
            }

            case 2: {
                reg.removeCarByPlate();
                break;
            }

            case 3:
                reg.displayAll();
                break;

            case 4: {
                reg.searchByBrand();
                break;
            }

            case 5: {
                reg.searchByColor();
                break;
            }

            case 6: {
                reg.searchMileageAbove();
                break;
            }

            case 7: {
                reg.searchMileageBelow();
                break;
            }

            case 8: {
                reg.saveToFile();
                break;
            }

            case 9: {
                reg.loadFromFile();
                break;
            }

            case 0:
                cout << "Do widzenia!\n";
                break;

            default:
                cout << "Nieznana opcja. Sprobuj ponownie.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
