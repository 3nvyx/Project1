/*
    Mew Mew

    Nguyen Tien Sy Doan, Kevin 
    Nguyen, Long (Eric) 
    Truong, Jeffrey
    Vu, Richard

    Spring 2025
    CS A250 - C++ 2
    
    Workshop Hub
*/
/*
    Comprehensive test for WorkshopList, DataLoader, ParticipantList, and Participant
*/

#include "DataLoader.h"
#include "WorkshopList.h"
#include "Workshop.h"
#include "ParticipantList.h"
#include "Participant.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // --- Test WorkshopList & DataLoader ---

    WorkshopList workshopList;
    DataLoader loader;

    // 1. isEmpty on fresh list
    cout << "workshopList.isEmpty()? "
        << (workshopList.isEmpty() ? "Yes" : "No") << "\n";

    // 2. Load from file
    ifstream infile("/Users/envn0/Downloads/workshop_database.txt");

    // 2. Create Participants and add
    Participant a(1, "Alice", "Anderson");
    Participant b(2, "Bob", "Brown");
    Participant c(3, "Cara", "Clark");
    participantList.addParticipant(a);
    participantList.addParticipant(b);
    participantList.addParticipant(c);

    return 0;
}
