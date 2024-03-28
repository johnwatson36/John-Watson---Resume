#include <iostream>
#include "Defender.h"
#ifndef RWB_H
#define RWB_H
class RWB : public Defender{
    public:
        // Default constructor    
        RWB() : Defender::Defender(){};

        // Constructor with stat inputs
        RWB(int pace, int shot, int pass, int drib, int def, int phys) : Defender::Defender(pace, shot, pass, drib, def, phys){};

        //Attack stat setter
        void set_attacking_stat(){
            attacking_stat = (drib + shot + pass)/3;
        };

        //Defense stat setter
        void set_defensive_stat(){
            defensive_stat = (pace + def + phys)*1.1/3;
        };
};

#endif