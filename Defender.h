#include <iostream>
#include "Player.h"
#ifndef DEFENDER_H
#define DEFENDER_H
class Defender : public Player {
    protected:    
        int shot;
        int drib;
        int pass;
        int phys;
        int pace;
        int def;
        
    public:
        // Default constructor 
        Defender(){
            name = "\n";
            this->shot = 0;
            this->pace = 0;
            this->drib= 0;
            this->phys = 0;
            this->pass = 0;
            this->def = 0;
        }

        // Constructor with stat inputs
        Defender(int pace, int shot, int pass, int drib, int def, int phys){
            this->shot = shot;
            this->pace = pace;
            this->drib= drib;
            this->phys = phys;
            this->pass = pass;
            this->def = def;        
        }

        //Stat getters
        int get_shot(){
            return shot;
        }
        void set_shot(int shot){
            this->shot = shot;
        }
        int get_drib(){
            return drib;
        }
        void set_drib(int drib){
            this->drib = drib;
        }
        int get_pass(){
            return pass;
        }
        void set_pass(int pass){
            this->pass = pass;
        }
        int get_phys(){
            return phys;
        }
        void set_phys(int phys){
            this->phys = phys;
        }
        int get_pace(){
            return pace;
        }
        void set_pace(int pace){
            this->pace = pace;
        }
        int get_def(){
            return def;
        }
        void set_def(int def){
            this->def = def;
        }
       

};

#endif
