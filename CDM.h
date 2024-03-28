#include <iostream>
#include "Midfielder.h"
#ifndef CDM_H
#define CDM_H
class CDM : public Midfielder{
    public:
        // Default constructor 
        CDM() : Midfielder::Midfielder(){};

        // Constructor with stat inputs
        CDM(int pace, int shot, int pass, int drib, int def, int phys) : Midfielder::Midfielder(pace, shot, pass, drib, def, phys){};

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