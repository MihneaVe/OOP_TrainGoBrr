//
// Created by Mihnea on 4/20/2024.
//

#ifndef OOP_INROUTESUSUAL_H
#define OOP_INROUTESUSUAL_H

#include "SeeRoutesMain.h"

struct Train {
    int trainNumber;
    std::string company;
    std::string departureTime;
    std::string destination;

};

class InRoutesUsual:public SeeRoutesMain{
private:
    int i=0;
    std::list<Train> trains;

    void readTrainsFromFile(const std::string& filePath) {
        std::ifstream inputFile(filePath);
        if (!inputFile) {
            std::cerr << "Unable to open file: " << filePath << std::endl;
            return;
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            Train train;
            std::istringstream iss(line);
            iss >> train.trainNumber >> train.company >> train.departureTime;
            std::getline(iss, train.destination);
            // Remove leading whitespace from destination
            if (!train.destination.empty() && train.destination.front() == ' ') {
                train.destination.erase(train.destination.begin());
            }
            trains.push_back(train);
        }

        inputFile.close();
    }

public:
    InRoutesUsual() : SeeRoutesMain() {
        readTrainsFromFile("include/GetRoutesIn.txt");
    }
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
            if(x==list_id[i] || x==0){
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

    void printTrainDetails(int trainNumber) const {
        auto it = std::find_if(trains.begin(), trains.end(),
                               [trainNumber](const Train& train) {
                                   return train.trainNumber == trainNumber;
                               });

        if (it != trains.end()) {
            std::cout << "Train " << it->trainNumber << " (" << it->company << ") to " << it->destination
                      << " departs at " << it->departureTime << "\n";
        } else {
            std::cout << "Train number " << trainNumber << " not found.\n";
        }
    }

    bool hasTrainToDestination(const std::string& destination) const {
        return std::any_of(trains.begin(), trains.end(),
                           [&destination](const Train& train) {
                               return train.destination == destination;
                           });
    }

    ~InRoutesUsual()=default;
};


#endif //OOP_INROUTESUSUAL_H
