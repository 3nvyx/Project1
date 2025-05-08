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

#include "WorkshopList.h"

using namespace std;

void WorkshopList::addWorkshop(const Workshop& workshop)
{
	workshopList.insert(Workshop);
}

int WorkshopList::getNumber(const Workshop& workshop) const
{
	return workshop.getNumber();
}

string WorkshopList::getTitle(int workshopNo) const
{
	iterator iter = workshopList.findbyNumber(workshopNo);
	*iter.getTitle();
}

int WorkshopList::getHours(int workshopNo) const
{
	iterator iter = workshopList.findbyNumber(workshopNo);
	*iter.getHours();
}

int WorkshopList::getCapacity(int workshopNo) const
{
	iterator iter = workshopList.findbyNumber(workshopNo);
	*iter.getCapacity();
}

double WorkshopList::getPrice(int workshopNo) const
{
	iterator iter = workshopList.findbyNumber(workshopNo);
	*iter.getPrice();
}

boolWorkshopList:: isEmpty() const
{
	return workshopList.size() == 0;
}

void clearList()
{
	workshopList.clear();
}

set<Workshop>::iterator findbyNumber(int workshopNo)
{
	iterator iter = workshopList.begin();
	bool found = false;
	while (!found)
	{
		if(*iter.getNumber() = workshopNo)
		{
			found = true;
		}
		else
		{
			++iter;
		}
	}
	return iter;
}
