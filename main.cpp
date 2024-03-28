#include "Final.h"

#include <iostream>

// Main function where the execution of the program begins.
int main(void) {

    const std::string RED_COLOUR = "\x1B[31m";
    const std::string GREEN_COLOUR = "\x1B[32m";
    const std::string YELLOW_COLOUR = "\x1B[33m";        
    const std::string RESET_COLOUR = "\x1B[0m";
    const std::string BLUE_COLOUR = "\x1B[34m";
    const std::string PURPLE_COLOUR = "\x1B[35m";

    // Declare a string variable to hold the name of the user's football team.
    std::string name;

    std::cout << "\n" << "Welcome to..." << "\n\n" << RED_COLOUR << "     ⚽️🏆  SOCCER BRAWL  🏆⚽️" << "\n" <<std::endl;

    // Prompt the user for the name of their football team.
    std::cout << RESET_COLOUR << "What is the name of your football team?" << std::endl;
    std::cin >> name; // Read the input from the user.
    
    // Create a Team object for the user's team with the name provided.
    // The 'true' argument indicates that this is a user's team.
    Team user(true, name);
    user.createTeam(); // Initialize the user's team with players.

    // Create three other Team objects for pre-defined teams.
    Team t2(false, "Manchester United");
    Team t3(false, "FC Barcelona");
    Team t4(false, "Real Madrid");

    // Create a Final tournament object with the four teams.
    Final tournament(user, t2, t3, t4);

    // Play the tournament (this will handle matches and results).
    tournament.play_tournament();

    std::cout << "\n" << PURPLE_COLOUR << "Thanks for playing SOCCER BRAWL ⚽️" << std::endl;

    // Return 0 to indicate successful execution.
    return 0;
}
