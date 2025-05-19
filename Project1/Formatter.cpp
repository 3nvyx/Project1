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

#include "Formatter.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std; 

 void Formatter::displayMenu() 
 {
    cout << "***********************************\n";
    cout << "\t\tWORKSHOP HUB\n";
    cout << "***********************************\n";
    cout << "\t1. View all workshops\n";
    cout << "\t2. View open workshops\n";
    cout << "\t3. View workshops by price\n";
    cout << "\t4. Register for a workshop\n";
    cout << "\t5. List all your workshops\n";
    cout << "\t6. Cancel registration\n";
    cout << "\t7. Exit\n";
 }

 void Formatter::printAllWorkshops(const WorkshopList& workshopList) 
 {
    if (workshopList.size() == 0) 
    {
        cout << "Workshop list is temporarily unavailable.
                 Please try again later\n";
        return;
    }

    cout << "ALL WORKSHOPS\n";
    cout << "(Workshop #) Workshop Name\n";
    cout << "------------------------------\n";

    for (const Workshop& workshop) : workshopList.getAllWorkshops()
    {
        cout << "(" << workshop.getNumber() << ") " << 
        workshop.getTitle() << "\n";
    }

 }

 void Formatter::printOpenWorkshops(const WorkshopList& workshopList,
     const RegistrationManager& registration)
 {
     if (registration.getOpenWorkshops().size() == 0)
     {
         cout << "There are no open workshops.\n";
         return;
     }

     cout << "OPEN WORKSHOPS\n";
     cout << "(Workshop #) Workshop Name\n";
     cout << "------------------------------\n";

     for (const Workshop& workshop : workshopList.getAllWorkshops())
     {
        cout << "(" << workshop.getNumber() << ") " << workshop.getTitle() << "\n";
     }

 }

 void Formatter::printWorkshopsByPrice(const WorkshopList& workshopList, 
    double price)
 {
    if (workshopList.size() == 0) 
    {
        cout << "Workshop list is temporarily unavailable. 
        Please try again later.\n";
        return;
    }

    cout << "WORKSHOPS BY PRICE\n";
    cout << "(Workshop #) $Price Workshop Name\n";
    cout << "------------------------------\n";

    for (const Workshop& workshop) : workshopList.getAllWorkshops()
    {
        if(workshop.getPrice <= price)
        {
            cout << "$" << workshop.getPrice() << "(" << workshop.getNumber() << ")"
            << workshop.getTitle() << endl;
        }
    }
 }

 void Formatter::printParticipantWorkshops(const ParticipantList& participantList, int participantID)
 {

     if (participantList.size() == 0)
     {
         cout << "You are not currently registered for any workshops.\n";
         return;
     }

     cout << "YOUR WORKSHOPS\n";
     cout << "(Workshop #) Workshop Name\n";
     cout << "------------------------------\n";

     for (const Workshop& workshop : participantList.getWorkshops(participantID))
     {
        cout << "(" << workshop.getNumber() << ") " << workshop.getTitle() << "\n";
     }
 }

 void Formatter::printWorkshop(const Workshop& workshop)
 {
     cout << workshop.getTitle() << "\n";
     cout << "Number: " << workshop.getNumber() << "\n";
     cout << "Hours: " << workshop.getHours() << "\n";
     cout << "Price: $" << fixed << setprecision(2) << workshop.getPrice() << "\n";
 }

 void Formatter::pauseAndWait()
 {
     cout << "\nPress 'Enter' to return to the menu...\n";
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cin.get();
 }