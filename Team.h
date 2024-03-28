#include "CAM.h"
#include "CB1.h"
#include "CB2.h"
#include "CDM.h"
#include "CM.h"
#include "GK.h"
#include "LW.h"
#include "LWB.h"
#include "RW.h"
#include "RWB.h"
#include "STRK.h"
#include "Player_array.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <random>
#include <cmath>

//header guards
#ifndef TEAM_H
#define TEAM_H


class Team {

    private:
        std::string team_name;
        int max_players;
        int average_attacking_stat;
        int average_defensive_stat;
        bool is_user_team;

    public:
        // player array is public to allow outside access to player values
        Player** players;

        // default constructor
        Team(){
            this->team_name = "\n";
            this->max_players = 11;
            this->players = new Player*[max_players];
            this->average_attacking_stat = 0;
            this->average_defensive_stat = 0;
        }
        
        // constructor with name input
        Team(bool is_user_team, std::string team_name){
            if (is_user_team == true){
                this->team_name = team_name;
                this->max_players = 11;
                this->players = new Player*[max_players];
                this->average_attacking_stat = 0;
                this->average_defensive_stat = 0;
            }else{
                this->team_name = team_name;
                this->max_players = 11;
                this->players = new Player*[max_players];
                this->average_attacking_stat = (rand()%16) + 80;
                this->average_defensive_stat = (rand()%16) + 80;
            }
            
        }

        // team creation function
        void createTeam(){

            //instantiates array of all possible player selections
            Player_array possible_players;

            //initialises attack and defense stat sum for calculation
            int sum_attacking_stat = 0;
            int sum_defensive_stat = 0;

            //for loop for user to select players
            for (int i = 0; i<max_players; i++){
                
                //initialises player choice number
                double choice = 0;

                std::cout << "The choices for " + possible_players.positions[i] + " will be displayed:" << std::endl;

                //image display
                #ifdef _WIN32
                // on Windows, using mspaint to display the image
                system("mspaint " + std::to_string(i) + ".png");
                #elif __APPLE__
                // on macOS, using open command which will open the image in the default image viewer
                system(("open " + std::to_string(i) + ".png").c_str());
                #else
                // on Linux, using eog
                system("eog " + std::to_string(i) + ".png");
                #endif
        
                //input validation
                while (true) {
                    std::cout << "Enter a corresponding number from 1 to 3 to select your player: ";
                    std::cin >> choice;
                    if (choice == 1 || choice == 2 || choice == 3) {
                        break;  // valid integer input equal to 1, 2 or 3
                    } else {
                        std::cout << "Invalid input. Please enter a valid number between 1 and 3." << std::endl;
                        std::cin.clear(); 
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard the input buffer.
                    }
                }

                //set player in team to selected player
                if (choice == 1){
                    players[i] = possible_players.player_array[static_cast<int>(choice) + (3*i) - 1];
                }else if (choice == 2){
                    players[i] = possible_players.player_array[static_cast<int>(choice) + (3*i) - 1];
                }else if (choice == 3){
                    players[i] = possible_players.player_array[static_cast<int>(choice) + (3*i) - 1];
                }
                std::cout << players[i]->get_name() << " was drafted into " << team_name << "!" << std::endl;

                //initialises attack and defense stats of selected player
                players[i]->set_attacking_stat();
                players[i]->set_defensive_stat();

                //adds attacking and defensive stats onto sum for later calculation
                sum_attacking_stat = sum_attacking_stat + players[i]->get_attacking_stat();
                sum_defensive_stat = sum_defensive_stat + players[i]->get_defensive_stat();
            
            }

            //calculate average attack/defense stats
            average_attacking_stat = sum_attacking_stat / max_players;
            average_defensive_stat = sum_defensive_stat / max_players;
        }

        //getter for team name
        std::string get_name(){
            return team_name;
        }

        //getter for attack stat
        int get_average_attacking_stat(){
            return this->average_attacking_stat;
        }

        //getter for defense stat
        int get_average_defensive_stat(){
            return this->average_defensive_stat;
        }

};

#endif