#include <iostream>
#include "Midfielder.h"
#ifndef CM_H
#define CM_H
class CM : public Midfielder{
    public:
        // Default constructor 
        CM() : Midfielder::Midfielder(){};

        // Constructor with stat inputs
        CM(int pace, int shot, int pass, int drib, int def, int phys) : Midfielder::Midfielder(pace, shot, pass, drib, def, phys){};

        //Attack stat setter
        void set_attacking_stat(){
            attacking_stat = (drib + shot + pass)*1.4/3;
        };

        //Defense stat setter
        void set_defensive_stat(){
            defensive_stat = (pace + def + phys)*1.4/3;
        };
};

#endif