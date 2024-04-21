//
// Created by Mihnea on 4/20/2024.
//

#ifndef OOP_INROUTESUSUAL_H
#define OOP_INROUTESUSUAL_H

#include "SeeRoutesMain.h"

class InRoutesUsual:public SeeRoutesMain{
private:
    int i=0;
public:
    InRoutesUsual():SeeRoutesMain(){}
    InRoutesUsual(const int id[150], std::string comp[150][4], std::string time[150][3], std::string cit[150][16])
            : SeeRoutesMain(id, comp, time, cit) {}
    InRoutesUsual(const InRoutesUsual& other) : SeeRoutesMain(other) {
        i = other.i;
    }

    [[nodiscard]] int getval1() const{
        return i;
    };//FOR UNIT TESTING ONLY

    void WishReserve(int x){
        for(i=0; i<150; i++){
            if(x==list_id[i]){
                TicketRoute(x);
                i=160;
            }
        }
        if(i!=161){
            std::cout<<"There is no train with that id.Try again...\n";
            std::cin>>x;
            WishReserve(x);
        }
    }
    ~InRoutesUsual()=default;
};


#endif //OOP_INROUTESUSUAL_H
