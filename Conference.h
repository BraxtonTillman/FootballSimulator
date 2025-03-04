// Header file for Conference Class
#ifndef CONFERENCE_H
#define CONFERENCE_H

// Preprocessor Directives
#include <vector>
#include <string>
#include "Team.h"

// CLASS HEADER
class Conference{
private:
    // Properties
    std::string name;
    std::vector<Team> teams;
public:
    // Constructor
    Conference(std::string name);

    // Methods
    void addTeam(Team& team); // Add a team to the conference
    std::vector<Team> getTeams(); // Get teams associated to the conference

};

#endif // CONFERENCE_H