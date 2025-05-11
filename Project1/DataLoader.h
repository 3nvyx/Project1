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
#include "Workshop.h"
#include "WorkshopList.h"

class DataLoader
{
public:
	static void loadWorkshops(WorkshopList &workshopList, std::ifstream &file);
};

#endif