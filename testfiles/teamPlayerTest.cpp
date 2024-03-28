#include <iostream>
#include <cstdlib>
#include "Team.h"

int main(){
    Team madrid(true, "Madrid");

    madrid.createTeam();
    for (int i = 0; i < 11; i++){
        std::cout << madrid.players[i]->get_name() << std::endl;
    }
    

    std::cout << madrid.get_average_attacking_stat() << " " << madrid.get_average_defensive_stat() << std::endl;
    return 0;
}