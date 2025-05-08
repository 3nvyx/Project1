#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <fstream>

class DataLoader
{
	static void loadWorkshops(workshopList& WorkshopList, ifstream& file);
}

#endif