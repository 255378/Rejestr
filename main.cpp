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
                string brand, model, color, plate;
                int mileage;
                cout << "Podaj marke: ";
                getline(cin, brand);
                cout << "Podaj model: ";
                getline(cin, model);
                cout << "Podaj kolor: ";
                getline(cin, color);
                cout << "Podaj przebieg: ";
                cin >> mileage;
                while (mileage < 0) {
                    cout << "Podaj prawidlowy przebieg." << endl;
                    cin >> mileage;
                }
                cin.ignore();
                cout << "Podaj numer rejestracyjny: ";
                getline(::cin, plate);

                Car car(brand, model, color, mileage, plate);
                reg.addCar(car);
                cout << "Samochod dodany.\n";
                break;
            }

            case 2: {
                string plate;
                cout << "Podaj numer rejestracyjny do usuniecia: ";
                getline(cin, plate);
                reg.removeCarByPlate(plate);
                break;
            }

            case 3:
                reg.displayAll();
                break;

            case 4: {
                string brand;
                cout << "Podaj marke do wyszukania: ";
                getline(cin, brand);
                reg.searchByBrand(brand);
                break;
            }

            case 5: {
                string color;
                cout << "Podaj kolor do wyszukania: ";
                getline(std::cin, color);
                reg.searchByColor(color);
                break;
            }

            case 6: {
                int mileage;
                cout << "Podaj minimalny przebieg: ";
                cin >> mileage;
                cin.ignore();
                reg.searchMileageAbove(mileage);
                break;
            }

            case 7: {
                int mileage;
                cout << "Podaj maksymalny przebieg: ";
                cin >> mileage;
                cin.ignore();
                reg.searchMileageBelow(mileage);
                break;
            }

            case 8: {
                string filename;
                cout << "Podaj nazwe pliku do zapisu: ";
                getline(cin, filename);
                reg.saveToFile(filename);
                break;
            }

            case 9: {
                string filename;
                cout << "Podaj nazwe pliku do wczytania: ";
                getline(cin, filename);
                reg.loadFromFile(filename);
                break;
            }

            case 0:
                std::cout << "Do widzenia!\n";
                break;

            default:
                std::cout << "Nieznana opcja. Sprobuj ponownie.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
