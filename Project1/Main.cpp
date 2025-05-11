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

    participantList.addParticipant(participantA);
    participantList.addParticipant(participantB);
    participantList.addParticipant(participantC);

    cout << "Added participants A, B, C.\n";
    cout << "participantList.isEmpty()? "
         << (participantList.isEmpty() ? "Yes" : "No") << "\n\n";

    // 3. Test getID, getFirstName, getLastName
    cout << "Testing getters for each participant:\n";
    for (auto pid : {1, 2, 3})
    {
        cout << " ID " << pid
             << " -> getFirstName: " << participantList.getFirstName(pid)
             << ", getLastName: " << participantList.getLastName(pid)
             << ", getID(obj): " << participantList.getID((pid == 1 ? participantA : pid == 2 ? participantB
                                                                                              : participantC))
             << "\n";
    }
    cout << "\n";

    // 4. Register some workshops to participants
    Workshop workshop1(501, "Workshop Test 1", 1, 10, 15.0);
    Workshop workshop2(502, "Workshop Test 2", 2, 20, 25.0);

    participantList.addWorkshopToParticipant(participantA, workshop1);
    participantList.addWorkshopToParticipant(participantB, workshop2);
    participantList.addWorkshopToParticipant(participantB, workshop1);

    cout << "Registered test workshops to A & B.\n\n";

    // 5. Test getWorkshops (and indirectly findByID)
    cout << "Participant A's workshops:\n";
    for (const Workshop &workshop : participantList.getWorkshops(1))
    {
        cout << "  #" << workshop.getNumber()
             << " " << workshop.getTitle() << "\n";
    }

    cout << "Participant B's workshops:\n";
    for (const Workshop &workshop : participantList.getWorkshops(2))
    {
        cout << "  #" << workshop.getNumber()
             << " " << workshop.getTitle() << "\n";
    }

    cout << "Participant C's workshops (should be none):\n";
    auto participantCWorkshops = participantList.getWorkshops(3);
    cout << (participantCWorkshops.empty() ? "  [none]\n" : "");
    cout << "\n";

    // 6. clearList and re-test isEmpty
    participantList.clearList();
    cout << "After clearList(), participantList.isEmpty()? "
         << (participantList.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}