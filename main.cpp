
#include "Playoff.h"
#include "Season.h"
#include "Game.h"
#include "Team.h"
#include <iostream>
#include <vector>



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
    Team team4("Alabama Crimson Tide", "SEC");
    
    // Build ratings
    team2.buildRating();
    team3.buildRating();
    team4.buildRating();

    std::cout << "Team: " << team2.getName() << "\n";
    std::cout << "Offense Rating: " << team2.getOffenseRating() << "\n";
    std::cout << "Defense Rating: " << team2.getDefenseRating() << "\n";
    std::cout << "Special Teams Rating: " << team2.getSpecialTeamsRating() << "\n";

    std::cout << "Team: " << team3.getName() << "\n";
    std::cout << "Offense Rating: " << team3.getOffenseRating() << "\n";
    std::cout << "Defense Rating: " << team3.getDefenseRating() << "\n";
    std::cout << "Special Teams Rating: " << team3.getSpecialTeamsRating() << "\n";

    std::cout << "Team: " << team4.getName() << "\n";
    std::cout << "Offense Rating: " << team4.getOffenseRating() << "\n";
    std::cout << "Defense Rating: " << team4.getDefenseRating() << "\n";
    std::cout << "Special Teams Rating: " << team4.getSpecialTeamsRating() << "\n";
    
    /////// TESTING SEASON CLASS ///////

    // Create a season and add games
    Season season;
    season.addTeam(&team1);
    season.addTeam(&team2);
    season.addTeam(&team3);
    season.addTeam(&team4);

    Game game1(team1, team2);
    Game game2(team2, team3);
    Game game3(team3, team4);
    Game game4(team1, team3);
    Game game5(team1, team4);
    Game game6(team2, team4);
    
    season.addGame(game1);
    season.addGame(game2);
    season.addGame(game3);
    season.addGame(game4);
    season.addGame(game5);
    season.addGame(game6);

    
    // Simulate the season
    season.simulateSeason();

    // Display results
    std::cout << "\nAll games simulated. Results displayed above." << std::endl;
    std::cout << team1.getName() << " Wins: " << team1.getWins() << " Losses: " << team1.getLosses() << std::endl;
    std::cout << team2.getName() << " Wins: " << team2.getWins() << " Losses: " << team2.getLosses() << std::endl;
    std::cout << team3.getName() << " Wins: " << team3.getWins() << " Losses: " << team3.getLosses() << std::endl;
    std::cout << team4.getName() << " Wins: " << team4.getWins() << " Losses: " << team4.getLosses() << std::endl;
    
    /////// TESTING PLAYOFF CLASS ///////
    std::cout << "\n \n \n";
    
    Playoff playoff(season.getTeams());
    
    playoff.simulatePlayoff();



    return 0;
}
