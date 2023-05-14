#include "Ninja.hpp"

namespace ariel
{

Ninja::Ninja(const string& name, const Point& location, int speed)
    : character(name, location), speed(speed), hitpoints(0) {}

void Ninja::move(character* enemy) {
    // Calculate the distance between the ninja and the enemy
    double dist = getLocation().distance(enemy->getLocation());

    // If the distance is less than or equal to the ninja's speed, move directly to the enemy's location
    if (dist <= speed)
        setLocation(enemy->getLocation());
    else {
        // Calculate the distance in the x and y axes between the ninja and the enemy
        double dx = enemy->getLocation().getX() - getLocation().getX();
        double dy = enemy->getLocation().getY() - getLocation().getY();

        // Calculate the ratio of the distance that the ninja can move in one step
        double ratio = speed / dist;

        // Move the ninja towards the enemy by the calculated distance
        Point newLocation(getLocation().getX() + dx * ratio, getLocation().getY() + dy * ratio);
        setLocation(newLocation);
    }
}

void Ninja::slash(character* enemy) {
    double dist = this->location.distance(enemy->getLocation());
    if (isAlive() && dist < 1.0){
        enemy->hit(40);
    }
}

string Ninja::print() const {
    return "Type: Ninja, " + character::print();
}



// bool Ninja::operator==(const Ninja& other) const {
//     // Perform the comparison of member variables in the base class
//     if (!(character::operator==(other))) {
//         return false;
//     }

//     // Perform the comparison of member variables in the derived class
//     return (this->speed == other.speed) && (this->hitpoints == other.hitpoints);
// }



// YoungNinja derived class
YoungNinja::YoungNinja(const string& name, const Point& location)
    : Ninja(name, location, SPEED), hitpoints(0) {}

// TrainedNinja derived class
TrainedNinja::TrainedNinja(const string& name, const Point& location)
    : Ninja(name, location, SPEED), hitpoints(0) {}

//old derived ninja
OldNinja::OldNinja(const string& name, const Point& location)
    : Ninja(name, location, SPEED), hitpoints(0) {}

}