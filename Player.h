#include <iostream>
#include <string>
#ifndef PLAYER_H
#define PLAYER_H
class Player {
    protected:
        // Player name
        std::string name;

        // Defensive stat
        int defensive_stat;

        // Attacking stat
        int attacking_stat;

    public:
        // Virtual functions for setting stats, are defined depending on what position the player is
        virtual void set_attacking_stat() = 0;
        virtual void set_defensive_stat() = 0;

        // Getter for attacking stat
        int get_attacking_stat(){
            return attacking_stat;
        }

        // Getter for defensive stat
        int get_defensive_stat(){
            return defensive_stat;
        }

        // Setter for player name
        void set_name(std::string name){
            this->name = name;
        }

        // Getter for player name
        std::string get_name(){
            return name;
        }

};

#endif