#include <iostream> //cin and cout
#include <string> //for inbuilt string functionality
#include<windows.h> //for the delay(sleep) jump to next line
#include <cstdlib> //for absolute function decision of winner
#include <ctime> //loading screen
#include <fstream> //handlingoffile
#include <iomanip> //
#include <chrono> //loadingscreenRT
using namespace std;

// voting machine
#define no_of_users 100

string password = "salim_habib";
int waiz = 100;
int abdullah = 10;
int ateeb = 100;
int shayan = 50;
int saif = 19;
int wassaf = 10;
int usama = 6;
int Sanjar = 020;
int Alparslan = 55;
int osman = 3;
int orhan = 5;




int rej = 0;
int total = 0 + waiz + abdullah + ateeb + shayan + saif + wassaf + usama + Sanjar + Alparslan + osman + orhan + rej;
int end_r = 0; //0 because voting in process
int i = 0;
string sindh[4] = { "WAIZ","ATEEB","ABDULLAH","SHAYAN" };
string punjab[4] = { "SAIF","WASSAF","USAMA" };
string balochistan[4] = { "Sanjar","Alparslan" };
string kpk[4] = { "OSMAN","ORHAN" };
int main();
void monitor();
void     drawVerticalGraph();

struct
{
    string name;
    string nic;
    string address;
} attribute[no_of_users];
void showLoadingBar(int duration = 4000, int barWidth = 50) {
    std::cout << "Loading: [";
    for (int i = 0; i < barWidth; ++i) {
        std::cout << " ";
    }
    std::cout << "]" << std::flush;

    auto startTime = std::chrono::steady_clock::now();

    for (int i = 0; i < barWidth; ++i) {
        // Busy-wait loop for the delay
        while (true) {
            auto currentTime = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
            if (elapsed >= (i + 1) * (duration / barWidth)) {
                break;
            }
        }
        std::cout << "\rLoading: [";
        for (int j = 0; j <= i; ++j) {
            std::cout << "#";
        }
        for (int j = i + 1; j < barWidth; ++j) {
            std::cout << " ";
        }
        std::cout << "]" << std::flush;
    }
    std::cout << std::endl;
}
void registervote() {
    cout << "               VOTING MACHINE" << endl << endl << endl << endl << endl;

    ofstream f("voter.txt", ios::app); //puttinginputinfileofstream
    if (f.is_open()) {
        cout << "Name: ";
        getline(cin, attribute[i].name); //getlineforthespacebwNAMES
        cout << "NIC: ";
        getline(cin, attribute[i].nic);
        cout << "Address: ";
        getline(cin, attribute[i].address);

        f << attribute[i].name << " " << attribute[i].nic << " " << attribute[i].address << endl;
        f.close();
        cout << "Registration successful. You can now vote." << endl;
    }
    else {
        cout << "Failed to open the file for registration." << endl;
    }
    Sleep(2000);  // Sleep for 2 seconds
}
void voting()
{
    system("cls");
    cout << "               VOTING MACHINE" << endl << endl << endl << endl << endl;
    string add = attribute[i].address;
    if (add.compare("Sindh") == 0) {

        cout << "        CANDIDATE LIST SINDH" << endl << endl << endl << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << j + 1 << ". " << sindh[j] << endl;
        }
        cout << "choose(1-4)" << endl;
        int choice;
        cin >> choice;
        if (choice < 1 || choice>4)
        {
            rej++;
            total++;
        }
        else {
            switch (choice)
            {
            case 1:
                /* code */
                waiz++;
                total++;
                break;
            case 2:
                ateeb++;
                total++;
                break;
            case 3:
                abdullah++;
                total++;
                break;
            case 4:
                shayan++;
                total++;
                break;


            default:
                break;
            }

            cout << "THANK YOU FOR VOTING !!" << endl;
            ofstream f("voted.txt");
            if (f.is_open())
            {
                f << attribute[i].nic << endl;
            }
            else {
                cout << "no file found!" << endl;
                exit(1);
            }
            Sleep(1000);
            i++;
            system("cls");
            return;
        }
    }
    else if (add.compare("Punjab") == 0) {
        cout << "        CANDIDATE LIST PUNJAB" << endl << endl << endl << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << j + 1 << ". " << punjab[j] << endl;
        }
        cout << "choose(1-3)" << endl;
        int choice;
        cin >> choice;
        if (choice < 1 || choice>3)
        {
            rej++;
            total++;
        }
        else {
            switch (choice)
            {
            case 1:
                /* code */
                saif++;
                total++;
                break;
            case 2:
                wassaf++;
                total++;
                break;
            case 3:
                usama++;
                total++;
                break;


            }
            cout << "THANK YOU FOR VOTING !!" << endl;
            ofstream f("voted.txt");
            if (f.is_open())
            {
                f << attribute[i].nic << endl;
            }
            else {
                cout << "no file found!" << endl;
                exit(1);
            }
            Sleep(1000);
            i++;
            system("cls");
            return;
        }
    }
    else if (add.compare("Balochistan") == 0) {
        cout << "        CANDIDATE LIST BALOCHISTAN" << endl << endl << endl << endl;
        for (int j = 0; j < 2; j++)
        {
            cout << j + 1 << ". " << balochistan[j] << endl;
        }
        cout << "choose(1-2)" << endl;
        int choice;
        cin >> choice;
        if (choice < 1 || choice>2)
        {
            rej++;
            total++;
        }
        else {
            switch (choice)
            {
            case 1:
                /* code */
                Sanjar++;
                total++;
                break;
            case 2:
                Alparslan++;
                total++;
                break;


            }
            cout << "THANK YOU FOR VOTING !!" << endl;
            ofstream f("voted.txt");
            if (f.is_open())
            {
                f << attribute[i].nic << endl;
            }
            else {
                cout << "no file found!" << endl;
                exit(1);
            }
            Sleep(1000);
            i++;
            system("cls");
            return;
        }
    }
    else if (add.compare("kpk") == 0) {
        cout << "        CANDIDATE LIST KPK" << endl << endl << endl << endl;
        for (int j = 0; j < 2; j++)
        {
            cout << j + 1 << ". " << kpk[j] << endl;
        }
        cout << "choose(1-2)" << endl;
        int choice;
        cin >> choice;
        if (choice < 1 || choice>2)
        {
            rej++;
            total++;
        }
        else {
            switch (choice)
            {
            case 1:
                /* code */
                osman++;
                total++;
                break;
            case 2:
                orhan++;
                total++;
                break;


            }
            cout << "THANK YOU FOR VOTING !!" << endl;
            ofstream f("voted.txt");
            if (f.is_open())
            {
                f << attribute[i].nic << endl;
            }
            else {
                cout << "no file found!" << endl;
                exit(1);
            }
            Sleep(3000);
            i++;
            system("cls");
            return;
        }
    }




}

