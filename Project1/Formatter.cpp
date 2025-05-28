/*
    Mew Mew

    Doan, Kevin (Team Leader)
    Nguyen, Long (Eric)
    Truong, Jeffrey
    Vu, Richard

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "Formatter.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

void Formatter::displayMenu()
{
    cout << "\n*********************************************\n"
         << "\t\tWORKSHOP HUB\n"
         << "*********************************************\n"
         << "\t1. View all workshops\n"
         << "\t2. View open workshops\n"
         << "\t3. View workshops by price\n"
         << "\t4. Register for a workshop\n"
         << "\t5. List all your workshops\n"
         << "\t6. Cancel registration\n"
         << "\t7. Exit\n"
         << endl;
}

void Formatter::printAllWorkshops(const WorkshopList &workshopList)
{
    if (workshopList.isEmpty())
    {
        cout << "Workshop list is temporarily unavailable."
             << " Please try again later.\n\n";
    }
    else
    {
        cout << "\tALL WORKSHOPS\n"
             << "\t(Workshop #) Workshop Name\n"
             << "\t-----------------------------\n";

        for (const Workshop &workshop : workshopList.getAllWorkshops())
        {
            cout << "\t(" << workshop.getNumber() << ") "
                 << workshop.getTitle() << "\n";
        }

        cout << endl;
    }
}

void Formatter::printOpenWorkshops(
    const WorkshopList &workshopList,
    const RegistrationManager &registration)
{
    if (registration.getOpenWorkshops().empty())
    {
        cout << "\n\tThere are no open workshops.\n";
    }
    else
    {
        cout << "\tOPEN WORKSHOPS\n"
             << "\t(Workshop #) Workshop Name\n"
             << "\t--------------------------\n";

        for (const Workshop &workshop : workshopList.getAllWorkshops())
        {
            if (registration.isOpen(workshop.getNumber()))
            {
                cout << "\t(" << workshop.getNumber() << ") "
                     << workshop.getTitle() << "\n";
            }
        }

        cout << endl;
    }
}

void Formatter::printWorkshopsByPrice(
    const WorkshopList &workshopList, double price)
{
    if (workshopList.isEmpty())
    {
        cout << "\n\tWorkshop list is temporarily unavailable."
             << " Please try again later.\n";
    }
    else
    {
        cout << "\n\tWORKSHOPS BY PRICE\n"
             << "\t(Workshop #) $Price Workshop Name\n"
             << "\t---------------------------------\n";

        for (const Workshop &workshop : workshopList.getAllWorkshops())
        {
            if (workshop.getPrice() <= price)
            {
                cout << "\t(" << workshop.getNumber() << ") $"
                     << fixed << setprecision(2)
                     << workshop.getPrice() << " "
                     << workshop.getTitle() << "\n";
            }
        }

        cout << endl;
    }
}

void Formatter::printParticipantWorkshops(
    const ParticipantList &participantList, int participantID)
{
    auto workshops = participantList.getWorkshops(participantID);
    if (workshops.empty())
    {
        cout << "\nYou are not currently registered for any workshops."
             << "\n\n";
    }
    else
    {
        cout << "\tYOUR WORKSHOPS\n"
             << "\t(Workshop #) Workshop Name\n"
             << "\t--------------------------\n";

        for (const Workshop &workshop :
             participantList.getWorkshops(participantID))
        {
            cout << "\t("
                 << workshop.getNumber() << ") "
                 << workshop.getTitle() << "\n";
        }

        cout << endl;
    }
}

void Formatter::printWorkshop(const Workshop &workshop)
{
    cout << "\n\t" << workshop.getTitle() << "\n"
         << "\tNumber: " << workshop.getNumber() << "\n"
         << "\tHours: " << workshop.getHours() << "\n"
         << "\tPrice: $" << fixed << setprecision(2)
         << workshop.getPrice() << "\n\n";
}

void Formatter::pauseAndWait()
{
    cout << "Press 'Enter' to return to the menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}