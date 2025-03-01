#include "Team.h"
#include <iostream>




int main(){
    /////// TESTING TEAM CLASS ///////
    Team team1("Florida Gators", "SEC");
    team1.buildRating();

    std::cout << "Team: " << team1.getName() << "\n";
    std::cout << "Offense Rating: " << team1.getOffenseRating() << "\n";
    std::cout << "Defense Rating: " << team1.getDefenseRating() << "\n";
    std::cout << "Special Teams Rating: " << team1.getSpecialTeamsRating() << "\n";

    return 0;
}