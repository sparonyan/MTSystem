// ------------------------------- drama.h ----------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents a Drama movie object for the rental store. Subclass of Movie.
// --------------------------------------------------------------------------
// Notes:
// The comparison methods are overriden in order to perform
// the correct comparison operation.
// --------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#include "movie.h"

// Drama movie that represent the drama genre movie in the rental store.
// This class is used to create a Drama movie objects while reading the
// inventory from file and then will be stored in InventoryDB.
class Drama : public Movie {

public:
    // ------------------ Drama default Constructor ------------------
    // Description:
    // Constructs and initializes Drama movie object.
    // ------------------------------------------------------------------
    Drama();


    // ------------------ Drama copy Constructor ------------------
    // Description:
    // Constructs and initializes Drama movie object to the value of passed
    // argument.
    //
    // D, Stock, Director, Title, Year it released
    // ------------------------------------------------------------------
    Drama(const Drama &obj);


    // --------------------- Drama  Constructor ----------------------
    // Description:
    // Constructs and initializes Drama movie object from the given string.
    //
    // The given string argument must be in the format:
    //  D, Stock, Director, Title, Year it released
    // ------------------------------------------------------------------
    explicit Drama(const std::string &line);


    // ---------------------- Drama Destructor -----------------------
    // Description:
    // Destroys Drama object.
    // ------------------------------------------------------------------
    virtual~Drama();


    // ------------------------------ operator== --------------------------
    // Description:
    // Returns true if two Drama movie objects are equal false otherwise.
    // Drama movie objects are equal if they have the same director name
    // and title.
    // @Override
    // ------------------------------------------------------------------
    bool operator==(const Movie& other) const;


    // ---------------------------- operator> ---------------------------
    // Description:
    // Returns true if this Drama movie is greater than the other passed
    // argument Drama, false otherwise. The comparison is done by comparing
    // director names and titles.
    // @Override
    // ------------------------------------------------------------------
    bool operator>(const Movie& other) const;


    // ---------------------------- operator< -----------------------------
    // Description:
    // Returns true if this Movie is less than the other passed
    // argument Movie, false otherwise. The comparison is done by comparing
    // director names and titles.
    // @Override
    // ------------------------------------------------------------------
    bool operator<(const Movie& other) const;


    // ----------------------------- operator<< -----------------------------
    // Description:
    // Overloaded operator :
    // Outputs this drama objects value in the following format:
    // D, Stock, Director, Title, Year it released
    // ----------------------------------------------------------------------
    friend std::ostream& operator<<(std::ostream& os, const Drama& dr);
};




#endif //DRAMA_H
