// Header file for Playoffs Class
#ifndef PLAYOFF_H
#define PLAYOFF_H

// Preprocessor Directives
#include <vector>
#include "Team.h"

// CLASS HEADER
class Playoff {
private:
    // Properties
    std::vector<Team> teams;
public:
    // Methods
    void addTeam(Team& team); // Add a team to the playoffs
    void simulatePlayoff(); // Simulate playoffs
};

#endif // PLAYOFF_H