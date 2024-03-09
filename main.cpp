#include <iostream>
#include <array>


///____----____----____----____----____----____----HereGoNotes----____----____----____----____----____----____\\\

/////////////////////////////////////////////////////////////////////////
/// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
/// (în formatul impus de voi) astfel încât execuția programului să se încheie.
/// De asemenea, trebuie să adăugați în acest fișier date de intrare
/// pentru cât mai multe ramuri de execuție.
/// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
/// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
/// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
/// pentru a simula date introduse de la tastatură.
/// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
/// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
/// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
/// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
/// program care merg (și să le evitați pe cele care nu merg).
/////////////////////////////////////////////////////////////////////////


///____----____----____----____----____----____----HereGoCode----____----____----____----____----____----____\\\

using namespace std;

class TakeAnAction_MainMenu {
private:
    int x; // Variable to store input
    const int pass = 989125; // Variable to contain the admin password
public:
    void PrintOptions() { // Method to list possible choices at the start of the app
        cout << "What do you wish to do? (insert number and press enter to select)"<<"\n";
        cout << "1.View inbound trains"<<"\n";
        cout << "2.View outbound trains"<<"\n";
        cout << "3.Check for issues on routes"<<"\n";
        cout << "4.Buy tickets"<<"\n";
        cout << "0.Quit"<<"\n";
        cout << "Administrator Menu (insert password)"<<"\n\n";
        TakeChoice();
    }

    void TakeChoice() { // Method to retain the selected choice (i.e. the menu selected)
        cin>>x;
        RedirectTo();
    }

    void RedirectTo() { // Method to redirect to the selected menu or quit the app
        if((0<=x && 4>=x)||(x==pass)) {
            cout << "You have chosen to ";
            if (x == 1) {
                cout<<"view inbound trains.";
            } else if (x == 2) {
                cout<<"view outbound trains.";
            } else if (x == 3) {
                cout<<"check for issues on routes.";
            } else if (x == 4) {
                cout<<"buy tickets.";
            } else if (x == pass) {
                cout<<"log in as admin.";
            }else{
                cout<<"close the app."<<"\n";
                cout<<"App is closing...Goodbye!";
            }
        }else{
            cout<<"Wrong input! Try again!"<<"\n\n";
            PrintOptions();
        }
    }

    // Default constructor
    explicit TakeAnAction_MainMenu() : x(0) {
        cout << "Hello and welcome to <<OURAPP TODO>>!" << "\n\n";
    }

    // Overloaded constructor with one parameter
    explicit TakeAnAction_MainMenu(int i) : x(i) {
        cout << "Hello and welcome to <<OURAPP TODO>>!" << "\n\n";
    }

    // Destructor
    ~TakeAnAction_MainMenu() {}
};


int main() {
    TakeAnAction_MainMenu play;
    play.PrintOptions();
    return 0;
}
