// ---------------------------- customer.cpp --------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// The Customer class is created to be used in CustomerDB implementation.
// Each customer object hold the transaction history for that specific
// customer.
// --------------------------------------------------------------------------
// Notes:
// Each customer is assigned a unique 4-digit id number and this id number
// will be read in from a file with first and last name.
// --------------------------------------------------------------------------


#include "customer.h"
#include <sstream> // to use stream buffer for historyNode output
#include <iomanip>  // using to format output


// ------------------ Customer default Constructor ------------------
// Description:
// Constructs and initializes Customer object.
// ------------------------------------------------------------------
Customer::Customer()
{
}

// ------------------ Customer(string &) Constructor ----------------
// Description:
// Constructs object from the read line, from the file.
// the input file must be formatted in the following order:
// 4-digit uniqe ID, lastname and name, all separeted by space.
// ------------------------------------------------------------------
Customer::Customer(std::string &inLine)
{
    std::string idNum;
    std::string lName;
    std::string fName;

    stringstream str(inLine);
    str >> idNum >> lName >> fName;

    this->idNumber = std::stoi(idNum);
    this->lastName = lName;
    this->firstName = fName;
}


// --------------------- Customer Destructor ---------------------
// Description:
// Destroys Customer object.
// ------------------------------------------------------------------
Customer::~Customer()
{
    history.clear();
}


// ---------------------------- getIDNumber  ------------------------
// Description:
// Returns the 4 digit id number of this Customer.
// ------------------------------------------------------------------
int Customer::getIDNumber() const
{
    return idNumber;
}


// --------------------------- getFirstName -------------------------
// Description:
// Returns the firstname of this Customer.
// ------------------------------------------------------------------
std::string Customer::getFirstName() const
{
    return firstName;
}


// -------------------------- getLAstName ---------------------------
// Description:
// Returns the lastname of this Customer.
// ------------------------------------------------------------------
std::string Customer::getLastName() const
{
    return lastName;
}


// ------------------------ addTransaction --------------------------
// Description:
//  Adds the line representing the transaction that is read from
// the command file to this customers history of transactions.
// ------------------------------------------------------------------
void Customer::addToHistory(const Transaction &transaction)
{
    history.push_front(transaction);
}


// --------------------- printCustomerHistory -----------------------
// Description:
//  Outputs this Customer's transaction history in the format:
//
//  Customer transaction history
//  ID: (4digit ID)   firstname lastname
//  actionType    mediaType    movieGenre    movieTitle,    releaseDate
//
//  NOTE: actionType - borrow or return,
//        mediaType - DVD
// ------------------------------------------------------------------
void Customer::printCustomerHistory() const
{
    std::cout << std::endl;
    std::cout << "= Transaction history =" << std::endl;

    std::cout << "ID: " << getIDNumber() << "  "
              << getFirstName() << " " << getLastName()
              << std::endl;

    if (history.empty())
    {
        std::cout << "- No Transaction history found"
            << std::endl;
        return;
    }

    std::cout << "------" << "    " << "---" << "    "
              << "--------" << "    -----------------------------" << "   "
              << "-------"  << "    ---------------------------"
              << std::endl;
    for (const auto &it : history)
    {

        std::cout << it.getTransactionInfo() << std::endl;

    }
}

