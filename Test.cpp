#include "doctest.h"

#include "sources/character.hpp"
#include "sources/Ninja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/smartTeam.hpp"
#include <random>
#include <chrono>



using namespace ariel;

TEST_CASE("Test character isAlive") {
    character* character1 = new character("Character1", *(new Point(0, 0)));
    character1->setHitPoints(80);
    character* character2 = new character("Character2",*(new Point(5, 5)));
    character2->setHitPoints(80);

    CHECK(character1->isAlive() == true);
    CHECK(character2->isAlive() == true);

    character1->hit(50);
    CHECK(character1->isAlive() == true);

    character1->hit(100);
    CHECK(character1->isAlive() == false);
}

TEST_CASE("Test character distance") {
    character* character1 = new character("Character1", *(new Point(0, 0)));
    character* character2 = new character("Character2", *(new Point(5, 5)));
    const double epsilon = 0.0001;
    double expectedDistance = 7.07107;
    double calculatedDistance = character1->distance(*character2);

    DOCTEST_CHECK_MESSAGE(abs(calculatedDistance - expectedDistance) <= epsilon, "Distance calculation is incorrect.");
}


TEST_CASE("Test character hit") {
    character* adam = new character("adam", *(new Point(0, 0)));
    adam->setHitPoints(100);
    CHECK(adam->getHitPoints() == 100);
    adam->hit(20);
    CHECK(adam->getHitPoints() == 80);
    adam->hit(90);
    CHECK(adam->getHitPoints() == 0);
}

TEST_CASE("Test character print") {
    character* Tal = new character("Tal", *(new Point(0, 0)));

    string output = Tal->print();

    CHECK(output == "Name: Tal, Hit Points: 0, Location: (0.000000, 0.000000)");
}


TEST_CASE("Test add function with more than 10 members") {
    Team team(new Ninja("Ninja Leader", Point(0, 0), 0));
    int count = 0;
    for (int i = 0; i < 10; i++) {
        CHECK_NOTHROW(team.add(new Ninja("Ninja " + to_string(i), Point(i, i+1),i+2)));
        count++;
    }

    CHECK_THROWS_AS(team.add(new Ninja("Extra Ninja", Point(count, count+1),count+2)),runtime_error);
}

TEST_CASE("Test Ninja move") {
    Ninja* ninja = new YoungNinja("Ninja", Point(0, 0));
    character* enemy = new character("Enemy", Point(5, 5));

    CHECK(ninja->getLocation() == Point(0, 0));
    ninja->move(enemy);
    CHECK(ninja->getLocation() == Point(2, 2));

}


// TEST_CASE("Test Ninja slash") {
//     character* ninja = new Ninja("Ninja", Point(0, 0), 10);
//     character* enemy = new character("Enemy", Point(2, 2));

//     CHECK(ninja->getHealth() == 100);
//     ninja->slash(enemy);
//     CHECK(enemy->getHealth() == 80);
// }

// TEST_CASE("Test Ninja print") {
//     character* ninja = new Ninja("Ninja", Point(0, 0), 10);

//     stringstream output;
//     output << ninja->print();

//     CHECK(output.str() == "Name: Ninja, Location: (0, 0), Speed: 10");
// }

// TEST_CASE("Test YoungNinja") {
//     character* youngNinja = new YoungNinja("Young Ninja", Point(0, 0));

//     CHECK(youngNinja->getSpeed() == 14);
// }

// TEST_CASE("Test TrainedNinja") {
//     character* trainedNinja = new TrainedNinja("Trained Ninja", Point(0, 0));

//     CHECK(trainedNinja->getSpeed() == 12);
// }

// TEST_CASE("Test OldNinja") {
//     character* oldNinja = new OldNinja("Old Ninja", Point(0, 0));

//     CHECK(oldNinja->getSpeed() == 8);
// }
// TEST_CASE("Test Cowboy shoot") {
//     character* cowboy = new Cowboy("Cowboy", Point(0, 0));
//     character* enemy = new character("Enemy", Point(5, 5));

//     CHECK(enemy->getHealth() == 100);
//     cowboy->shoot(enemy);
//     CHECK(enemy->getHealth() == 80);
// }

// TEST_CASE("Test Cowboy hasBullets") {
//     character* cowboy = new Cowboy("Cowboy", Point(0, 0));

//     CHECK(cowboy->hasBullets() == true);
//     cowboy->shoot(nullptr);
//     CHECK(cowboy->hasBullets() == false);
// }

// TEST_CASE("Test Cowboy reload") {
//     character* cowboy = new Cowboy("Cowboy", Point(0, 0));

