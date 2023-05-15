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
    Cowboy* character1 = new Cowboy("Character1", *(new Point(0, 0)));
    Ninja* character2 = new YoungNinja("Character2",*(new Point(5, 5)));

    CHECK(character1->isAlive() == true);
    CHECK(character2->isAlive() == true);

    character1->hit(50);
    CHECK(character1->isAlive() == true);

    character2->hit(200);
    CHECK(character2->isAlive() == false);
}

TEST_CASE("Test character distance") {
    character* character1 = new character("Character1", *(new Point(0, 0)),200);
    character* character2 = new character("Character2", *(new Point(5, 5)),100);
    const double epsilon = 0.0001;
    double expectedDistance = 7.07107;
    double calculatedDistance = character1->distance(*character2);

    DOCTEST_CHECK_MESSAGE(abs(calculatedDistance - expectedDistance) <= epsilon, "Distance calculation is incorrect.");
}


TEST_CASE("Test character hit") {
    character* adam = new character("adam", *(new Point(0, 0)),100);
    CHECK(adam->getHealth() == 100);
    adam->hit(20);
    CHECK(adam->getHealth() == 80);
    adam->hit(90);
    CHECK(adam->getHealth() == 0);
}

TEST_CASE("Test character print") {
    character* Tal = new character("Tal", *(new Point(0, 0)),200);

    string output = Tal->print();

    CHECK(output == "Name: Tal, Hit Points: 200, Location: (0.000000, 0.000000)");
}


TEST_CASE("Test adding more than 10 members to a team") {
    Team team(new OldNinja("Ninja Leader", Point(0, 0)));

    for (int i = 0; i < 10; i++) {
        CHECK_NOTHROW(team.add(new YoungNinja("Ninja " + to_string(i), Point(i, i + 1))));
    }

    CHECK_THROWS_AS(team.add(new Cowboy("Extra Fighter", Point(11, 12))), runtime_error);
}


TEST_CASE("Test Ninja move") {
    Ninja* ninja = new YoungNinja("Ninja", Point(0, 0));
    character* enemy = new TrainedNinja("Enemy", Point(5, 5));

    CHECK(ninja->getLocation().getX() == 0);
    CHECK(ninja->getLocation().getY() == 0);
    ninja->move(enemy);
    CHECK(ninja->getLocation().getX() == 5);
    CHECK(ninja->getLocation().getY() == 5);

}

TEST_CASE("Test Ninja slash") {
    Ninja* ninja = new OldNinja("Ninja", Point(0, 0));
    Ninja* enemy = new YoungNinja("Enemy", Point(2, 2));
    Ninja* enemy1 = new YoungNinja("Enemy", Point(0, 0.5));


    CHECK(ninja->getHealth() == 150);
    ninja->slash(enemy);
    CHECK(enemy->getHealth() == 100);
    ninja->slash(enemy1);
    CHECK(ninja->getHealth() == 150);
    CHECK(enemy1->getHealth() == 60);

}


TEST_CASE("Test YoungNinja") {
    Ninja* youngNinja = new YoungNinja("Young Ninja", Point(0, 0));

    CHECK(youngNinja->getSpeed() == 14);
}

TEST_CASE("Test TrainedNinja") {
    Ninja* trainedNinja = new TrainedNinja("Trained Ninja", Point(0, 0));

    CHECK(trainedNinja->getSpeed() == 12);
}

TEST_CASE("Test OldNinja") {
    Ninja* oldNinja = new OldNinja("Old Ninja", Point(0, 0));

    CHECK(oldNinja->getSpeed() == 8);
}

TEST_CASE("Test Cowboy shoot") {
    Cowboy* cowboy = new Cowboy("Cowboy", Point(0, 0));
    Ninja* enemy = new OldNinja("Enemy", Point(5, 5));

    CHECK(cowboy->getHealth() == 110);
    cowboy->shoot(enemy);
    CHECK(enemy->getHealth() == 140);
}

TEST_CASE("Test Cowboy hasBullets") {
    Cowboy* cowboy = new Cowboy("Cowboy", Point(0, 0));
    Ninja* enemy = new OldNinja("Enemy", Point(5, 5));

    CHECK(cowboy->hasBullets() == true);
    for(int i=0; i<5; i++){
        cowboy->shoot(enemy);
        CHECK(cowboy->hasBullets() == true);

    }
    cowboy->shoot(enemy);
    CHECK(cowboy->hasBullets() == false);
}

TEST_CASE("Test Cowboy reload") {
    Cowboy* cowboy = new Cowboy("Cowboy", Point(0, 0));
    Ninja* enemy = new OldNinja("Enemy", Point(5, 5));

    CHECK(cowboy->hasBullets() == true);
    for(int i=0; i<6; i++){
            cowboy->shoot(enemy);
        }
    CHECK(cowboy->hasBullets() == false);

    cowboy->reload();
    CHECK(cowboy->hasBullets() == true);
}


TEST_CASE("Test attack") {
    // Create team with leader
    Cowboy* leader1 = new Cowboy("Michal", Point(4, 8));
    // Create team 1
    Team team1(leader1);
    team1.add(new Cowboy("Tal", Point(5, 10)));
    team1.add(new Cowboy("Hadar", Point(3, 7)));
    team1.add(new TrainedNinja("Tom", Point(8, 3)));

    // Create team with leader
    Cowboy* leader2 = new Cowboy("Avi", Point(10, 15));
    // Create team 2
    Team team2(leader2);
    team2.add(new Cowboy("Ariel", Point(4, 8)));
    team2.add(new OldNinja("Omer", Point(6, 5)));
    team2.add(new YoungNinja("Shir", Point(7, 4)));

    // Test attack function
    team1.attack(&team2);

    CHECK(team1.stillAlive() == 4); // Expected number of alive members in team 1
    CHECK(team2.stillAlive() == 0); // Expected number of alive members in team 2
}


// TEST_CASE("Test adding the same participant to two different teams") {
//     Ninja* leader1 = new YoungNinja("Ninja Leader 1", Point(0, 0));
//     Ninja* leader2 = new TrainedNinja("Ninja Leader 2", Point(10, 10));

//     Team team1(leader1);
//     Team team2(leader2);

//     Ninja* participant = new OldNinja("Participant", Point(5, 5));

//     CHECK_NOTHROW(team1.add(participant));
//     CHECK_THROWS_AS(team2.add(participant), runtime_error);
// }

