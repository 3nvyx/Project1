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
    WorkshopList &workshopList, ifstream &file)
{
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;

        int number, hours, capacity;
        double price;
        string title;

        // parse number
        getline(ss, token, '|');
        number = stoi(token);

        // parse title
        getline(ss, title, '|');

        // parse hours
        getline(ss, token, '|');
        hours = stoi(token);

        // parse capacity
        getline(ss, token, '|');
        capacity = stoi(token);

        // parse price
        getline(ss, token, '|');
        price = stod(token);

        // Add to list
        workshopList.addWorkshop(
            Workshop(number, title,
                     hours, capacity, price));
    }
}

void DataLoader::loadParticipants(
    ParticipantList &participantList, ifstream &file)
{
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;

        int id;
        string firstName, lastName;

        // parse ID
        getline(ss, token, '|');
        id = stoi(token);

        // parse first name
        getline(ss, firstName, '|');

        // parse last name
        getline(ss, lastName, '|');

        // Add to list
        participantList.addParticipant(
            Participant(id, firstName, lastName));
    }
}
