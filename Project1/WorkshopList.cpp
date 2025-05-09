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
#include "Workshop.h"

using namespace std;

void WorkshopList::addWorkshop(const Workshop& workshop)
{
	workshopList.insert(workshop);
}

int WorkshopList::getNumber(const Workshop& workshop) const
{
	return workshop.getNumber();
}

string WorkshopList::getTitle(int workshopNo) const
{
	auto iter = findByNumber(workshopNo);
	return (iter != workshopList.end()) ? iter->getTitle() : "Not found";
}

int WorkshopList::getHours(int workshopNo) const
{
	auto iter = findByNumber(workshopNo);
	return (iter != workshopList.end()) ? iter->getHours() : 0;
}

int WorkshopList::getCapacity(int workshopNo) const
{
	auto iter = findByNumber(workshopNo);
	return (iter != workshopList.end()) ? iter->getCapacity() : 0;
}

double WorkshopList::getPrice(int workshopNo) const
{
	auto iter = findByNumber(workshopNo);
	return (iter != workshopList.end()) ? iter->getPrice() : 0;
}

bool WorkshopList::isEmpty() const
{
	return workshopList.empty();
}

void WorkshopList::clearList()
{
	workshopList.clear();
}

std::set<Workshop>::iterator WorkshopList::findByNumber(int workshopNo) const
{
	auto iter = workshopList.cbegin();
	while (iter != workshopList.cend())
	{
		if (iter->getNumber() == workshopNo)
			return iter;
		++iter;
	}
	return workshopList.cend();
}

std::set<Workshop>::const_iterator WorkshopList::begin() const
{
	return workshopList.cbegin();
}

std::set<Workshop>::const_iterator WorkshopList::end() const
{
	return workshopList.cend();
}

