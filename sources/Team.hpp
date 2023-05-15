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

namespace ariel {
    class Team {
        
protected:
    vector<character*> members;
    character* leader;

public:
    //Constructor
    Team(character *leader);
    // Default Constructor
    Team();
    // Copy Constructor
    Team(const Team& other);
    // Copy Assignment Operator
    Team& operator=(const Team& other);
    // Move Constructor
    Team(Team&& other) noexcept;
    // Move Assignment Operator
    Team& operator=(Team&& other) noexcept;
    // Destructor
    ~Team();

    //getter and setter methods
    vector<character*> getMembers() const{
        return this->members;
    }
    void setLeader(character* leader);
    character* getLeader(){
        return this->leader;
    }
    // Add a Fighter (Ninja or Cowboy) to the team
    void add(character* fighter);
    // Helper function to find the closest living enemy character to the given character
    character* findClosestEnemy(character* characterObj, const vector<character*>& enemies);
    // Attack an enemy team
    void attack(Team* enemyTeam);
    // Helper function for attacking the target
    void attackTarget(character* attacker, character* target);
    // Chooses a new leader for the attacking group if the current leader is dead.
    // The new leader is the living character closest to the deceased leader in terms of distance.
    character* chooseNewLeader(character* leader, const vector<character*>& members);

    double distanceTo(character& member1, character& member2);
    // Check how many fighters of the team are still alive
    int stillAlive() const;
    // Print the details of the team
    void print() const;
    };
}  
    

   