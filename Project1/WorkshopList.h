
#ifndef WORKSHOPLIST_H
#define WORKSHOPLIST_H

#include <iostream>
#include <string>
#include <set>
#include "Workshop.h"

class WorkshopList
{
public:
	void addWorkshop(const Workshop& workshop);
	int getNumber(const Workshop& workshop) const;
	std::string getTitle(int workshopNo) const;
	int getHours(int workshopNo) const;
	int getCapacity(int workshopNo) const;
	double getPrice(int workshopNo) const;
	bool isEmpty() const;
	void clearList();
	std::set<Workshop>::iterator findbyNumber(int workshopNo) const;
	~WorkshopList() {}

private:
	std::set<Workshop> workshopList;
	
};

#endif