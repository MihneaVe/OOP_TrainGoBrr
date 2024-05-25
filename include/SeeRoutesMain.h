
#ifndef OOP_SEEROUTESMAIN_H
#define OOP_SEEROUTESMAIN_H

#include <iostream>
#include <cstring>


class SeeRoutesMain{
private:
    int p = 0;
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
        for(p=0; p<150; p++){
            company[p][0]=comp[p][0];
        }
        for(p=0; p<150; p++){
            list_time[p][0]=time[p][0];
        }
        for(p=0; p<150; p++){
            city[p][0]=cit[p][0];
        }
    }
    SeeRoutesMain(const SeeRoutesMain& other) {
        std::memcpy(list_id, other.list_id, sizeof(list_id));

        for(p = 0; p < 150; p++) {
            company[p][0] = other.company[p][0];
            list_time[p][0] = other.list_time[p][0];
            city[p][0] = other.city[p][0];
        }
    }

    [[nodiscard]] int getval() const{
        return p;
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
        for(p=0; p<150; p++){
            std::cout<<list_id[p]<<"  "<<company[p][0]<<"  "<<list_time[p][0] << " : " << city[p][0] << "\n\n";
        }
    }
    void TicketRoute(int x){
        std::cout<<"You have reserved a ticket for route "<<x<<"!\n";
        resTickets +=1;
    }
    void virtual AddDelay(int x, int delayMin){
        for(p=0; p<150; p++){
            if(list_id[p]==x || p==0){
                std::ofstream fout("IssueRap.txt", std::ios::app);
                fout<<"\nThere is a "<<delayMin<<" minute delay to the "<<x<<" route heading to: " <<city[p][0]<<".\n";
                p=160;
            }
        }
        if(p!=161){
            std::cout<<"There is no train with that id. Try again: \n";
            std::cin>>p;
            AddDelay(p, delayMin);
        }
    }
    void virtual CancelTrain(int x){
        std::ofstream fout("IssueRap.txt", std::ios::app);
        fout<<"There has been a cancellation on route "<< x;
        for(p=0; p<150; p++){
            if(x==list_id[p] || p==0){
                city[p][0]="Cancelled";
                std::cout<<list_id[p]<<"  "<<company[p][0]<<"  "<<list_time[p][0] << " : " << city[p][0] << "\n\n";
                p=160;
            }
        }
        if(p!=161){
            std::cout<<"There is no train with that id. Try again: \n";
            std::cin>>p;
            CancelTrain(p);
        }
    }
    virtual ~SeeRoutesMain()= default;
};

#endif //OOP_SEEROUTESMAIN_H
