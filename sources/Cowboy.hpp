#pragma once

#include <iostream>
#include "character.hpp"

using namespace std;

namespace ariel
{

class Cowboy : public character {
protected:
    int balls;
    int hitPoints;

public:
    Cowboy(const string& name, const Point& location);

    /*
     * Shoot an enemy character.
     *
     * @param enemy The enemy character.
     */
    void shoot(character* enemy);

    /*
     * Check if the Cowboy has bullets.
     *
     * @return true if the Cowboy has bullets, false otherwise.
     */
    bool hasBullets() const;

    int getBullets() const {
        return this->balls;
    }

    /*
     * Reload the Cowboy's gun.
     */
    void reload();

    /*
     * Print information about the Cowboy.
     */
    string print() const override;

    // bool operator==(const Cowboy& other) const;

};

} 
