// ---------------------------- inventoryDB.cpp -----------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// InventoryDB implements the inventory database for the rental store.
// The inventory (movies with genre Comedy, Classics or Drama) for the store
// is read from a file.
//
// This class provides a public interface to check if the transaction to be
// made is valid or not, if valid then make transaction and update the data
// base and if not then notify with error message and discard.
// --------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// The underlying data structures are three sorted sets (treesets) for each
// movie genre. The overloaded operators< for each movie genre is used by sets
// to store objects in required sorted order.
// --------------------------------------------------------------------------


#include "inventoryDB.h"

// ---------------- default Constructor/ Destructor  ----------------
// Description:
// Constructs and initializes InventoryDB.
// Destructs InventoryDB
// ------------------------------------------------------------------

InventoryDB::InventoryDB() {}


InventoryDB::~InventoryDB() {}


// ------------------------- addClassicsInventory -------------------
// Description:
// Inserts a valid classic movie into the InventoryDB.
// Note:
// The valid input must have the format:
// C, Stock, Director, Title, Major actor releaseMonth releaseYear
// ------------------------------------------------------------------
void InventoryDB::addClassicsInventory(const Classics& cl)
{
    // uses classics's overriden operator< to insert in the sorted order
    classicsInv.insert(cl);
}


// -------------------------- addComedyInventory  -------------------
// Description:
// Inserts a valid comedy movie into the InventoryDB.
// Note:
// The valid input must have the format:
// F, Stock, Director, Title, releaseYear
// ------------------------------------------------------------------
void InventoryDB::addComedyInventory(const Comedy& cmd)
{
    // uses comedy's overriden operator< to insert in the sorted order
    comedyInv.insert(cmd);
}


// ------------------------ addDramaInventory -----------------------
// Description:
// Inserts a valid drama movie into the InventoryDB.
// Note:
// The valid input must have the format:
// D, Stock, Director, Title, releaseYear
// ------------------------------------------------------------------
void InventoryDB::addDramaInventory(const Drama& dr)
{
    // uses drama's overriden operator< to insert in the sorted order
    dramaInv.insert(dr);
}



