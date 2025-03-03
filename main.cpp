


#include "Game.h"
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

    /////// TESTING GAME CLASS ///////
    Team team2("Florida State Seminoles", "ACC");
    Team team3("Georgia Bulldogs", "SEC");

    // Build ratings
    team2.buildRating();
    team3.buildRating();

    std::cout << "Team: " << team2.getName() << "\n";
    std::cout << "Offense Rating: " << team2.getOffenseRating() << "\n";
    std::cout << "Defense Rating: " << team2.getDefenseRating() << "\n";
    std::cout << "Special Teams Rating: " << team2.getSpecialTeamsRating() << "\n";

    std::cout << "Team: " << team3.getName() << "\n";
    std::cout << "Offense Rating: " << team3.getOffenseRating() << "\n";
    std::cout << "Defense Rating: " << team3.getDefenseRating() << "\n";
    std::cout << "Special Teams Rating: " << team3.getSpecialTeamsRating() << "\n";

    // Initial Records
    std::cout << "Before the game: " << std::endl;
    std::cout << team2.getName() << " - Wins: " << team2.getWins() << ", Losses: " << team2.getLosses() << std::endl;
    std::cout << team3.getName() << " - Wins: " << team3.getWins() << ", Losses: " << team3.getLosses() << std::endl;

    // Simulate a game 
    Game game(team2, team3);
    game.simulateGame(team2, team3);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // Display game results
    std::cout << "\nAfter the game:" << std::endl;
    std::cout << team2.getName() << " - Wins: " << team2.getWins() << ", Losses: " << team2.getLosses() << std::endl;
    std::cout << team3.getName() << " - Wins: " << team3.getWins() << ", Losses: " << team3.getLosses() << std::endl;

    return 0;
}