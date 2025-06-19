#ifndef CAR_H
#define CAR_H
using namespace std;
#include <string>

class Car {
private:
    string brand;
    string model;
    string color;
    int mileage;
    string plateNumber;

public:
    Car(); // Konstruktor domyślny
    Car(string b, string m, string c, int km, string plate);




    void display() const;




    string getBrand() const;

    string getColor() const;

    int getMileage() const;

    string getPlate() const;


    string serialize() const;

    static Car deserialize(const string &line);
};

#endif
