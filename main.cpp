#include <iostream>
#include <string>
#include "Car.h"
#include "Register.h"

int main() {
    Register reg;
    int choice;

    do {
        std::cout << "\n -----MENU REJESTRU SAMOCHODOWEGO -----\n";
        std::cout << "1. Dodaj samochod\n";
        std::cout << "2. Usun samochod po rejestracji\n";
        std::cout << "3. Wyswietl wszystkie\n";
        std::cout << "4. Szukaj po marce\n";
        std::cout << "5. Szukaj po kolorze\n";
        std::cout << "6. Szukaj powyzej przebiegu\n";
        std::cout << "7. Szukaj ponizej przebiegu\n";
        std::cout << "8. Zapisz do pliku\n";
        std::cout << "9. Wczytaj z pliku\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string brand, model, color, plate;
                int mileage;
                std::cout << "Podaj marke: ";
                std::getline(std::cin, brand);
                std::cout << "Podaj model: ";
                std::getline(std::cin, model);
                std::cout << "Podaj kolor: ";
                std::getline(std::cin, color);
                std::cout << "Podaj przebieg: ";
                std::cin >> mileage;
                std::cin.ignore();
                std::cout << "Podaj numer rejestracyjny: ";
                std::getline(std::cin, plate);

                Car car(brand, model, color, mileage, plate);
                reg.addCar(car);
                std::cout << "Samochod dodany.\n";
                break;
            }

            case 2: {
                std::string plate;
                std::cout << "Podaj numer rejestracyjny do usuniecia: ";
                std::getline(std::cin, plate);
                reg.removeCarByPlate(plate);
                break;
            }

            case 3:
                reg.displayAll();
                break;

            case 4: {
                std::string brand;
                std::cout << "Podaj marke do wyszukania: ";
                std::getline(std::cin, brand);
                reg.searchByBrand(brand);
                break;
            }

            case 5: {
                std::string color;
                std::cout << "Podaj kolor do wyszukania: ";
                std::getline(std::cin, color);
                reg.searchByColor(color);
                break;
            }

            case 6: {
                int mileage;
                std::cout << "Podaj minimalny przebieg: ";
                std::cin >> mileage;
                std::cin.ignore();
                reg.searchMileageAbove(mileage);
                break;
            }

            case 7: {
                int mileage;
                std::cout << "Podaj maksymalny przebieg: ";
                std::cin >> mileage;
                std::cin.ignore();
                reg.searchMileageBelow(mileage);
                break;
            }

            case 8: {
                std::string filename;
                std::cout << "Podaj nazwe pliku do zapisu: ";
                std::getline(std::cin, filename);
                reg.saveToFile(filename);
                break;
            }

            case 9: {
                std::string filename;
                std::cout << "Podaj nazwe pliku do wczytania: ";
                std::getline(std::cin, filename);
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
