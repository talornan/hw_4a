#include "character.hpp"
namespace ariel
{

character::character(const string& name, const Point& location) 
    : name(name), location(location), hitPoints(0) {}

bool character::isAlive() const{
    return hitPoints>0;
}

double character::distance(character& other){
    return this->location.distance(other.getLocation());
}

void character::hit(int damage)  {
    hitPoints -= damage;
    if (hitPoints < 0)
        hitPoints = 0;
}

string character::print() const {
    string result = "Name: " + name + ", Hit Points: " + to_string(hitPoints) + ", Location: ";
    result += location.print();
    return result;
}

bool character::operator==(const character& other) const {
    return (this->name == other.name) && (this->location == other.location) &&
           (this->hitPoints == other.hitPoints);
}


character :: ~character(){}



}

