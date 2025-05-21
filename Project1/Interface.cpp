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

#include "Interface.h"
#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"
#include "Formatter.h"

#include <iostream>

using namespace std;

void processMenu(
    const WorkshopList &workshopList,
    ParticipantList &participantList,
    RegistrationManager &registrationManager)
{
    int choice{0};

    do
    {
        Formatter::displayMenu();
        cout << "Please make a selection: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            viewAllWorkshops(workshopList);
            break;
        case 2:
            viewOpenWorkshops(workshopList, registrationManager);
            break;
        case 3:
            viewWorkshopsByPrice(workshopList);
            break;
        case 4:
            registerForWorkshop(workshopList, participantList, registrationManager);
            break;
        case 5:
            viewParticipantWorkshops(participantList);
            break;
        case 6:
            cancelWorkshop(workshopList, participantList, registrationManager);
            break;
        case 7:
            cout << "Thank you for visiting!";
            break;
        default:
            cerr << "Invalid selection. Please try again." << endl;
        }

        if (choice != 7)
        {
            Formatter::pauseAndWait();
        }
    } while (choice != 7);
}

void getIdentification(
    int &id, string &firstName, string &lastName)
{
    cout << "Enter your ID: ";
    cin >> id;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;
    cout << endl;
}

bool verifyIdentification(
    const ParticipantList &participantList,
    int id, const string &firstName, const string &lastName)
{
    const Participant &participant = participantList.getParticipant(id);

    if (
        participant.getID() == id &&
        participant.getFirstName() == firstName &&
        participant.getLastName() == lastName)
    {
        return true;
    }

    return false;
}

void viewAllWorkshops(const WorkshopList &workshopList)
{
    Formatter::printAllWorkshops(workshopList);
}

void viewOpenWorkshops(
    const WorkshopList &workshopList,
    const RegistrationManager &registrationManager)
{
    Formatter::printOpenWorkshops(workshopList, registrationManager);
}

void viewWorkshopsByPrice(const WorkshopList &workshopList)
{
    double maxPrice{0.0};
    string priceInput;

    cout << "Enter max price: $";
    cin >> priceInput;

    // Remove $ if present
    if (!priceInput.empty() && priceInput[0] == '$')
    {
        priceInput.erase(0, 1);
    }

    maxPrice = stod(priceInput);

    Formatter::printWorkshopsByPrice(workshopList, maxPrice);
}

void viewParticipantWorkshops(const ParticipantList &participantList)
{
    int id{0};
    string firstName, lastName;
    getIdentification(id, firstName, lastName);

    if (verifyIdentification(participantList, id, firstName, lastName))
    {
        Formatter::printParticipantWorkshops(participantList, id);
    }
    else
    {
        cerr << "The ID number does not match the name provided." << "\n\n";
    }
}

void registerForWorkshop(
    const WorkshopList &workshopList,
    ParticipantList &participantList,
    RegistrationManager &registration)
{
    cout << "\tLet's register you for a workshop!" << "\n\n";

    viewOpenWorkshops(workshopList, registration);

    // Get workshop number
    cout << "Enter the workshop number or '0' to cancel: ";
    int workshopNumber{0};
    cin >> workshopNumber;
    cout << endl;

    // Run only if not cancelled
    if (workshopNumber != 0)
    {
        // Get identification info
        int id{0};
        string firstName, lastName;
        getIdentification(id, firstName, lastName);

        // Verify identification
        if (!verifyIdentification(participantList, id, firstName, lastName))
        {
            cerr << "The ID number does not match the name provided." << endl;
        }
        else
        {
            // Get selected workshop
            Workshop selectedWorkshop = workshopList.getWorkshop(workshopNumber);

            // Register participant
            registration.registerParticipant(workshopNumber, id);

            // Print confirmation
            cout << "You are registered for the following workshop:\n\n";
            Formatter::printWorkshop(selectedWorkshop);
            cout << "A confirmation email with payment details has been sent to you."
                 << "\n\n";
        }
    }
}

void cancelWorkshop(
    const WorkshopList &workshopList,
    const ParticipantList &participantList,
    RegistrationManager &registration)
{
    // Get identification info
    int id{0};
    string firstName, lastName;
    getIdentification(id, firstName, lastName);

    // Verify identification
    if (!verifyIdentification(participantList, id, firstName, lastName))
    {
        cerr << "The ID number does not match the name provided." << endl;
    }
    else
    {
        Formatter::printParticipantWorkshops(participantList, id);

        cout << "Which workshop would you like to cancel? ";
        int workshopNumber{0};
        cin >> workshopNumber;

        cout << "\nYour registration for the following workshop has been cancelled:\n";
        Formatter::printWorkshop(workshopList.getWorkshop(workshopNumber));

        // Unregister participant
        registration.unregisterParticipant(workshopNumber, id);

        // Confirmation message
        cout << "A confirmation email with refund details has been sent to you."
             << "\n\n";
    }
}
