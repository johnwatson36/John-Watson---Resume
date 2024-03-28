#include <iostream>
#include "Attacker.h"
#ifndef STRK_H
#define STRK_H
class STRK : public Attacker{
    private:
        int plty;
    public:
        // Default constructor
        STRK() : Attacker::Attacker(){};

        // Constructor with stat inputs
        STRK(int pace, int shot, int pass, int drib, int def, int phys, int plty) : Attacker::Attacker(pace, shot, pass, drib, def, phys){
            this->plty = plty;
        }

        //Attack stat setter
        void set_attacking_stat(){
            attacking_stat = (drib + shot + pass)*1.5/3;
        }

        //Defense stat setter
        void set_defensive_stat(){
            defensive_stat = (pace + def + phys)/3;
        }

        //Penalty stat getter
        int get_plty_stat(){
            return plty;
        }

        //Penalty stat setter
        void set_plty_stat(int plty){
            this->plty = plty;
        }
};

#endif