#include <iostream>
#include "Defender.h"
#ifndef CB2_H
#define CB2_H
class CB2 : public Defender{
    public:
        // Default constructor 
        CB2() : Defender::Defender(){};

        // Constructor with stat inputs
        CB2(int pace, int shot, int pass, int drib, int def, int phys) : Defender::Defender(pace, shot, pass, drib, def, phys){};

        //Attack stat setter
        void set_attacking_stat(){
            attacking_stat = (drib + shot + pass)/3;
        };

        //Defense stat setter
        void set_defensive_stat(){
            defensive_stat = (pace + def + phys)/3;
        };
};

#endif