//
// Created by Mihnea on 4/20/2024.
//

#ifndef OOP_INROUTESADMIN_H
#define OOP_INROUTESADMIN_H

#include "SeeRoutesMain.h"

class InRoutesAdmin:public SeeRoutesMain{
private:
    int x;
public:
    InRoutesAdmin():SeeRoutesMain(), x(0){}
    InRoutesAdmin(const int id[150], std::string comp[150][4], std::string hour[150][3], std::string min[150][3], std::string cit[150][16], const int remTick[150][2])
            : SeeRoutesMain(id, comp, hour, min, cit, remTick) {
    }
    void showAdminConsole(){
        std::cout<<"Press 1 to cancel a train route, 2 to add delay to a train, 3 to see routes or 0 to exit this menu.\n";
        std::cin>>x;
        goToMenu(x);
    };

    void goToMenu(int y){
        if(y==1){

        }else if(y==2) {

        }else if(y==3) {
            InRoutesAdmin reDo;
            SeeRoutesMain *ptRe = &reDo;
            auto *showPtr = dynamic_cast<InRoutesAdmin *>(ptRe);
            showPtr->printRoutes();
            showAdminConsole();
        }else if(x==0) {
            //I finally learned to do this non-cyclically. This is automatically done in the first created object.
        }else{
            std::cout<<"Invalid Request. Redirecting...";
            showAdminConsole();
        }
    }
};


#endif //OOP_INROUTESADMIN_H
