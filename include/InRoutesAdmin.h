//
// Created by Mihnea on 4/20/2024.
//

#ifndef OOP_INROUTESADMIN_H
#define OOP_INROUTESADMIN_H

#include "SeeRoutesMain.h"
#include "GetRoutesHelp.h"

class InRoutesAdmin:public SeeRoutesMain{
private:
    int x;
    int numRoutes;
    int traintemp, delaytemp;
public:
    InRoutesAdmin():SeeRoutesMain(), x(0), numRoutes(0), traintemp(0), delaytemp(0) {}
    InRoutesAdmin(const int id[150], std::string comp[150][4], std::string time[150][3], std::string cit[150][16])
            : SeeRoutesMain(id, comp, time, cit), x(0), numRoutes(0), traintemp(0), delaytemp(0) {}
    InRoutesAdmin(const InRoutesAdmin& other)
            : SeeRoutesMain(other), x(other.x), numRoutes(other.numRoutes), traintemp(other.traintemp), delaytemp(other.delaytemp) {}

    void showAdminConsole(){
        std::cout<<"Press 1 to cancel a train route, 2 to add delay to a train, 3 to see routes or 0 to exit this menu.\n";
        std::cin>>x;
        goToMenu(x);
    };

    void goToMenu(int y){
        if(y==1){
            RouteInfo routesInfo = GetFromFile(R"(C:\Users\Mihnea\Documents\Clion CPP projects\OOP_TrainGoBrr\GetRoutesIn.txt)", numRoutes);
            InRoutesAdmin reDo(routesInfo.id, routesInfo.company, routesInfo.time, routesInfo.city);
            SeeRoutesMain *ptRe = &reDo;
            auto *showPtr = dynamic_cast<InRoutesAdmin *>(ptRe); //DOWNCASTING
            std::cout<<"For what train?\n";
            std::cin>>traintemp;
            showPtr->CancelTrain(traintemp);
            showAdminConsole();
        }else if(y==2) {
            RouteInfo routesInfo = GetFromFile(R"(C:\Users\Mihnea\Documents\Clion CPP projects\OOP_TrainGoBrr\GetRoutesIn.txt)", numRoutes);
            InRoutesAdmin reDo(routesInfo.id, routesInfo.company, routesInfo.time, routesInfo.city);
            SeeRoutesMain *ptRe = &reDo;
            auto *showPtr = dynamic_cast<InRoutesAdmin *>(ptRe); //DOWNCASTING
            std::cout<<"For what train and how much delay? Separate by space: \n";
            std::cin>>traintemp>>delaytemp;
            showPtr->AddDelay(traintemp, delaytemp);
            showAdminConsole();
        }else if(y==3) {
            RouteInfo routesInfo = GetFromFile(R"(C:\Users\Mihnea\Documents\Clion CPP projects\OOP_TrainGoBrr\GetRoutesIn.txt)", numRoutes);
            InRoutesAdmin reDo(routesInfo.id, routesInfo.company, routesInfo.time, routesInfo.city);
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

    ~InRoutesAdmin() = default;
};


#endif //OOP_INROUTESADMIN_H
