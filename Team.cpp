// Implementation for Team Class

// Preprocessor Directives
#include "Team.h"
#include <random>
#include <iostream>

// Constructor
Team::Team(std::string name, std::string conference): name(name), conference(conference) {}

// Methods
void Team::recordWin(){
    wins++;
    // Test 
    std::cout << name << " won! Wins: " << wins << std::endl;
}

void Team::recordLoss(){
    losses++;
    // Test
    std::cout << name << " lost! Losses: " << losses << std::endl;
}

void Team::buildRating() {
    std::random_device randomDevice; // Seed for randomness
    std::mt19937 gen(randomDevice()); // Mersenne Twister PRNG
    std::uniform_real_distribution<float> dist(60.0,99.0); // Random float between 60.0 and 90.0

    offenseRating = dist(gen);
    defenseRating = dist(gen);
    specialTeamsRating = dist(gen);
}

// Getters
std::string Team::getName(){
    return name;
}

int Team::getWins(){
    return wins;
}

int Team::getLosses(){
    return losses;
}

float Team::getOffenseRating(){
    return offenseRating;
}

float Team::getDefenseRating(){
    return defenseRating;
}

float Team::getSpecialTeamsRating(){
    return specialTeamsRating;
}