void votingMenu()
{
l2:
    system("cls");
    cout << "               VOTING MACHINE" << endl << endl << endl << endl << endl;
    cout << "1. MONITER VOTES" << endl;
    cout << "2. Vote" << endl;
l1:
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        monitor();
        goto l2;
        break;
    case 2:
        voting();
        break;

    default:
        cout << "Invalid choice" << endl;
        goto l1;
    }
}

void end();





void voter() {
    system("cls");
    cout << "               VOTING MACHINE" << endl << endl << endl << endl << endl;
    if (end_r == 1) {
        end();
    }
    else {
        cout << "NAME: ";
        cin.ignore();
        getline(cin, attribute[i].name);
        cout << "NIC: ";
        getline(cin, attribute[i].nic);

        bool found = false;

        // Check if the NIC has already voted
        ifstream of("voted.txt");
        if (of.is_open()) {
            string nic;
            while (of >> nic) {
                if (nic == attribute[i].nic) {
                    cout << "YOU HAVE ALREADY VOTED!" << endl;
                    Sleep(3000);
                    of.close();
                    system("cls");

                    return;
                }
            }
            of.close();
        }
        else {
            cout << "FILE NOT FOUND" << endl;
            exit(1);
        }

        // Check if the NIC is registered
        ifstream f("voter.txt");
        if (f.is_open()) {
            string name, nic, addr, lname;
            while (f >> name >> lname >> nic >> addr) {
                if (nic == attribute[i].nic) {
                    found = true;
                    attribute[i].name = name;
                    attribute[i].address = addr;
                    cout << "\n\n\nNIC: " << attribute[i].nic << " IS REGISTERED\n\n\nPROCEEDING TO THE VOTERS MENU!" << endl;
                    showLoadingBar();
                    Sleep(3000);  // Sleep for 3 seconds
                    votingMenu();
                    return;
                }
            }
            f.close();

            if (!found) {
                cout << "\n\n\nNIC: " << attribute[i].nic << " IS NOT REGISTERED\n\n";
                cout << "REGISTER YOUR NIC FIRST!" << endl << endl;
                Sleep(2000);  // Sleep for 2 seconds
                system("cls");
                registervote();
                system("cls");
                return;
            }
        }
        else {
            cout << "FILE NOT FOUND" << endl;
            exit(1);
        }
    }
}
void monitor() {

    system("cls");
    cout << "VOTING MACHINE" << endl << endl;
    cout << "NAME\t\tVOTES" << endl;
    cout << endl;

    // Candidates and their respective votes arrays for each province
    string sindhCandidates[] = { "ATEEB AZAM", "WAIZ USMANI", "ABDULLAH", "SHAYAN" };
    int sindhVotes[] = { ateeb, waiz, abdullah, shayan };

    string punjabCandidates[] = { "SAIF", "WASSAF", "USAMA" };
    int punjabVotes[] = { saif, wassaf, usama };

    string balochistanCandidates[] = { "Sanjar", "Alparslan" };
    int balochistanVotes[] = { Sanjar, Alparslan };

    string kpkCandidates[] = { "OSMAN", "ORHAN" };
    int kpkVotes[] = { osman, orhan };

    // Display votes for Sindh
    cout << "       SINDH" << endl << "       =====" << endl;
    for (int i = 0; i < sizeof(sindhCandidates) / sizeof(sindhCandidates[0]); ++i) {
        cout << left << setw(15) << sindhCandidates[i] << sindhVotes[i] << endl;
    }
    cout << endl;

    // Display votes for Punjab
    cout << "       PUNJAB" << endl << "       ======" << endl;
    for (int i = 0; i < sizeof(punjabCandidates) / sizeof(punjabCandidates[0]); ++i) {
        cout << left << setw(15) << punjabCandidates[i] << punjabVotes[i] << endl;
    }
    cout << endl;

    // Display votes for Balochistan
    cout << "       BALOCHISTAN" << endl << "       ===========" << endl;;
    for (int i = 0; i < sizeof(balochistanCandidates) / sizeof(balochistanCandidates[0]); ++i) {
        cout << left << setw(15) << balochistanCandidates[i] << balochistanVotes[i] << endl;
    }
    cout << endl;

    // Display votes for KPK
    cout << "       KPK" << endl << "       ===" << endl;
    for (int i = 0; i < sizeof(kpkCandidates) / sizeof(kpkCandidates[0]); ++i) {
        cout << left << setw(15) << kpkCandidates[i] << kpkVotes[i] << endl;
    }
    cout << endl;

    // Total and rejected votes
    cout << "TOTAL VOTES\t" << total << endl;
    cout << "REJECTED VOTES\t" << rej << endl;

    system("pause");
}
void end() {
    cout << "VOTING HAS BEEN ENDED!" << endl;
    drawVerticalGraph();
}

