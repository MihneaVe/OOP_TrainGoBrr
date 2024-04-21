
#ifndef OOP_SEEROUTESMAIN_H
#define OOP_SEEROUTESMAIN_H

#include <iostream>
#include <cstring>


class SeeRoutesMain{
private:
    int i = 0;
protected:
    std::string toptext = "---T_ID------CPNY------HOUR------CITY---";
    int list_id[150]{};
    std::string company[150][4];
    std::string list_time[150][3];
    std::string city[150][16];
    int resTickets = 0;
public:
    SeeRoutesMain()= default;
    SeeRoutesMain(const int id[150], std::string comp[150][4], std::string time[150][3], std::string cit[150][16]){
        std::memcpy(list_id, id, sizeof(list_id));
        for(i=0; i<150; i++){
            company[i][0]=comp[i][0];
        }
        for(i=0; i<150; i++){
            list_time[i][0]=time[i][0];
        }
        for(i=0; i<150; i++){
            city[i][0]=cit[i][0];
        }
    }
    SeeRoutesMain(const SeeRoutesMain& other) {
        std::memcpy(list_id, other.list_id, sizeof(list_id));

        for(i = 0; i < 150; i++) {
            company[i][0] = other.company[i][0];
            list_time[i][0] = other.list_time[i][0];
            city[i][0] = other.city[i][0];
        }
    }

    [[nodiscard]] int getval() const{
        return i;
    };//FOR UNIT TESTING ONLY

    void virtual goSomewhere(int x){
        if (x==0){
            std::cout<<"Press 1 to see routes\n";
            std::cin>>x;
            goSomewhere(x);
        }else if(x==1){
            printRoutes();
        }else{
            std::cout<<"Invalid input. Redirecting...\n";
            goSomewhere(0);
        }
    }
    void virtual printRoutes(){
        std::cout<<toptext<<'\n';
        for(i=0; i<150; i++){
            std::cout<<list_id[i]<<"  "<<company[i][0]<<"  "<<list_time[i][0] << " : " << city[i][0] << "\n\n";
        }
    }
    void TicketRoute(int x){
        std::cout<<"You have reserved a ticket for route "<<x<<"!\n";
        resTickets +=1;
    }
    void virtual AddDelay(int x, int delayMin){
        for(i=0; i<150; i++){
            if(list_id[i]==x || i==0){
                std::ofstream fout("IssueRap.txt", std::ios::app);
                fout<<"\nThere is a "<<delayMin<<" minute delay to the "<<x<<" route heading to: " <<city[i][0]<<".\n";
                i=160;
            }
        }
        if(i!=161){
            std::cout<<"There is no train with that id. Try again: \n";
            std::cin>>i;
            AddDelay(i, delayMin);
        }
    }
    void virtual CancelTrain(int x){
        std::ofstream fout("IssueRap.txt", std::ios::app);
        fout<<"There has been a cancellation on route "<< x;
        for(i=0; i<150; i++){
            if(x==list_id[i] || i==0){
                city[i][0]="Cancelled";
                std::cout<<list_id[i]<<"  "<<company[i][0]<<"  "<<list_time[i][0] << " : " << city[i][0] << "\n\n";
                i=160;
            }
        }
        if(i!=161){
            std::cout<<"There is no train with that id. Try again: \n";
            std::cin>>i;
            CancelTrain(i);
        }
    }
    virtual ~SeeRoutesMain()= default;
};

#endif //OOP_SEEROUTESMAIN_H
