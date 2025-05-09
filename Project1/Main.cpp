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

#include "DataLoader.h"
#include "WorkshopList.h"
#include "Workshop.h"
#include "ParticipantList.h"
#include "Participant.h"

#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    WorkshopList myWorkshopList;
    DataLoader loader;

    ifstream infile("workshop_database.txt");


    // Participants
    ParticipantList list;
    Participant p1(100, "Joe", "Doh");
    Participant p2(120, "Santa", "Claus");
    Participant p3(130, "Enigma", "Man");

    list.addParticipant(p1);
    list.addParticipant(p2);
    list.addParticipant(p3);

    cout << "\n=== Participants ===\n";
    cout << "First name of p1: " << p1.getFirstName() << endl;
    cout << "Last name of p1: " << p1.getLastName() << endl;
    cout << "ID of p1: " << p1.getID() << endl;

    cout << "First name of p2: " << p2.getFirstName() << endl;
    cout << "Last name of p2: " << p2.getLastName() << endl;
    cout << "ID of p2: " << p2.getID() << endl;

    cout << "First name of p3: " << p3.getFirstName() << endl;
    cout << "Last name of p3: " << p3.getLastName() << endl;
    cout << "ID of p3: " << p3.getID() << endl;

    return 0;
}