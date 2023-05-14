#pragma once

#include <iostream>
#include "character.hpp"

namespace ariel
{

class Ninja : public character {
protected:
    int speed;
    int hitpoints;

public:
    /*
     * Constructor for the Ninja class.
     *
     * @param name The name of the ninja.
     * @param location The initial location of the ninja.
     * @param speed The speed of the ninja.
     */
    Ninja(const string& name, const Point& location, int speed);

    /*
     * Move towards an enemy character.
     *
     * @param enemy The enemy character.
     */
    virtual void move(character* enemy);

    /*
     * Perform a slashing attack on an enemy character.
     *
     * @param enemy The enemy character.
     */
    virtual void slash(character* enemy);

    /*
     * Print information about the ninja.
     */
    virtual string print() const ;

    // Getter and Setter methods

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int newSpeed) {
        speed = newSpeed;
    }

    bool operator==(const Ninja& other) const; 
};

// YoungNinja derived class
class YoungNinja : public Ninja {
private:
    static const int SPEED = 14;
    int hitpoints;

public:
    YoungNinja(const string& name, const Point& location);

};

// TrainedNinja derived class
class TrainedNinja : public Ninja {
private:
    static const int SPEED = 12;
    int hitpoints;

public:
    TrainedNinja(const string& name, const Point& location);

};

// OldNinja derived class
class OldNinja : public Ninja {
private:
    static const int SPEED = 8;
    int hitpoints;

public:
    OldNinja(const string& name, const Point& location);
};

}
