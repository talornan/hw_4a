// #include "Team.hpp"

// namespace ariel
// {
//     // Constructor
//     Team::Team(character* leader) : leader(leader) {}

//     // Add a Fighter (Ninja or Samurai) to the team
//     void Team::add(character* fighter) {
//         members.push_back(fighter);
//     }

//     // Helper function to find the closest living enemy character to the given character
//     character* Team::findClosestEnemy(character* characterObj, vector<character*>& enemies) {
//         character* closestEnemy = nullptr;
//         double closestDistance = numeric_limits<double>::max();

//         for (character* enemy : enemies) {
//             if (enemy->isAlive()) {
//                 double distance = characterObj->getLocation().distance(enemy->getLocation());
//                 if (distance < closestDistance) {
//                     closestDistance = distance;
//                     closestEnemy = enemy;
//                 }
//             }
//         }
//         return closestEnemy;
//     }

//     // Helper function for attacking the target
//     void Team::attackTarget(character* attacker, character* target) {
//         if (Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)) {
//             if (cowboy->hasBullets()) {
//                 // Cowboys with bullets shoot at the target
//                 cowboy->shoot(target);
//             } else {
//                 // Cowboys without bullets reload their weapons
//                 cowboy->reload();
//             }
//         } else if (Ninja* ninja = dynamic_cast<Ninja*>(attacker)) {
//             if (ninja->getLocation().distance(target->getLocation()) <= 1) {
//                 // Ninjas within 1 meter of the target slash the target
//                 ninja->slash(target);
//             } else {
//                 // Ninjas farther than 1 meter from the target move towards the target
//                 ninja->move(target);
//             }
//         }
//     }

//     // Chooses a new leader for the attacking group if the current leader is dead.
//     // The new leader is the living character closest to the deceased leader in terms of distance.
//     character* Team::chooseNewLeader(character* leader, vector<character*>& members) {
//         // Check if the current leader is alive
//         if (leader->isAlive()) {
//             // The attacking group's leader is alive - no need to choose a new leader
//             return leader;
//         } else {
//             // Find the closest living character to the deceased leader
//             character* closestCharacter = nullptr;
//             double closestDistance = numeric_limits<double>::max();

//             // Iterate through the members and find the closest living character to the deceased leader
//             for (character* member : members) {
//                 if (member->isAlive()) {
//                     double distance = member->getLocation().distance(leader->getLocation());
//                     if (distance < closestDistance) {
//                         closestCharacter = member;
//                         closestDistance = distance;
//                     }
//                 }
//             }
//             return closestCharacter;
//         }
//     }

// /*
//  * @brief Perform attack by the attacking group.
//  *
//  * The attack is executed in the following steps:
//  * 1. Check if the attacking group's leader is alive. If not, choose a new leader.
//  * 2. Select a target from the enemy group, which is the closest living member to the attacking group's leader.
//  * 3. All living members of the attacking group attack the selected target.
//  *    - Cowboys with bullets shoot at the target.
//  *    - Cowboys without bullets reload their weapons.
//  *    - Ninjas within 1 meter of the target stab the target.
//  *    - Ninjas farther than 1 meter from the target move towards the target.
//  * 4. If the target dies, select a new target as the closest living member to the attacking group's leader.
//  * 5. Repeat steps 3-4 until there are no living members in either the attacking group or the enemy group.
//  *
//  * @param members The vector of pointers to the members of the attacking group.
//  * @param enemyGroup The vector of pointers to the members of the enemy group.
//  */

//    void Team::attack(Team* enemyTeam) {
//     // Step 1: Find the leader of the attacking team
//     character* leader = chooseNewLeader(this->leader,this->members);

//     // Step 2: Find the initial target as the closest living enemy to the leader of the enemy team
//     character* target = enemyTeam->findClosestEnemy(leader, enemyTeam->members);

//     // Step 3: Repeat steps 3-4 until there are no living members in either the attacking team or the enemy team.
//     while (this->stillAlive() > 0 && enemyTeam->stillAlive() > 0) {
//         // Step 3: All living members of the attacking team attack the selected target.
//         for (character* character : this->members) {
//             if (character->isAlive()) {
//                 this->attackTarget(character, target);
//             }
//         }

//         // Step 4: If the target dies, select a new target as the closest living enemy to the leader of the enemy team.
//         if (target != nullptr && !target->isAlive()) {
//             target = enemyTeam->findClosestEnemy(leader, enemyTeam->members);
//         }
//     }
// }


// // Check if the team is still alive
// int Team::stillAlive() const {
//     int count = 0;
//     for (const auto& member : members) {
//         if (member->isAlive()) {
//             count++;
//         }
//     }
//     return count;
// }

// // Print the details of the team
// void Team::print() const {
//     cout << "Team Leader: ";
//     leader->print();

//     cout << "Team Members:" << endl;
//     for (const auto& member : members) {
//         cout << "- ";
//         member->print();
//     }
// }

// // Destructor
// Team::~Team() {
//     for (auto& member : members) {
//         if (dynamic_cast<character*>(member) != nullptr) {
//             delete member;
//         }
//     }
// }
// } 