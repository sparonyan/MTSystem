// ------------------------------- classics.cpp -----------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents a Classics movie object for the rental store. Subclass of Movie.
// --------------------------------------------------------------------------
// Notes:
// The comparison methods are overriden in order to perform
// the correct comparison operation.
// --------------------------------------------------------------------------

#ifndef CLASSICS_H
#define CLASSICS_H

#include <string>
#include <vector>
#include "movie.h"

// Classics movie that represent the drama genre movie in the rental store.
// This class is used to create a Classics movie objects while reading the
// inventory from file and then will be stored in InventoryDB.
class Classics : public Movie {

public:

    // ------------------ Classics default Constructor ------------------
    // Description:
    // Constructs and initializes Classics object.
    // ------------------------------------------------------------------
    Classics();


    // ------------------ Classics copy Constructor ------------------
    // Description:
    // Constructs and initializes Classics object to the value of passed
    // argument.
    // ------------------------------------------------------------------
    Classics(const Classics &obj);


    // --------------------- Classics  Constructor ----------------------
    // Description:
    // Constructs and initializes Classics object from the given string.
    //
    // The given string argument must be in the format:
    //  C, Stock, Director, Title, Major actor Release date
    // ------------------------------------------------------------------
    explicit Classics(const std::string &line);


    // ---------------------- Classics Destructor -----------------------
    // Description:
    // Destroys Classics object.
    // ------------------------------------------------------------------
    virtual~Classics();


    // ------------------------------ isEqual ---------------------------
    // Description:
    // Returns true if two Classics movie objects are equal false otherwise.
    // Classics movie objects are equal if they have the same release date
    // and actor.
    // @Override
    // ------------------------------------------------------------------
    bool operator==(const Movie& other) const;

    // ---------------------------- isGreater ---------------------------
    // Description:
    // Returns true if this Classics movie is greater than the other passed
    // argument Classics, false otherwise. This Movie objects is grater than
    // the other movie, if this movie is released later. If their release
    // dates are equal, then the major actor's (strings) are compared.
    // @Override
    // ------------------------------------------------------------------
    bool operator>(const Movie& other) const;

    // ---------------------------- isLess ------------------------------
    // Description:
    // Returns true if this Movie is less than the other passed
    // argument Movie, false otherwise. This Movie objects is less that the
    // other movie, if this movie is released earlier, in case their release
    // dates are equal, then the major actor's (strings) are compared.
    // @Override
    // ------------------------------------------------------------------
    bool operator<(const Movie& other) const;


    // ----------------------------- operator<< -----------------------------
    // Description:
    // Overloaded operator :
    // Outputs this classics objects value in the following format:
    // C, Stock, Director, Title, Major actor Release date
    // ----------------------------------------------------------------------
    friend std::ostream& operator<<(std::ostream& os, const Classics& cl);



};


#endif //CLASSICS_H
