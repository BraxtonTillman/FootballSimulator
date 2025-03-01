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
    std::string conference;
    int wins = 0;
    int losses = 0;
    float offenseRating=0;
    float defenseRating=0;
    float specialTeamsRating=0;

public:
    // Constructor
    Team(std::string name,std::string conference);

    // Methods
    void recordWin(); // Update wins
    void recordLoss(); // Update losses
    void buildRating(); // build the offense, defense, and special teams rating

    // Getters
    std::string getName(); // Get name
    int getWins(); // Get wins
    int getLosses(); // Get losses
    float getOffenseRating(); // Get offense rating
    float getDefenseRating(); // Get defense rating
    float getSpecialTeamsRating(); // Get special teams rating
};

#endif // TEAM_H