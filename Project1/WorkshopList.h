/*
	Mew Mew

	Doan, Kevin (Team Leader)
	Nguyen, Long (Eric)
	Truong, Jeffrey
	Vu, Richard

	Spring 2025
	CS A250 - C++ 2

	Workshop Hub
*/

#ifndef WORKSHOPLIST_H
#define WORKSHOPLIST_H

#include "Workshop.h"

#include <set>

class WorkshopList
{
public:
	void addWorkshop(const Workshop &workshop);

	int getNumber(const Workshop &workshop) const;
	std::string getTitle(int workshopNo) const;
	int getHours(int workshopNo) const;
	int getCapacity(int workshopNo) const;
	double getPrice(int workshopNo) const;
	const Workshop &getWorkshop(int workshopNo) const;
	const std::set<Workshop> &getAllWorkshops() const;

	bool isEmpty() const;
	void clearList();

private:
	std::set<Workshop>::const_iterator findByNumber(int workshopNo) const;

	std::set<Workshop> workshopList;
};

#endif