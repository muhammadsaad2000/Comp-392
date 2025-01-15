// main.cpp
#include "Player.h"
#include "Explosive.h"

using namespace Game;

int main() {
    // Create Player and Explosive objects
    Player player(100, 20, 50);
    Explosive explosive(10, 40, 3.5);

    // Demonstrate functionality
    player.attack();
    player.applyDamage(15);

    explosive.explode();
    explosive.applyDamage(20);

    return 0;
}
