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

#ifndef REGISTRATION_MANAGER_H
#define REGISTRATION_MANAGER_H

#include "WorkshopList.h"
#include "ParticipantList.h"
#include <set>
#include <map>

class RegistrationManager
{
public:
    RegistrationManager(
        const WorkshopList &newWorkshopList, const ParticipantList &newParticipantList)
        : workshopList(newWorkshopList), participantList(newParticipantList) {}

    void addOpenWorkshop(int workshopNo);
    void registerParticipant(int workshopNo,
                             int participantID);
    void unregisterParticipant(int workshopNo,
                               int participantID);
    void closeWorkshop(int workshopNo);
    void reopenWorkshop(int workshopNo);

    bool isOpen(int workshopNo) const;

    const std::set<int>& getOpenWorkshops() const;

private:
    std::map<int, std::set<int>> registration;
    std::set<int> openWorkshops;
    const WorkshopList &workshopList;
    const ParticipantList &participantList;
};

#endif
