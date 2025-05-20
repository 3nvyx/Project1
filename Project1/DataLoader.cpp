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

#include "DataLoader.h"

#include <sstream>

using namespace std;

void DataLoader::loadWorkshops(
    WorkshopList &workshopList, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Could not open " << filename << "\n";
    }
    else
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string token;

            int number, hours, capacity;
            double price;
            string title;

            getline(ss, token, '|');
            number = stoi(token);
            getline(ss, title, '|');
            getline(ss, token, '|');
            hours = stoi(token);
            getline(ss, token, '|');
            capacity = stoi(token);
            getline(ss, token, '|');
            price = stod(token);

            workshopList.addWorkshop(
                Workshop(number, title, hours, capacity, price));
        }
    }
}

void DataLoader::loadParticipants(
    ParticipantList &participantList, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Could not open " << filename << "\n";
    }
    else
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string token;
            int id;
            string firstName, lastName;

            getline(ss, token, '|');
            id = stoi(token);
            getline(ss, firstName, '|');
            getline(ss, lastName, '|');

            participantList.addParticipant(
                Participant(id, firstName, lastName));
        }
    }
}

void DataLoader::loadRegistration(
    RegistrationManager &regManager, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Could not open " << filename << "\n";
    }
    else
    {
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string token;

            if (!getline(ss, token, '|'))
                continue;

            int workshopNo = stoi(token);
            regManager.addOpenWorkshop(workshopNo);

            while (getline(ss, token, '|'))
            {
                if (token.empty())
                    continue;

                int participantID = stoi(token);
                regManager.registerParticipant(workshopNo, participantID);
            }
        }
    }
}
