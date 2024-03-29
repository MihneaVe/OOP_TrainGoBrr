#include <iostream>
#include <fstream>
#include <string>

///____----____----____----____----____----____----HereGoNotes----____----____----____----____----____----____|||


// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
// (în formatul impus de voi) astfel încât execuția programului să se încheie.
// De asemenea, trebuie să adăugați în acest fișier date de intrare
// pentru cât mai multe ramuri de execuție.
// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
// pentru a simula date introduse de la tastatură.
// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
// program care merg (și să le evitați pe cele care nu merg).

///This project will note classes by the following types:

///---Read---
///We assume this class will only take small inputs (such as redirecting to another menu or quitting the app)

///---Input---
///We assume this class will take larger chunks of data, and send it to a process class to do something with it

///---Process---
///We assume this class will take the aforementioned inputs and...well...process it...


///____----____----____----____----____----____----HereGoCode----____----____----____----____----____----____|||
class TakeAnAction_View {
private:
    int x;
    std::string p;
public:
    void ListTrainsIN();
    void WantReturn();
    explicit TakeAnAction_View() : x(0){
        std::cout << "List of InBound Trains today:" << "\n\n";
        std::cout << "ID--------------Company--------------Will Arrive At--------------Delay--------------From\n";
    }
    ~TakeAnAction_View() = default;
};



///Main Menu Class (Read Type)
class TakeAnAction_MainMenu {
private:
    int x; // Variable to store input
    const int pass = 989125; // Variable to contain the admin password
    TakeAnAction_View* view{}; //Pointer to previously declared class
public:
    void PrintOptions() { // Method to list possible choices at the start of the app
        std::cout << "What do you wish to do? (insert number and press enter to select)"<<"\n";
        std::cout << "1.View inbound trains"<<"\n";
        std::cout << "2.View outbound trains"<<"\n";
        std::cout << "3.Check for issues on routes"<<"\n";
        std::cout << "4.Buy tickets"<<"\n";
        std::cout << "0.Quit"<<"\n";
        std::cout << "Administrator Menu (insert password)"<<"\n\n";
        TakeChoice();
    }

    void TakeChoice() { // Method to retain the selected choice (i.e. the menu selected)
        std::cin>>x;
        RedirectTo();
    }

    void RedirectTo() { // Method to redirect to the selected menu or quit the app
        if((0<=x && 4>=x)||(x==pass)) {
            std::cout << "You have chosen to ";
            if (x == 1) {
                std::cout<<"view inbound trains.";
                view->ListTrainsIN();
            } else if (x == 2) {
                std::cout<<"view outbound trains.";
            } else if (x == 3) {
                std::cout<<"check for issues on routes.";
            } else if (x == 4) {
                std::cout<<"buy tickets.";
            } else if (x == pass) {
                std::cout<<"log in as admin.";
            }else{
                std::cout<<"close the app."<<"\n";
                std::cout<<"App is closing...Goodbye!";
            }
        }else{
            std::cout<<"Wrong input! Try again!"<<"\n\n";
            PrintOptions();
        }
    }

    // Default constructor
    explicit TakeAnAction_MainMenu() : x(0), view(nullptr) {
        std::cout << "Hello and welcome to <<OURAPP TODO>>!" << "\n\n";
    }

    // Overloaded constructor with one parameter
    explicit TakeAnAction_MainMenu(int i) : x(i), view(nullptr) {
        std::cout << "Hello and welcome to <<OURAPP TODO>>!" << "\n\n";
    }

    // Destructor
    ~TakeAnAction_MainMenu() = default;
};

///Inbound/Outbound Trains Class (Read Type)
     void TakeAnAction_View::ListTrainsIN(){
        std::ifstream fin("Inbound.txt");
        if (!fin.is_open()){
            std::cout << "There has been an error! Inbound train file missing or not open! Please report to admin!\n";
            std::cout<<  "Restarting query...\n\n";
            TakeAnAction_MainMenu restart;
            restart.PrintOptions();
        }else{
            std::string line;
            while (std::getline(fin, line)) {
                std::cout << line << "\n";
            }
            fin.close();
            WantReturn();
        }
    }
    void TakeAnAction_View::WantReturn(){
        std::cout<<"Enter anything to return to menu!";
        std::cin>>p;
        TakeAnAction_MainMenu goBack;
        goBack.PrintOptions();
    }





int main() {
    TakeAnAction_MainMenu play;
    play.PrintOptions();
    return 0;
}
