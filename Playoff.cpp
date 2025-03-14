// Implementation for playoff class

#include "Playoff.h"
#include "Game.h"
#include <iostream>
#include <algorithm>

// Constructor
Playoff::Playoff(std::vector<Team*>& allTeams) {
    // Sort by wins (This sort compares team a to team b based on wins in descending order)

    std::cout << "\n SORTING!" << std::endl;

    std::sort(allTeams.begin(), allTeams.end(), [](Team* a, Team* b){
        return a->getWins() > b->getWins();
    });

    std::cout << "SORTING DONE!" << std::endl;

    std::cout << "Starting to take top 4!" << std::endl;

    // Take top 4 teams
    for (int i = 0; i < 4 && i < allTeams.size(); i++) {
        std::cout << "Top Team " << i << std::endl;
        teams.push_back(allTeams[i]); 
    }

    std::cout << "Top teams done!" << std::endl;
}
 
// Methods
void Playoff::addTeam(Team* team) {
    if (teams.size() < 4) {
        teams.push_back(team);
    }
}

// Playoff.cpp

void Playoff::simulatePlayoff() {
    if (teams.size() < 4){
        std::cout << "Not enough teams for playoff! \n";
        return;
    }

    std::cout << "\n--- COLLEGE FOOTBALL PLAYOFFS ---\n";
    Team& team1 = *teams[0]; // Dereference the pointer to get a reference
    Team& team2 = *teams[1];
    Team& team3 = *teams[2];
    Team& team4 = *teams[3];

    // Semifinals
    Game semifinal1(team1, team4); // Pass references
    Game semifinal2(team2, team3);

    Team& winner1 = semifinal1.simulateGame(); // Get reference to winner
    Team& winner2 = semifinal2.simulateGame();

    std::cout << "Semifinal 1 Winner: " << winner1.getName() << "\n";
    std::cout << "Semifinal 2 Winner: " << winner2.getName() << "\n";

    // Championship
    Game championship(winner1, winner2); // Pass references to the championship game

    std::cout << "Championship Game: " << winner1.getName() << " vs. " << winner2.getName() << std::endl;

    Team& champion = championship.simulateGame();
    
    std::cout << "\nNATIONAL CHAMPION: " << champion.getName() << "\n";
}
