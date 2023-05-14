#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "point.hpp"

using namespace std;

namespace ariel
{
    class character {
    protected:
        Point location;
        string name;
        int hitPoints;

    public:
        character(const string& name, const Point& location);

        //getter & setter

        string getName() const{
            return this->name;
        }

        void setName(string newName){
            this->name = newName;
        }

        Point getLocation() const {
            return this->location;
        }
        void setLocation(Point newLocation){
            this->location = newLocation;
        }

        int getHitPoints() const{
            return this->hitPoints;
        }

        void setHitPoints(int newHitPoints){
            this->hitPoints=newHitPoints;
        }


        /*
         * Check if the character is alive.
         *
         * @return true if the character is alive, false otherwise.
         */
        bool isAlive() const;

        /*
         * Calculate the distance between two characters.
         *
         * @param other The other character.
         * @return The distance between the characters.
         */
        double distance(character& other);

        /*
         * Print information about the character.
         */
        virtual string  print() const = 0;

        /*
         * Inflict damage to the character.
         *
         * @param damage The amount of damage to inflict.
         */
        void hit(int damage) ;

        bool operator==(const character& other) const;

        // Destructor
        virtual ~character();
    };

} 
