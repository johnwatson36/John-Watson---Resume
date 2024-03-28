#include <iostream>
#include "Attacker.h"
#ifndef LW_H
#define LW_H
class LW : public Attacker{
    public:
        // Default constructor 
        LW() : Attacker::Attacker(){};

        // Constructor with stat inputs
        LW(int pace, int shot, int pass, int drib, int def, int phys) : Attacker::Attacker(pace, shot, pass, drib, def, phys){};

        //Attack stat setter
        void set_attacking_stat(){
            attacking_stat = (drib + shot + pass)*1.1/3;
        };

        //Defense stat setter
        void set_defensive_stat(){
            defensive_stat = (pace + def + phys)/3;
        };
};

#endif