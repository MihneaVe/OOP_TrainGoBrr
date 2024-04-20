//
// Created by Mihnea on 4/20/2024.
//

#ifndef OOP_INROUTESUSUAL_H
#define OOP_INROUTESUSUAL_H

#include "SeeRoutesMain.h"

class InRoutesUsual:public SeeRoutesMain{
private:
    int x;
public:
    InRoutesUsual():SeeRoutesMain(), x(0){}
    InRoutesUsual(const int id[150], std::string comp[150][4], std::string hour[150][3], std::string min[150][3], std::string cit[150][16], const int remTick[150][2])
            : SeeRoutesMain(id, comp, hour, min, cit, remTick) {
    }
    void reserveTickets(int route, int nr){
        if(remTickets[route][1]<=nr){
            std::cout<<"You have reserved the tickets on the selected train. Please note you will have to pay on the train.\n";
            remTickets[route][1] -= nr;
        }else{
            std::cout<<"Please select a smaller number!";
        }
    }
};


#endif //OOP_INROUTESUSUAL_H
