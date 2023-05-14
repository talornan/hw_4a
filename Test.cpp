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


TEST_CASE("Test add function with more than 10 members") {
    Team team(new Ninja("Ninja Leader", Point(0, 0)));

    for (int i = 0; i < 11; i++) {
        CHECK_NOTHROW(team.add(new Ninja("Ninja " + to_string(i), Point(0, 0))));
    }

    CHECK_THROWS_AS(team.add(new Ninja("Extra Ninja", Point(0, 0))), std::runtime_error);
}

TEST_CASE("Test findClosestEnemy function") {
    Team team1(new Ninja("Ninja Leader 1", Point(0, 0)));
    Team team2(new Ninja("Ninja Leader 2", Point(10, 10)));

    character* enemy1 = new Ninja("Enemy 1", Point(3, 3));
    character* enemy2 = new Ninja("Enemy 2", Point(5, 5));
    character* enemy3 = new Ninja("Enemy 3", Point(7, 7));

    team2.add(enemy1);
    team2.add(enemy2);
    team2.add(enemy3);

    character* closestEnemy = team1.findClosestEnemy(team1.getLeader(), team2.getMembers());
    CHECK_EQ(closestEnemy, enemy1);
}

TEST_CASE("Test attack function") {
    Team team1(new Ninja("Ninja Leader 1", Point(0, 0)));
    Team team2(new Ninja("Ninja Leader 2", Point(10, 10)));

    character* enemy1 = new Ninja("Enemy 1", Point(3, 3));
    character* enemy2 = new Ninja("Enemy 2", Point(5, 5));
    character* enemy3 = new Ninja("Enemy 3", Point(7, 7));

    team2.add(enemy1);
    team2.add(enemy2);
    team2.add(enemy3);

    team1.attack(&team2);

    CHECK_EQ(team2.stillAlive(),true);
}

TEST_CASE("Test adding the same participant to two different teams") {
    character* leader1 = new Ninja("Ninja Leader 1", Point(0, 0));
    character* leader2 = new Ninja("Ninja Leader 2", Point(10, 10));

    Team team1(leader1);
    Team team2(leader2);

    character* participant = new Ninja("Participant", Point(5, 5));

    CHECK_NOTHROW(team1.add(participant));
    CHECK_THROWS_AS(team2.add(participant), std::runtime_error);
}

TEST_CASE("Test Ninja move") {
    character* ninja = new Ninja("Ninja", Point(0, 0), 10);
    character* enemy = new character("Enemy", Point(5, 5));

    CHECK(ninja->getLocation() == Point(0, 0));
    ninja->move(enemy);
    CHECK(ninja->getLocation() == Point(2, 2));
}

TEST_CASE("Test Ninja slash") {
    character* ninja = new Ninja("Ninja", Point(0, 0), 10);
    character* enemy = new character("Enemy", Point(2, 2));

    CHECK(ninja->getHealth() == 100);
    ninja->slash(enemy);
    CHECK(enemy->getHealth() == 80);
}

TEST_CASE("Test Ninja print") {
    character* ninja = new Ninja("Ninja", Point(0, 0), 10);

    stringstream output;
    output << ninja->print();

    CHECK(output.str() == "Name: Ninja, Location: (0, 0), Speed: 10");
}

TEST_CASE("Test YoungNinja") {
    character* youngNinja = new YoungNinja("Young Ninja", Point(0, 0));

    CHECK(youngNinja->getSpeed() == 14);
}

TEST_CASE("Test TrainedNinja") {
    character* trainedNinja = new TrainedNinja("Trained Ninja", Point(0, 0));

    CHECK(trainedNinja->getSpeed() == 12);
}

TEST_CASE("Test OldNinja") {
    character* oldNinja = new OldNinja("Old Ninja", Point(0, 0));

    CHECK(oldNinja->getSpeed() == 8);
}
TEST_CASE("Test Cowboy shoot") {
    character* cowboy = new Cowboy("Cowboy", Point(0, 0));
    character* enemy = new character("Enemy", Point(5, 5));

    CHECK(enemy->getHealth() == 100);
    cowboy->shoot(enemy);
    CHECK(enemy->getHealth() == 80);
}

TEST_CASE("Test Cowboy hasBullets") {
    character* cowboy = new Cowboy("Cowboy", Point(0, 0));

    CHECK(cowboy->hasBullets() == true);
    cowboy->shoot(nullptr);
    CHECK(cowboy->hasBullets() == false);
}

TEST_CASE("Test Cowboy reload") {
    character* cowboy = new Cowboy("Cowboy", Point(0, 0));

    CHECK(cowboy->hasBullets() == true);
    cowboy->shoot(nullptr);
    CHECK(cowboy->hasBullets() == false);

    cowboy->reload();
    CHECK(cowboy->hasBullets() == true);
}

TEST_CASE("Test Cowboy print") {
    character* cowboy = new Cowboy("Cowboy", Point(0, 0));

    stringstream output;
    output << cowboy->print();

    CHECK(output.str() == "Name: Cowboy, Location: (0, 0), Bullets: 6");
}
TEST_CASE("Test character isAlive") {
    character* character1 = new character("Character1", Point(0, 0));
    character* character2 = new character("Character2", Point(5, 5));

    CHECK(character1->isAlive() == true);
    CHECK(character2->isAlive() == true);

    character1->hit(50);
    CHECK(character1->isAlive() == true);

    character1->hit(100);
    CHECK(character1->isAlive() == false);
}

TEST_CASE("Test character distance") {
    character* character1 = new character("Character1", Point(0, 0));
    character* character2 = new character("Character2", Point(3, 4));

    double expectedDistance = 5.0;
    double calculatedDistance = character1->distance(*character2);

    CHECK(calculatedDistance == expectedDistance);
}

TEST_CASE("Test character hit") {
    character* character = new character("Character", Point(0, 0));

    CHECK(character->getHitPoints() == 100);
    character->hit(20);
    CHECK(character->getHitPoints() == 80);
    character->hit(90);
    CHECK(character->getHitPoints() == 0);
}

TEST_CASE("Test character print") {
    character* character = new character("Character", Point(0, 0));

    stringstream output;
    output << character->print();

    CHECK(output.str() == "Name: Character, Location: (0, 0), Hit Points: 100");
}


