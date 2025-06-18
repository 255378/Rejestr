#ifndef REGISTER_H
#define REGISTER_H

#include "Car.h"
#include <string>

class Register {
private:
    Car cars[100];
    int size;

public:
    Register();

    void addCar(const Car& car);
    void removeCarByPlate(const std::string& plate);
    void displayAll() const;

    void searchByBrand(const std::string& brand) const;
    void searchByColor(const std::string& color) const;
    void searchMileageAbove(int mileage) const;
    void searchMileageBelow(int mileage) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
