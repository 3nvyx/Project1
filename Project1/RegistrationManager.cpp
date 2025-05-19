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
	auto iter = find(workshopNo);
	
}

void RegistrationManager::unregisterParticipant(int workshopNo,
                               int participantID)
{

}

void RegistrationManager::closeWorkshop(int workshopNo)
{

}

void RegistrationManager::reopenWorkshop(int workshopNo)
{

}

bool RegistrationManager::isOpen(int workshopNo)
{

}

const std::set<int> &RegistrationManager::getOpenWorkshop()
{

}
