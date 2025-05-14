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

export module Interface;

export void processMenu(const WorkshopList& workshopList, 
  const ParticipantList& participantList, 
  const RegistrationManager& registrationManager);

export void getIdentification(
  int id, const std::string& firstName, const std::string& lastName);

export bool verifyIdentification(const ParticipantList& participantList, 
  int id, const std::string& firstName, const std::string& lastName);

export void viewAllWorkshops(const WorkshopList& workshopList);

export void viewOpenWorkshops(const WorkshopList& workshopList, 
  const RegistrationManager& registrationManager);

export void viewWorkshopsByPrice(const WorkshopList& workshopList);

export void viewParticipantWorkshops(const ParticipantList& participantList);

export void registerForWorkshop(const WorkshopList& workshopList,    
  const ParticipantList& participantList,
  const RegistrationManager& registration);

export void cancelWorkshop(const WorkshopList& workshopList,
  const ParticipantList&  participantList,
  const RegistrationManager& registration);


#endif     