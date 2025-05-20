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

#include "Workshop.h"
#include "WorkshopList.h"

using namespace std;

void WorkshopList::addWorkshop(const Workshop &workshop)
{
	workshopList.insert(workshop);
}

int WorkshopList::getNumber(const Workshop &workshop) const
{
	return workshop.getNumber();
}

string WorkshopList::getTitle(int workshopNo) const
{
	return findByNumber(workshopNo)->getTitle();
}

int WorkshopList::getHours(int workshopNo) const
{
	return findByNumber(workshopNo)->getHours();
}

int WorkshopList::getCapacity(int workshopNo) const
{
	return findByNumber(workshopNo)->getCapacity();
}

double WorkshopList::getPrice(int workshopNo) const
{
	return findByNumber(workshopNo)->getPrice();
}

bool WorkshopList::isEmpty() const
{
	return workshopList.empty();
}

void WorkshopList::clearList()
{
	workshopList.clear();
}

const Workshop &WorkshopList::getWorkshop(int workshopNo) const
{
	auto found = findByNumber(workshopNo);
	if (found != workshopList.end())
	{
		return *found;
	}
}

const set<Workshop> &WorkshopList::getAllWorkshops() const
{
	return workshopList;
}

set<Workshop>::const_iterator
WorkshopList::findByNumber(int workshopNo) const
{
	return find_if(
		workshopList.begin(), workshopList.end(),
		[workshopNo](const Workshop &workshop)
		{ return workshop.getNumber() == workshopNo; });
}