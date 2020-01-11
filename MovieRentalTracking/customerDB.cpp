// ----------------------------- customerDB.cpp -----------------------------
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

#include "customerDB.h"


// ------------------------- Constructor  --------------------------
// Description:
// Constructs and initializes CustomerDB object.
// ------------------------------------------------------------------
CustomerDB::CustomerDB()
{
    arrSize = 11; //initial size
    numOfcustomersAdded = 0;
    customersData = new std::forward_list<Customer>[arrSize];
}


// --------------------------- Destructor  --------------------------
// Description:
// Destroys CustomerDB object.
// ------------------------------------------------------------------
CustomerDB::~CustomerDB()
{
    delete[] customersData;
    customersData = nullptr;
    numOfcustomersAdded = 0;
    arrSize = 0;
}


// ----------------------- isValidCustomer  ------------------------
// Description:
// Returns true if the customer exists in the customerDB,
// false otherwise.
// ------------------------------------------------------------------
bool CustomerDB::isValidCustomer(int id) const
{
    return containsCustomer((id % arrSize), id);
} // end of isValidCustomer


// ----------------------- containsCustomer  ------------------------
// Description:
// Returns true if the customer already exists in the customerDB,
// false otherwise.
// ------------------------------------------------------------------
bool CustomerDB::containsCustomer(int bucket, int idNum) const
{
    for (auto &element : customersData[bucket])
    {
        if (element.getIDNumber() == idNum)
        {
            return true;
        }
    }
    return false;   // no customer with the given idNumber is in the bucket
} // end of containsCustomer


// ------------------------- addNewCustomer  ------------------------
// Description:
// Insert the given Customer object to the CustomerDB (hash table)
// if it does not exist there yet.
// ------------------------------------------------------------------
void CustomerDB::addNewCustomer(const Customer &custmr)
{
    if (numOfcustomersAdded == arrSize)
    {
        growHashTale();
    }
    int id = custmr.getIDNumber();
    int bucket = id % arrSize;
    if (customersData[bucket].empty() ||
        !containsCustomer(bucket, id))
    {
        // insert to the table
        customersData[bucket].push_front(custmr);
        numOfcustomersAdded++;
    }
} // end of addNewCustomer


// --------------------------- growHashTale  --------------------------
// Description:
// Creates larger hash table then rebuckets the elements stored
// in the older hash table to this newly created, the older hash table
// then destroyed.
// ------------------------------------------------------------------
void CustomerDB::growHashTale()
{
    int newSize = 2 * arrSize;
    std::forward_list<Customer>* grownHTable =
            new std::forward_list<Customer>[newSize];

    // loop through the original table and
    // rebucket the elements to the new table
    for (int i = 0; i < arrSize; i++)
    {
        if (!customersData[i].empty())
        {
            for (auto it = customersData[i].begin(); it != customersData[i].end(); it++)
            {
                int id = it->getIDNumber();
                int bucket = id % newSize;
                grownHTable[bucket].push_front(*it);
            }

        }
    }

    // delete the original table
    delete[] customersData;
    customersData = grownHTable;
    // update data members
    arrSize = newSize;

} //end of growHashTale


// ------------------- addNewTransactionToHistory  ------------------
// Description:
// Inserts new transaction to the Customer's transaction history.
// ------------------------------------------------------------------
void CustomerDB::addNewTransactionToHistory(int id, const Transaction &tr)
{
    int bucket = id % arrSize;
    for (auto &it : customersData[bucket])
    {
        if (it.getIDNumber() == id)
        {
            it.addToHistory(tr);
        }
    }
} // end of addNewTransactionToHistory


// ------------------------ printCustomerInfo  ----------------------
// Description:
// Outputs transaction history of the customer with the given id number.
// ------------------------------------------------------------------
void CustomerDB::printCustomerInfo(int id) const {

    int bucket = id % arrSize;
    if (!containsCustomer(bucket, id))
    {
        cerr << "\nCustomer with id " << id << " is not found"
             << std::endl;
        return;
    }

    if (!customersData[bucket].empty())
    {
        for (const auto &it : customersData[bucket])
        {
            if (it.getIDNumber() == id)
            {
                it.printCustomerHistory();
            }
        }
    }
} // end of printCustomerInfo