// ---------------------------- transaction.h -------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents Borrow or Return transaction. The object is created when the
// valid input is read from a file. Transaction is used to modify the
// InventoryDB and CustomerDB. The valid transactions will be assigned to
// the customer it is associated with.
//
// If valid borrow then the inventory stock for the specified movie will
// be decreased by one. If valid return the inventory stock for the specified
// movie will be increased by one.
// --------------------------------------------------------------------------
// Notes:
// Uses a friend factory function to process the input and if valid then
// initialize Transaction.
// --------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H


#include <string>
#include <iostream>

// Transaction object represents a valid Borrow or Return.
class Transaction
{
private:

    // customer unique id
    int idNumber;

    // return of borrow
    char actionType;

    // at this type store has only DVD's
    char mediaType;

    // Comedy, Drama or Classics
    char movieGenre;

    std::string movieTitle;

    int releaseYear;

    int releaseMonth;

    std::string majorActor;

    std::string director;

public:

    // ---------------------- Transaction constructors ------------------
    // Description:
    // Constructs and initializes Transaction object.
    // ------------------------------------------------------------------
    Transaction();


    Transaction(const Transaction &tr);


    // ------------------------ Transaction Destructor ------------------
    // Description:
    // Destroys transaction object.
    // ------------------------------------------------------------------
    virtual ~Transaction();


    // ------------------------ getCustomerIdNumber ---------------------
    // Description:
    // Returns a 4 digit integer representing a customer id number, which
    // is associated with this Transaction.
    // ------------------------------------------------------------------
    int getCustomerIdNumber() const;


    // ------------------------- getActionType --------------------------
    // Description:
    // Returns a string representing transaction type (Borrow or Return).
    // ------------------------------------------------------------------
    char getActionType() const;


    // -------------------------- getMediaType --------------------------
    // Description:
    // Returns a string representing the media type (DVD)
    // ------------------------------------------------------------------
    char getMediaType() const;


    // -------------------------- getMovieType --------------------------
    // Description:
    // Returns a string representing a movie genre (Comedy, Drama or
    // Classics).
    // ------------------------------------------------------------------
    char getMovieGenreType() const;


    // ------------------------- getMovieTitle --------------------------
    // Description:
    // Returns a string representing the movie title.
    // ------------------------------------------------------------------
    std::string getMovieTitle() const;


    // ------------------------ getReleaseYear --------------------------
    // Description:
    // Returns a string representing the movie release year.
    // ------------------------------------------------------------------
    int getReleaseYear() const;


    // ------------------------ getReleaseMonth -------------------------
    // Description:
    // Returns a string representing the movie release month.
    // ------------------------------------------------------------------
    int getReleaseMonth() const;


    // ------------------------ getMajorActor --------------------------
    // Description:
    // Returns a string representing the name of the movie's major actor.
    // ------------------------------------------------------------------
    std::string getMajorActor() const;


    // ----------------------- getMovieDirector -------------------------
    // Description:
    // Returns a string representing the movie director's name.
    // ------------------------------------------------------------------
    std::string getMovieDirector() const;


    // ------------------------- getTransactionInfo  ----------------------
    // Description:
    // Returns a string representing this transaction
    // in the following format:
    // "actionType   movieGenre   mediaType   movieTitle,  releaseDate"
    // ------------------------------------------------------------------
    std::string  getTransactionInfo() const;


    // ---------------------- getComedyMovieCommand ---------------------
    // Description:
    // Returns a string representing the command received for comedy movie
    // to perform transaction.
    // @pre - Transaction for comedy movie is created successfully.
    // ------------------------------------------------------------------
    std::string getComedyMovieCommand() const;


    // ----------------------- getDramaMovieCommand ---------------------
    // Description:
    // Returns a string representing the command received for drama movie
    // to perform transaction.
    // @pre - Transaction for drama movie is created successfully.
    // ------------------------------------------------------------------
    std::string getDramaMovieCommand() const;


    // -------------------- getClassicsMovieCommand ---------------------
    // Description:
    // Returns a string representing the command received for classics
    // movie to perform transaction.
    // @pre - Transaction for classics movie is created successfully.
    // ------------------------------------------------------------------
    std::string getClassicsMovieCommand() const;


    // -------------------------- setMovieTitle -------------------------
    // Description:
    // Sets this transaction movie title to the given string.
    // ------------------------------------------------------------------
    void setMovieTitle(const std::string &title);


    // -------------------------- setReleaseYear ------------------------
    // Description:
    // Sets this transaction movie title to the given string.
    // ------------------------------------------------------------------
    void setReleaseYear(const int &val);


    // factory function declared as friend.
    friend bool createTransaction(Transaction &T, const std::string &line, char action, int id);
};

// ------------------------ createTransaction -----------------------
// Description:
// Factory function to create a Transaction object if the received
// command line if valid, returns true in this case, othewise the object
// is not created and false is returned.
// ------------------------------------------------------------------
bool createTransaction(Transaction &T, const std::string &line, char action, int id);

#endif //TRANSACTION_H
