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

///Inbound/Outbound Class
class TakeAnAction_View {
private:
public:
    void ListTrainsIN();
    void ListTrainsOUT();
    void ListIssues();
    static void WantReturn();
    TakeAnAction_View();
    ~TakeAnAction_View() = default;
};

class CreateTickets{
private:
    int val;
    std::string name, surname;
public:
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


///Main Menu Class
class TakeAnAction_MainMenu {
private:
    int x, l; // Int type variables for multiple purposes
    TakeAnAction_View* view{}; //Pointer to previously declared class
    const int pass =989125; //constant password, will work anytime
    struct multipass {
        mutable int Setpass[10] = {-123, -123, -123, -123, -123, -123, -123, -123, -123,-123};
        multipass& operator=(int k) {
            std::cout << "Note that next admin session will NOT be affected\n";
            std::cout << "Do you still wish to do this?(y/n)\n";
            std::string p;
            std::cin >> p;
            while (true) {
                if (p == "y") {
                    int i = 0;
                    while (true) {
                        if (i==10){
                            i=-1;
                            break;
                        }else if (Setpass[i]==-123){
                            Setpass[i]=k;
                            break;
                        }
                        i++;
                    }
                    if(i==-1){
                        std::cout<<"Password list full!Scrapping...\n";
                    }
                    break;
                } else if (p != "n") {
                    std::cout << "Wrong input! Only (y/n) accepted!\n";
                    std::cin >> p;
                } else {
                    break;
                }
            }
            return *this;
        }
    }Multipass; //set up to ten new passwords.
    struct tickets {
        int brasov = 323;
        int pBv = 40;
        int constanta = 612;
        int pCt = 60;
        int iasi = 74;
        int pIs = 80;
        int sibiu = 95;
        int pSb = 55;
        int oradea = 122;
        int pOr = 125;
        int other = 1415;
        int pOther = (pBv+pCt+pIs+pSb+pOr)/5;

        tickets& operator/(int k){
            int sum = brasov*pBv + constanta*pCt + iasi*pIs + sibiu*pSb + oradea*pOr + other*pOther;
            std::cout<<sum/k;
            return *this;
        }
    }Tickets;
public:
    void PrintOptions() { // Method to list possible choices at the start of the app
        std::cout << "What do you wish to do? (insert number and press enter to select)"<<"\n";
        std::cout << "1.View inbound trains"<<"\n";
        std::cout << "2.View outbound trains"<<"\n";
        std::cout << "3.Check for issues on routes"<<"\n";
        std::cout << "4.Buy tickets"<<"\n";
        std::cout << "0.Quit"<<"\n\n";
        std::cout << "(Or insert any admin password to enter admin menu)\n";
        std::cin>>x;
        RedirectTo();
    }

    void RedirectTo() { // Method to redirect to the selected menu or quit the app
        if(0<=x && 4>=x) {
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
                std::cout <<"Press 1 for tickets to Constanta\n";
                std::cout <<"Press 2 for tickets to Brasov\n";
                std::cout <<"Press 3 for tickets to Sibiu\n";
                std::cout <<"Press 4 for tickets to Iasi\n";
                std::cout <<"Press 5 for tickets to Oradea\n";
                std::cout <<"Press 6 for tickets to other cities\n";
                std::cout <<"Press any other number to cancel\n";
                std::cin >>x;
                if(x==1){
                    std::cout<<"\nHow many?\n";
                    CreateTickets buy(x);
                    Tickets.constanta+=x;
                    buy.info();
                    std::cout<<"\nIf you wish to purchase tickets in the same amount for (an)other train again, press 1.\nIf not, press any other number.\n";
                    l = x;
                    std::cin>>x;
                    if(x==1){
                        CreateTickets buy2 = buy;
                        buy2.addtolist();
                        Tickets.other+=l;
                    }
                }else if(x==2){
                    std::cout<<"\nHow many?\n";
                    std::cin >> x;
                    CreateTickets buy(x);
                    Tickets.brasov+=x;
                    buy.info();
                    std::cout<<"\nIf you wish to purchase tickets in the same amount for (an)other train again, press 1.\nIf not, press any other number.\n";
                    l = x;
                    std::cin>>x;
                    if(x==1){
                        CreateTickets buy2 = buy;
                        buy2.addtolist();
                        Tickets.other+=l;
                    }
                }else if(x==3){
                    std::cout<<"\nHow many?";
                    std::cin >> x;
                    CreateTickets buy(x);
                    Tickets.sibiu+=x;
                    buy.info();
                    std::cout<<"\nIf you wish to purchase tickets in the same amount for (an)other train again, press 1.\nIf not, press any other number.\n";
                    l = x;
                    std::cin>>x;
                    if(x==1){
                        CreateTickets buy2 = buy;
                        buy2.addtolist();
                        Tickets.other+=l;
                    }
                }else if(x==4){
                    std::cout<<"\nHow many?";
                    std::cin >> x;
                    CreateTickets buy(x);
                    Tickets.iasi+=x;
                    buy.info();
                    std::cout<<"\nIf you wish to purchase tickets in the same amount for (an)other train again, press 1.\nIf not, press any other number.\n";
                    l = x;
                    std::cin>>x;
                    if(x==1){
                        CreateTickets buy2 = buy;
                        buy2.addtolist();
                        Tickets.other+=l;
                    }
                }else if(x==5){
                    std::cout<<"\nHow many?";
                    std::cin >> x;
                    CreateTickets buy(x);
                    Tickets.oradea+=x;
                    buy.info();
                    std::cout<<"\nIf you wish to purchase tickets in the same amount for (an)other train again, press 1.\nIf not, press any other number.\n";
                    l = x;
                    std::cin>>x;
                    if(x==1){
                        CreateTickets buy2 = buy;
                        buy2.addtolist();
                        Tickets.other+=l;
                    }
                }else if(x==6){
                    std::cout<<"\nHow many?";
                    std::cin >> x;
                    CreateTickets buy(x);
                    Tickets.other+=x;
                    buy.info();
                    std::cout<<"\nIf you wish to purchase tickets in the same amount for (an)other train again, press 1.\nIf not, press any other number.\n";
                    l = x;
                    std::cin>>x;
                    if(x==1){
                        CreateTickets buy2 = buy;
                        buy2.addtolist();
                        Tickets.other+=l;
                    }
                }
                PrintOptions();
            } else {
                std::cout << "close the app." << "\n";
                std::cout << "App is closing...Goodbye!\n";
            }
        }else if(x==-1){
            std::cout<<"Redirecting to normal mode...\n\n";
        }else if(x==pass || x==Multipass){
            std::cout<<"You have entered admin mode!\n";
            AdminMenu();
        }else{
            std::cout<<"Wrong input! Try again!\n\n";
            PrintOptions();
        }
    }


