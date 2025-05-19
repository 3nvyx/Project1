#include "Interface.h"
#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"
#include "Formatter.h"

#include <iostream>
#include <string>

using namespace std;

void processMenu(
    const WorkshopList &workshopList,
    ParticipantList &participantList,
    RegistrationManager &registrationManager)
{
  int choice;

  do
  {
    Formatter::displayMenu();
    cout << "Please make a selection: ";
    cin >> choice;

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
      cout << "Thank you for visiting!" << endl;
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
    int &id, std::string &firstName, std::string &lastName)
{
  cout << "Enter your ID: ";
  cin >> id;

  cout << "Enter your first name: ";
  cin >> firstName;

  cout << "Enter your last name: ";
  cin >> lastName;
}

bool verifyIdentification(
    const ParticipantList &participantList,
    int id, const std::string &firstName, const std::string &lastName)
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
  double maxPrice = 0.0;
  string priceInput;

  cout << "Enter max price: ";
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
  int id;
  std::string firstName, lastName;
  getIdentification(id, firstName, lastName);

  if (verifyIdentification(participantList, id, firstName, lastName))
  {
    Formatter::printParticipantWorkshops(participantList, id);
  }
  else
  {
    cerr << "The ID number does not match the name provided." << endl;
  }
}

void registerForWorkshop(
    const WorkshopList &workshopList,
    ParticipantList &participantList,
    RegistrationManager &registration)
{
  cout << "Let's register you for a workshop!" << endl;

  viewOpenWorkshops(workshopList, registration);

  // Get workshop number
  cout << "Enter the workshop number or '0' to cancel: ";
  int workshopNumber;
  cin >> workshopNumber;

  // Run only if not cancelled
  if (workshopNumber != 0)
  {
    // Get identification info
    int id{0};
    std::string firstName, lastName;
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
      participantList.addWorkshopToParticipant(participantList.getParticipant(id), selectedWorkshop);
      registration.registerParticipant(id, workshopNumber);

      // Print confirmation
      cout << "You are registered for the following workshop:" << endl;
      Formatter::printWorkshop(selectedWorkshop);
      cout << "A confirmation email with payment details has been sent to you." << endl;
    }
  }
}

void cancelWorkshop(
    const WorkshopList &workshopList,
    const ParticipantList &participantList,
    RegistrationManager &registration)
{
  // Get identification info
  int id;
  std::string firstName, lastName;
  getIdentification(id, firstName, lastName);

  // Verify identification
  if (!verifyIdentification(participantList, id, firstName, lastName))
  {
    cerr << "The ID number does not match the name provided." << endl;
  }
  else
  {
    cout << "Which workshop would you like to cancel? ";
    int workshopNumber;
    cin >> workshopNumber;

    cout << "Your registration for the following workshop has been cancelled:" << endl;
    Formatter::printWorkshop(workshopList.getWorkshop(workshopNumber));

    // Unregister participant
    registration.unregisterParticipant(id, workshopNumber);

    // Confirmation message
    cout << "A confirmation email with refund details has been sent to you." << endl;
  }
}
