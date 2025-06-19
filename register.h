#ifndef REGISTER_H
#define REGISTER_H
using namespace std;
#include "Car.h"
#include <string>

class Register {
private:
    Car cars[100];
    int size;
public:
    Register();
    void addCar();
    void removeCarByPlate();
    void displayAll() const;
    void searchByBrand() const;
    void searchByColor() const;
    void searchMileageAbove() const;
    void searchMileageBelow() const;
    void saveToFile() const;
    void loadFromFile();
};

#endif
