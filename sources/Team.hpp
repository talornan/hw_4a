#pragma once

#include "character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace ariel
{

class Team {
protected:
    vector<character*> members;
    character* leader;

public:
    // Constructor
    Team(character* leader);

    //getter and setter methods
   vector<character*> getMembers(){
    return this->members;
    }

    void setLeader(character* leader2){
        this->leader = leader2;
    }

    character* getLeader(){
        return this->leader;
    }

    // Add a Fighter (Ninja or Samurai) to the team
    virtual void add(character* fighter);

    // Helper function to find the closest living enemy character to the given character
    character* findClosestEnemy(character* characterObj, const vector<character*>& enemies);

    // Attack an enemy team
    void attack(Team* enemyTeam);

    // Helper function for attacking the target
    void attackTarget(character* attacker, character* target);


    // Chooses a new leader for the attacking group if the current leader is dead.
    // The new leader is the living character closest to the deceased leader in terms of distance.
    character* chooseNewLeader(character* leader, vector<character*>& members);

    virtual double distanceTo(character& member1, character& member2){
        return member1.getLocation().distance(member2.getLocation());
    }

    // Check how many fighters of the team are still alive
    virtual int stillAlive() const;

    // Print the details of the team
    virtual void print() const;

    // Destructor
    virtual ~Team();
};

}


