// ------------------------------ inventoryDB.h -----------------------------
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

#ifndef INVENTORYDB_H
#define INVENTORYDB_H

#include <set>
#include <string>
#include "classics.h"
#include "drama.h"
#include "comedy.h"
#include "transaction.h"

using namespace std;

// Implements inventory data base for the rental store. It provides a public
// methods to add a movie with valid genre, print all the inventory as well
// as accept valid transactions and update the stock.
class InventoryDB
{

public:

    set<Classics> classicsInv;   // stores all Classic movies in sorted order

    set<Drama> dramaInv;   // stores all Drama movies in sorted order

    set<Comedy> comedyInv;   // stores all Comedy movies in sorted order


public:
    // ---------------- default Constructor/ Destructor  ----------------
    // Description:
    // Constructs and initializes InventoryDB.
    // Destructs InventoryDB
    // ------------------------------------------------------------------
    InventoryDB();
    virtual ~InventoryDB();


    // ------------------------- addClassicsInventory -------------------
    // Description:
    // Inserts a valid classic movie into the InventoryDB.
    // Note:
    // The valid input must have the format:
    // C, Stock, Director, Title, Major actor releaseMonth releaseYear
    // ------------------------------------------------------------------
    void addClassicsInventory(const Classics& cl);


    // -------------------------- addComedyInventory  -------------------
    // Description:
    // Inserts a valid comedy movie into the InventoryDB.
    // Note:
    // The valid input must have the format:
    // F, Stock, Director, Title, releaseYear
    // ------------------------------------------------------------------
    void addComedyInventory(const Comedy& cmd);


    // ------------------------ addDramaInventory -----------------------
    // Description:
    // Inserts a valid drama movie into the InventoryDB.
    // Note:
    // The valid input must have the format:
    // D, Stock, Director, Title, releaseYear
    // ------------------------------------------------------------------
    void addDramaInventory(const Drama& dr);


    // ---------------------- isValidTransaction ------------------------
    // Description:
    // Returns true if the transaction to be made is valid.
    // A valid transaction can borrow or return a movie item. If this
    // InventoryDB contains a movie to be borrowed or returned then the
    // transaction is valid.
    bool makeTransaction(Transaction &transaction);


    // -------------------------- printInventory -------------------------
    // Description:
    // Outputs all Comedy movies, then all Dramas, then all Classics.
    // Each category of movies is ordered according to the sorting criteria.
    // ------------------------------------------------------------------
    void printInventory();

};


#endif //INVENTORYDB_H
