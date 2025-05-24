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

#ifndef INTERFACE_H
#define INTERFACE_H

#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"

#include <string>

void processMenu(
    const WorkshopList &workshopList,
    ParticipantList &participantList,
    RegistrationManager &registrationManager);

void getIdentification(
    int &id, std::string &firstName, std::string &lastName);

bool verifyIdentification(
    const ParticipantList &participantList,
    int id, const std::string &firstName,
    const std::string &lastName);

void viewAllWorkshops(const WorkshopList &workshopList);

void viewOpenWorkshops(
    const WorkshopList &workshopList,
    const RegistrationManager &registrationManager);

void viewWorkshopsByPrice(const WorkshopList &workshopList);

void viewParticipantWorkshops(const ParticipantList &participantList);

void registerForWorkshop(
    const WorkshopList &workshopList,
    ParticipantList &participantList,
    RegistrationManager &registration);

void cancelRegistration(
    const WorkshopList &workshopList,
    const ParticipantList &participantList,
    RegistrationManager &registration);

#endif