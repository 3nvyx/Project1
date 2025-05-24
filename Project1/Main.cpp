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

#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"
#include "DataLoader.h"
#include "Interface.h"
#include "Formatter.h"

#include <iostream>

using namespace std;

int main()
{
    ParticipantList participantList;
    DataLoader::loadParticipants(
        participantList, "participant_database.txt");

    WorkshopList workshopList;
    DataLoader::loadWorkshops(workshopList, "workshop_database.txt");

    RegistrationManager regManager(workshopList, participantList);
    DataLoader::loadRegistration(regManager, "registration_database.txt");

    processMenu(workshopList, participantList, regManager);

    cout << endl
         << endl;
    system("Pause");
    return 0;
}
