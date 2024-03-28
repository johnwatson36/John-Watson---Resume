#include <iostream>
#include <string>
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

#ifndef PLAYER_ARRAY_H
#define PLAYER_ARRAY_H

class Player_array{
    public:
    Player* player_array[33];

    std::string positions[11];

    //constructor, creates and fills array of every possible selectable player and an array of the names of positions
    Player_array() {

        positions[0] = "Goal Keeper";
        positions[1] = "Centre Back 1";
        positions[2] = "Centre Back 2";
        positions[3] = "Left Wing Back";
        positions[4] = "Right Wing Back";
        positions[5] = "Central Defensive Midfielder";
        positions[6] = "Central Midfielder";
        positions[7] = "Central Attacking Midfielder";
        positions[8] = "Left Winger";
        positions[9] = "Right Winger";
        positions[10] = "Striker";

        player_array[0] = new GK(84, 89, 75, 90, 46, 89, 75);
        player_array[0]->set_name("Courtois");

        player_array[1] = new GK(87, 88, 91, 88, 56, 91, 86);
        player_array[1]->set_name("Neur");

        player_array[2] = new GK(86, 85, 84, 89, 54, 90, 89);
        player_array[2]->set_name("Alisson");

        player_array[3] = new CB1(81, 60, 71, 72, 91, 86);
        player_array[3]->set_name("Van Dijk");

        player_array[4] = new CB1(79, 56, 75, 74, 89, 80);
        player_array[4]->set_name("Marquinhos");

        player_array[5] = new CB1(63, 39, 66, 68, 88, 88);
        player_array[5]->set_name("Ruben Dias");

        player_array[6] = new CB2(82, 33, 59, 68, 88, 85);
        player_array[6]->set_name("Koulibaly");

        player_array[7] = new CB2(66, 69, 78, 77, 86, 83);
        player_array[7]->set_name("Fabinho");

        player_array[8] = new CB2(82, 58, 71, 67, 86, 85);
        player_array[8]->set_name("Rudiger");

        player_array[9] = new LWB(85, 73, 85, 85, 81, 73);
        player_array[9]->set_name("Cancelo");

        player_array[10] = new LWB(80, 61, 81, 81, 82, 76);
        player_array[10]->set_name("Robertson");

        player_array[11] = new LWB(76, 74, 83, 87, 80, 83);
        player_array[11]->set_name("Acuna");

        player_array[12] = new RWB(76, 69, 89, 80, 80, 73);
        player_array[12]->set_name("Alexander Arnold");

        player_array[13] = new RWB(91, 63, 77, 78, 80, 82);
        player_array[13]->set_name("Walker");

        player_array[14] = new RWB(91, 63, 77, 78, 80, 82);
        player_array[14]->set_name("Carvajal");

        player_array[15] = new CDM(78, 82, 82, 82, 81, 86);
        player_array[15]->set_name("Goretzka");

        player_array[16] = new CDM(72, 66, 74, 81, 87, 82);
        player_array[16]->set_name("Kante");

        player_array[17] = new CDM(82, 69, 86, 87, 77, 78);
        player_array[17]->set_name("de Jong");

        player_array[18] = new CM(74, 88, 93, 87, 64, 77);
        player_array[18]->set_name("de Bruyne");

        player_array[19] = new CM(77, 86, 89, 88, 72, 66);
        player_array[19]->set_name("Modric");

        player_array[20] = new CM(53, 81, 90, 81, 71, 68);
        player_array[20]->set_name("Kroos");

        player_array[21] = new CAM(77, 78, 84, 92, 61, 68);
        player_array[21]->set_name("Silva");

        player_array[22] = new CAM(60, 61, 87, 91, 79, 66);
        player_array[22]->set_name("Verratti");

        player_array[23] = new CAM(61, 72, 87, 90, 72, 69);
        player_array[23]->set_name("Thiago");

        player_array[24] = new LW(87, 83, 85, 93, 39, 61);
        player_array[24]->set_name("Neymar");

        player_array[25] = new LW(90, 83, 80, 88, 44, 77);
        player_array[25]->set_name("Son");

        player_array[26] = new LW(90, 83, 80, 88, 44, 77);
        player_array[26]->set_name("Mane");

        player_array[27] = new RW(81, 89, 90, 94, 34, 64);
        player_array[27]->set_name("Messi");

        player_array[28] = new RW(90, 89, 82, 90, 45, 75);
        player_array[28]->set_name("Salah");

        player_array[29] = new RW(90, 80, 78, 86, 45, 67);
        player_array[29]->set_name("Sterling");

        player_array[30] = new STRK(80, 88, 83, 87, 39, 78, 84);
        player_array[30]->set_name("Benzema");

        player_array[31] = new STRK(75, 91, 79, 86, 44, 83, 81);
        player_array[31]->set_name("Lewandowski");

        player_array[32] = new STRK(87, 89, 80, 92, 36, 76, 74);
        player_array[32]->set_name("Mbappe");

    }

    

};

#endif