// ---------------------- isValidTransaction ------------------------
// Description:
// Returns true if the transaction to be made is valid.
// A valid transaction can borrow or return a movie item. If this
// InventoryDB contains a movie to be borrowed or returned then the
// transaction is valid.
bool InventoryDB::makeTransaction(Transaction &transaction)
{
    char transType = transaction.getActionType();
    char movieType = transaction.getMovieGenreType();

    switch (movieType)
    {
        case 'C':
        {  // Classics
            int month = transaction.getReleaseMonth();
            int year = transaction.getReleaseYear();
            string actor = transaction.getMajorActor();

            for (auto &it : classicsInv)
            {
                if (it.containsActor(actor) &&
                    it.getReleaseMonth() == month &&
                    it.getReleaseYear() == year)
                {
                    auto clItem = it;
                    classicsInv.erase(it);

                    // update transaction info (add movie title)
                    transaction.setMovieTitle(clItem.getTitle());

                    // BORROW if stock is >= 1
                    if (transType == 'B')
                    {

                        // if borrow required and stock is at least 1
                        // then borrow transaction can be done
                        int qty = clItem.getStock();
                        if (qty >= 1)
                        {
                            clItem.setStock(qty - 1);  // movie is BORROWed
                        }
                        else
                        {
                            cerr << "\nInvalid Command: - Item is out of stock\n"
                                 << transaction.getTransactionInfo() << endl;

                            classicsInv.insert(clItem);
                            return false;
                        }
                        classicsInv.insert(clItem);
                        return true;
                    }
                    else
                    { //RETURN to stock

                        int qty = clItem.getStock();
                        clItem.setStock(qty + 1); // movie is RETURNed
                        classicsInv.insert(clItem);
                        return true;
                    }

                }
            }
            cerr << "\nInvalid Command - movie is not found\n"
                 << transaction.getClassicsMovieCommand()<< endl;
            break;
        } // transaction for Classics movies

        case 'D':
        { // Drama

            std::string dir = transaction.getMovieDirector();
            std::string mTitle = transaction.getMovieTitle();

            for (auto &it : dramaInv)
            {
                if (it.getDirector() == dir &&
                    it.getTitle() == mTitle)
                {
                    auto drItem = it;
                    dramaInv.erase(it);

                    // update transaction info (add release year )
                    transaction.setReleaseYear(drItem.getReleaseYear());


                    // BORROW if stock is >= 1
                    if (transType == 'B')
                    {
                        // if borrow required and stock is at least 1
                        // then borrow transaction can be done
                        int qty = drItem.getStock();
                        if (qty >= 1)
                        {
                            drItem.setStock(qty - 1);  // movie is BORROWed
                        }
                        else
                        {
                            cerr << "\nInvalid Command - Item is out of stock\n"
                                 << transaction.getTransactionInfo() << endl;

                            dramaInv.insert(drItem);
                            return false;
                        }
                        dramaInv.insert(drItem);
                        return true;
                    }
                    else
                    { //RETURN to stock

                        int qty = drItem.getStock();
                        drItem.setStock(qty + 1); // movie is RETURNed
                        dramaInv.insert(drItem);
                        return true;
                    }
                }
            }
            cerr << "\nInvalid Command - movie is not found\n"
                << transaction.getDramaMovieCommand() << endl;
            break;
        }

        case 'F':
        { // Comedy

            std::string mTitle = transaction.getMovieTitle();
            int year = transaction.getReleaseYear();

            for (auto &it : comedyInv)
            {
                if (it.getTitle() == mTitle &&
                    it.getReleaseYear() == year)
                {
                    auto comItem = it;
                    comedyInv.erase(it);
                    // BORROW if stock is >= 1
                    if (transType == 'B')
                    {
                        // if borrow required and stock is at least 1
                        // then borrow transaction can be done
                        int qty = comItem.getStock();
                        if (qty >= 1)
                        {
                            comItem.setStock(qty - 1);  // movie is BORROWed
                        }
                        else
                        {
                            cerr << "\nInvalid Command: - Item is out of stock\n"
                                 << transaction.getTransactionInfo() << endl;

                            comedyInv.insert(comItem);
                            return false;
                        }
                        comedyInv.insert(comItem);
                        return true;
                    }
                    else
                    { //RETURN to stock

                        int qty = comItem.getStock();
                        comItem.setStock(qty + 1); // movie is RETURNed
                        comedyInv.insert(comItem);
                        return true;
                    }
                }
            }
            cerr << "\nInvalid Command - movie is not found\n"
                 << transaction.getComedyMovieCommand() << endl;
            break;
        }
        default:
            break;
    } //end of switch
    return false; // incorrect information for the transaction

} // end of makeTransaction



// -------------------------- printInventory -------------------------
// Description:
// Outputs all Comedy movies, then all Dramas, then all Classics.
// Each category of movies is ordered according to the sorting criteria.
// ------------------------------------------------------------------
void InventoryDB::printInventory()
{
    // Comedy movies inventroy
    if (!comedyInv.empty())
    {
        std::cout << std::endl;
        std::cout << "All Comedy Movies: " << std::endl;
        std::cout << "Stock      Title                             " <<
                  "Director             Released" << std::endl;
        std::cout << "-----    -------------------------------- " <<
                  "  --------------------  ---------" << std::endl;

        for (auto it = comedyInv.begin(); it != comedyInv.end(); it++)
        {
            std::cout << *it << std::endl;
        }
    }

    // print drama movies inventory
    if (!dramaInv.empty())
    {
        std::cout << std::endl;
        std::cout << "All Drama Movies: " << std::endl;
        std::cout << "Stock      Title                             " <<
                  "Director             Released" << std::endl;
        std::cout << "-----    -------------------------------- " <<
                  "  --------------------  ---------" << std::endl;

        for (auto it = dramaInv.begin(); it != dramaInv.end(); it++)
        {
            std::cout << *it << std::endl;
        }
    }

    // print classic movies inventory
    if (!classicsInv.empty())
    {
        std::cout << std::endl;
        std::cout << "All Classic Movies: " << std::endl;

        std::cout << "Stock     Title                                " <<
                     "Director               Major Actor            Released"
                     << std::endl;

        std::cout << "-----    --------------------------------     " <<
                     "-------------------    -------------------    " <<
                     "---------" << std::endl;

        for (auto it = classicsInv.begin(); it != classicsInv.end(); it++)
        {
            std::cout << *it << std::endl;
        }
    }
}
