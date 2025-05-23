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

#ifndef PARTICIPANTLIST_H
#define PARTICIPANTLIST_H

#include "Participant.h"
#include "Workshop.h"

#include <string>
#include <map>
#include <vector>

class ParticipantList
{
public:
	void addParticipant(const Participant &participant);
	void addWorkshopToParticipant(
		const Participant &participant,
		const Workshop &workshop);

	int getID(const Participant &participant) const;
	std::string getFirstName(int participantID) const;
	std::string getLastName(int participantID) const;
	const Participant &getParticipant(int participantID) const;
	std::vector<Workshop> getWorkshops(int participantID) const;

	void cancelWorkshop(int participantID, int workshopNo);

	bool isEmpty() const;

	void clearList();

private:
	std::map<Participant, std::vector<Workshop>>::const_iterator
	findByID(int participantID) const;

	std::map<Participant, std::vector<Workshop>> participantList;
};

#endif
