//
// Created by Mihnea on 3/22/2024.
//

#ifndef OOP_CREATETICKETS_H
#define OOP_CREATETICKETS_H

#include "TakeAnAction.h"

class CreateTickets{
private:
    int val;
    std::string name, surname;
public:

    [[nodiscard]] int getval() const{
        return val;
    }
    //Up above stricly for unit tests

    void info(){
        std::cout<<"Please enter your surname for this transaction:\n";
        std::cin>>surname;
        std::cout<<"Also enter just one given name:\n";
        std::cin>>name;
        addtolist();
    }

    void addtolist(){
        std:: ofstream fout("Buyers.txt", std::ios::app);
        fout<<name<< " "<<surname<<" has just bought "<<val<<" tickets.\n\n";
    }

    CreateTickets(): val(1){};

    explicit CreateTickets(int newval): val(newval){
        std::cout<<"You have bought "<<val<<" tickets!";
    }
    CreateTickets(const CreateTickets &other): val(other.val){
        std::cout<<"You have bought another "<<val<<" tickets!";
    }
    ~CreateTickets()= default;
};

#endif //OOP_CREATETICKETS_H
