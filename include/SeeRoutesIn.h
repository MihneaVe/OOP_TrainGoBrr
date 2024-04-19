
#ifndef OOP_SEEROUTESIN_H
#define OOP_SEEROUTESIN_H

#include <iostream>
#include <cstring>
#include "InRoutesAdmin.h"

class SeeRoutesIn{
private:
    std::string toptext = "---T_ID------CPNY------HOUR------CITY---";
    int list_id[150]{};
    std::string company[150][4];
    std::string list_hour[150][3];
    std::string list_minute[150][3];
    std::string city[150][16];
    int remTickets[150][2]{};
public:
    SeeRoutesIn()= default;
    SeeRoutesIn(const int id[150], std::string comp[150][4], std::string hour[150][3], std::string min[150][3], std::string cit[150][16], const int remTick[150][2]){
        std::memcpy(list_id, id, sizeof(list_id));
        for(int i=0; i<150; i++){
            for(int j=0; j<4; j++)
                company[i][j]=comp[i][j];
        }
        for(int i=0; i<150; i++){
            for(int j=0; j<3; j++)
                list_hour[i][j]=hour[i][j];
        }
        for(int i=0; i<150; i++){
            for(int j=0; j<3; j++)
                list_minute[i][j]=min[i][j];
        }
        for(int i=0; i<150; i++){
            for(int j=0; j<16; j++)
                city[i][j]=cit[i][j];
        }
        for(int i=0; i<150; i++){
            for(int j=0; j<2; j++)
                remTickets[i][j]=remTick[i][j];
        }
    }
    void goSomewhere(int x){
        if (x==0){
            std::cout<<"What do you want to do?(1 for seeing routes, 2 for reserving a seat or more)";
            std::cin>>x;
            goSomewhere(x);
        }else if(x==1){
            printRoutes();
        }else if(x==2){
            std::cout<<"How many tickets, and which route?";
            int temp, nr, i, j;
            reserveTickets(temp, nr);
        }
    }
    void printRoutes(){
        std::cout<<toptext<<'\n';
        for(int i=0; i<150; i++){
            std::cout<<list_id[i]<<"  "<<company[i]<<"  "<<list_hour[i]<<':'<<list_minute[i]<<"  "<<city[i]<<"\n\n";
        }
        SeeRoutesIn redo(list_id,company,list_hour,list_minute,city,remTickets);
        redo.goSomewhere(0);
    }
    void reserveTickets(int route, int nr){
        if(remTickets[route][1]<=nr){
            std::cout<<"You have reserved the tickets on the selected train. Please note you will have to pay on the train.\n";
            remTickets[route][1] -= nr;
        }else{
            std::cout<<"Please select a smaller number!";
        }
        SeeRoutesIn redo(list_id,company,list_hour,list_minute,city,remTickets);
        redo.goSomewhere(0);
    }
    void ModifySmth(){

    }
};

#endif //OOP_SEEROUTESIN_H
