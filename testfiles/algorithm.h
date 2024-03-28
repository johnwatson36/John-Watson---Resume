#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include <random>
#include <cmath>

// Define a struct to store the match results
struct MatchResults {
    int team1_score;
    int team2_score;
    int team1_shoot_out_score;
    int team2_shoot_out_score;
};

//int algorithm(double team1_ave_offensive, double team1_ave_defensive, double team2_ave_offensive, double team2_ave_defensive ) {

MatchResults Algorithm(double team1_ave_offensive, double team1_ave_defensive, double team2_ave_offensive, double team2_ave_defensive) {
   
    MatchResults results;

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
    int goalkeeper1_skill = team1_ave_offensive ; //average of all stats and rounded down to nearest integer
    int striker1_skill = team1_ave_defensive; //average of all stats and rounded down to nearest integer (this is the penality stat for the striker)


    //team 2 players
    int goalkeeper2_skill = team2_ave_offensive; //average of all stats and rounded down to nearest integer
    int striker2_skill = team2_ave_defensive; //average of all stats and rounded down to nearest integer (this is the penality stat for the striker)

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
    int team2_score = std::abs(std::round(team1_win_probability * (0.8 * t1_num_penalties + 0.2 * t1_num_free_kicks) + extra_score1 * (team1_win_probability) * 1.5));
    int team1_score = std::abs(std::round(team2_win_probability * (0.8 * t2_num_penalties + 0.2 * t2_num_free_kicks) + extra_score2 * (team2_win_probability) * 1.5));

    std::cout << "Predicted Score for Team 1: " << team1_score << std::endl;
    std::cout << "Predicted Score for Team 2: " << team2_score << std::endl;

    //Determine if the match has resulted in a draw, or if the match has not ended in a draw, display the winning team and the final score
    bool draw = false;
    std::string name_of_team1 = "John";
    std::string name_of_team2 = "Jack";

    bool team1_win = false;
    bool team2_win = false;

    if (team1_score == team2_score) {
        std::cout << "Draw! Time for a penalty shootout." << std::endl;
        draw = true; //if scores are the same, trigger a draw
    } else if (team1_score > team2_score) { //if team 1's score is greater than team 2's score, team 1 wins
        std::cout << "" << name_of_team1 << " has beaten " << name_of_team2 << " " << team2_score << " : " << team1_score << std::endl;
        std::cout << "" << name_of_team2 << " has been eliminated. " << std::endl;
        team1_win = true;
    } else if (team2_score > team1_score) { //if team 2's score is greater than team 1's score, team 2 wins
        std::cout << "" << name_of_team2 << " has beaten " << name_of_team1 << " " << team2_score << " : " << team1_score << std::endl;
        std::cout << "" << name_of_team1 << " has been eliminated. " << std::endl;
    };

    //Calculate winner of the penalty shootout (each team has 50% chance of winning regardless of stats)
    int team1_shoot_out_score;
    int team2_shoot_out_score;

    if (shoot_out_winner_distribution(gen) == 0) {
        team1_win = true; //if random numnber equals 0 (range 0-1), team 1 will win the shootout
    } else if (shoot_out_winner_distribution(gen) == 1) {
        team2_win = true; //if random numnber equals 1 (range 0-1), team 2 will win the shootout
    }

    //Determine final score of the penality shootout
    if (draw == 1 && (team1_win = 1)) {
        team1_shoot_out_score = 5; //if team 1 wins shootout, set its score to 5
        team2_shoot_out_score = loser_shoot_out_score_distribution(gen); //if team 1 wins, generate a random score between 0 and 4 for the losing team (team 2)
        std::cout << "" << name_of_team1 << " has won the penalty shootout against " <<  name_of_team2 << " " << team1_shoot_out_score << " : " << team2_shoot_out_score<< std::endl;
        std::cout << "" << name_of_team2 << " has been eliminated." << std::endl;
    } else if (draw == 1 && (team2_win = 0)) {
        team2_shoot_out_score = 5; //if team 2 wins shootout, set its score to 5
        team1_shoot_out_score = loser_shoot_out_score_distribution(gen); //if team 2 wins, generate a random score between 0 and 4 for the losing team (team 1)
        std::cout << "" << name_of_team2 << " has won the penalty shootout against " << name_of_team1 << " " << team2_shoot_out_score << " to " << team1_shoot_out_score << std::endl;
        std::cout << "" << name_of_team1 << " has been eliminated." << std::endl;
    }  

    results.team1_score = team1_score;
    results.team2_score = team2_score;
    results.team1_shoot_out_score = team1_shoot_out_score;
    results.team2_shoot_out_score = team2_shoot_out_score;

    return results;
}

#endif