// ----------------------------- customerDB.h -------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// The purpose of creating a CustomerDB is to implement a customer data base
// for the rental store. The underlying data structure for this CustomerDB
// is open hash table.
// The CustomerDB holds customer objects, where each customer holds its
// transaction history.
// --------------------------------------------------------------------------
// Notes:
// The hash table will be automatically grow as it reaches
// the limit of number of element to be added. When hash table grows the number
// of elements to be added into it also grows. The open hashing is used so the
// should not be any collisions.
// --------------------------------------------------------------------------

#ifndef CUSTOMERDB_H
#define CUSTOMERDB_H

#include <iostream>
#include "customer.h"
using namespace std;


// CustomerDB class represents customer data base of rental store. It holds
// customer objects. This class provides ability to add new customers,
// add transaction history to a specific customer as well as display all the
// transaction history for a specific customer.
class CustomerDB
{
private:
    // array of pointers to linked list of customer objects
    std::forward_list<Customer>* customersData;   // hash table

    int arrSize; // the size of the array

    // limit of the number of elements to be added into hash table before it
    // grows bigger
    int numOfcustomersAdded;


public:
    // ------------------------- Constructor  --------------------------
    // Description:
    // Constructs and initializes CustomerDB object.
    // ------------------------------------------------------------------
    CustomerDB();


    // --------------------------- Destructor  --------------------------
    // Description:
    // Destroys CustomerDB object.
    // ------------------------------------------------------------------
    virtual ~CustomerDB();


    // ----------------------- isValidCustomer  ------------------------
    // Description:
    // Returns true if the customer exists in the customerDB,
    // false otherwise.
    // ------------------------------------------------------------------
    bool isValidCustomer(int id) const;


    // ------------------------- addNewCustomer  ------------------------
    // Description:
    // Inserts the Customer object into customerDB, if it is not already
    // existing in customerDB.
    // ------------------------------------------------------------------
    void addNewCustomer(const Customer &custmr);


    // ------------------- addNewTransactionToHistory  ------------------
    // Description:
    // Inserts new transaction to the Customer's transaction history.
    // ------------------------------------------------------------------
    void addNewTransactionToHistory(int id, const Transaction &tr);



    // ------------------------ printCustomerInfo  ----------------------
    // Description:
    // Outputs transaction history of the customer with the given id number.
    // ------------------------------------------------------------------
    void printCustomerInfo(int id) const;


private:
    // ----------------------- containsCustomer  ------------------------
    // Description:
    // Returns true if the customer already exists in the customerDB,
    // false otherwise.
    // ------------------------------------------------------------------
    bool containsCustomer(int bucket, int idNum) const;


    // --------------------------- growHashTale  --------------------------
    // Description:
    // Creates larger hash table then rebuckets the elements stored
    // in the older hash table to this newly created, the older hash table
    // then destroyed.
    // ------------------------------------------------------------------
    void growHashTale();

};
#endif //CUSTOMERDB_H
