#include <iostream>
#include "Goalkeeper.h"
#ifndef GK_H
#define GK_H
class GK : public Goalkeeper{
    private:
        int plty;
    public:
        // Default constructor 
        GK() : Goalkeeper::Goalkeeper(){};

        // Constructor with stat inputs
        GK(int div, int hand, int kick, int ref, int spe, int pos, int plty) : Goalkeeper::Goalkeeper(div, hand, kick, ref, spe, pos){};

        //Attack stat setter
        void set_attacking_stat(){
            attacking_stat = (kick + ref + spe)/3;
        };

        //Defense stat setter
        void set_defensive_stat(){
            defensive_stat = (div + hand + pos)*1.5/3;
        };

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