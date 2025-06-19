#include "Register.h"
#include <iostream>
#include <fstream>
using namespace std;
Register::Register() {
    size = 0;
}

void Register::addCar() {
    if (size >= 100) {
        cout << "Rejestr jest pelny!\n";
        return;
    }

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
    cin.ignore();
    cout << "Podaj numer rejestracyjny: ";
    getline(cin, plate);

    Car car(brand, model, color, mileage, plate);

    cars[size] = car;
    size++;

    cout << "Samochod dodany.\n";
}

void Register::removeCarByPlate() {
    string plate;
    cout << "Podaj numer rejestracyjny do usuniecia: ";
    getline(std::cin, plate);
    for (int i = 0; i < size; i++) {
        if (cars[i].getPlate() == plate) {

            for (int j = i; j < size - 1; j++) {
                cars[j] = cars[j + 1];
            }
            size--;
            cout << "Usunieto samochod o rejestracji: " << plate << endl;
            return;
        }
    }
    cout << "Nie znaleziono samochodu o tej rejestracji.\n";
}

void Register::displayAll() const {
    if (size == 0) {
        cout << "Rejestr jest pusty" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cars[i].display();
    }
}

void Register::searchByBrand() const {
    string brand;
    cout << "Podaj marke do wyszukania: ";
    getline(cin, brand);
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (cars[i].getBrand() == brand) {
            cars[i].display();
            ++count;
        }
    }
    if (count == 0) {
        cout << "Nie ma samochodu o takiej marce.\n";
    }
}

void Register::searchByColor() const {
    string color;
    cout << "Podaj kolor do wyszukania: ";
    getline(std::cin, color);
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (cars[i].getColor() == color) {
            cars[i].display();
            ++count;
        }
    }
    if (count == 0) {
        cout << "Nie ma samochodu w takim kolorze.\n";
    }
}



void Register::searchMileageAbove() const {
    int mileage;
    cout << "Podaj minimalny przebieg: ";
    cin >> mileage;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (cars[i].getMileage() > mileage) {
            cars[i].display();
            count++;
        }
    }
    if (count == 0) {
        cout << "Brak samochodow z przebiegiem wiekszym niz " << mileage << ".\n";
    }
}

void Register::searchMileageBelow() const {
    int mileage;
    cout << "Podaj maksymalny przebieg: ";
    cin >> mileage;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (cars[i].getMileage() < mileage) {
            cars[i].display();
            count++;
        }
    }
    if (count == 0) {
        cout << "Brak samochodów z przebiegiem mniejszym niż " << mileage << ".\n";
    }
}

void Register::saveToFile() const {
    string filename;
    cout << "Podaj nazwe pliku do zapisu: ";
    getline(cin, filename);
    ofstream file(filename);
    if (!file) {
        cout << "Blad otwierania pliku do zapisu!\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        file << cars[i].serialize() << endl;
    }
    file.close();
    cout << "Zapisano dane do pliku.\n";
}

void Register::loadFromFile() {
    string filename;
    cout << "Podaj nazwe pliku do wczytania: ";
    getline(cin, filename);
    ifstream file(filename);
    if (!file) {
        cout << "Blad otwierania pliku do odczytu!\n";
        return;
    }
    string line;
    size = 0;
    while (getline(file, line) && size < 100) {
        cars[size] = Car::deserialize(line);
        size++;
    }
    file.close();
    cout << "Wczytano dane z pliku.\n";
}
