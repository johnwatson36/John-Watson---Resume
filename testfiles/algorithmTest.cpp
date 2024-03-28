#include <iostream>
#include <cmath>
#include "algorithm.h"

using namespace std;

int main() {
    double t1_off = 85;
    double t1_def = 78;
    double t2_off = 90;
    double t2_def = 72;
    string t1_name = "ajaay";
    string t2_name = "jack";
    bool t1_wins = false;
    bool t2_wins = false;
    bool draw = false;

    //cout << "Offensive rating of t1:" << endl;
    //cin >> t1_off;
    //cout << "Defensive rating of t1:" << endl;
    //cin >> t1_def;
    //cout << "Offensive rating of t2:" << endl;
    //cin >> t2_off;
    //cout << "Defensive rating of t2:" << endl;
    //cin >> t2_def;

    MatchResults matchResults = Algorithm(t1_off, t1_def, t2_off, t2_def);

    if (matchResults.team1_score > matchResults.team2_score) {
        t1_wins = true;
        cout << t1_name << " beat " << t2_name << " " << matchResults.team1_score << ":" << matchResults.team2_score << endl;
    } else if (matchResults.team2_score > matchResults.team1_score) {
        t2_wins = true;
        cout << t2_name << " beat " << t1_name << " " << matchResults.team2_score << ":" << matchResults.team1_score << endl;
    } else {
        draw = true;
        cout << t1_name << " drew with " << t2_name << " " << matchResults.team1_score << ":" << matchResults.team2_score << endl;
    }

    if (draw && matchResults.team1_shoot_out_score != matchResults.team2_shoot_out_score) {
        if (matchResults.team1_shoot_out_score > matchResults.team2_shoot_out_score) {
            t1_wins = true;
            cout << t1_name << " beat " << t2_name << " in a penalty shootout" << endl;
        } else {
            t2_wins = true;
            cout << t2_name << " beat " << t1_name << " in a penalty shootout" << endl;
        }
    }

    return 0;
}