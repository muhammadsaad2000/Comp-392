#include <iostream>
using namespace std;

// Define the Enemy class
class Enemy {
private:
    // Private attributes
    int health;    // Health of the enemy
    int ammo;      // Ammo the enemy has
    int power;     // Attack power of the enemy
    float x, y, z; // Position of the enemy in 3D space

public:
    // Constructor to initialize the attributes
    Enemy(int h, int a, int p, float posX, float posY, float posZ)
        : health(h), ammo(a), power(p), x(posX), y(posY), z(posZ) {}

    // Getter methods for private attributes
    int getHealth() { return health; }
    int getAmmo() { return ammo; }
    int getPower() { return power; }
    void getPosition(float &posX, float &posY, float &posZ) {
        posX = x;
        posY = y;
        posZ = z;
    }

    // Setter methods for private attributes
    void setHealth(int h) { health = h; }
    void setAmmo(int a) { ammo = a; }
    void setPower(int p) { power = p; }
    void setPosition(float posX, float posY, float posZ) {
        x = posX;
        y = posY;
        z = posZ;
    }

    // Method to display the enemy's details
    void displayStatus() {
        cout << "Enemy Status:\n";
        cout << "Health: " << health << "\n";
        cout << "Ammo: " << ammo << "\n";
        cout << "Power: " << power << "\n";
        cout << "Position: (" << x << ", " << y << ", " << z << ")\n";
    }

    // Method to simulate an attack (reduces ammo)
    void attack() {
        if (ammo > 0) {
            ammo--;
            cout << "Enemy attacks! Remaining ammo: " << ammo << "\n";
        } else {
            cout << "Out of ammo!\n";
        }
    }

    // Method to receive damage (reduces health)
    void receiveDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            health = 0;
            cout << "Enemy is defeated!\n";
        } else {
            cout << "Enemy takes damage. Current health: " << health << "\n";
        }
    }
};

int main() {
    // Create an Enemy object
    Enemy enemy(100, 10, 20, 0.0f, 0.0f, 0.0f);

    // Display the initial status
    enemy.displayStatus();

    // Simulate an attack
    enemy.attack();

    // Update position using the setter method
    enemy.setPosition(5.0f, 10.0f, 15.0f);
    enemy.displayStatus();

    // Receive damage
    enemy.receiveDamage(30);
    enemy.displayStatus();

    // Access health using the getter method
    cout << "Enemy's current health: " << enemy.getHealth() << "\n";

    return 0;
}
