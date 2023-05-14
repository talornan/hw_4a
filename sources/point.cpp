#include "point.hpp"

namespace ariel
{
    Point::Point(double x2, double y2) : x(x2), y(y2) {}

    double Point::distance(const Point& other) const {
        return sqrt(pow((x - other.x),2) + pow((y - other.y),2));
    }

    string Point::print() const {
        return "(" + to_string(x) + ", " + to_string(y) +")" ;
    }

    Point Point::moveTowards(Point& src, Point& dest, double dist) const {
        double currentDistance = sqrt(pow((dest.x - src.x),2) + pow((dest.y - src.y),2));

        if (currentDistance <= dist) {
            return dest;
        } 
        else {
            double ratio = dist / currentDistance;
            double newX = src.x + (dest.x - x)* ratio;
            double newY = src.y + (dest.y - y) * ratio;
            return Point(newX, newY);
        }
    }

    bool Point::operator==(const Point& other) const {
        return (this->x == other.x) && (this->y == other.y);
}


    Point::~Point(){
    }
}  
