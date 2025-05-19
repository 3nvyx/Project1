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

 int Formatter::promptSelection() 
 {
    int selection;
    cout << "Please make a selection: ";
    cin >> selection;
    return selection;
 }

 void Formatter::printAllWorkshops(const WorkshopList& workshopList) 
 {
    if (workshopList.size() == 0) 
    {
        cout << "ERROR: There are no workshops available.\n";
        return;
    }

    cout << "ALL WORKSHOPS\n";
    cout << "(Workshop #) Workshop Name\n";
    cout << "------------------------------\n";

    for (int i = 0; i < workshopList.size(); ++i) 
    {
        const Workshop& list = workshopList.get(i);
        cout << "(" << list.getNumber() << ") " << list.getTitle() << "\n";
    }
 }

 void Formatter::printOpenWorkshops(const WorkshopList& workshopList,
     const RegistrationManager& registration)
 {
     if (workshopList.size() == 0)
     {
         cout << "Workshop list is temporarily unavailable. Please try again later.\n";
         return;
     }

     cout << "OPEN WORKSHOPS\n";
     cout << "(Workshop #) Workshop Name\n";
     cout << "------------------------------\n";

     bool anyPrinted = false;

     for (int i = 0; i < workshopList.size(); ++i)
     {
         const Workshop& list = workshopList.get(i);
         if (registration.isOpen(list.getNumber()))
         {
             cout << "(" << list.getNumber() << ") " << list.getTitle() << "\n";
             anyPrinted = true;
         }
     }

     if (!anyPrinted)
     {
         cout << "There are no open workshops.\n";
     }
 }

 void Formatter::printWorkshopsByPrice(const WorkshopList& workshopList, 
    double price)
 {
    if (workshopList.size() == 0) 
    {
        cout << "Workshop list is temporarily unavailable. Please try again later.\n";
        return;
    }

    bool found = false;
    for (int i = 0; i < workshopList.size(); ++i) {
        if (workshopList.get(i).getPrice() <= price) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "There are no workshops at or below that price.\n";
        return;
    }

    cout << "WORKSHOPS BY PRICE\n";
    cout << "(Workshop #) $Price Workshop Name\n";
    cout << "------------------------------\n";

    for (int i = 0; i < workshopList.size(); ++i) 
    {
        const Workshop& list = workshopList.get(i);
        if (list.getPrice() <= price) {
            cout << "$" << list.getPrice() << "(" << list.getNumber() << ")" 
                << list.getTitle() << "\n";
        }
    }
 }

 void Formatter::printParticipantWorkshops(const ParticipantList& participantList, int participantID)
 {
     const WorkshopList& list = participantList.getWorkshops(participantID);

     if (list.size() == 0)
     {
         cout << "You are not currently registered for any workshops.\n";
         return;
     }

     cout << "YOUR WORKSHOPS\n";
     cout << "(Workshop #) Workshop Name\n";
     cout << "------------------------------\n";

     for (int i = 0; i < list.size(); ++i)
     {
         const Workshop& w = list.get(i);
         cout << "(" << w.getNumber() << ") " << w.getTitle() << "\n";
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