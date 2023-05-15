#pragma once

#include <iostream>
#include "character.hpp"

namespace ariel
{

class Ninja : public character {
protected:
    int speed;
    int health;

public:
    /*
     * Constructor for the Ninja class.
     *
     * @param name The name of the ninja.
     * @param location The initial location of the ninja.
     * @param speed The speed of the ninja.
     */
    Ninja(const string& name, const Point& location,int health, int speed);

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
    string print() const override;

    // Getter and Setter methods

    virtual int getSpeed() const {
        return speed;
    }

    virtual void setSpeed(int newSpeed) {
        speed = newSpeed;
    }

    virtual Point getLocation() const {
        return this->location;
    }

    // virtual int getHealth() const{
    //     return this->hitPoints;
    // }

    // bool operator==(const Ninja& other) const; 
};

// YoungNinja derived class
class YoungNinja : public Ninja {

public:
    YoungNinja(const string& name, const Point& location);

};

// TrainedNinja derived class
class TrainedNinja : public Ninja {
public:
    TrainedNinja(const string& name, const Point& location);

};

// OldNinja derived class
class OldNinja : public Ninja {
public:
    OldNinja(const string& name, const Point& location);
};

}