//     CHECK(cowboy->hasBullets() == true);
//     cowboy->shoot(nullptr);
//     CHECK(cowboy->hasBullets() == false);

//     cowboy->reload();
//     CHECK(cowboy->hasBullets() == true);
// }

// TEST_CASE("Test Cowboy print") {
//     character* cowboy = new Cowboy("Cowboy", Point(0, 0));

//     stringstream output;
//     output << cowboy->print();

//     CHECK(output.str() == "Name: Cowboy, Location: (0, 0), Bullets: 6");
// }


// TEST_CASE("Test findClosestEnemy") {
//     // Create team with leader
//     character* leader = new Cowboy("Tom", Point(4, 8));
//     Team team(leader);

//     // Create team members
//     character* cowboy = new Cowboy("John", Point(5, 10));
//     character* ninja1 = new Ninja("Emily", Point(8, 3), 2);
//     ninja1->setHitPoints(150);
//     character* ninja2 = new Ninja("Alex", Point(7, 4), 3);
//     ninja1->setHitPoints(100);

//     // Add team members to the team
//     team.add(cowboy);
//     team.add(ninja1);
//     team.add(ninja2);

//         // Test findClosestEnemy function
//     character* closestEnemy = team.findClosestEnemy(leader, team.getMembers());

//     CHECK(closestEnemy->getName() == "John");
//     CHECK(closestEnemy->getType() == "Cowboy");

//     // Cleanup
//     delete leader;
//     delete cowboy;
//     delete ninja1;
//     delete ninja2;
// }






// TEST_CASE("Test attackTarget") {
//     // Create attacker and target
//     Cowboy* attacker = new Cowboy("John", Point(5, 10));
//     Ninja* target = new Ninja("Emily", Point(8, 3));

//     // Test attackTarget function
//     Team team;
//     team.attackTarget(attacker, target);

//     CHECK(attacker->getBullets() == 4); // Expected bullets after shooting
//     CHECK(target->getHealth() == 7); // Expected health after being shot
// }

// TEST_CASE("Test chooseNewLeader") {
//     // Create team with members
//     Team team;
//     team.addCharacter(new Cowboy("John", Point(5, 10)));
//     team.addCharacter(new Cowboy("Mike", Point(3, 7)));
//     team.addCharacter(new Ninja("Emily", Point(8, 3)));

//     // Test chooseNewLeader function
//     character* deceasedLeader = team.getLeader();
//     character* newLeader = team.chooseNewLeader(deceasedLeader, team.members);

//     CHECK(newLeader->getName() == "John");
//     CHECK(newLeader->getType() == "Cowboy");
// }

// TEST_CASE("Test attack") {
//     // Create team 1
//     Team team1;
//     team1.addCharacter(new Cowboy("John", Point(5, 10)));
//     team1.addCharacter(new Cowboy("Mike", Point(3, 7)));
//     team1.addCharacter(new Ninja("Emily", Point(8, 3)));

//     // Create team 2
//     Team team2;
//     team2.addCharacter(new Cowboy("Tom", Point(4, 8)));
//     team2.addCharacter(new Ninja("Sophia", Point(6, 5)));
//     team2.addCharacter(new Ninja("Alex", Point(7, 4)));

//     // Test attack function
//     team1.attack(&team2);

//     CHECK(team1.stillAlive() == 2); // Expected number of alive members in team 1
//     CHECK(team2.stillAlive() == 1); // Expected number of alive members in team 2
// }






// TEST_CASE("Test attack function") {
//     Team team1(new Ninja("Ninja Leader 1", Point(0, 0)));
//     Team team2(new Ninja("Ninja Leader 2", Point(10, 10)));

//     character* enemy1 = new Ninja("Enemy 1", Point(3, 3));
//     character* enemy2 = new Ninja("Enemy 2", Point(5, 5));
//     character* enemy3 = new Ninja("Enemy 3", Point(7, 7));

//     team2.add(enemy1);
//     team2.add(enemy2);
//     team2.add(enemy3);

//     team1.attack(&team2);

//     CHECK_EQ(team2.stillAlive(),true);
// }

// TEST_CASE("Test adding the same participant to two different teams") {
//     character* leader1 = new Ninja("Ninja Leader 1", Point(0, 0));
//     character* leader2 = new Ninja("Ninja Leader 2", Point(10, 10));

//     Team team1(leader1);
//     Team team2(leader2);

//     character* participant = new Ninja("Participant", Point(5, 5));

//     CHECK_NOTHROW(team1.add(participant));
//     CHECK_THROWS_AS(team2.add(participant), std::runtime_error);
// }

