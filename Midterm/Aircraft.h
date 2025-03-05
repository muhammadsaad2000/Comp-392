#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <iostream>
#include <string>

using namespace std;

// Base abstract class

class Aircraft {
protected:
    string modelName;
    int maxSpeed;
    int fuelCapacity;

public:
    Aircraft(string model, int speed, int fuel)
        : modelName(model), maxSpeed(speed), fuelCapacity(fuel) {}

    virtual void fly() = 0; // Pure virtual function

    void displayStats() {
        cout << "Aircraft Model: " << modelName << endl;
        cout << "Max Speed: " << maxSpeed << " knots" << endl;
        cout << "Fuel Capacity: " << fuelCapacity << " gallons" << endl;
    }

    virtual ~Aircraft() {} // Virtual destructor
};

// Derived class: CommercialPlane
class CommercialPlane : public Aircraft {
public:
    CommercialPlane(string model, int speed, int fuel)
        : Aircraft(model, speed, fuel) {}

    void fly() override {
        cout << "CommercialPlane " << modelName << " is cruising at 35,000 feet." << endl;
    }
};

// Derived class: FighterJet
class FighterJet : public Aircraft {
public:
    FighterJet(string model, int speed, int fuel)
        : Aircraft(model, speed, fuel) {}

    void fly() override {
        cout << "FighterJet " << modelName << " is engaging in a high-speed maneuver!" << endl;
    }
};

#endif // AIRCRAFT_H
