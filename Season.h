// Header file for Season class
#ifndef SEASON_H
#define SEASON_H

// Preprocessor Directives
#include <vector>
#include "Game.h"
#include "Team.h"

// CLASS HEADER
class Season {
private:
    // Properties
    std::vector<Team*> teams;
    std::vector<Game> games;
public:
    // Methods
    void addTeam(Team* team); // Add team to season
    void addGame(Game& game); // Add game to season
    void simulateSeason(); // Simulate the season
    std::vector<Game> getGames(); // Get games in a season
    std::vector<Team*>& getTeams(); // Get teams in a season
};

#endif // SEASON_H