double scale[5];
void drawVerticalGraphForProvince(const string& province, const string candidates[], const int votes[], int numCandidates) {
    const int maxGraphHeight = 20;

    // Calculate the maximum votes among candidates
    int maxVotes = 0;
    for (int i = 0; i < numCandidates; ++i) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
        }
    }
    scale[numCandidates];
    // Calculate the scaling factor for each candidate
    for (int i = 0; i < numCandidates; ++i) {
        scale[i] = (maxVotes > maxGraphHeight) ? (static_cast<double>(maxGraphHeight) / maxVotes) : 1.0;
    }

    // Calculate the maximum length of candidate names
    int maxNameLength = 0;
    for (int i = 0; i < numCandidates; ++i) {
        if (candidates[i].length() > maxNameLength) {
            maxNameLength = candidates[i].length();
        }
    }

    // Calculate spacing based on the maximum candidate name length
    int spacing = maxNameLength + 1;

    cout << "RESULTS GRAPH FOR " << province << endl;
    for (int i = maxGraphHeight; i > 0; --i) {
        for (int j = 0; j < numCandidates; ++j) {
            cout << (votes[j] * scale[j] >= i ? "  *  " : "     ") << string(spacing - 5, ' ');
        }
        cout << endl;
    }

    // Display candidate names
    for (int i = 0; i < numCandidates; ++i) {
        cout << candidates[i] << string(spacing - candidates[i].length(), ' ');
    }
    cout << endl;

    // Display votes with scaling applied
    for (int i = 0; i < numCandidates; ++i) {
        cout << votes[i] << string(spacing - to_string(votes[i]).length(), ' ');
    }
    cout << endl << endl;

    // Announcement of winner and runner-up
    int maxVotesIndex = 0;
    for (int i = 1; i < numCandidates; ++i) {
        if (votes[i] > votes[maxVotesIndex]) {
            maxVotesIndex = i;
        }
    }

    // Find the runner-up
    int runnerUpIndex = (maxVotesIndex + 1) % numCandidates;
    for (int i = 0; i < numCandidates; ++i) {
        if (i != maxVotesIndex && votes[i] > votes[runnerUpIndex]) {
            runnerUpIndex = i;
        }
    }

    // Check if there's a tie between the first and second candidates
    bool tie = false;
    if (votes[maxVotesIndex] == votes[runnerUpIndex]) {
        tie = true;
    }

    if (tie) {
        cout << "It's a tie between " << candidates[maxVotesIndex] << " and " << candidates[runnerUpIndex] << "!" << endl;
    }
    else {
        cout << "Winner: " << candidates[maxVotesIndex] << " (" << votes[maxVotesIndex] << " votes)" << endl;
        cout << "Runner-up: " << candidates[runnerUpIndex] << " (" << votes[runnerUpIndex] << " votes)" << endl;
    }

}




