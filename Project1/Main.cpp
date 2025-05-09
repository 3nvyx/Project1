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
#include "Participant.h"
#include "ParticipantList.h"
#include "Workshop.h"
#include "WorkshopList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>


using namespace std;

int main() 
{
    ParticipantList list; 
    Participant p0();  //what does this return? 

    Participant p1(100, "Joe", "Doh");
    Participant p2(120, "Santa", "Claus");
    Participant p3(130, "Enigma", "Man");

    cout << "First name of p1: " << p1.getFirstName() << endl;
    cout << "Last name of p1: " << p1.getLastName() << endl;
    cout << "ID of p1: " << p1.getID() << endl;

    cout << "First name of p2: " << p2.getFirstName() << endl;
    cout << "Last name of p2: " << p2.getLastName() << endl;
    cout << "ID of p2: " << p2.getID() << endl;

    cout << "First name of p3: " << p3.getFirstName() << endl;
    cout << "Last name of p3: " << p3.getLastName() << endl;
    cout << "ID of p3: " << p3.getID() << endl;

        //Workshop(int theNumber, const std::string& theTitle, int theHours, int theCapacity, double thePrice) :
    // should come from the txt file. 
    
    list.addParticipant(p1);
    list.addParticipant(p2);
    list.addParticipant(p3);

    list.addWorkshopToParticipant(p1, w1);
    list.addWorkshopToParticipant(p2, w2);
    list.addWorkshopToParticipant(p3, w2);

    //bool operator<(const Participant & participant) const { return id < participant.id; }


	return 0;
}