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

#include "ParticipantList.h"

#include <algorithm>

using namespace std;

void ParticipantList::addParticipant(const Participant &participant)
{
    participantList.insert(
        pair<Participant, vector<Workshop>>(participant, {}));
}

// participant: Participant, workshop: Workshop
void ParticipantList::addWorkshopToParticipant(
    const Participant &participant, const Workshop &workshop)
{
    participantList[participant].push_back(workshop);
}

int ParticipantList::getID(const Participant &participant) const
{
    return participant.getID();
}

string ParticipantList::getFirstName(int participantID) const
{
    return findByID(participantID)->first.getFirstName();
}

string ParticipantList::getLastName(int participantID) const
{
    return findByID(participantID)->first.getLastName();
}

vector<Workshop> ParticipantList::getWorkshops(int participantID) const
{
    return findByID(participantID)->second;
}

const Participant &ParticipantList::getParticipant(int participantID) const
{
    return findByID(participantID)->first;
}

void ParticipantList::cancelWorkshop(int participantID, int workshopNo)
{
    Participant participant = getParticipant(participantID);
    auto participantIter = participantList.find(participant);

    vector<Workshop> &workshops = participantIter->second;

    auto workshopIter = remove_if(
        workshops.begin(), workshops.end(),
        [workshopNo](const Workshop &workshop)
        { return workshop.getNumber() == workshopNo; });

    workshops.erase(workshopIter);
}

bool ParticipantList::isEmpty() const
{
    return participantList.size() == 0;
}

void ParticipantList::clearList()
{
    participantList.clear();
}

map<Participant, vector<Workshop>>::const_iterator
ParticipantList::findByID(int participantID) const
{
    return find_if(
        participantList.begin(), participantList.end(),
        [participantID](const pair<Participant, vector<Workshop>> &element)
        { return element.first.getID() == participantID; });
}
