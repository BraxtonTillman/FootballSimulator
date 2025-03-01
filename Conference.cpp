// Implementation for Conference class


#include "Conference.h"

Conference::Conference(std::string name) : name(name) {}

void Conference::addTeam(Team& team){
    teams.push_back(team);
}

std::vector<Team> Conference::getTeams(){
    return teams;
}