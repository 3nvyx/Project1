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

#ifndef PARTICIPANT_LIST_H
#define PARTICIPANT_LIST_H

#include <string>
#include <map>
#include <vector>
#include "Participant.h"
#include "Workshop.h"

class ParticipantList {
public:
	void addParticipant(const Participant&);
	void addWorkshopToParticipant(const Participant& , const Workshop&);
	int getID(const Participant&) const;
	std::string getFirstname(int) const;
	std::string getLastName(int) const;
	std::vector<Workshop> getWorkshops(int) const;
	bool isEmpty() const;
	void clearList();
	std::map<Participant, std::vector<Workshop>>::const_iterator findByID(int) const;
private:
	std::map<Participant, std::vector<Workshop>> participantList;
};

#endif
