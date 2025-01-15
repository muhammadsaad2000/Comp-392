// Explosive.h
#ifndef EXPLOSIVE_H
#define EXPLOSIVE_H

#include <iostream>
namespace Game {
    class Explosive {
    private:
        int power;
        int damage;
        float spawnTime;

    public:
        Explosive(int p, int d, float s) : power(p), damage(d), spawnTime(s) {}

        void explode() {
            std::cout << "Explosive is detonating with " << power << " power and " << damage << " damage." << std::endl;
        }

        void applyDamage(int damageTaken) {
            std::cout << "Explosive sustained " << damageTaken << " damage. Integrity compromised." << std::endl;
        }
    };
}

#endif // EXPLOSIVE_H
