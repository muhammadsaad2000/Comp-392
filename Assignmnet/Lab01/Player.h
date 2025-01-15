// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
namespace Game {
    class Player {
    private:
        int health;
        int damage;
        int manaPower;

    public:
        Player(int h, int d, int m) : health(h), damage(d), manaPower(m) {}

        void attack() {
            std::cout << "Player is attacking with " << damage << " damage." << std::endl;
        }

        void applyDamage(int damageTaken) {
            health -= damageTaken;
            std::cout << "Player received " << damageTaken << " damage. Health is now " << health << "." << std::endl;
        }
    };
}

#endif // PLAYER_H
