/*
    Mew Mew

    Doan, Kevin
    Nguyen, Long (Eric)
    Truong, Jeffrey
    Vu, Richard

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "DataLoader.h"
#include "Workshop.h"
#include "WorkshopList.h"
#include "Participant.h"
#include "ParticipantList.h"

#include <sstream>
#include <vector>

using namespace std;

int main()
{
    // --- Test WorkshopList & DataLoader ---
    cout << "=== WorkshopList Tests ===\n";

    WorkshopList workshopList;
    DataLoader loader;

    // 1. isEmpty on fresh list
    cout << "workshopList.isEmpty()? "
         << (workshopList.isEmpty() ? "Yes" : "No") << "\n";

    // 2. Load workshop database from file
    ifstream infile("Project1/workshop_database.txt");
    if (!infile)
    {
        cerr << "ERROR: Cannot open workshop_database.txt\n";
        return 1;
    }

    loader.loadWorkshops(workshopList, infile);
    infile.close();

    // 3. isEmpty after load
    cout << "After load, isEmpty()? "
         << (workshopList.isEmpty() ? "Yes" : "No") << "\n\n";

    // 4. Using number from workshop_database.txt
    //    loop through each workshop and test member functions
    ifstream testFile("Project1/workshop_database.txt");
    if (!testFile)
    {
        cerr << "ERROR: Cannot open workshop_database.txt to test\n";
        return 1;
    }

    string line;
    while (getline(testFile, line))
    {
        stringstream ss(line);
        string token;

        // Get number
        getline(ss, token, '|');
        int number = stoi(token);

        // Get workshop
        auto workshopIter = workshopList.findByNumber(number);

        // Try each member function
        cout << "Workshop #" << number << "\n"
             << "Title: " << workshopIter->getTitle() << "\n"
             << "Hours: " << workshopIter->getHours() << "\n"
             << "Capacity: " << workshopIter->getCapacity() << "\n"
             << "Price: $" << workshopIter->getPrice() << "\n\n";
    }

    testFile.close();

    // 6. Test clearList and use isEmpty to verify
    workshopList.clearList();
    cout << "After clearList(), isEmpty()? "
         << (workshopList.isEmpty() ? "Yes" : "No") << "\n\n";

    // --- Test ParticipantList & Participant ---
    cout << "=== ParticipantList Tests ===\n";

    ParticipantList participantList;

    // 1. isEmpty on fresh list
    cout << "participantList.isEmpty()? "
         << (participantList.isEmpty() ? "Yes" : "No") << "\n";

    // 2. Create participants and add to participantList
    Participant participantA(1, "Alice", "Anderson");
    Participant participantB(2, "Bob", "Brown");
    Participant participantC(3, "Cara", "Clark");

    // Participants
    ParticipantList list;
    Participant p1(100, "Joe", "Doh");
    Participant p2(120, "Santa", "Claus");
    Participant p3(130, "Enigma", "Man");

    list.addParticipant(p1);
    list.addParticipant(p2);
    list.addParticipant(p3);

    cout << "\ntesting participants \n";
    cout << "First name of p1: " << p1.getFirstName() << endl;
    cout << "Last name of p1: " << p1.getLastName() << endl;
    cout << "ID of p1: " << p1.getID() << endl;

    cout << "Participant C's workshops (should be none):\n";
    auto participantCWorkshops = participantList.getWorkshops(3);
    cout << (participantCWorkshops.empty() ? "  [none]\n" : "");
    cout << "\n";

    cout << "First name of p3: " << p3.getFirstName() << endl;
    cout << "Last name of p3: " << p3.getLastName() << endl;
    cout << "ID of p3: " << p3.getID() << endl;

    return 0;
}