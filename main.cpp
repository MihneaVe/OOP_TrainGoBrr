#include <iostream>
#include "TakeAnAction.h"
#include "FindPassword.h"
///____----____----____----____----____----____----HereGoNotes----____----____----____----____----____----____|||

///Nothing to note yet :)
///WIll be added at a later date

///____----____----____----____----____----____----HereGoCode----____----____----____----____----____----____|||


int main() {
        int x;
        while(true) {
            std::cout<<"Press 0 to open app or 1 to find if your admin password is correct.\nPress any other number to end process.\n";
            std::cin>>x;
            if(x==0){
                std::cout<<"Enter 0 for admin mode, 1 for normal mode.";
                std::cin>>x;
                if (x == 1 || x == 0) {
                    TakeAnAction_MainMenu play;
                    if (x == 0) {
                        std::cout << "Enter the admin password\n";
                        operator>>(std::cin, play);
                        TakeAnAction_MainMenu again(play);
                        again.AdminMenu();
                    }
                    play.PrintOptions();
                } else {
                    std::cout << "Invalid input! Restarting...";
                }
            }else if(x==1){
                std::cout<<"Please enter the password: \n";
                std::cin>>x;
                FindPassword::showcasepass(x);
            }else{
                std::cout << "Shutting down...";
                break;
            }
        }
        return 0;
}