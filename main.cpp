#include <iostream>
#include "TakeAnAction.h"
#include "SeeRoutesMain.h"
#include "InRoutesAdmin.h"
#include "GetRoutesHelp.h"
///____----____----____----____----____----____----HereGoNotes----____----____----____----____----____----____|||

///Nothing to note yet :)
///WIll be added at a later date

///____----____----____----____----____----____----HereGoCode----____----____----____----____----____----____|||


//int main() {
//        int x;
//        while(true) {
//            std::cout<<"Press 0 to open app.\nPress any other number to end process.\n";
//            std::cin>>x;
//            if(x==0){
//                std::cout<<"Enter 0 for admin mode, 1 for normal mode.";
//                std::cin>>x;
//                if (x == 1 || x == 0) {
//                    TakeAnAction_MainMenu play;
//                    if (x == 0) {
//                        std::cout << "Enter the admin password\n";
//                        operator>>(std::cin, play);
//                        TakeAnAction_MainMenu again(play);
//                        again.AdminMenu();
//                    }
//                    play.PrintOptions();
//                } else {
//                    std::cout << "Invalid input! Restarting...";
//                }
//            }else{
//                std::cout << "Shutting down...";
//                break;
//            }
//        }
//        return 0;
//}

int main() {
    int numRoutes;
    // Call the function with the filename
    RouteInfo* routes = GetFromFile("C:\\Users\\Mihnea\\Documents\\Clion CPP projects\\OOP_TrainGoBrr\\GetRoutesIn.txt", numRoutes); // Replace "GetRoutesIn.txt" with your actual filename

    if (routes == nullptr) {
        std::cerr << "Failed to retrieve route information from file." << std::endl;
        return 1; // Return error code indicating failure
    }

    // Output the extracted data
    for (int i = 0; i < numRoutes; ++i) {
        std::cout << "ID: " << routes[i].id << std::endl;
        std::cout << "Company: " << routes[i].company << std::endl;
        std::cout << "Hour: " << routes[i].hour << std::endl;
        std::cout << "Minute: " << routes[i].minute << std::endl;
        std::cout << "City: " << routes[i].city << std::endl;
        std::cout << std::endl;
    }

    // Free dynamically allocated memory
    delete[] routes;

    return 0;
}