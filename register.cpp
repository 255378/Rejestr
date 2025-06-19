#include "Register.h"
#include <iostream>
#include <fstream>
using namespace std;
Register::Register() {
    size = 0;
}

void Register::addCar(const Car& car) {
    if (size < 100) {
        cars[size] = car;
        size++;
    } else {
        cout << "Rejestr jest pelny!\n";
    }
}

void Register::removeCarByPlate(const string& plate) {
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
    for (int i = 0; i < size; i++) {
        cars[i].display();
    }
}

void Register::searchByBrand(const string& brand) const {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (cars[i].getBrand() == brand) {
            cars[i].display();
            ++count;
        }
    }
    if (count == 0) {
        std::cout << "Nie ma samochodu o takiej marce.\n";
    }
}

void Register::searchByColor(const string& color) const {
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



void Register::searchMileageAbove(int mileage) const {
    for (int i = 0; i < size; i++) {
        if (cars[i].getMileage() > mileage) {
            cars[i].display();
        }
    }
}

void Register::searchMileageBelow(int mileage) const {
    for (int i = 0; i < size; i++) {
        if (cars[i].getMileage() < mileage) {
            cars[i].display();
        }
    }
}

void Register::saveToFile(const string& filename) const {
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

void Register::loadFromFile(const string& filename) {
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
