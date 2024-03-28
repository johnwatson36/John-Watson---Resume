#ifndef FILEREADGOODCOPY_H
#define FILEREADGOODCOPY_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;

// Function to read a random player's name from the text file
std::string getRandomPlayerName(const std::string& filename, int num_players) {
    std::ifstream infile(filename);
    std::vector<std::string> playerNames;
    std::string playerName;

    if (infile.is_open()) {
        while (std::getline(infile, playerName)) {
            playerNames.push_back(playerName);
        }
        infile.close();

        if (!playerNames.empty()) {
            // Generate a random index to select a random player
            int randomIndex = rand() % playerNames.size();
            std::string selectedName = playerNames[randomIndex];

            // Increment the counter of selected names
            static int selectedCount = 0;
            selectedCount++;

            //If the counter reaches num_players, clear the file
            if (selectedCount == num_players) {
                std::ofstream clearfile(filename, std::ios::trunc);
                clearfile.close();
            }

            return selectedName;
        }
    }

    return "No player names available in the file.";
}

    // Function to generate and display players with names and random values
    void generateAndDisplayPlayers(std::string names[6], int num_players) {

        
        // Create maps to count the occurrences of player names and store random values for each player
        std::map<std::string, int> playerCounts;
        std::map<std::string, std::vector<int>> playerRandomValues;

        // ANSI escape code to change text color
        const std::string RED_COLOUR = "\x1B[31m";
        const std::string GREEN_COLOUR = "\x1B[32m";
        const std::string YELLOW_COLOUR = "\x1B[33m";
        const std::string RESET_COLOUR = "\x1B[0m";
        const std::string BLUE_COLOUR = "\x1B[34m";
        const std::string PURPLE_COLOUR = "\x1B[35m";

        // ANSI escape code for text styles
        const std::string BOLD = "\x1B[1m";
       const std::string UNDERLINE = "\x1B[4m";

        // Seed the random number generator
        srand(static_cast<unsigned>(time(nullptr)));

        const std::string filename = "players.txt";
        std::ofstream outfile(filename, std::ios::app);

        if (!outfile.is_open()) {
            std::cerr << "Unable to open the file for writing." << std::endl;
        }

        // Ask the user to add three player names to the file
        for (int i = 0; i < 6; i++) {
            std::string playerName = names[i];
            outfile << playerName << std::endl;
        }

        outfile.close();

        // Read and display player names with '*' counts
        for (int i = 0; i < num_players; i++) {
            std::string randomPlayerName = getRandomPlayerName(filename, num_players);
            playerCounts[randomPlayerName]++;
            playerRandomValues[randomPlayerName].push_back(rand() % 90 + 1);
        }

        // Display player names, '*' counts, and random values
        for (const auto& entry : playerCounts) {
            std::cout << BOLD << GREEN_COLOUR << entry.first << " " << RESET_COLOUR;

            for (int j = 0; j < entry.second; j++) {
                std::cout << "⚽ ";
            }

            // Sort the random values in ascending order using bubble sort
            std::vector<int>& randomValues = playerRandomValues[entry.first];
            int n = randomValues.size();
            
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (randomValues[j] > randomValues[j + 1]) {
                        // Swap the values
                        int temp = randomValues[j];
                        randomValues[j] = randomValues[j + 1];
                        randomValues[j + 1] = temp;
                    }
                }
            }

            for (int k = 0; k < n; k++) {
                cout << randomValues[k];
                if (k < n - 1) {
                    cout << "' " << RESET_COLOUR;
                }
            }
            cout << "'" << endl;
        }
}


#endif