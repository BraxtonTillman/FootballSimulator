// Header file for Season class
#ifndef SEASON_H
#define SEASON_H

// Preprocessor Directives
#include <vector>
#include "Game.h"

// CLASS HEADER
class Season {
private:
    // Properties
    std::vector<Game> games;
public:
    // Methods
    void addGame(Game& game); // Add game to season
    void simulateSeason(); // Simulate the season
    std::vector<Game> getGames(); // Get games in a season
};

#endif // SEASON_H