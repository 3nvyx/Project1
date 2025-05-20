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
    WorkshopList& workshopList,
    const string& filename)
{
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open " << filename << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        int number, hours, capacity;
        double price;
        string title;

        getline(ss, token, '|');
        number = stoi(token);
        getline(ss, title, '|');
        getline(ss, token, '|'); hours = stoi(token);
        getline(ss, token, '|'); capacity = stoi(token);
        getline(ss, token, '|'); price = stod(token);

        workshopList.addWorkshop(
            Workshop(number, title, hours, capacity, price)
        );
    }
}

void DataLoader::loadParticipants(
    ParticipantList& participantList,
    const string& filename)
{
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open " << filename << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        int id;
        string firstName, lastName;

        getline(ss, token, '|'); id = stoi(token);
        getline(ss, firstName, '|');
        getline(ss, lastName, '|');

        participantList.addParticipant(
            Participant(id, firstName, lastName)
        );
    }
}

void DataLoader::loadRegistration(
    RegistrationManager& regManager,
    const string& filename)
{
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open " << filename << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        // 1) Read the workshop number
        if (!getline(ss, token, '|'))
            continue;

        int workshopNo;
        try {
            workshopNo = stoi(token);
        }
        catch (invalid_argument&) {
            // malformed workshop number → skip line
            continue;
        }

        // 2) Always add the workshop as open,
        //    even if there are zero registrations on this line.
        regManager.addOpenWorkshop(workshopNo);

        // 3) Now consume _all_ remaining tokens as possible participant IDs
        while (getline(ss, token, '|')) {
            if (token.empty()) {
                // skip blank entries
                continue;
            }
            int participantID;
            try {
                participantID = stoi(token);
            }
            catch (invalid_argument&) {
                // skip any non-numeric token
                continue;
            }
            regManager.registerParticipant(workshopNo, participantID);
        }
    }
}
