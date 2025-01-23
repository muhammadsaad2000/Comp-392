#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

// Base Warrior class
class Warrior {
protected:
    int health;
    int power;
    int damagePower;
    int x, y;

public:
    Warrior(int h, int p, int d, int x, int y) : health(h), power(p), damagePower(d), x(x), y(y) {}

    virtual std::string getType() const = 0;

    void move() {
        int dx = rand() % 3 - 1; // -1, 0, or 1
        int dy = rand() % 3 - 1;
        x = std::max(0, std::min(9, x + dx));
        y = std::max(0, std::min(9, y + dy));
    }

    void attack(Warrior &opponent) {
        opponent.health -= damagePower;
    }

    bool isAlive() const {
        return health > 0;
    }

    int getX() const { return x; }
    int getY() const { return y; }
    int getHealth() const { return health; }
};

// Derived Soldier class
class Soldier : public Warrior {
public:
    Soldier(int x, int y) : Warrior(100, 10, 15, x, y) {}

    std::string getType() const override {
        return "Soldier";
    }
};

// Derived Queen class
class Queen : public Warrior {
public:
    Queen(int x, int y) : Warrior(150, 20, 25, x, y) {}

    std::string getType() const override {
        return "Queen";
    }
};

// Team class
class Team {
    std::vector<Warrior *> warriors;

public:
    Team(int soldierCount, int queenCount) {
        for (int i = 0; i < soldierCount; ++i)
            addWarrior(new Soldier(rand() % 10, rand() % 10));

        for (int i = 0; i < queenCount; ++i)
            addWarrior(new Queen(rand() % 10, rand() % 10));
    }

    ~Team() {
        for (auto w : warriors)
            delete w;
    }

    void addWarrior(Warrior *w) {
        while (isPositionOccupied(w->getX(), w->getY())) {
            w->move();
        }
        warriors.push_back(w);
    }

    void attackOpponent(Team &opponent) {
        for (auto &w : warriors) {
            if (!w->isAlive())
                continue;

            for (auto &op : opponent.warriors) {
                if (op->isAlive()) {
                    w->attack(*op);
                    break;
                }
            }
        }
    }

    bool isTeamAlive() const {
        return std::any_of(warriors.begin(), warriors.end(), [](Warrior *w) { return w->isAlive(); });
    }

    void moveWarriors() {
        for (auto &w : warriors) {
            if (w->isAlive())
                w->move();
        }
    }

    void printStatus() const {
        for (const auto &w : warriors) {
            std::cout << w->getType() << " at (" << w->getX() << ", " << w->getY()
                      << ") with " << w->getHealth() << " health\n";
        }
    }

private:
    bool isPositionOccupied(int x, int y) const {
        for (const auto &w : warriors) {
            if (w->getX() == x && w->getY() == y)
                return true;
        }
        return false;
    }
};

// Battle Simulator class
class BattleSimulator {
    Team teamA;
    Team teamB;

public:
    BattleSimulator() : teamA(5, 3), teamB(5, 3) {}

    void run() {
        int round = 1;
        while (teamA.isTeamAlive() && teamB.isTeamAlive()) {
            std::cout << "\nRound " << round << ":\n";

            teamA.moveWarriors();
            teamB.moveWarriors();

            teamA.attackOpponent(teamB);
            teamB.attackOpponent(teamA);

            std::cout << "\nTeam A:\n";
            teamA.printStatus();

            std::cout << "\nTeam B:\n";
            teamB.printStatus();

            ++round;
        }

        if (teamA.isTeamAlive())
            std::cout << "\nTeam A wins the battle!\n";
        else
            std::cout << "\nTeam B wins the battle!\n";
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::cout << "Welcome to the Battle Simulator!\n";
    BattleSimulator simulator;
    simulator.run();

    return 0;
}
