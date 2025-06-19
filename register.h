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
    void addCar(const Car& car);
    void removeCarByPlate(const string& plate);
    void displayAll() const;
    void searchByBrand(const string& brand) const;
    void searchByColor(const string& color) const;
    void searchMileageAbove(int mileage) const;
    void searchMileageBelow(int mileage) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
