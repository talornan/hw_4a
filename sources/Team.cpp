#include "Team.hpp"


namespace ariel
{
    // Constructor
Team::Team(character* leader) : leader(leader) {
    if (leader->getStatus())
        throw runtime_error("In team already!");
    members.push_back(leader);

    leader->setStatus(true);
}

    // Default Constructor
Team::Team() {}

Team::Team(const Team& other) {
    for (auto& member : other.members) {
        this->members.push_back(member);
    }
    this->leader = other.leader;
}

Team& Team::operator=(const Team& other) {
    if (this == &other) {
        return *this;
    }

    for (auto& member : this->members) {
        delete member;
    }
    this->members.clear();

    for (auto& member : other.members) {
        this->members.push_back(member);
    }

    this->leader = other.leader;
    return *this;
}

Team::Team(Team&& other) noexcept {
    for (auto& member : other.members) {
        this->members.push_back(member);
    }
    other.members.clear();

    this->leader = other.leader;
    other.leader = nullptr;
}

Team& Team::operator=(Team&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    for (auto& member : this->members) {
        delete member;
    }
    this->members.clear();
    for (auto& member : other.members) {
        this->members.push_back(member);
    }
    other.members.clear();

    this->leader = other.leader;
    other.leader = nullptr;

    return *this;
}

Team::~Team() {
    for (auto& member : this->members) {
        delete member;
    }
    this->members.clear();
}


    // Add a Fighter (Ninja or Samurai) to the team
    void Team::add(character* fighter) {
        if (members.size() >= 10) {
            throw runtime_error("Exceeded maximum number of participants in the team");
        }
            // Check if the character already exists in the team
           if (fighter->getStatus())
                throw runtime_error("In team already!");

        members.push_back(fighter);

       fighter->setStatus(true);
    }




   void Team::attack(Team* enemyTeam) {
    
    }


// Check if the team is still alive
int Team::stillAlive() const {
   return 0;
}

// Print the details of the team
void Team::print() const {

}
}