#ifndef FINAL_H
#define FINAL_H

#include "Match.h"
#include "Team.h"
#include "fileReadGoodCopy.h"

class Final {

private:
    Team * teams;
    std::string user_scorers[6];
    
public:

    //Semi Final
    Final(Team user, Team t2, Team t3, Team t4){ 
        teams = new Team[4];
        teams[0] = user;
        teams[1] = t2;
        teams[2] = t3;
        teams[3] = t4;

        for (int i = 0; i < 6; i++){
            user_scorers[i] = teams[0].players[i+5]->get_name();
        }
    }

    void scorer_output(std::string team_name, int score){
        std::string team2[6] = {"Casemiro", "Guimaraes", "Mbappe", "Pedri", "Rodri", "Ronaldo"};
        std::string team3[6] = {"Barella", "Casemiro", "Jorginho", "Lukaku", "Ramos", "Rice"};
        std::string team4[6] = {"Aouar", "Brozović", "Fabinho", "Henderson", "Kane", "Milinković-Savić"};
        
        if (team_name == teams[0].get_name()){
            generateAndDisplayPlayers(user_scorers, score);
        }else if (team_name == teams[1].get_name()){
            generateAndDisplayPlayers(team2, score);
        }else if (team_name == teams[2].get_name()){
            generateAndDisplayPlayers(team3, score);
        }else if (team_name == teams[3].get_name()){
            generateAndDisplayPlayers(team4, score);
        }
    }

    //tournament function
    void play_tournament(){
        //colour code setters
        const std::string RED_COLOUR = "\x1B[31m";
        const std::string GREEN_COLOUR = "\x1B[32m";
        const std::string YELLOW_COLOUR = "\x1B[33m";
        const std::string RESET_COLOUR = "\x1B[0m";
        const std::string BLUE_COLOUR = "\x1B[34m";
        const std::string PURPLE_COLOUR = "\x1B[35m";

        std::cout << "\n" << YELLOW_COLOUR << "Let's start the first semi final! KICKOFF⚽️" << std::endl << std::endl;

        //initialises first match
        Match semi_final_1(&teams[0], &teams[1]);

        //compares scores from the match
        if (semi_final_1.get_losing_score() != semi_final_1.get_winning_score()){
            //prepares to print scoring players
            if (semi_final_1.get_winning_score() != 0){
                std::cout << RESET_COLOUR << "The scorers of the game are:" << std::endl;
            }
            scorer_output(semi_final_1.get_winning_team(), semi_final_1.get_winning_score());
            std::cout << "" << std::endl;
            scorer_output(semi_final_1.get_losing_team(), semi_final_1.get_losing_score());
        }



        std::cout << "\n" << YELLOW_COLOUR << "Let's start the second semi final! KICKOFF⚽️" << std::endl << std::endl;
        //initialises first match
        Match semi_final_2(&teams[2], &teams[3]);

        //compares scores from the match
        if (semi_final_2.get_losing_score() != semi_final_2.get_winning_score()){
            //prepares to print scoring players
            if (semi_final_2.get_winning_score() != 0){
                std::cout << RESET_COLOUR << "The scorers of the game are:" << std::endl;
            }
            scorer_output(semi_final_2.get_winning_team(), semi_final_2.get_winning_score());
            std::cout << "" << std::endl;
            scorer_output(semi_final_2.get_losing_team(), semi_final_2.get_losing_score());
        }


        std::cout << std::endl << YELLOW_COLOUR << "Welcome to the" << PURPLE_COLOUR << " GRAND FINAL ⚽️⚽️⚽️" << std::endl << std::endl;
        if (semi_final_1.get_winning_team() == teams[0].get_name()) {
            if (semi_final_2.get_winning_team() == teams[2].get_name()) {
                // Team 1 and Team 3 enter the grand final
                Match grand_final(&teams[0], &teams[2]);
                if (grand_final.get_winning_score() != 0){
                    std::cout << RESET_COLOUR << "The scorers of the game are:" << std::endl;
                }
                    scorer_output(grand_final.get_winning_team(), grand_final.get_winning_score());
                    scorer_output(grand_final.get_losing_team(), grand_final.get_losing_score());
            } else if (semi_final_2.get_winning_team() == teams[3].get_name()) {
                // Team 1 and Team 4 enter the grand final
                Match grand_final(&teams[0], &teams[3]);
                if (grand_final.get_winning_score() != 0){
                    std::cout << RESET_COLOUR << "The scorers of the game are:" << std::endl;
                }
                scorer_output(grand_final.get_winning_team(), grand_final.get_winning_score());
                scorer_output(grand_final.get_losing_team(), grand_final.get_losing_score());  
            } 
        if (semi_final_1.get_winning_team() == teams[1].get_name()) {
            if (semi_final_2.get_winning_team() == teams[2].get_name()) {
                // Team 2 and Team 3 enter the grand final
                Match grand_final(&teams[1], &teams[2]);
                if (grand_final.get_winning_score() != 0){
                    std::cout << RESET_COLOUR << "The scorers of the game are:" << std::endl;
                }
                scorer_output(grand_final.get_winning_team(), grand_final.get_winning_score());
                scorer_output(grand_final.get_losing_team(), grand_final.get_losing_score());
            } else if (semi_final_2.get_winning_team() == teams[3].get_name()) {
                // Team 2 and Team 4 enter the grand final
                Match grand_final(&teams[1], &teams[3]);
                if (grand_final.get_winning_score() != 0){
                    std::cout << RESET_COLOUR << "The scorers of the game are:" << std::endl;
                }
                scorer_output(grand_final.get_winning_team(), grand_final.get_winning_score());
                scorer_output(grand_final.get_losing_team(), grand_final.get_losing_score());
            }
        }
        }      
    }
    

    void printscorers() {
        for (int i = 0; i < 6; i++){
            std::cout << user_scorers[i] << std::endl;
        };
    }

    ~Final(){
        delete [] teams;
    }

    


};


#endif