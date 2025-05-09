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

#include "DataLoader.h"
#include "WorkshopList.h"
#include "Workshop.h"
#include <sstream>

void DataLoader::loadWorkshops(WorkshopList& workshopList, std::ifstream& file)
{
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;

        int number, hours, capacity;
        double price;
        std::string title;

        // parse number
        std::getline(ss, token, '|');
        number = std::stoi(token);

        // parse title
        std::getline(ss, title, '|');

        // parse hours
        std::getline(ss, token, '|');
        hours = std::stoi(token);

        // parse capacity
        std::getline(ss, token, '|');
        capacity = std::stoi(token);

        // parse price
        std::getline(ss, token, '|');
        price = std::stod(token);

        // Add to list
        workshopList.addWorkshop(Workshop(number, title, hours, capacity, price));
    }
}