void drawVerticalGraph() {
    string province;

    while (province != "exit") {
        cout << "Enter the name of the province (Sindh, Punjab, Balochistan, KPK) or 'exit' to quit: " << endl;
        cin >> province;

        if (province == "Sindh") {
            const string candidates[] = { "WAIZ", "ATEEB", "ABDULLAH", "SHAYAN" };
            const int votes[] = { waiz, ateeb, abdullah, shayan };
            drawVerticalGraphForProvince(province, candidates, votes, 4);
        }
        else if (province == "Punjab") {
            const string candidates[] = { "SAIF", "WASSAF", "USAMA" };
            const int votes[] = { saif, wassaf, usama };
            drawVerticalGraphForProvince(province, candidates, votes, 3);
        }
        else if (province == "Balochistan") {
            const string candidates[] = { "Sanjar", "Alparslan" };
            const int votes[] = { Sanjar, Alparslan };
            drawVerticalGraphForProvince(province, candidates, votes, 2);
        }
        else if (province == "kpk") {
            const string candidates[] = { "OSMAN", "ORHAN" };
            const int votes[] = { osman, orhan };
            drawVerticalGraphForProvince(province, candidates, votes, 2);
        }
        else if (province == "exit") {
            // Exit the loop if "exit" is entered
            break;
        }
        else {
            cout << "Invalid province name. Please enter a valid province or 'exit' to quit." << endl;
        }

        // Announcement of winner and runner-up

        ;
    }
}

void administrative() {
    string name;
    string pass;
    int count = 0;
    system("cls");

    cout << "               VOTING MACHINE" << endl << endl << endl << endl << endl;
    cout << "Enter name: " << endl;
    getline(cin, name);
    cout << "Enter password:" << endl;
    cin >> pass;

l1:
    if (pass == password && count < 3) {
        string y_n;
        count = 0;
    l2:
        system("cls");
        cout << "Welcome admin " << name << endl;
        cout << "Choose" << endl << "1. MONITOR VOTES\n2. END VOTING\n3. EXIT" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
        case 1:
            monitor();
            break;
        case 2:
            if (end_r == 1) {
                cout << "Voting has already been ended" << endl;
                goto l3;
            }
            end_r = 1;
            cout << "Voting has been ended" << endl;
        l3:
            cout << "SHOULD WE ANNOUNCE THE RESULT?" << endl;
            cin >> y_n;
            if (y_n.compare("yes") == 0 || y_n.compare("YES") == 0) {
                //announcement();
                //loading menu
                showLoadingBar();
                cout << "The result has been announced" << endl;
                Sleep(2000);
                goto l2;
            }
            else if (y_n.compare("no") == 0 || y_n.compare("NO") == 0) {
                cout << "THANK YOU MR " << name << "!" << endl;
                Sleep(3000);
                system("cls");
                goto l2;
            }
            else {
                cout << "Wrong input" << endl;
                Sleep(1000);
                system("cls");
                goto l3;
            }
            break;
        case 3:
            cout << "Exiting..." << endl;
            showLoadingBar();
            Sleep(2000);
            return;
            break;
        default:
            break;
        }
        goto l2;
    }
    else if (count == 3) {
        cout << "You have entered wrong password 3 times" << endl;
        cout << "Exiting...." << endl;
        return;
    }
    else if (pass != password) {
        count++;
        cout << "Wrong password" << endl;
        goto l1;
    }
}

int main() {
l1:
    system("cls");
    cout << "               VOTING MACHINE" << endl << endl << endl << endl << endl;
    cout << "1.vote" << endl << "2.admin" << endl << "3.exit" << endl;
    int n;
    cin >> n;

    switch (n) {
    case 1:
        voter();
        break;
    case 2:
        administrative();
        break;
    case 3:
        cout << "Exiting...." << endl;
        return 0;
    default:
        break;
    }
    goto l1;
}