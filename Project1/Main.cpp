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

#include <iostream>
#include <string>

#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"
#include "Formatter.h"
#include "DataLoader.h"
#include "Interface.h"

using namespace std;

int main()
{
    WorkshopList workshopList;
    ParticipantList participantList;

    DataLoader::loadWorkshops(workshopList, "workshop_database.txt");
    DataLoader::loadParticipants(participantList, "participant_database.txt");

    RegistrationManager regManager(workshopList, participantList);
    DataLoader::loadRegistration(regManager, "registration_database.txt");

    processMenu(workshopList, participantList, regManager);

    cout << endl
         << endl;
    system("Pause");

    return 0;
}
