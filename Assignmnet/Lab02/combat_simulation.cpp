#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Enemy {
protected:
    string _name;
    int _health;
    int _attack_power;

public:
    Enemy(string name, int health, int attack_power) : _name(name), _health(health), _attack_power(attack_power) {}
    virtual ~Enemy() {}

    virtual void attack() = 0;
    void take_damage(int damage) {
        _health -= damage;
        if (_health < 0) _health = 0;
    }
    bool is_defeated() { return _health <= 0; }
    virtual void special_ability() {}
    void display_status() { cout << _name << " Health: " << _health << "\n"; }
    string get_name() const { return _name; }
};

class Goblin : public Enemy {
public:
    Goblin() : Enemy("Goblin", 30, 10) {}
    void attack() override {
        int damage = _attack_power;
        if (rand() % 10 < 1) { // 10% chance
            cout << _name << " used Sneaky Strike! Critical hit!\n";
            damage *= 2;
        }
        cout << _name << " attacks with " << damage << " damage.\n";
    }
};

class Dragon : public Enemy {
public:
    Dragon() : Enemy("Dragon", 100, 30) {}
    void attack() override {
        int fire_damage = 10;
        cout << _name << " breathes fire and attacks with " << (_attack_power + fire_damage) << " damage!\n";
    }
};

class UndeadKnight : public Enemy {
public:
    UndeadKnight() : Enemy("Undead Knight", 50, 15) {}
    void attack() override {
        cout << _name << " slashes with " << _attack_power << " damage.\n";
    }
    void special_ability() override {
        if (is_defeated() && rand() % 5 == 0) { // 20% chance
            _health = 25;
            cout << _name << " resurrects with 25 health!\n";
        }
    }
};

void battle(Enemy &enemy) {
    cout << enemy.get_name() << " appears!\n";
    enemy.attack();
    enemy.take_damage(20);
    if (enemy.is_defeated()) {
        cout << enemy.get_name() << " is defeated!\n";
        enemy.special_ability();
    } else {
        enemy.display_status();
    }
}

int main() {
    srand(time(0));
    Goblin goblin;
    Dragon dragon;
    UndeadKnight knight;
    
    battle(goblin);
    battle(dragon);
    battle(knight);
    return 0;
}
