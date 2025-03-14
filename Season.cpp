// Implementation for Season class
#include "Season.h"
#include <iostream>

// Add a team to the season
void Season::addTeam(Team* team) {
    teams.push_back(team);
}

// Add a game to the season
void Season::addGame(Game& game) {
    games.push_back(game);
}

// Simulate the season by playing each game
void Season::simulateSeason() {
    std::cout << "Simulating Season...\n";
    
    for (Game& game : games) {
        Team winner = game.simulateGame();
        std::cout << "Game Result: " << winner.getName() << " won the game.\n";
    }
}

// Get all games in the season
std::vector<Game> Season::getGames() {
    return games;
}

std::vector<Team*>& Season::getTeams() {
    return teams;
}