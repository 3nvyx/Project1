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

#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include "WorkshopList.h"
#include "ParticipantList.h"

class RegistrationManager
{
public:
    RegistrationManager(const &newWorkshopList, 
        const ParticipantList &newParticipantList)
        : workshopList(newWorkshopList), 
        participantList(newParticipantList) {}

    void addOpenWorkshop(int workshopNo);
    void registerParticipant(int workshopNo,
        int participantID);
    void unregisterParticipant(int workshopNo, 
        int participantID);
    void closeWorkshop(int workshopNo);
    void reopenWorkshop(int workshopNo);

    bool isOpen(int workshopNo);

    const set<int>& getOpenWorkshop();

private:
    std::map<int, std::set<int>> registration;
    std::set<int> openWorkshops;
    const WorkshopList& workshopList;
    ParticipantList& participantList;
}
