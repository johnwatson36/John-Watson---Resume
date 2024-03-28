#include <iostream>
using namespace std;
#include "fileReadGoodCopy.h"


void generateAndDisplayPlayers(std::string names[6], int num_players, int team_num);
std::string getRandomPlayerName(const std::string& filename, int num_players);

int main(void) {

    int score;
    int team_num;
    //for method format, inputs will be team name and score (use method once for )
    cout << "Choose your team: 1 (Manchester United), 2 (Barcelona) or 3 (Real Madrid)" << endl;
    cin >> team_num;

    cout << "How many goals did your team score?" << endl;
    cin >> score;

    // Define the player names for the three teams
    string team1[6] = {"Casemiro", "Guimaraes", "Mbappe", "Pedri", "Rodri", "Ronald"};
    string team2[6] = {"Barella", "Casemiro", "Jorginho", "Lukaku", "Ramos", "Rice"};
    string team3[6] = {"Aouar", "Brozović", "Fabinho", "Henderson", "Kane", "Milinković-Savić"};

    if (team_num == 1) {
        generateAndDisplayPlayers(team1, score);
    } else if (team_num == 2) {
        generateAndDisplayPlayers(team2, score);
    } else if (team_num == 3) {
        generateAndDisplayPlayers(team3, score);
    } else {
        cout << "Unknown team name." << endl;
    }

    return 0;
}