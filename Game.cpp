// Implementation for Game class

// Preprocessor Directives
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor
Game::Game(Team& home, Team& away) : homeTeam(home), awayTeam(away) {
    std::srand(std::time(0));
}

// Simulate the game 
Team Game::simulateGame(Team& homeTeam, Team& awayTeam) {
    float homeOffense = homeTeam.getOffenseRating();
    float homeDefense = homeTeam.getDefenseRating();
    float homeSpecialTeams = homeTeam.getSpecialTeamsRating();

    float awayOffense = awayTeam.getOffenseRating();
    float awayDefense = awayTeam.getDefenseRating();
    float awaySpecialTeams = awayTeam.getSpecialTeamsRating();

    int homeScore = 0;
    int awayScore = 0;

    // Offense vs Defensive Matchup
    float homeAdvantage = homeOffense - awayDefense;
    float awayAdvantage = awayOffense - homeDefense;

    // Test Matchup
    std::cout << "Home Advantage: " << homeAdvantage << std::endl;
    std::cout << "Away Advantage: " << awayAdvantage << std::endl;

    // Generate base score based on ratings
    homeScore = generateScore(homeAdvantage);
    awayScore = generateScore(awayAdvantage);

    // Test scores before adjust
    std::cout << "Home Score (Before Adjust): " << homeScore << std::endl;
    std::cout << "Away Score (Before Adjust): " << awayScore << std::endl;

    // Special Teams Decider for Close Games
    if (abs(homeScore - awayScore) <= 7) {
        if (homeSpecialTeams > awaySpecialTeams) {
            homeScore += 3; // This gives slight advantage to special teams
        }
        else if (awaySpecialTeams > homeSpecialTeams) {
            awayScore += 3;
        }
    }

    // Adjust scores in multiples of 3 and 7
    homeScore = adjustScore(homeScore);
    awayScore = adjustScore(awayScore);

    // Test scores after adjust
    std::cout << "Home Score (After Adjust): " << homeScore << std::endl;
    std::cout << "Away Score (After Adjust): " << awayScore << std::endl;

    // Determine winner and update record
    if (homeScore > awayScore) {
        homeTeam.recordWin();
        awayTeam.recordLoss();
        //std::cout << "Home team won! Win recorded." << std::endl;
    }
    else if (awayScore > homeScore) {
        awayTeam.recordWin();
        homeTeam.recordLoss();
        //std::cout << "Away team won! Win recorded." << std::endl;
    }

    if (homeScore > awayScore) {
        return homeTeam;
    }
    else {
        return awayTeam;
    }
}

// Function to generate a score based on team ratings
int Game::generateScore(float advantage) {
    int baseScore = 0;
    int numTouchdowns = 0;
    int numFieldGoals = 0;

    // Determine base points based on advantage
    if (advantage > 10){ // Strong offensive advantage
        numTouchdowns = 3 + (std::rand() % 2); // 3 or 4 TDs
        numFieldGoals = std::rand() % 2; // 0 or 1 FGs
    } 
    else if (advantage > 0) { // Slight advantage
        numTouchdowns = 2 + (std::rand() % 2); // 2 or 3 TDs
        numFieldGoals = std::rand() % 3; // 0 to 2 FGs
    }
    else if (advantage > -10) { // Evenly matched
        numTouchdowns = 1 + (std::rand() % 2); // 1 or 2 TDs
        numFieldGoals = std::rand() % 3; // 0 to 2 FGs
    }
    else { // Strong defensive advantage 
        numTouchdowns = std::rand() % 2; // 0 or 1 TD
        numFieldGoals = 1 + (std::rand() % 2); // 1 to 2 FGs
    }

    baseScore = (numTouchdowns * 7) + (numFieldGoals * 3);

    // TEST
    std::cout << "Base Score: " << baseScore << std::endl;

    return baseScore;
}

// Validify base score
int Game::adjustScore(int score) {
    if (score % 3 == 0 || score % 7 == 0) return score;

    // Adjust to the nearest valid score
    int remainder = score % 10;
    if (remainder == 1 || remainder == 2) return score - remainder;  // Round down
    if (remainder == 8 || remainder == 9) return score + (10 - remainder);  // Round up
    
    // Testing adjusted score
    std::cout << "Adjust function score: " << score << std::endl;

    return score;  // If already valid, return as is
}