    void AdminMenu(){
        if(x!=-2) {
            std::cout << "Press 1 to add another password\n"; ///TO DO ADD FUNCTIONALITY HERE AND DONT FORGET IT GOES TO NORMAL MODE BY ITSELF AFTER FUNCTION
            std::cout << "Press 2 to see all current passwords\n";
            std::cout << "Press 3 to see profits from tickets on all routes\n";
            std::cout << "Press 4 to see how many tickets have been sold and the average cost of a ticket\n";
            std::cout << "Press 0 to return to normal mode\n";
            std::cin >> x;
            if(x==1) {
                std::cin >> x;
                Multipass = x;
                AdminMenu();
            }else if(x==2){
                std::cout<<Multipass;
                AdminMenu();
            }else if (x==3){
                std::cout<<"Do you wish to view it in EUR(press 1) or RON(press 2)?";
                std::cin>>x;
                if(x==1){
                    std::cout<<"~";
                    Tickets/5;
                    std::cout<<" EUR\n";
                }else if (x==2){
                    Tickets/1;
                    std::cout<<" RON\n";
                }else{
                    std::cout<<"Invalid input...redirecting...";
                }
                AdminMenu();
            }else if (x==4){
                std::cout<<"Do you wish to see in 1=unit(press 1), 10=unit(press 2), 100=unit(press 3)?\n";
                std::cin>>x;
                if(x==1){
                    Tickets*1;
                }else if(x==2){
                    Tickets*10;
                }else if(x==3){
                    Tickets*100;
                }else{
                    std::cout<<"Invalid input...redirecting...";
                }
                AdminMenu();
            }else if(x!=0){
                std::cout<<"Invalid input! Try again!";
                AdminMenu();
            }else{
                PrintOptions();
            }
        }else{
            //This is quite hardcoded but oh well...
        }
    }

    // Default constructor
    explicit TakeAnAction_MainMenu() : x(0), l(0){
        std::cout << "Hello and welcome to <<OURAPP TODO>>!" << "\n\n";
    }

    // Destructor
    ~TakeAnAction_MainMenu() = default;


    //Operator>> overloader;
    friend std::istream& operator>>(std::istream& input, TakeAnAction_MainMenu& menu) {
        int tempX;
        // Read data into temporary variables
        input >> tempX;

        // Create a new object using the appropriate constructor
        while (true) {
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

    //Operator<< overloader;
    friend std::ostream& operator<<(std::ostream& output, const multipass& allpass){
        int i = 0;
        while (i<10){
            if(allpass.Setpass[i] != -123)
                std::cout<<i+1<<":"<<allpass.Setpass[i]<<"\n";
            i++;
        }
        return output;
    }

    friend bool operator==(int k, const multipass& allpass){
        int i=0;
        bool retval;
        while(i!=10){
            if(k==allpass.Setpass[i]){
                retval = true;
                break;
            }else{
                retval = false;
            }
            i++;
        }
        return retval;
    }

    friend float operator*(tickets& lister, float k);

    friend std::ostream& operator<<(std::ostream& output, tickets& lister) {
        int sum = (lister.brasov*lister.pBv + lister.constanta*lister.pCt + lister.iasi*lister.pIs
                    + lister.sibiu*lister.pSb + lister.oradea*lister.pOr + lister.other*lister.pOther);
        int ttot=(lister.brasov+lister.constanta+lister.iasi+lister.sibiu+lister.oradea+lister.other);
        auto avg = static_cast<float>(sum);
        avg /= static_cast<float>(ttot);
        output <<"~"<< avg << '\n';
        return output;
    }
};

float operator*(TakeAnAction_MainMenu::tickets& lister, float k){
    int sum = lister.other+lister.constanta+lister.oradea+lister.brasov+lister.iasi+lister.sibiu;
    auto floatValue = static_cast<float>(sum);
    floatValue/=k;
    std::cout<<floatValue<<" units ("<< k<<" tickets)" <<" have been sold\n";
    std::cout<<"The average cost per ticket is: ";
    std::cout<<lister;
    return 0;
};

///Inbound/Outbound Trains Class Functions
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
                ListIssues();
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
        while(true) {
            std::cout<<"Press 0 to open app.\nPress any other number to end process.\n";
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
            }else{
                std::cout << "Shutting down...";
                break;
            }
        }
        return 0;
}
