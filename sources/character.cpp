#include "character.hpp"

namespace ariel
{

character::character(const string& name, const Point& location,int hitPoints) 
    : name(name), location(location), hitPoints(hitPoints) ,status(false){}

bool character::isAlive() const{
    return hitPoints>0;
}

double character::distance(const character& other) const{
    return this->location.distance(other.getLocation());
}


void character::hit(int damage)  {
    hitPoints -= damage;
    if (hitPoints < 0)
        hitPoints = 0;
}

string character::print() const {
    std::string result = "Name: " + name + ", Hit Points: " + std::to_string(hitPoints) + ", Location: ";
    result += location.print();
    return result;
}

const Point& character:: getLocation() const {
        return this->location;
 }

character& character::operator=(const character& other) {
    if (this != &other) {
        // Perform the assignment of member variables
        this->name = other.name;
        this->location = other.location;
        this->hitPoints = other.hitPoints;
    }
    return *this;
}


character :: ~character(){}

}


