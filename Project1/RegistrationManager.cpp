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

#include "RegistrationManager.h"

using namespace std

void RegistrationManager::addOpenWorkshop(int workshopNo)
{
	openWorkshops.insert(workshopNo);
	registration.insert(worshopNo, set<int> participantIDs {});
}

void RegistrationManager::registerParticipant(int workshopNo,
                             int participantID)
{
	*registration.find(workshopNo).insert(participantID);
	participantList.addWorkshopToParticipant(
		participantList.getParticipant(participantID), 
		workshopList.getWorkshop(workshopNo));
	if (*registration.find(workshopNo).second.size() 
		>= workshopList.getWorkshop(workshopNo).getCapacity())
	{
		openWorkshops.closeWorkshop(workshopNo);
	}
	
}

void RegistrationManager::unregisterParticipant(int workshopNo,
                               int participantID)
{
	*registration.find(workshopNo).erase(participantID);
	if (*registration.find(workshopNo).second.size() 
		< workshopList.getWorkshop(workshopNo).getCapacity()
	{
		openWorkshops.reopenWorkshops(workshopNo);
	}
	participantList.cancelWorkshop(participantID, workshopNo);
}

void RegistrationManager::closeWorkshop(int workshopNo)
{
	openWorkshops.erase(workshopNo);
}

void RegistrationManager::reopenWorkshop(int workshopNo)
{
	openWorkshops.insert(workshopNo);
}

bool RegistrationManager::isOpen(int workshopNo) const
{
	return openWorkshop.find(workshopNo) != openWorkshop.end();
}

const std::set<int>& RegistrationManager::getOpenWorkshop() const
{
	return openWorkshop;
}
