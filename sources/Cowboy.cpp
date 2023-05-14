#include "Cowboy.hpp"

namespace ariel
{

Cowboy::Cowboy(const string& name, const Point& location)
    : character(name, location), balls(6), hitPoints(110) {
    // Constructor implementation
}

void Cowboy::shoot(character* enemy) {
    /*
    Shoots the enemy if the Cowboy is alive and has bullets remaining.
    Decreases the enemy's hit points by 10 and decrements the bullet count.
    */

    if (isAlive() && balls > 0) {
        enemy->hit(10);
       balls--;
    }
}

bool Cowboy::hasBullets() const {
    /*
    Returns true if the Cowboy has balls remaining, false otherwise.
    */

    return balls > 0;
}

void Cowboy::reload() {
    /*
    Reloads the Cowboy's gun by setting the bullet count back to 6.
    */

    balls = 6;
}

string Cowboy::print() const {
    /*
    Returns a string representation of the Cowboy.
    */

    string info = "Name: " + getName() + ", Hit Points: " + to_string(hitPoints) + ", Location: ";
    info += getLocation().print();
    return info;
}

bool Cowboy::operator==(const Cowboy& other) const {
    // Perform the comparison of member variables in the base class
    if (!(character::operator==(other))) {
        return false;
    }
    // Perform the comparison of member variables
    return (this->name == other.name) && (this->location == other.location) &&
           (this->balls == other.balls) && (this->hitPoints == other.hitPoints);
}


} 
