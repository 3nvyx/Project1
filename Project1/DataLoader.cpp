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
            stringstream stream(line);
            string token;

            int number, hours, capacity;
            double price;
            string title;

            getline(stream, token, '|');
            number = stoi(token);
            getline(stream, title, '|');
            getline(stream, token, '|');
            hours = stoi(token);
            getline(stream, token, '|');
            capacity = stoi(token);
            getline(stream, token, '|');
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
            stringstream stream(line);
            string token;
            int id;
            string firstName, lastName;

            getline(stream, token, '|');
            id = stoi(token);
            getline(stream, firstName, '|');
            getline(stream, lastName, '|');

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
        cout << "Could not open " << filename << "\n";
    }
    else
    {
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream stream(line);
            string token;

            if (!getline(stream, token, '|'))
                continue;

            int workshopNo = stoi(token);
            regManager.addOpenWorkshop(workshopNo);

            while (getline(stream, token, '|'))
            {
                if (token.empty())
                    continue;

                int participantID = stoi(token);
                regManager.registerParticipant(workshopNo, participantID);
            }
        }
    }
}
