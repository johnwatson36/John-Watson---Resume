#ifndef MATCH_H
#define MATCH_H

#include "Team.h"
#include <iostream>
#include <random>
#include <cmath>

class Match {

    protected:
        std::string winning_team;
        std::string losing_team;
        int winning_score;
        int losing_score;

    public:

        //intakes two teams, runs algorithm to decide winner
        Match(Team* t1, Team* t2){

        std::string name_of_team1 = t1->get_name();
        std::string name_of_team2 = t2->get_name();
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

        // Get average attacking and defensive stats for both teams
        double team1_ave_offensive = t1->get_average_attacking_stat();
        double team1_ave_defensive = t1->get_average_defensive_stat();
        double team2_ave_offensive = t2->get_average_attacking_stat();
        double team2_ave_defensive = t2->get_average_defensive_stat();

        // Create a random number generator
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister engine

        //Establish range that each random number generator can take (determined by the variable)
        std::uniform_int_distribution<int> penalty_distribution(0, 3);
        std::uniform_int_distribution<int> freekick_distribution(2, 5);
        std::uniform_int_distribution<int> extra_score1_distribution(0, 2);
        std::uniform_int_distribution<int> extra_score2_distribution(0, 2);
        std::uniform_int_distribution<int> random_distribution(0, 10);
        std::uniform_int_distribution<int> shoot_out_winner_distribution(0, 1);
        std::uniform_int_distribution<int> loser_shoot_out_score_distribution(0, 4);
   

        // Generate number of penalties and free kicks for both teams
        int t1_num_penalties = penalty_distribution(gen);
        int t1_num_free_kicks = freekick_distribution(gen);
        int t2_num_penalties = penalty_distribution(gen);
        int t2_num_free_kicks = freekick_distribution(gen);

        // Calculate win probabilities for both teams
        double team1_win_probability = (1 / (1 + exp(team2_ave_defensive - team1_ave_offensive)) + 1 / (1 + exp(team1_ave_offensive - team2_ave_defensive)))/2;
        double team2_win_probability = (1 / (1 + exp(team1_ave_defensive - team2_ave_offensive)) + 1 / (1 + exp(team2_ave_offensive - team1_ave_defensive)))/2;

        //Calculate difference between striker and goalkeeper
        //team 1 players
        int goalkeeper1_skill = t1->get_average_defensive_stat(); //average of all stats and rounded down to nearest integer
        int striker1_skill = t1->get_average_attacking_stat(); //average of all stats and rounded down to nearest integer (this is the penality stat for the striker)


        //team 2 players
        int goalkeeper2_skill = t2->get_average_defensive_stat(); //average of all stats and rounded down to nearest integer
        int striker2_skill = t2->get_average_attacking_stat();; //average of all stats and rounded down to nearest integer (this is the penality stat for the striker)

        // Calculate the probability of scoring from a penalty and a free kick
        double t1_penalty_probability = 1 / (1 + std::exp(goalkeeper1_skill - striker2_skill));
        double t1_freekick_probability = 1 / (1 + std::exp(0.8 * goalkeeper1_skill - striker2_skill));

        double t2_penalty_probability = 1 / (1 + std::exp(goalkeeper2_skill - striker1_skill));
        double t2_freekick_probability = 1 / (1 + std::exp(0.8 * goalkeeper2_skill - striker1_skill));

        //Generate extra score for each team
        int extra_score1 = extra_score1_distribution(gen);
        int extra_score2 = extra_score1_distribution(gen);
        int random_num = random_distribution(gen);


        //Determine which team should win statistically and increase their score, whilst reducing the score of the team with the lower stats (ensuring better team will win a majority of the time)
        if (team1_win_probability > team2_win_probability && (random_num == 2 || random_num == 5 || random_num == 7 || random_num == 10)) {
            extra_score1 = extra_score1 + 1.5;
            extra_score2 = extra_score2 - 2;
        } else if (team2_win_probability > team1_win_probability && (random_num == 2 || random_num == 5 || random_num == 7 || random_num == 10)) {
            extra_score2 = extra_score2 + 1.5;
            extra_score1 = extra_score1 - 2;
        }

        // Calculate and display the predicted scores for both teams
        int team1_score = std::abs(std::round(team1_win_probability * (0.8 * t1_num_penalties + 0.2 * t1_num_free_kicks) + extra_score1 * (team1_win_probability) * 1.5));
        int team2_score = std::abs(std::round(team2_win_probability * (0.8 * t2_num_penalties + 0.2 * t2_num_free_kicks) + extra_score2 * (team2_win_probability) * 1.5));

        //Determine if the match has resulted in a draw, or if the match has not ended in a draw, display the winning team and the final score
        bool draw = false;
        

        bool team1_win = false;
        bool team2_win = false;

        if (team1_score == team2_score) {
            std::cout << BOLD << "Draw! Time for a penalty shootout." << RESET_COLOUR << std::endl;
            draw = true; //if scores are the same, trigger a draw
        } else if (team1_score > team2_score) { //if team 1's score is greater than team 2's score, team 1 wins
            std::cout << BLUE_COLOUR << "" << name_of_team1 << " has beaten " << RED_COLOUR << name_of_team2 << " " << team1_score << " : " << team2_score << std::endl;
            std::cout << "" << name_of_team2 << " has been eliminated. " << std::endl;
            team1_win = true;
            this->winning_team = name_of_team1;
            this->losing_team = name_of_team2;
            this->winning_score = team1_score;
            this->losing_score = team2_score;
        } else if (team2_score > team1_score) { //if team 2's score is greater than team 1's score, team 2 wins
            std::cout << BLUE_COLOUR << "" << name_of_team2 << " has beaten " << RED_COLOUR << name_of_team1 << " " << team2_score << " : " << team1_score << std::endl;
            std::cout << "" << name_of_team1 << " has been eliminated. " << std::endl;
            team2_win = true;
            this->winning_team = name_of_team2;
            this->losing_team = name_of_team1;
            this->winning_score = team2_score;
            this->losing_score = team1_score;
        }

        //Calculate winner of the penalty shootout (each team has 50% chance of winning regardless of stats)
        int team1_shoot_out_score;
        int team2_shoot_out_score;



            if (draw == 1 && shoot_out_winner_distribution(gen) == 1) {
                team1_win = true; //if random numnber equals 0 (range 0-1), team 1 will win the shootout
                this->winning_team = name_of_team1;
                this->losing_team = name_of_team2;
                winning_score = 0;
                losing_score = 0;
                std::cout << BLUE_COLOUR <<name_of_team1 << " beat " << name_of_team2 << " in the penalty shootout." << std::endl;
            } else if (draw == 1 && shoot_out_winner_distribution(gen) == 0) {
                team2_win = true; //if random numnber equals 1 (range 0-1), team 2 will win the shootout
                this->winning_team = name_of_team2;
                this->losing_team = name_of_team1;
                winning_score = 0;
                losing_score = 0;
                std::cout << BLUE_COLOUR <<name_of_team2 << " beat " << name_of_team1 << " in the penalty shootout." << std::endl;
            }           
           
    }   

    std::string get_winning_team(){
        return this->winning_team;
    }

    std::string get_losing_team(){
        return this->losing_team;
    }

    int get_winning_score(){
        return this->winning_score;
    }

    int get_losing_score(){
        return this->losing_score;
    }
    
};


#endif