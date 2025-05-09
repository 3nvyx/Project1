#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <fstream>
#include "Workshop.h"
#include "WorkshopList.h"

class DataLoader
{
public:
	static void loadWorkshops(WorkshopList& workshopList, std::ifstream& file);
};

#endif