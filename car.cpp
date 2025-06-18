#include "Car.h"
#include <iostream>
#include <sstream>

Car::Car() : brand(""), model(""), color(""), mileage(0), plateNumber("") {}
Car::Car(std::string b, std::string m, std::string c, int km, std::string plate)
    : brand(b), model(m), color(c), mileage(km), plateNumber(plate) {}

void Car::display() const {  //wyswietla
    std::cout << "Marka: " << brand
              << ", Model: " << model
              << ", Kolor: " << color
              << ", Przebieg: " << mileage
              << ", Rejestracja: " << plateNumber << std::endl;
}

std::string Car::getBrand() const {
    return brand;
}

std::string Car::getColor() const {
    return color;
}

int Car::getMileage() const {
    return mileage;
}

std::string Car::getPlate() const {
    return plateNumber;
}

std::string Car::serialize() const {
    return brand + ";" + model + ";" + color + ";" + std::to_string(mileage) + ";" + plateNumber;
}

Car Car::deserialize(const std::string& line) {
    std::stringstream ss(line);



    std::string b, m, c, kmStr, plate;

    std::getline(ss, b, ';');
    std::getline(ss, m, ';');
    std::getline(ss, c, ';');
    std::getline(ss, kmStr, ';');
    std::getline(ss, plate, ';');

    int km = std::stoi(kmStr);
    return Car(b, m, c, km, plate);
}
