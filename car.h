#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    std::string color;
    int mileage;
    std::string plateNumber;

public:
    Car(); // Konstruktor domyślny
    Car(std::string b, std::string m, std::string c, int km, std::string plate);




    void display() const;




    std::string getBrand() const;

    std::string getColor() const;

    int getMileage() const;

    std::string getPlate() const;


    std::string serialize() const;

    static Car deserialize(const std::string &line);
};

#endif
