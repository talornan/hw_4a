#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(const string& name, const Point& location,  int health,int speed)
        : character(name, const_cast<Point&>(location),health), speed(speed) {}


    void Ninja::move(character* enemy) {
        Point newLocation = Point::moveTowards(getLocation(), enemy->getLocation(), speed);


        setLocation(newLocation);
    }

    void Ninja::slash(character* enemy) {
        double dist = getLocation().distance(enemy->getLocation());
        if (isAlive() && dist < 1.0) {
            enemy->hit(40);
        }
    }

    string Ninja::print() const {
        if (!isAlive()) {
            return "Name: N (" + getName() + "), Location: " + getLocation().print();
        }
        return "Name: N " + getName() + ", HP: " + to_string(getHealth()) + ", Location: " + getLocation().print();
    }

    // YoungNinja derived class
    YoungNinja::YoungNinja(const string& name, const Point& location)
        : Ninja(name, location, 100,14) {}

    // TrainedNinja derived class
    TrainedNinja::TrainedNinja(const string& name, const Point& location)
        : Ninja(name, location,120,12) {}

    // OldNinja derived class
    OldNinja::OldNinja(const string& name, const Point& location)
        : Ninja(name, location,150,8) {}
}
