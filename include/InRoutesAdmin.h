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
    bool visited[150] = {false};
    int maxDifference=0,time1=0,time2=0,difference=0;
    std::string placeholder;
    int hours,minutes;
public:
    InRoutesAdmin():SeeRoutesMain(), x(0), numRoutes(0), traintemp(0), delaytemp(0), maxDifference(0), time1(0),time2(0),difference(0),placeholder(""), hours(0),minutes(0){}
    InRoutesAdmin(const int id[150], std::string comp[150][4], std::string time[150][3], std::string cit[150][16])
            : SeeRoutesMain(id, comp, time, cit), x(0), numRoutes(0), traintemp(0), delaytemp(0), maxDifference(0), time1(0),time2(0),difference(0),placeholder(""), hours(0),minutes(0) {}
    InRoutesAdmin(const InRoutesAdmin& other)
            : SeeRoutesMain(other), x(other.x), numRoutes(other.numRoutes), traintemp(other.traintemp), delaytemp(other.delaytemp), hours(0),minutes(0) {}

    [[nodiscard]] int getval2() const{
        return traintemp;
    };//FOR UNIT TESTING ONLY
    void showAdminConsole(){
        std::cout<<"Press 1 to cancel a train route, "
                   "2 to add delay to a train, "
                   "3 to see routes , "
                   "4 to see data about today's trains ,"
                   "5 to check max distance between two trains going to the same city ,"
                   "or 0 to exit this menu.\n";
        std::cin>>x;
        goToMenu(x);
    };
    int timeToMinutes(const std::string& timeStr) {
        sscanf(timeStr.c_str(), "%d:%d", &hours, &minutes);
        return hours * 60 + minutes;
    }
    void goToMenu(int y) {
        if (y == 1) {
            RouteInfo routesInfo = GetFromFile("GetRoutesIn.txt", numRoutes);
            InRoutesAdmin reDo(routesInfo.id, routesInfo.company, routesInfo.time, routesInfo.city);
            SeeRoutesMain *ptRe = &reDo;
            auto *showPtr = static_cast<InRoutesAdmin *>(ptRe);
            std::cout << "For what train?\n";
            std::cin >> traintemp;
            showPtr->CancelTrain(traintemp);
            showAdminConsole();
        } else if (y == 2) {
            RouteInfo routesInfo = GetFromFile("GetRoutesIn.txt", numRoutes);
            InRoutesAdmin reDo(routesInfo.id, routesInfo.company, routesInfo.time, routesInfo.city);
            SeeRoutesMain *ptRe = &reDo;
            auto *showPtr = static_cast<InRoutesAdmin *>(ptRe);
            std::cout << "For what train and how much delay? Separate by space: \n";
            std::cin >> traintemp >> delaytemp;
            showPtr->AddDelay(traintemp, delaytemp);
            showAdminConsole();
        } else if (y == 3) {
            RouteInfo routesInfo = GetFromFile("GetRoutesIn.txt", numRoutes);
            InRoutesAdmin reDo(routesInfo.id, routesInfo.company, routesInfo.time, routesInfo.city);
            SeeRoutesMain *ptRe = &reDo;
            auto *showPtr = static_cast<InRoutesAdmin *>(ptRe);
            showPtr->printRoutes();
            showAdminConsole();
        } else if (y == 4) {
            InfoTrains();
        } else if(y == 5) {
            std::cout<<"What city?\n";
            std::cin>>placeholder;
            MaxDistance(placeholder);
        }else if(y==0) {
            //I finally learned to do this non-cyclically. This is automatically done in the first created object.
        }else{
            std::cout<<"Invalid Request. Redirecting...";
            showAdminConsole();
        }
    }
    void InfoTrains(){
        std::cout<<"Here is some information about today's trains: \n";
        std::cout<<"Cities today: ";
        for (int i = 0; i < 150; ++i) {
            if (!visited[i]) {
                std::cout << city[i][0] << " ";
                visited[i] = true;
                // Mark all other occurrences of arr[i] as visited
                for (int j = i + 1; j < 150; ++j) {
                    if (city[j][0] == city[i][0]) {
                        visited[j] = true;
                    }
                }
            }
        }
        std::cout<<"\nLargest distance between two distinct trains: ";
        for (int i = 1; i < 150; ++i) {
            time1 = timeToMinutes(list_time[i - 1][0]);
            time2 = timeToMinutes(list_time[i][0]);
            difference = time2 - time1;
            if (difference > maxDifference) {
                maxDifference = difference;
            }
        }
        std::cout<<maxDifference<<" minutes\n";
    }
    void MaxDistance(const std::string& cit){
        for (int i = 1; i < 150; ++i) {
            if(city[i][0]==cit && x==0){
                x=i;
            }
            if(city[i][0]==cit && x!=0 && x!=i){
                time1 = timeToMinutes(list_time[x][0]);
                time2 = timeToMinutes(list_time[i][0]);
                difference = time2 - time1;
                if (difference > maxDifference) {
                    maxDifference = difference;
                }
            }
        }
        if(maxDifference!=0){
            std::cout<<"The maximum distance between a train that goes to "<<cit<<" is "<<maxDifference<<"minutes \n";
        }else{
            std::cout<<"There is only one or less train to that location.\n";
        }
    }

    ~InRoutesAdmin() = default;
};


#endif //OOP_INROUTESADMIN_H
