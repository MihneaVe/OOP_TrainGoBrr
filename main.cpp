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


///This functions just compares two strings regardles of case sensitivity
bool isEqualIgnoreCase(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false; // If lengths are different, strings are not equal
    }

    for (size_t i = 0; i < str1.length(); ++i) {
        if (std::tolower(str1[i]) != std::tolower(str2[i])) {
            return false; // If characters at corresponding positions are different, strings are not equal
        }
    }

    return true; // Strings are equal
}

///Inbound/Outbound Class (Read Type)
class TakeAnAction_View {
private:
    int x;
    char p;
public:
    void ListTrainsIN();
    void ListTrainsOUT();
    void ListIssues();
    void WantReturn();
    TakeAnAction_View();
    ~TakeAnAction_View() = default;
};



///Main Menu Class (Read Type)
class TakeAnAction_MainMenu {
private:
    int x, l; // Int type variables for multiple purposes
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
                std::cout << "view inbound trains.\n";
                view->ListTrainsIN();
            } else if (x == 2) {
                std::cout << "view outbound trains.\n";
                view->ListTrainsOUT();
            } else if (x == 3) {
                std::cout << "check or report issues.\n";
                view->ListIssues();
            } else if (x == 4) {
                std::cout << "buy tickets.\n";
            } else if (x == pass) {
                std::cout << "log in as admin.\n";
            } else {
                std::cout << "close the app." << "\n";
                std::cout << "App is closing...Goodbye!\n";
            }
        }else if(x==-1){
            std::cout<<"Redirecting to normal mode...\n\n";
        }else{
            std::cout<<"Wrong input! Try again!\n\n";
            PrintOptions();
        }
    }

    void AdminMenu(){
        if(x!=-2) {
            std::cout << "Placeholder\n\n"; ///TO DO ADD FUNCTIONALITY HERE AND DONT FORGET IT GOES TO NORMAL MODE BY ITSELF AFTER FUNCTION
            std::cin >> x;
        }else{
            //This is quite hardcoded but oh well...
        }
    }

    // Default constructor
    explicit TakeAnAction_MainMenu() : x(0) {
        std::cout << "Hello and welcome to <<OURAPP TODO>>!" << "\n\n";
    }

    // Destructor
    ~TakeAnAction_MainMenu() = default;
    friend std::istream& operator>>(std::istream& input, TakeAnAction_MainMenu& menu) {
        int tempX;
        // Read data into temporary variables
        input >> tempX;

        // Create a new object using the appropriate constructor
        while (tempX != menu.pass) {
            if(tempX == menu.pass){
                // Assign temporary values to the object
                menu.x = tempX;
                break;
            }else{
                std::cout<<"Incorrect password. Try again or press 0 to enter normal mode\n";
                input >> tempX;
            }
            if(tempX==0){
                // Assign temporary values to the object
                menu.x = -2;
                break;
            }
        }

        return input;
    }
};

//Inbound/Outbound Trains Class (Read Type)
    void TakeAnAction_View::ListTrainsIN(){
        std::ifstream fin("Inbound.txt");
        if (!fin.is_open()){
            std::cout << "There has been an error! Inbound train file missing or not open! Please report to admin!\n";
            std::cout<<  "Restarting query...\n\n";
            TakeAnAction_MainMenu restart;
            restart.PrintOptions();
        }else{
            std::cout << "\nList of InBound Trains today:" << "\n\n";
            std::cout << "ID | Company | Arrival | Delay | From\n";
            std::string line;
            while (std::getline(fin, line)) {
                std::cout << line << "\n";
            }
            fin.close();
            std::cout<<"\n\n";
            WantReturn();
        }
    }
    void TakeAnAction_View::ListTrainsOUT() {
        std::ifstream fin("Outbound.txt");
        if (!fin.is_open()){
            std::cout << "There has been an error! Outbound train file missing or not open! Please report to admin!\n";
            std::cout<<  "Restarting query...\n\n";
            TakeAnAction_MainMenu restart;
            restart.PrintOptions();
        }else{
            std::cout << "\nList of OutBound Trains today:" << "\n\n";
            std::cout << "ID | Company | Arrival | Delay | To\n";
            std::string line;
            while (std::getline(fin, line)) {
                std::cout << line << "\n";
            }
            fin.close();
            std::cout<<"\n\n";
            WantReturn();
        }
    }
    void TakeAnAction_View::ListIssues() {
        std:: ifstream fin("IssueRap.txt");
        if (!fin.is_open()) {
            std::cout << "There has been an error! Outbound train file missing or not open! Please report to admin!\n";
            std::cout << "Restarting query...\n\n";
            TakeAnAction_MainMenu restart;
            restart.PrintOptions();
        }else{
            std::cout<<"This is a list of the possible issues that may occur on your routes and in the station!\n";
            std::cout<<"Please report any more issues by entering \"issue\" in the console!\nIf you wish to return, enter anything else!\n";
            std::string line;
            while (std::getline(fin, line)) {
                std::cout << line << "\n";
            };
            fin.close();
            std::cout<<"\n\n";
            std::cin>>line;
            if (isEqualIgnoreCase(line, "issue")) {
                int wr = false;
                std::cout<<"What is the problem?\n";
                std::ofstream fout("IssueRap.txt", std::ios::app);
                std::cin>>line;
                fout<< "\n" << line;
                do{
                    if(wr)
                        fout << line << ' ';
                    else
                        wr=true;
                    if(line.empty()){
                        break;
                    }
                }while(std::getline(std::cin, line));
                fout.close();
                std::cout << "Issue added successfully.\n";
            }else{
                TakeAnAction_MainMenu restart;
                restart.PrintOptions();
            }
        }
    }
    void TakeAnAction_View::WantReturn(){
         std::cout<<"Press any key and enter to return to the menu!";
         std::string l;
         std::cin>>l;
         std::cout<<"\n\n";
         TakeAnAction_MainMenu restart;
         restart.PrintOptions();
    }

TakeAnAction_View::TakeAnAction_View() {
    std::cout<<"Redirecting...";
}


int main() {
        int x;
        std::cout<<"Enter 0 for admin mode, 1 for normal mode.";
        std::cin>>x;
        if(x==1 || x==0) {
            TakeAnAction_MainMenu play;
            if (x==0){
                std::cout<<"Enter the admin password\n";
                std::cin>>play;
                TakeAnAction_MainMenu again(play);
                again.AdminMenu();
            }
            play.PrintOptions();
        }else{
            std::cout<<"Invalid input! Shutting down...";
        }
        return 0;
}
