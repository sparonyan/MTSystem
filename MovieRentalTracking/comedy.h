// ------------------------------- comedy.h ---------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents a Comedy movie object for the rental store. Subclass of Movie.
// --------------------------------------------------------------------------
// Notes:
// The comparison methods are overriden in order to perform
// the correct comparison operation.
// --------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include <string>
#include "movie.h"

// Comedy movie that represent the drama genre movie in the rental store.
// This class is used to create a Comedy movie objects while reading the
// inventory from file and then will be stored in InventoryDB.
class Comedy : public Movie {

public:
    // ------------------ Comedy default Constructor ------------------
    // Description:
    // Constructs and initializes Comedy movie object.
    // ------------------------------------------------------------------
    Comedy();


    // ------------------ Comedy copy Constructor ------------------
    // Description:
    // Constructs and initializes Comedy movie object to the value of the
    // passed argument.
    // ------------------------------------------------------------------
    Comedy(const Comedy &obj);


    // ----------------------- Comedy Constructor ----------------------
    // Description:
    // Constructs and initializes Comedy movie object from the given string.
    //
    // The given string argument must be in the format:
    //  F, Stock, Director, Title, Year it released
    // ------------------------------------------------------------------
    explicit Comedy(const std::string &line);


    // ---------------------- Comedy Destructor -----------------------
    // Description:
    // Destroys Drama object.
    // ------------------------------------------------------------------
    virtual~Comedy();


    // ------------------------------ operator== --------------------------
    // Description:
    // Returns true if two Comedy movie objects are equal, false otherwise.
    // Comedy movie objects are equal if they have the same title and
    // release year.
    // @Override
    // ------------------------------------------------------------------
    bool operator==(const Movie& other) const;


    // ---------------------------- operator> ---------------------------
    // Description:
    // Returns true if this Comedy movie is greater than the other passed
    // argument Drama, false otherwise. The comparison is done by comparing
    // titles and release years.
    // @Override
    // ------------------------------------------------------------------
    bool operator>(const Movie& other) const;


    // ---------------------------- operator< -----------------------------
    // Description:
    // Returns true if this Comedy is less than the other passed
    // argument Movie, false otherwise. The comparison is done by comparing
    // titles and release years.
    // @Override
    // ------------------------------------------------------------------
    bool operator<(const Movie& other) const;


    // ----------------------------- operator<< -----------------------------
    // Description:
    // Overloaded operator :
    // Outputs this comedy object in the following format:
    // D, Stock, Director, Title, Year it released
    // ----------------------------------------------------------------------
    friend std::ostream& operator<<(std::ostream& os, const Comedy& cmd);
};


#endif //COMEDY_H
