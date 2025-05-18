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
    participantList.insert(pair<Participant, vector<Workshop>>(participant, {}));
}

// participant: Participant, workshop: Workshop
void ParticipantList::addWorkshopToParticipant(const Participant &participant, const Workshop &workshop)
{
    participantList[participant].push_back(workshop);
}

int ParticipantList::getID(const Participant &participant) const
{
    return participant.getID();
}

string ParticipantList::getFirstName(int id) const
{
    return findByID(id)->first.getFirstName();
}

string ParticipantList::getLastName(int id) const
{
    return findByID(id)->first.getLastName();
}

vector<Workshop> ParticipantList::getWorkshops(int id) const
{
    return findByID(id)->second;
}

const Participant &ParticipantList::getParticipant(int id) const
{
    return findByID(id)->first;
}

void ParticipantList::cancelWorkshop(int id, int workshopNo)
{
    vector<Workshop> workshops = getWorkshops(id);
    remove_if(workshops.begin(), workshops.end(),
              [workshopNo](Workshop workshop)
              { return workshop.getNumber() == workshopNo; });
}

bool ParticipantList::isEmpty() const
{
    return participantList.size() == 0;
}

void ParticipantList::clearList()
{
    participantList.clear();
}

std::map<Participant, std::vector<Workshop>>::const_iterator ParticipantList::findByID(int id) const
{
    return find_if(participantList.begin(), participantList.end(),
                   [id](const pair<Participant, vector<Workshop>> &element)
                   {
                       return element.first.getID() == id;
                   });
}
