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

#ifndef INTERFACE_H
#define INTERFACE_H

#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"

#include <string>

void processMenu(const WorkshopList &workshopList,
                 const ParticipantList &participantList,
                 const RegistrationManager &registrationManager);

void getIdentification(
    int id, const std::string &firstName, const std::string &lastName);

bool verifyIdentification(const ParticipantList &participantList,
                          int id, const std::string &firstName, const std::string &lastName);

void viewAllWorkshops(const WorkshopList &workshopList);

void viewOpenWorkshops(const WorkshopList &workshopList,
                       const RegistrationManager &registrationManager);

void viewWorkshopsByPrice(const WorkshopList &workshopList);

void viewParticipantWorkshops(const ParticipantList &participantList);

void registerForWorkshop(const WorkshopList &workshopList,
                         const ParticipantList &participantList,
                         const RegistrationManager &registration);

void cancelWorkshop(const WorkshopList &workshopList,
                    const ParticipantList &participantList,
                    const RegistrationManager &registration);

#endif