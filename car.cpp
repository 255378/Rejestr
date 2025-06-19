#include "Car.h"
#include <iostream>
#include <sstream>
using namespace std;
Car::Car() : brand(""), model(""), color(""), mileage(0), plateNumber("") {}
Car::Car(string b, string m, string c, int km, string plate)
    : brand(b), model(m), color(c), mileage(km), plateNumber(plate) {}

void Car::display() const {  //wyswietla
    cout << "Marka: " << brand
              << ", Model: " << model
              << ", Kolor: " << color
              << ", Przebieg: " << mileage
              << ", Rejestracja: " << plateNumber << endl;
}

string Car::getBrand() const {
    return brand;
}

string Car::getColor() const {
    return color;
}

int Car::getMileage() const {
    return mileage;
}

string Car::getPlate() const {
    return plateNumber;
}

string Car::serialize() const {
    return brand + ";" + model + ";" + color + ";" + to_string(mileage) + ";" + plateNumber;
}

Car Car::deserialize(const string& line) {
    stringstream ss(line);



    string b, m, c, kmStr, plate;

    getline(ss, b, ';');
    getline(ss, m, ';');
    getline(ss, c, ';');
    getline(ss, kmStr, ';');
    getline(ss, plate, ';');

    int km = stoi(kmStr);
    return Car(b, m, c, km, plate);
}
