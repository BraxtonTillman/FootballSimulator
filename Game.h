// Header file for Game class
#ifndef GAME_H
#define GAME_H

// Preprocessor Directives
#include "Team.h"

// CLASS HEADER
class Game {
private:
    // Properties
    Team homeTeam;
    Team awayTeam;
public:
    // Constructor
    Game(Team& homeTeam, Team& awayTeam);

    // Methods
    Team simulateGame(); // Simulates the game and returns the winner and loser
};

#endif // GAME_H