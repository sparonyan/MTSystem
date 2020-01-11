// ---------------------------- customer.h -----------------------------------
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

#ifndef CPLUSPLUSDIR_CUSTOMER_H
#define CPLUSPLUSDIR_CUSTOMER_H

#include <string>
#include <iostream>
#include<forward_list> // using linkedlist for transaction history
#include "transaction.h"
using namespace std;

// The Customer class represents a single customer of the rental store.
// Each customer object hold the transaction history for that specific
// customer.
class Customer
{
private:
    // unique ID number
    int idNumber;
    std::string lastName;
    std::string firstName;

    // linkedList of customer transaction history (borrow and returns)
    std::forward_list<Transaction> history;



public:
    // ---------------------- Customer Constructors ---------------------
    // Description:
    // Construct and initialize Customer object.
    // ------------------------------------------------------------------
    Customer();

    // constructs object from the read line, from the file.
    // the input file must be formatted in the following order:
    // 4-digit uniqe ID, lastname and name, all separeted by space.
    Customer(std::string &inLine);


    // ------------------------- Customer Destructor --------------------
    // Description:
    // Destroys Customer object.
    // ------------------------------------------------------------------
    virtual ~Customer();


    // ---------------------------- getIDNumber  ------------------------
    // Description:
    // Returns the 4 digit id number of this Customer.
    // ------------------------------------------------------------------
    int getIDNumber() const;


    // --------------------------- getFirstName -------------------------
    // Description:
    // Returns the firstname of this Customer.
    // ------------------------------------------------------------------
    std::string getFirstName() const;


    // -------------------------- getLAstName ---------------------------
    // Description:
    // Returns the lastname of this Customer.
    // ------------------------------------------------------------------
    std::string getLastName() const;


    // ------------------------ addTransaction --------------------------
    // Description:
    //  Adds the line representing the transaction that is read from
    // the command file to this customers history of transactions.
    // ------------------------------------------------------------------
    void addToHistory(const Transaction &transaction);


    // ------------------------- printCustomerHistory -------------------
    // Description:
    // Outputs this Customer's transaction history.
    // ------------------------------------------------------------------
    void printCustomerHistory() const;

};

#endif //CPLUSPLUSDIR_CUSTOMER_H
