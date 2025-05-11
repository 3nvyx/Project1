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

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>

class Participant
{
public:
	Participant(int newId, std::string newFirstName, std::string newLastName)
			: id(newId), firstName(newFirstName), lastName(newLastName) {}
	int getID() const { return id; }
	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }
	bool operator<(const Participant &participant) const { return id < participant.id; }
	~Participant() {};

private:
	int id;
	std::string firstName;
	std::string lastName;
};

#endif
