#include "Aircraft.h"

int main() {
    // Create objects
    CommercialPlane plane1("Airbus A380", 560, 50000);
    FighterJet jet1("F-22 Raptor", 1500, 8200);
    CommercialPlane plane2("Boeing 737", 540, 6000);
    FighterJet jet2("F-16 Falcon", 1500, 7000);

    // Display stats for one object
    cout << "=== Displaying Aircraft Stats ===" << endl;
    plane1.displayStats();
    cout << endl;

    // Array of Aircraft pointers
    Aircraft* aircraftArray[4] = { &plane1, &jet1, &plane2, &jet2 };

    // Loop through array and call fly()
    cout << "=== Aircraft in Action ===" << endl;
    for (int i = 0; i < 4; i++) {
        aircraftArray[i]->fly();
    }

    return 0;
}
