// Header file for Team class
#ifndef TEAM_H
#define TEAM_H

// Preprocessor Directives
#include <string>

// CLASS HEADER
class Team {
private:
    // Properties
    std::string name;
    int wins = 0;
    int losses = 0;

public:
    // Properties
    float offenseRating;
    float defenseRating;
    float specialTeamsRating; 

    // Constructor
    Team(std::string& name);

    // Methods
    void updateStats(); // Update wins and losses (this is a setter for the stats)
    void buildRating(); // build the offense, defense, and special teams rating

    // Getters
    std::string getName(); // Get name
    int getWins(); // Get wins
    int getLosses(); // Get losses
};

#endif // TEAM_H