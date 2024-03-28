#include <iostream>
#include "Midfielder.h"
#ifndef CAM_H
#define CAM_H
class CAM : public Midfielder{
    public:
        // Default constructor 
        CAM() : Midfielder::Midfielder(){};

        // Constructor with stat inputs
        CAM(int pace, int shot, int pass, int drib, int def, int phys) : Midfielder::Midfielder(pace, shot, pass, drib, def, phys){};

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