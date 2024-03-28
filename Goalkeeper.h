#include <iostream>
#include "Player.h"
#ifndef GOALKEEPER_H
#define GOALKEEPER_H
class Goalkeeper : public Player {
    protected:    
        int div;
        int hand;
        int kick;
        int ref;
        int spe;
        int pos;

    public:
        // Default constructor 
        Goalkeeper(){
            name = "\n";
            this->div = 0;
            this->hand = 0;
            this->kick= 0;
            this->ref = 0;
            this->spe = 0;
            this->pos = 0;
        }

        // Constructor with stat inputs
        Goalkeeper(int div, int hand, int kick, int ref, int spe, int pos){
            this->div = div;
            this->hand = hand;
            this->kick= kick;
            this->ref = ref;
            this->spe = spe;
            this->pos = pos;        
        }

        //Stat getters
        int get_div(){
            return div;
        }
        void set_div(int div){
            this->div = div;
        }
        int get_kick(){
            return kick;
        }
        void set_kick(int kick){
            this->kick = kick;
        }
        int get_hand(){
            return hand;
        }
        void set_hand(int hand){
            this->hand = hand;
        }
        int get_ref(){
            return ref;
        }
        void set_ref(int ref){
            this->ref = ref;
        }
        int get_spe(){
            return spe;
        }
        void set_spe(int spe){
            this->spe = spe;
        }
        int get_pos(){
            return pos;
        }
        void set_pos(int pos){
            this->pos = pos;
        }
       

};

#endif
