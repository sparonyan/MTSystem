// -------------------------------- action.h --------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents an action objects that provides a public method processCommands,
// which is used to process the input file with commands and make transactions
// for the rental store.
// --------------------------------------------------------------------------
// Notes:
// If the input is invalid the error message will be displayed to user and
// that command action will be discarded.
// --------------------------------------------------------------------------

#ifndef CPLUSPLUSDIR_ACTION_H
#define CPLUSPLUSDIR_ACTION_H

#include <string>
#include <iostream>
#include <fstream>
#include "customerDB.h"
#include "inventoryDB.h"
using namespace std;


// Provides a public interface for processing the commands file and to perform
// transaction.
class Action
{
public:

    // ------------------- default Constructor / Destructor -------------
    // Description:
    // Constructs and initializes the Action.
    // Destructs the object.
    // ------------------------------------------------------------------
    Action();
    virtual ~Action();


    // -------------------------- processCommands -----------------------
    // Description:
    // Processes the input string, if the format is valid performs the
    // required operations, such as print the store inventory, print
    // transaction history and borrow or return movie.
    //
    // If the input is invalid then error message is outputted and the
    // command is discarded.
    // ------------------------------------------------------------------
    void processCommands(std::string fileName, InventoryDB &storeInv,
            CustomerDB &storeCustomers);
};




#endif //CPLUSPLUSDIR_ACTION_H
