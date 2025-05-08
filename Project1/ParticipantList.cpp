/*
    Mew Mew

    Nguyen Tien Sy Doan, Kevin 
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

void ParticipantList::addParticipant(const Participant& participant)
{
    participantList.insert(pair<Participant, vector<Workshop>>(participant, {}));
}

// participant: Participant, workshop: Workshop
void ParticipantList::addWorkshopToParticipant(const Participant& participant, const Workshop& workshop)
{
    int participantId = participant.getId();
    findByID(participantId)->second.push_back(workshop);
}

int ParticipantList::getID(const Participant& participant) const
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

bool ParticipantList::isEmpty() const
{
    return participantList.size() == 0;
}

void ParticipantList::clearList()
{
    participantList.clear();
}

map<Participant, vector<Workshop>>::const_iterator ParticipantList::findById(int id) const
{
    auto participantListIter = participantList.begin();

  while (participantListIter != nullptr) 
  {
    if (participantListIter->first.getID() == id)
    {
      return participantListIter;
    }

    ++participantListIter;
  }
}