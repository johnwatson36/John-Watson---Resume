#include <iostream>
#include "Defender.h"
#ifndef LWB_H
#define LWB_H
class LWB : public Defender{
    public:
        // Default constructor 
        LWB() : Defender::Defender(){};

        // Constructor with stat inputs
        LWB(int pace, int shot, int pass, int drib, int def, int phys) : Defender::Defender(pace, shot, pass, drib, def, phys){};

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