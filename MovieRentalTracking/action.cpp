// ------------------------------ action.cpp --------------------------------
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


#include "action.h"
#include "transaction.h"
#include <string>

// ------------------- default Constructor / Destructor -------------
// Description:
// Constructs and initializes the Action.
// Destructs the object.
// ------------------------------------------------------------------
Action::Action() {
}

Action::~Action() {}


// -------------------------- processCommands -----------------------
// Description:
// Processes the input string, if the format is valid performs the
// required operations, such as print the store inventory, print
// transaction history and borrow or return movie.
//
// If the input is invalid then error message is outputted and the
// command is discarded.
// ------------------------------------------------------------------
void Action::processCommands(std::string fileName, InventoryDB &storeInv,
        CustomerDB &storeCustomers)
{
    fstream file(fileName);
    if (file.fail())
    {
        cerr << "Can't find commands file: " << fileName << endl;
        return;
    }


    while (!file.eof())
    {

        char actionType;
        std::string command;
        std::string idNum;

        std::string wholeLine;
        getline(file, wholeLine);
        auto position = wholeLine.find('\r');
        if (position != std::string::npos)
        {
            wholeLine = wholeLine.substr(0, position);
        }

        if (wholeLine.length() == 0)
        {
            continue;
        }
        // read first char (action type) in command line
        actionType = wholeLine[0];


        // if line contains only action and it is invalid, then discarding
        // the command
        if (wholeLine.length() == 1 &&
            (actionType != 'H' && actionType != 'B' && actionType != 'R' &&
            actionType != 'I'))
        {
            //action type is incorrect
            cerr << "\nInvalid Command type: " << actionType << endl;
            continue;
        }


        command = wholeLine.substr(1, wholeLine.length());

        if (actionType != 'I')
        {
            command = command.substr(1, command.length());
            // will assign the characters until finds space
            idNum = command.substr(0, command.find(' '));
        }


        switch (actionType)
        {
            case 'I':
            {
                storeInv.printInventory();
                break;
            }
            case 'H':
            {
                storeCustomers.printCustomerInfo(std::stoi(idNum));
                break;
            }
            case 'B':
            case 'R':
            {
                if (storeCustomers.isValidCustomer(std::stoi(idNum)))
                {
                    //NOTE: after first char (action type) was extracted from
                    // line the rest of the line will be past into
                    // borrowInventory and returnInventory
                    //Transaction transaction();
                    Transaction staticT;
                    bool createdT = createTransaction(staticT, command,
                            actionType, std::stoi(idNum));
                    if (createdT)
                    {
                        bool isTransactionValid = storeInv.makeTransaction(staticT);
                        if (isTransactionValid)
                        {
                            storeCustomers.addNewTransactionToHistory(std::stoi(idNum), staticT);
                        }
                    }

                }
                else
                { // invalid customer id
                    cerr << "\nInvalid Command - Customer Not Found: "
                        << actionType << " " << command << endl;
                }
                break;
            }
            default:
                //action type is incorrect
                cerr << "\nInvalid Command type: " << actionType
                    << " " << command <<
                    "\nIncorrect action: \'" << actionType << "\'" << endl;

        } //end of switch

    } // end of while

    file.close();

} // end of processCommands

