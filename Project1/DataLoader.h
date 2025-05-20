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

#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <fstream>
#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"

class DataLoader
{
public:
	static void loadWorkshops(WorkshopList& workshopList, 
		const std::string& filename);
	static void loadParticipants(ParticipantList& participantList, 
		const std::string& filename);
	static void loadRegistration(RegistrationManager& regManager, 
		const std::string& filename);
};

#endif
